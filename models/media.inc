<?php

require_once ("Object.inc");
/**
 * Media model
 * - Agrega y gestiona los Media object
 */
class Media extends Object{
		
  private $ID;
  private $name;
  private $url;
  private $size;
  private $limit = 1000; //TODO poner en configs
  private $saveable_fields = array( 'name', 'url', 'size');
	

  /*
  * Carga un objeto media
  */
  public function getMedia($mediaID){
    $query = "SELECT * FROM media where ID =".$mediaID ;
    $this->registry->getObject('db')->executeQuery( $query );
    if( $this->registry->getObject('db')->numRows() > 0 )
    {
      $data = $this->registry->getObject('db')->getRows();
      $this->setID($data['ID']);
      $this->setName($data['name']);
      $this->setURL($data['url']);
      $this->setSize($data['size']);
      return true;
    }
    return false;
  }


 /**
  * Obtiene todos los media
  * Se llama desde Admin_media
  * @return Object 
  * Id del media
  * Nombre del media
  */
  public function getAllMedia()
  {
    $this->paginatedResult->setLimit(1000000000); // TODO sin limite
    $this->paginatedResult->setOffset(0);
    $query = "SELECT ID as mediaID , name as mediaName FROM media" ;
    $this->paginatedResult->setQuery( $query );
    $this->paginatedResult->setMethod( 'cache' );
    $this->paginatedResult->generatePagination();
    return $this->paginatedResult;
  }




  /**
   * Genera lista de imagenes paginadas
   * @param int $criteria
   * @return Object pagination object
   */
  public function browse($criteria)
  {
	  $this->paginatedResult->setLimit(1000000); //TODO poner no limit
	  $this->paginatedResult->setOffset(0);
	  $query = "SELECT id, url, name, size from media where name like '%".$criteria."%' " ; // poner un indice
	  $this->paginatedResult->setQuery( $query );
	  $this->paginatedResult->setMethod( 'cache' );
	  $this->paginatedResult->generatePagination();
	  return $this->getAsTable($this->paginatedResult);
  }


  /**
   * Genera lista de categorias que coinciden con el criterio pasado paginados 
   * Este metodo se llama en Admin_media desde el administrador
   * Devuelve un ResulSet con la siguiente informacion en caché:
   * @param int $offset, pagina de la busqueda
   * @param String $criteria, cadena de busqueda 
   * @return Object pagination object
   */
  public function search($offset = 1, $criteria = "")
  {
    $this->paginatedResult->setLimit(10);
    $this->paginatedResult->setOffset($offset - 1);
    $query=" SELECT tbl.*, GROUP_CONCAT(DISTINCT tagName SEPARATOR ' ') 
    As all_tags FROM(SELECT m.ID as ID, m.name as name, m.url as url, m.size as size, CONCAT('<a href=\"admin_tags/view/',t.tag_name,'\" class=\"label label-info\">',t.tag_name,'</a> ') as tagName from media m inner join list_media_tags l on l.ID_media = m.ID inner join tags t on t.ID = l.ID_tag where name like '%".$criteria."%') tbl GROUP BY tbl.id ";
    $this->paginatedResult->setQuery( $query );
    $this->paginatedResult->setMethod( 'cache' );
    $this->paginatedResult->generatePagination();
    return $this->paginatedResult;
  }

	
  /*
  * Permite cargar una imagen de media
  */
  public function loadImage($mediaID){
    $query = "SELECT url FROM media where ID =".$mediaID ;
    $this->registry->getObject('db')->executeQuery( $query );
    if( $this->registry->getObject('db')->numRows() > 0 )
    {
      $data = $this->registry->getObject('db')->getRows();
      $this->setUrl($data['url']);
    }
    return false;
  }
	
    /**
	 * borra un media a partir de su ID
	 * @param int $mediaID 
	 */
	public function delete($mediaID)
	{
      $this->registry->getObject('db')->deleteRecords( 'media',' id = '.$mediaID,'1');
	   $uid = $this->registry->getObject('db')->lastInsertID();
	   return $uid;  
	}
	

	public function save()
	{
     $changes = array();
	  foreach( $this->saveable_fields as $field )
	  {
	    $changes[ $field ] = $this->$field;
	  }
	  $this->registry->getObject('db')->insertRecords( 'media', $changes );
	  $uid = $this->registry->getObject('db')->lastInsertID();
	  return $uid;  
	}	
	
	private function getAsTable($result){
      
      if ($result->getTotalRows()!=0){
      	$table = "<table class='table table-hover image_browser'>
      	          <thead>
                  <th>ID</th>
                  <th>Nombre</th>
                  <th>Imagen</th>
                  <th>Tamaño</th>
                  </thead>
                  <tbody>";
	    while ($value = $this->registry->getObject('db')->resultsFromCache($result->getCache()))
	    {
           $table.="<tr>
                    <td class='col-md-2'>".$value["id"]."</td>
                    <td class='col-md-4'>".$value["name"]."</td>
                    <td class='col-md-4'>
                      <img data-media='".$value["id"]."'' src='".$value["url"]."' class='img-thumbnail' width='80' height='80' />
                    </td>
                    <td class='col-md-2'>".$value["size"]."</td>
                    ";
      	}
      	$table.= "</tbody></table>"; 
      	return $table;
      } else{

      	return "No hay registros";
      }

      
	}
	
  /*
  * Metodos setter y getter
  *
  */
  public function getID(){
    $this->ID;
  }

  public function setID($value){
    $this->ID = $value;
  }
   
  public function setName($name){
    $this->name=$name;
  }
   
  public function getName(){
    return $this->name;
  }
   
  public function setUrl($url){
    $this->url = $url;
  }
   
  public function getUrl(){
    return $this->url;
  }

  public function setSize($value){
    $this->size = $value;
  }
   
  public function getSize(){
    return $this->size;
  }


}
?>