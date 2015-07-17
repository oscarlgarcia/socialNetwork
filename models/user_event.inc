<?php

require_once ("Object.inc");

/**
* Clase Modelo para gestionar los datos de la tabla
* User_Event
*/
class User_Event extends Object{
	
   private $idUser;
   private $eventName;
   private $ipAddress;
   private $data;
   private $dateExecuted;
   	
	/**
	* Guarda un objeto User_Event y lo retorna como objeto
	*/
	public function save($user,$event,$ipAddress,$data)
	{
	  $user_event['ID_User'] =$user;
	  $this->idUser=$user;
      $user_event['eventName'] =$event;
      $this->eventName=$event;
      $user_event['ipaddress'] =$ipAddress;
      $this->ipAddress=$ipAddress;
      $user_event['data'] =$data;
      $this->data=$data;
      $user_event['dateExecuted']= date("Y-m-d H:i:s");
      $this->dateExecuted=$user_event['dateExecuted'];
  	  $this->registry->getObject('db')->insertRecords( 'user_event', $user_event );
  	  return $this;	
	}
	
	
	/**
	* Retorna el numero de ocurrencias por evento de un usuario
	*
	*/
	public function getThresholdByUserEvent($user,$event) 
	{
	  $sql = "SELECT * FROM user_event WHERE id_user='{$user}' and eventName='{$event}'";
      $this->registry->getObject('db')->executeQuery($sql);
      return $this->registry->getObject('db')->numRows();
    }
	
}

?>