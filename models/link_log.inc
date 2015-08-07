<?php

require_once ("Object.inc");

/**
 * Link_Log model
 * - Agrega y gestiona los eventos para los Links
 */
class Link_Log extends Object{
	
  private $ID;
  private $ID_User;
  private $ID_Link;
  private $event;
  private $created;
  private $limit = 100;
  private $saveable_fields = array( 'ID_User', 'ID_Link','event','created');
	
  /*
  * Constructor explicito para este objeto
  */
  public function __construct( Registry $registry,$ID_User=0,$ID_Link=0,$event='')
  {
    parent::__construct($registry);
	  $this->ID_User = $ID_User;
	  $this->ID_Link = $ID_Link;
	  $this->event = $event;
	  $this->created = date("Y-m-d H:i:s");
  }


  public function save()
  {
    $changes = array();
	  foreach( $this->saveable_fields as $field )
	    $changes[ $field ] = $this->$field;

	  $this->registry->getObject('db')->insertRecords( 'link_log', $changes );
  }

  /**
  * Metodo que retorna el Historial del Link
  * Se llama en Admin_Links
  * Retorna un objeto pagination con los elementos:
  * - ID
  * - Evento
  * - Fecha de creacion
  * - Titulo
  * - Usuario que lo creo
  * - imagen que corresponde al tipo de evento
  * @param idSnippet
  * @return paginatedResult
  */

  public function getHistory($idLink = 1) 
  {
    $this->paginatedResult->setLimit(1000);
    $this->paginatedResult->setOffset(0);
    $query="SELECT a.id, a.event, DATE_FORMAT(a.created,'%d %b %Y %T') as created, b.Title, c.user_login, d.imageEvent 
    FROM link_log a INNER JOIN links b ON a.ID_Link = b.ID 
    INNER JOIN users c ON a.ID_User = c.ID  INNER JOIN event d ON a.event = d.eventName 
    WHERE `ID_Link` =".$idLink. "  ORDER BY created  ";
    $this->paginatedResult->setQuery( $query );
    $this->paginatedResult->setMethod( 'cache' );
    $this->paginatedResult->generatePagination();
    return $this->paginatedResult;
  }
	
}
?>