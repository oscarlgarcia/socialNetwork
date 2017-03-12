<?php

require_once ("Object.inc");

/**
 * Search_Term model
 * - Agrega y gestiona los terminos de busqueda
 */
class Search_Term extends Object{
	
  private $ID;
  private $term;
  private $limit = 10; //TODO poner en configs
  private $saveable_fields = array( 'term');


  /**
  * Metodo que guarda el search term
  */
  public function save()
  {
    $changes = array();
	  foreach( $this->saveable_fields as $field )
	  {
	    $changes[ $field ] = $this->$field;
	  }
	  $this->registry->getObject('db')->insertRecords( 'snippets', $changes );
	  $uid = $this->registry->getObject('db')->lastInsertID();
	  return $uid;  
  }	

  /*
  * Metodos setter y getter
  *
  */
  public function getID(){
    $this->ID;
  }
   
  public function setTerm($term){
    $this->title = $term;
  }
   
  public function getTerm(){
    return $this->term;
  }
  
	
}
?>