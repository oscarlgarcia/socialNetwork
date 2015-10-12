<?php

require_once( 'AbstractObserver.class.inc' );
/*
 * Clase para gestionar la suma de puntos y 
 * experiencia en la gamificacion
 * autor : Oscar Garcia
 */

class Notify extends AbstractObserver{
  
	/**
	 * Constructor
	 */
	public function __construct( Registry $registry )
	{
		$this->registry = $registry;
	}
	
	/**
	* Metodo para actualizar el valor de un evento realizado
	*/
	public function update(AbstractSubject $subject) 
	{    
    require_once( FRAMEWORK_PATH . 'models/notification.inc');
    $notification = new Notification( $this->registry );
	  $notification->setIDUser($subject->getUserTrigger());
    $notification->setUserIDFrom($subject->getUserFrom());
    $notification->setNotificationType($subject->getEvent());
    $notification->setShow($subject->isShowed());
    $notification->setTimestamp($subject->getTimestamp());
    $notification->setMessage($subject->getMessage());
    $notification->save();
	}
  
}

?>