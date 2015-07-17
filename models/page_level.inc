<?php

require_once ("Object.inc");
/**
 *  PageLevel model
 * - Agrega y gestiona los Page_Level para los pages
 */
class PageLevel extends Object{
	
  private $id;
  private $name;
  private $description;
  private $saveable_fields = array( 'name','description');
	
  /*
  * Metodo que almacena un comentario en la bbdd
  * @return ID del comentario.
  *
  */
  public function save()
  {
    $changes = array();
	foreach( $this->saveable_fields as $field )
	{
	  $changes[ $field ] = $this->$field;
	}
	$this->registry->getObject('db')->insertRecords( 'page_level', $changes );
	$uid = $this->registry->getObject('db')->lastInsertID();
	return $uid;
  }	
	
  /*
  * Metodo que lista los tipos de paginas
  */
  public function listLevel()
  {
    $this->paginatedResult->setLimit(500);
	$this->paginatedResult->setOffset(0);
	$query = "SELECT s.ID as level_id ,s.name as level_name, s.description as level_description FROM  page_level s order by s.ID ASC" ;
	$this->paginatedResult->setQuery( $query );
	$this->paginatedResult->setMethod( 'cache' );
	$this->paginatedResult->generatePagination();
	return $this->paginatedResult;
  }

  /*
  * Metodo que lista los tipos de paginas
  */
  public function listLevelSelected($levelID)
  {
    $this->paginatedResult->setLimit(500);
	$this->paginatedResult->setOffset(0);
	$query = "SELECT s.ID as level_id ,s.name as level_name , IF(s.ID =".$levelID.",'selected','') as level_selected  FROM  page_level s order by s.ID ASC" ;
	$this->paginatedResult->setQuery( $query );
	$this->paginatedResult->setMethod( 'cache' );
	$this->paginatedResult->generatePagination();
	return $this->paginatedResult;
  }

  public function setName($name){
    $this->name = $name;
  }
	
  public function getName(){
    return $this->name;
  }
	
  public function setID($id){
    $this->id= $id;
  }

  public function getID(){
    return $this->id;
  }
		
}
?>