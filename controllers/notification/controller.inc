<?php
 /**
 * Controlador para procesar las notificaciones
 * @version 1.0
 * @author  Oscar Garcia
 */	
class Notificationcontroller{
	
	/**
	 * Referencia del objeto registro
	 */
	private $registry;
	
	/**
	 * Usuario 
	 */
	private $userID;
	
	/**
	 * Constructor del controlador - direct call a false cuando esta embebido a traves de otro controlador
	 * @param Registry $registry nuestro objeto registro
	 * @param bool $directCall - TRUE si lo llamamos a traves del framework, o FALSE si es por otra via
	 */
	public function __construct( Registry $registry, $directCall )
	{
		require_once( FRAMEWORK_PATH . 'models/notification.inc'); 
		$this->registry = $registry;
		$this->userID = $userID;
		$this->notify($userID);
	}
	
	/*
	* Metodo que obtiene las notificaciones del usuario
	* y las envia como Stream
	*/
	private function notify($userID){
      $notification = new Notification($this->registry);
      $notification->sendNotification($notification->getNotifications($userID));
	}
   
	
}

			
?>