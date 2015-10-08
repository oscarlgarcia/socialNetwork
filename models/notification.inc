<?php

require_once ("Object.inc");
/**
 * Notification model
 * - Agrega y gestiona las notificaciones
 */
class Event extends Object{
	
  private $id;
  private $id_User;
  private $id_User_From;
  private $notification;
  private $showed;
  private $timestamp;
  private $limit = 1000;
  private $saveable_fields = array( 'id_User','id_User_From','notification','showed','timestamp');
	
	
  /**
  * Obtiene una notificacion a partir de su ID
  * Se llama desde Admin_XXXX
  * @param String $notifID 
  * @return Object notification
  */
  public function getNotification($notifID)
  {
    $query = "SELECT * FROM notification where ID = ".$notifID;
    $this->registry->getObject('db')->executeQuery( $query );
    if( $this->registry->getObject('db')->numRows() > 0 )
    {
      $data = $this->registry->getObject('db')->getRows();
      $this->setID($data['ID']);
      $this->setIDUser($data['id_User']);
      $this->setUserIDFrom($data['id_User_From']);
      $this->setNotificationType($data['notification']);
      $this->setShow($data['showed']);
      $this->setTimestamp($data['timestamp']);
      return true;
    }
    return null;
  }

  /**
  * Obtiene todas las notificaciones de un usuario y las envia
  * @param String $userID 
  */
  public function sendNotification($userID)
  {
    while(1){
      $this->update($userID,0,1);  // separamos las q devolveremos

      $this->paginatedResult->setLimit($this->limit);
      $this->paginatedResult->setOffset(0);
      $query = "select * from notification where  ID_User =".$userID." and showed = 1";
      $this->paginatedResult->setQuery( $query );
      $this->paginatedResult->setMethod( 'cache' );
      $this->paginatedResult->generatePagination();
      
      $this->update($userID,1,2);  //marcamos las devueltas para no procesarlas de nuevo

    }
   
  }



  /**
  * actualiza el showed de la notificacion
  * @param int $userID
  * @param int $notifID 
  */
  public function update($userID,$previous, $next)
  {
    $changes = array();
    $changes['showed'] = $next;
    $this->registry->getObject('db')->updateRecords('notification', $changes," ID_User = ".$userID." and showed = ".$previous );
    $uid = $this->registry->getObject('db')->lastInsertID();
    return $uid;  
  }



  public function writeOutput($cursor){

    header("Content-Type: text/event-stream");
    header("Cache-Control: no-cache");
    header("Access-Control-Allow-Origin: *");


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
	  $this->registry->getObject('db')->insertRecords( 'notification', $changes );
	  $uid = $this->registry->getObject('db')->lastInsertID();
	  return $uid;
  }	
	

  /*
  * Metodos setter
  */
  private $timestamp;

  public function getID(){
    return $this->id;
  }

  public function setID($id){
    $this->id = $id;
  }

  public function getUserID(){
    return $this->id_User;
  }

  public function setIDUser($id_User){
    $this->id_User = $id_User;
  }

  public function getUserIDFrom(){
    return $this->id_User_From;
  }

  public function setUserIDFrom($id_User_From){
    $this->id_User_From = $id_User_From;
  }

  public function getNotificationType(){
    return $this->notification;
  }

  public function setNotificationType($notification){
    $this->notification = $notification;
  }

  public function isShowed(){
    return $this->showed;
  }

  public function setShow($showed){
    $this->showed = $showed;
  }

  public function getTimestamp(){
    return $this->timestamp;
  }

  public function setTimestamp($timestamp){
    $this->timestamp = $timestamp;
  }

}
?>