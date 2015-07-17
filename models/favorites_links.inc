<?php

require_once ("Object.inc");
/**
 * Favorites_Links model
 * - Agrega y gestiona los links favoritos de un usuario
 */
class Favorites_Links extends Object{
	
  private $idFav;
  private $ID_Users;
  private $ID_Links;
  private $saveable_fields = array( 'ID_Users', 'ID_Links');
	
  public function __construct( Registry $registry,$ID_Users,$ID_Links)
  {
  	parent::__construct($registry);
    $this->ID_Users = $ID_Users;
	$this->ID_Links = $ID_Links;
  }


	public function save()
	{
     $changes = array();
	  foreach( $this->saveable_fields as $field )
	  {
	    $changes[ $field ] = $this->$field;
	  }
	  $this->registry->getObject('db')->insertRecords( 'list_favorites_links', $changes );
	  $uid = $this->registry->getObject('db')->lastInsertID();
	  return $uid;  
	}

	public function delete()
	{
      $this->registry->getObject('db')->deleteRecords( 'list_favorites_links','ID_Links='.$this->ID_Links.' and ID_Users='.$this->ID_Users,'1');
	  $uid = $this->registry->getObject('db')->lastInsertID();
	  return $uid;  
	}
	
}
?>