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
  private $limit = 1000; //TODO poner en configs
  private $saveable_fields = array( 'name', 'url');
	
  /**
   * Genera lista de imagenes paginadas
   * @param int $criteria
   * @return Object pagination object
   */
  public function search($criteria)
  {
	$this->paginatedResult->setLimit(5); //TODO poner no limit
	$this->paginatedResult->setOffset(0);
	$query = "SELECT id, url, name from media where name like '%".$criteria."%' " ; // poner un indice
	$this->paginatedResult->setQuery( $query );
	$this->paginatedResult->setMethod( 'cache' );
	$this->paginatedResult->generatePagination();
	return $this->getAsTable($this->paginatedResult);
  }
	
	
    /**
	 * borra un snippet a partir de su ID
	 * @param int $snippetID 
	 */
	public function delete($id)
	{
      $this->registry->getObject('db')->deleteRecords( 'snippets',' id = '.$id,'1');
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
      	$table = "<table class='table table-hover'>
      	          <thead>
                  <th>ID</th>
                  <th>Nombre</th>
                  <th>Imagen</th>
                  </thead>
                  <tbody>";
	    while ($value = $this->registry->getObject('db')->resultsFromCache($result->getCache()))
	    {
           $table.="<tr>
                     <td class='col-md-2'>".$value["id"]."</td>
                     <td class='col-md-4'>".$value["name"]."</td>
                     <td class='col-md-6'>
                       <img src='".$value["url"]."' class='img-thumbnail' width='80' height='80' />
                     </td>
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
    $this->url=$url;
  }
   
  public function getUrl(){
    return $this->url;
  }

}
?>