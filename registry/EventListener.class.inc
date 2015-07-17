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
  
  /*
   * Constructor
   */
  public function __construct( Registry $registry ) 
  {
    $this->registry = $registry;
    require_once( 'Logger.class.inc' );
    require_once( 'Gamification.class.inc' );
    $this->attach(new Logger($registry));
    $this->attach(new Gamification($registry));
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
  public function notify($event,$userID,$ip='',$data='') 
  {
  	$this->event=$event;
  	$this->userTrigger=$userID;
  	$this->ip=$ip;
  	$this->data=$data;
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
}

?>