<?php

require_once ("Object.inc");
/**
 * Event model
 * - Agrega y gestiona los Event
 */
class Event extends Object{
	
  private $eventName;
  private $description;
  private $imageEvent;
  private $limit = 10;
  private $saveable_fields = array( 'eventName','description','imageEvent');
	
	
  /**
  * Obtiene un Event a partir de su nombre
  * Se llama desde Admin_event
  * @param String $eventID 
  * @return Object Event
  */
  public function getEvent($eventName)
  {
    $query = "SELECT * FROM event where eventName = '".$eventName."'";
    $this->registry->getObject('db')->executeQuery( $query );
    if( $this->registry->getObject('db')->numRows() > 0 )
    {
      $data = $this->registry->getObject('db')->getRows();
      $this->setEventName($data['eventName']);
      $this->setEventDescription($data['description']);
      $this->setEventImage($data['imageEvent']);
      return true;
    }
    return null;
  }


  /**
   * Genera lista de Eventos
   * @param int $offset 
   * @return Object pagination object
   */
  public function listEvent( $offset=0 )
  {
    $this->paginatedResult->setLimit(500);
    $this->paginatedResult->setOffset( $offset );
    $query = "SELECT e.eventName as name, e.description as description FROM  event e order by e.eventName ASC" ;
    $this->paginatedResult->setQuery( $query );
    $this->paginatedResult->setMethod( 'cache' );
    $this->paginatedResult->generatePagination();
    return $this->paginatedResult;
  }


    /**
   * Genera lista de eventos con una seleccionada
   * @param int $offset ,  $eventName
   * @return Object pagination object
   */
  public function listEventSelected( $eventName )
  {
    $this->paginatedResult->setLimit(500);
    $this->paginatedResult->setOffset(0);
    $query = "SELECT e.eventName as name, e.description as description, IF( eventName = '".$eventName."','selected','') as eventSelected FROM event e order by e.eventName ASC" ;
    $this->paginatedResult->setQuery( $query );
    $this->paginatedResult->setMethod( 'cache' );
    $this->paginatedResult->generatePagination();
    return $this->paginatedResult;
  }



	
   /**
   * Genera lista de Eventos que coinciden con el criterio pasado paginados 
   * Este metodo se llama en Admin_event desde el administrador
   * Devuelve un ResulSet con la siguiente informacion en caché:
   * Nombre del evento
   * Descripcion
   * Imagen
   * @param int $offset, pagina de la busqueda
   * @param String $criteria, cadena de busqueda 
   * @return Object pagination object
   */
  public function search($offset = 1, $criteria = "")
  {
    $this->paginatedResult->setLimit($this->limit);
    $this->paginatedResult->setOffset($offset - 1);
    $query="SELECT e.eventName as name, e.description as description, e.imageEvent as image FROM event e WHERE e.eventName like '%".$criteria."%' or e.description like '%".$criteria."%'";
    $this->paginatedResult->setQuery( $query );
    $this->paginatedResult->setMethod( 'cache' );
    $this->paginatedResult->generatePagination();
    return $this->paginatedResult;
  }


  /**
  * Metodo que verifica si un Evento esta ya guardado
  * @param String $eventName , Nombre del Evento
  * @return ID del evento o false sino existe
  */
  public function isSaved($eventName = '')
  {
    if ($eventName == "") 
      return true;
 	  $query= "SELECT e.eventName as name FROM event e where e.eventName = '".$eventName."'" ;
    $this->paginatedResult->setQuery( $query );
	  $this->paginatedResult->setMethod( 'cache' );
	  $this->paginatedResult->generatePagination();
	  if ($this->paginatedResult->getTotalRows() == 1)
    {  
      return true;
	  }
	  return false;
  }

   
  /*
  * Metodo que almacena un setting en la bbdd
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

    //lo guardamos
	  $this->registry->getObject('db')->insertRecords( 'event', $changes );
	  $uid = $this->registry->getObject('db')->lastInsertID();
	  return $uid;
  }	
	

  /**
  * borra un tag a partir de su eventName
  * @param int $eventName 
  */
  public function delete($eventName)
  {
    $this->registry->getObject('db')->deleteRecords( 'event',' eventName = '.$eventName,'1');
    $uid = $this->registry->getObject('db')->lastInsertID();
    return $uid;  
  }

  
  /*
  * Metodos setter
  */
  public function setEventName($eventName){
    $this->eventName = $eventName;
  }

  public function setEventDescription($description){
    $this->description = $description;
  }

  public function setEventImage($imageEvent){
    $this->imageEvent = $imageEvent;
  }  

 public function getEventName(){
    return $this->eventName;
  }

  public function getEventDescription(){
    return $this->description;
  }

  public function getEventIamge(){
    return $this->imageEvent;
  }  

}
?>