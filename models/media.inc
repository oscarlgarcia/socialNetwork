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
	
  /**
   * Genera lista de imagenes paginadas
   * @param int $criteria
   * @return Object pagination object
   */
  public function search($criteria)
  {
	  $this->paginatedResult->setLimit(5); //TODO poner no limit
	  $this->paginatedResult->setOffset(0);
	  $query = "SELECT id, url, name, size from media where name like '%".$criteria."%' " ; // poner un indice
	  $this->paginatedResult->setQuery( $query );
	  $this->paginatedResult->setMethod( 'cache' );
	  $this->paginatedResult->generatePagination();
	  return $this->getAsTable($this->paginatedResult);
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