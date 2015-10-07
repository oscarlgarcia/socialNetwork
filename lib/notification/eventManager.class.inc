<?php

/**
 * Clase EventManager 
 * Gestiona los eventos a notificarse en el site
 */
class EventManager {

  private $registry;
  /**
  * Constructor
  * @param Object registry
  * @return void
  */
  function __construct( Registry $registry) 
  {
    $this->registry = $registry;
  }


  function feed(){

    header("Content-Type: text/event-stream");
    header("Cache-Control: no-cache");
    header("Access-Control-Allow-Origin: *");
    
  }


}

?>