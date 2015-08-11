<?php

require_once ("Object.inc");
/**
 * Category Controller
 * - Agrega y gestiona las controladores del site
 */
class Controller extends Object
{
	
  private $ID;
  private $controller;
  private $active;
  private $description;
  private $created;
  private $saveable_fields = array( 'controller', 'active','description','created'); 
  private $limit = 10; //poner en config
  
  /*
  * Metodo que guarda el controller en BBDD
  */
  public function save()
  {
    $changes = array();
	foreach( $this->saveable_fields as $field )
	{
	  $changes[ $field ] = $this->$field;
	}
	$this->registry->getObject('db')->insertRecords( 'controllers', $changes );
	$uid = $this->registry->getObject('db')->lastInsertID();
	return $uid;  
  }	

  /*
  * Metodo que actualiza el controller en BBDD
  */
  public function update()
  {
    $changes = array();
    foreach( $this->saveable_fields as $field )
    {
      $changes[ $field ] = $this->$field;
    }
    $this->registry->getObject('db')->updateRecords('controllers', $changes," id = ".$this->ID );
    $uid = $this->registry->getObject('db')->lastInsertID();
    return $uid;  
  }

  /**
  * borra un controller a partir de su ID
  * @param int $controllerID 
  */
  public function delete($controllerID)
  {
    $this->registry->getObject('db')->deleteRecords( 'controllers',' id = '.$controllerID,'1');
    $uid = $this->registry->getObject('db')->lastInsertID();
    return $uid;  
  }

  /**
  * Obtiene un controlador a partir de su ID
  * Devuelve un objeto con la siguiente Informacion:
  * - ID 
  * - name
  * - created
  * - Description
  * @param int $controllerID 
  * @return Object 
  */
  public function getController($controllerID)
  {
    $query = "SELECT ID, controller, created, active, description FROM controller where ID = ".$controllerID;
	  $this->registry->getObject('db')->executeQuery( $query );
    if( $this->registry->getObject('db')->numRows() > 0 )
    {
      $data = $this->registry->getObject('db')->getRows();
      $this->setID($data['ID']);
      $this->setControllerName($data['controller']);
      $this->setCreated($data['active']);
      $this->setActive($data['active']);
      $this->setDescription($data['description']);
      return true;
    }
    return false;
  }
	
  /**
   * Genera lista de controladores
   * Se utiliza en Admin_controllers
   * Retorna un objeto paginacion con
   * - ID
   * - Controlador
   * - created
   * - Descripcion
   * - CSS
   * @param int $offset 
   * @return Object pagination object
   */
  public function search( $offset = 1, $criteria = "" )
  {
    $this->paginatedResult->setLimit($this->limit);
	  $this->paginatedResult->setOffset( $offset - 1);
	  $query = "SELECT c.ID as ID , c.controller as controller,  DATE_FORMAT(c.created,'%d %b %Y %T') as created, c.description as description, s.status_class as class FROM  controllers c inner join operational_status s  on c.active = s.ID where controller like '%".$criteria."%' order by controller ASC" ;
	  $this->paginatedResult->setQuery( $query );
	  $this->paginatedResult->setMethod( 'cache' );
	  $this->paginatedResult->generatePagination();
	  return $this->paginatedResult;
  }


  // Setter and Getters
  public function setID($id){ 
    $this->ID = $id; 
  }
  
  public function getID(){
    return $this->ID;
  }

  public function setCreated($created){ 
    $this->created = $created; 
  }
  
  public function getCreated(){
    return $this->created;
  }

  public function setControllerName($name){ 
    $this->controller = $name; 
  }
  
  public function getControllerName(){
  	return $this->controller;
  }

  public function setActive($flag){ 
  	$this->active = $flag; 
  }
  
  public function isActive(){
 	return $this->active;
  }

  public function setDescription($description){ 
  	$this->description = $description; 
  }
  
  public function getDescription(){
  	return $this->description;
  }

}
?>