<?php

require_once ("Object.inc");
/**
 * Tags model
 * - Agrega y gestiona los Tags
 */
class Tags extends Object{
	
  private $tag_name;
  private $limit = 15;
  private $saveable_fields = array( 'tag_name');
	
	
  /**
  * Genera lista de tags mas usados en Snippets 
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
  * Obtiene el tag
  * @param int $id 
  * @return Object pagination object
  */
  public function getTag( $tagID )
  {
	  $query = "SELECT ID,tag_name as tag FROM tags where ID=".$tagID ;
	  $this->paginatedResult->setQuery( $query );
	  $this->paginatedResult->setMethod( 'cache' );
	  $this->paginatedResult->generatePagination();
	  return $this->paginatedResult;
  }
	
  /*
  * Metodo que verifica si un tag esta ya guardado
  * @param varchar nombre del tag
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
	
  /*
  * Metodos setter
  */
  public function setName($name){
    $this->tag_name= $name;
  }
	
}
?>