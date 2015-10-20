<?php

require_once ("Object.inc");

/**
* Clase Modelo para gestionar los datos de la tabla
* badges
*/
class Badges extends Object{
	
   private $id;
   private $name;
   private $title;
   private $description;
   private $path_image;
	 private $limit = 10;
	 private $saveable_fields = array( 'name','description','path_image','title');
	
  /**
  * Obtiene un Badge a partir de su ID
  * @param String $badgeID 
  * @return Object Badge
  */
  public function load($badgeID)
  {
    $query = "SELECT * FROM badges where id = ".$badgeID;
    $this->registry->getObject('db')->executeQuery( $query );
    if( $this->registry->getObject('db')->numRows() > 0 )
    {
      $data = $this->registry->getObject('db')->getRows();
      $this->setName($data['name']);
      $this->setDescription($data['description']);
      $this->setPathImage($data['path_image']);
      $this->setTitle($data['title']);
      return true;
    }
    return null;
  }


  /*
  * Metodo que almacena un badge en la bbdd
  * @return ID del badge.
  *
  */
  public function save()
  {
    $changes = array();
    foreach( $this->saveable_fields as $field )
    {
      $changes[ $field ] = $this->$field;
    }

    //lo guardamos
    $this->registry->getObject('db')->insertRecords( 'badges', $changes );
    $uid = $this->registry->getObject('db')->lastInsertID();
    return $uid;
  } 

  /*
  * Metodos setter
  */
 
  public function setName($value){
    $this->name = $value;
  }

  public function setDescription($value){
    $this->description = $value;
  }
  
  public function setPathImage($value){
    $this->path_image = $value;
  }
  
  public function setID($value){
    $this->id = $value;
  }   

  public function setTitle($value){
    $this->title = $value;
  }   


   public function getName(){
    return $this->name;
  }

  public function getDescription(){
    return $this->description;
  }
  
  public function getPathImage(){
    return $this->path_image;
  }
  
  public function getID(){
    return $this->id;
  }   

  public function getTitle(){
    return $this->title;
  }

  
}

?>