<?php

require_once ("Object.inc");
/**
 * Tags model
 * - Agrega y gestiona los Tags
 */
class Tags extends Object{
	
  private $tag_name;
  private $limit = 10;
  private $saveable_fields = array( 'tag_name');
	
	
  /**
  * Obtiene un Tag a partir de su ID
  * Se llama desde Admin_tags
  * @param int $tagID 
  * @return Object 
  * Id del Tag
  * Nombre del Tag
  */
  public function getTag($tagID)
  {
    $query = "SELECT t.tag_name FROM tags t where t.ID=".$tagID ;
    $this->registry->getObject('db')->executeQuery( $query );
    if( $this->registry->getObject('db')->numRows() > 0 )
    {
      $data = $this->registry->getObject('db')->getRows();
      $tempo['tag_name']=$data['tag_name']; 
      return $tempo; 
    }
    return null;
  }

  /**
  * Obtiene todos los Tags
  * Se llama desde Admin_tags
  * @return Object 
  * Id del Tag
  * Nombre del Tag
  */
  public function getTags()
  {
    $this->paginatedResult->setLimit(1000000);
    $this->paginatedResult->setOffset(0);
    $query = "SELECT ID, tag_name FROM tags" ;
    $this->paginatedResult->setQuery( $query );
    $this->paginatedResult->setMethod( 'cache' );
    $this->paginatedResult->generatePagination();
    return $this->paginatedResult;
  }

  /**
  * Genera lista de tags mas usados en Snippets
  * Se utiliza en Snippets para crear la nube de tags
  * Devuelve un objeto:
  * Total de ocurrencias.
  * nombre Tag
  * @return Object pagination object
  */
  public function topSnippetTags()
  {
    $this->paginatedResult->setLimit($this->limit); 
	  $this->paginatedResult->setOffset(0);
	  $query = "SELECT count(a.tag_name) total, a.tag_name as name FROM tags a inner join lista_tag_snippet b on a.ID=b.ID_tag group by a.tag_name order by total desc";
  	$this->paginatedResult->setQuery( $query );
	  $this->paginatedResult->setMethod( 'cache' );
	  $this->paginatedResult->generatePagination();
	  return $this->paginatedResult;
  }
	
   /**
   * Genera lista de tags que coinciden con el criterio pasado paginados 
   * Este metodo se llama en Admin_Tags desde el administrador
   * Devuelve un ResulSet con la siguiente informacion en caché:
   * ID del Tag
   * Nombre del Tag
   * Total de Snippets que tiene este tag
   * Total de Links que tiene este tag
   * Total de Paginas que tiene este Tag
   * Total de Imagenes que tiene este tag.
   * @param int $offset, pagina de la busqueda
   * @param String $criteria, cadena de busqueda 
   * @return Object pagination object
   */
  public function search($offset = 1, $criteria = "")
  {
    $this->paginatedResult->setLimit($this->limit);
    $this->paginatedResult->setOffset($offset - 1);
    $query="SELECT t.ID, t.tag_name, count(DISTINCT ts.ID) as total_snippets, count(DISTINCT tl.ID) as total_links, count(DISTINCT tp.ID) as total_pages, count(DISTINCT tm.ID) as total_media FROM tags t left join lista_tag_snippet ts on ts.ID_tag = t.id left join list_tags_links tl on tl.ID_tags = t.ID left join list_tag_page tp on tp.ID_tag = t.ID left join list_media_tags tm on tm.ID_tag = t.ID WHERE t.tag_name like '%".$criteria."%' group by t.ID";
    $this->paginatedResult->setQuery( $query );
    $this->paginatedResult->setMethod( 'cache' );
    $this->paginatedResult->generatePagination();
  return $this->paginatedResult;
  }




  /**
  * Metodo que verifica si un tag esta ya guardado
  * @param String $tagName , Nombre del tag
  * @return ID del tag o false sino existe
  */
  public function isSaved($tagName)
  {
 	  $query = "SELECT ID as id, tag_name as tag FROM tags where tag_name='".$tagName."'" ;
	  $this->paginatedResult->setQuery( $query );
	  $this->paginatedResult->setMethod( 'cache' );
	  $this->paginatedResult->generatePagination();
	  if ($this->paginatedResult->getTotalRows()==1)
    {  
	    $tag = $this->registry->getObject('db')->resultsFromCache($this->paginatedResult->getCache());
	    return $tag["id"];
	  }
	  return false;
  }

  /*
  * Metodo que almacena un tag en la bbdd
  * @return ID del tag.
  *
  */
  public function save()
  {
    $changes = array();
	  foreach( $this->saveable_fields as $field )
	  {
	    $changes[ $field ] = $this->$field;
	  }
	  $isSaved=$this->isSaved($this->tag_name);
	
	  // Si el tag no esta guardado
	  if(!$isSaved)
    {
	    //lo guardamos
	    $this->registry->getObject('db')->insertRecords( 'tags', $changes );
	    $uid = $this->registry->getObject('db')->lastInsertID();
	    return $uid;  
	  }
	
	  //sino lo devolvemos
	  return $isSaved;
  }	
	

  /**
  * borra un tag a partir de su ID
  * @param int $snippetID 
  */
  public function delete($id)
  {
    $this->registry->getObject('db')->deleteRecords( 'tags',' id = '.$id,'1');
    $uid = $this->registry->getObject('db')->lastInsertID();
    return $uid;  
  }

  /**
  * actualiza el nombre del tag
  * @param int $tagID 
  */
  public function updateTagName($tagID, $newName)
  {
    $changes = array();
    $changes['tag_name'] = $newName;
    $this->registry->getObject('db')->updateRecords('tags', $changes," id = ".$tagID );
    $uid = $this->registry->getObject('db')->lastInsertID();
    return $uid;  
  }
  
  /**
  * Metodo que comprueba si este tag tiene algun recurso asignado
  * La idea es que no deje borrar un Tag si hay algun recurso que lo contenga
  * @param $tagID
  * @return True si no hay resurso asignado ( puede ser borrado),
  * False si hay algun recurso ( no puede borrarse)
  */
  public function canErase($tagID)
  {
    $query = "SELECT t.ID, t.tag_name, count(DISTINCT ts.ID) as total_snippets, count(DISTINCT tl.ID) as total_links, count(DISTINCT tp.ID) as total_pages, count(DISTINCT tm.ID) as total_media FROM tags t left join lista_tag_snippet ts on ts.ID_tag = t.id left join list_tags_links tl on tl.ID_tags = t.ID left join list_tag_page tp on tp.ID_tag = t.ID left join list_media_tags tm on tm.ID_tag = t.ID WHERE t.ID =".$tagID;
    $this->paginatedResult->setQuery( $query );
    $this->paginatedResult->setMethod( 'cache' );
    $this->paginatedResult->generatePagination();
    if ($this->paginatedResult->getTotalRows()==1)
    {  
      $tag = $this->registry->getObject('db')->resultsFromCache($this->paginatedResult->getCache());
      $temp['total_snippets'] = intval($tag["total_snippets"]);
      $temp['total_links'] = intval($tag["total_links"]);
      $temp['total_pages'] = intval($tag["total_pages"]);
      $temp['total_media'] = intval($tag["total_media"]);
      if ( $temp['total_snippets']==0 && $temp['total_links'] == 0 && $temp['total_pages'] == 0 && $temp['total_media'] == 0 )
        return true;
      return false;
    }
    return false;
  }

  /*
  * Metodos setter
  */
  public function setName($name){
    $this->tag_name= $name;
  }
	
}
?>