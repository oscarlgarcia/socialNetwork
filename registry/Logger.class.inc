<?php
require_once( 'AbstractObserver.class.inc' );
/*
 * Clase para registrar los eventos que se
 * desean almacenar de historico
 * autor : Oscar Garcia 
 */

class Logger extends AbstractObserver{
	
  /**
   * Constructor
   */
  public function __construct( Registry $registry ) 
  {
	   $this->registry = $registry;
  }

  /*
  * Metodo que actualiza el registro de eventos
  */
  public function update(AbstractSubject $subject) 
  {
    require_once( FRAMEWORK_PATH . 'models/user_event.inc');
	  $user_event = new User_Event( $this->registry );
	  $user_event->save($subject->getUserTrigger(),$subject->getEvent(),$subject->getIPAddress(),$subject->getEventData());
  }
	
}

?>