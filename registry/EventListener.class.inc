<?php
require_once( 'AbstractSubject.class.inc' );
/*
 * Clase para escuchar los eventos y 
 * propagarlos a los observadores
 * autor : Oscar Garcia
 */
class EventListener extends AbstractSubject{
  
  
  // Registro de Array de post-event
  private $observers = array();
  
  private $event;
  private $userTrigger;
  private $ip;
  private $data;
  private $userFrom;
  private $message;
  private $timestamp;
  private $showed;
  
  /*
   * Constructor
   */
  public function __construct( Registry $registry ) 
  {
    $this->registry = $registry;
    require_once( 'Logger.class.inc' );
    require_once( 'Gamification.class.inc' );
    require_once( 'Notify.class.inc' );
    $this->attach(new Logger($registry));
    $this->attach(new Gamification($registry));
    $this->attach(new Notify($registry));
  }

  /*
   * Metodo para agregar un observer a nuestro array
   */
  public function attach(AbstractObserver $observer_in) 
  {
    $this->observers[] = $observer_in;
  }
  
  /*
   * Metodo para desagregar un observer del array
   */
  public function detach(AbstractObserver $observer_in) 
  {
    foreach($this->observers as $key => $val) 
    {
  	  if ($val == $observer_in) 
  	  {
  	    unset($this->observers[$key]);
  	  }
  	}
  }
  
  /*
   * Propagamos el evento
   */
  public function notify($event,$userID,$ip='',$data='',$from = '',$message = '', $timestamp = '', $showed = 0 ) 
  {
  	$this->event = $event;
  	$this->userTrigger = $userID;
  	$this->ip = $ip;
  	$this->data = $data;
    $this->userFrom = $from;
    $this->message = $message;
    $this->timestamp = $timestamp;
    $this->showed = $showed;

  	foreach($this->observers as $obs) 
  	{
  		$obs->update($this);
  	}
  }

  public function getEvent(){
    return 	$this->event;
  	
  }
  
  public function getUserTrigger(){
    return 	$this->userTrigger;
  	
  }

  public function getIPAddress(){
    return 	$this->ip;
  	
  }
    public function getEventData(){
    return 	$this->data;
  	
  }

  public function getUserFrom(){
    return  $this->userFrom;
    
  }
  
  public function getMessage(){
    return  $this->message;  
  }

  public function getTimestamp(){
    return  $this->timestamp;  
  }

  public function isShowed(){
    return  $this->showed;  
  }

}

?>