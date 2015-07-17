<?php

require_once ("Object.inc");
/**
 * LoggerPage model
 * - Agrega y gestiona las peticiones al site
 * Esta clase sera la encargada de registrar todas las peticiones al site
 */
class LoggerPage extends Object
{
	
  private $ID;
  private $ipAddress;
  private $date;
  private $route;
  private $session;
  private $browser;
  private $saveable_fields = array( 'ipAddress', 'date','route','session','browser'); 
  private $limit = 500; //poner en config
  

  public function __construct( Registry $registry , $ipAddress ='NO_IP_AVAILABLE', $route = 'REDIRECT',$date , $session = 'NOSESSION', $browser = 'NOBROWSER')
  {
    parent::__construct($registry);
    $this->ipAddress = $ipAddress;
    $this->route = $route;
    $this->date = $date;
    $this->session = $session;
    $this->browser = $browser;
  }


  /*
  * Metodo que guarda la route en BBDD
  */
  public function save()
  {
    $changes = array();
	  foreach( $this->saveable_fields as $field )
    {
      $changes[ $field ] = $this->$field;
    }
    $this->registry->getObject('db')->insertRecords( 'logger', $changes );
    $uid = $this->registry->getObject('db')->lastInsertID();
    return $uid;  
  }	


  /**
  * Obtiene una Log a partir de su ID
  * @param int $loggerID 
  * @return Object 
  */
  public function getLogger($loggerID)
  {
    $query = "SELECT ID, ipAddress , route , date , session  FROM logger where c.ID = ".$loggerID ;
	  $this->registry->getObject('db')->executeQuery( $query );
    if( $this->registry->getObject('db')->numRows() > 0 )
    {
      $data = $this->registry->getObject('db')->getRows();
      $this->setID($data['ID']);
      return true;
    }
    return false;
  }

  // Setter and Getters
  public function setID($id){ 
    $this->ID = $id; 
  }
  
  public function getID(){
    return $this->ID;
  }

  public function setIPAddress($ipAddress){ 
    $this->ipAddress = $ipAddress; 
  }
  
  public function getIPAddress(){
  	return $this->ipAddress;
  }

  public function setRoute($route){ 
  	$this->route = $route; 
  }
  
  public function getRoute(){
 	return $this->route;
  }

  public function setDate($date){ 
  	$this->date = $date; 
  }
  
  public function getDate(){
  	return $this->date;
  }

  public function setSession($session){ 
    $this->session = $session; 
  }
  
  public function getSession(){
    return $this->session;
  }

  public function setBrowserData($browser){ 
    $this->browser = $browser; 
  }
  
  public function getBrowserData(){
    return $this->browser;
  }

}
?>