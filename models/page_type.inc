<?php

require_once ("Object.inc");
/**
 *  PageType model
 * - Agrega y gestiona los Page_Type para los pages
 */
class PageType extends Object{
	
  private $name;
  private $limit = 500;
  private $saveable_fields = array( 'name');
		
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
	$this->registry->getObject('db')->insertRecords( 'page_type', $changes );
	$uid = $this->registry->getObject('db')->lastInsertID();
	return $uid;
  }	
	
  /*
  * Metodo que lista los tipos de paginas
  */
  public function listTypes()
  {
    $this->paginatedResult->setOffset(0);
	$query = "SELECT s.ID as type_id ,s.name as type_name FROM  page_type s order by s.name ASC" ;
	$this->paginatedResult->setQuery( $query );
	$this->paginatedResult->setMethod( 'cache' );
	$this->paginatedResult->generatePagination();
	return $this->paginatedResult;
  }

  /*
  * Metodo que lista los tipos de paginas
  */
  public function listTypesSelected($typeId)
  {
   	$this->paginatedResult->setOffset(0);
	$query = "SELECT s.ID as type_id ,s.name as type_name , IF(s.ID =".$typeId.",'selected','') as type_selected  FROM  page_type s order by s.name ASC" ;
	$this->paginatedResult->setQuery( $query );
	$this->paginatedResult->setMethod( 'cache' );
	$this->paginatedResult->generatePagination();
	return $this->paginatedResult;
  }


  public function setName($name){
    $this->name = $name;
  }
	
  public function getName(){
    $this->name;
  }
		
}
?>