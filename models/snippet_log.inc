<?php

require_once ("Object.inc");

/**
 * Snippet_Log model
 * - Agrega y gestiona los eventos para snippets
 */
class Snippet_Log extends Object{
	
  private $ID;
  private $ID_User;
  private $ID_Snippet;
  private $event;
  private $created;
  private $limit = 100;
  private $saveable_fields = array( 'ID_User', 'ID_Snippet','event','created');
	
  /*
  * Constructor explicito para este objeto
  */
  public function __construct( Registry $registry,$ID_User=0,$ID_Snippet=0,$event='')
  {
    parent::__construct($registry);
	  $this->ID_User = $ID_User;
	  $this->ID_Snippet = $ID_Snippet;
	  $this->event = $event;
	  $this->created = date("Y-m-d H:i:s");
  }


  public function save()
  {
    $changes = array();
	foreach( $this->saveable_fields as $field )
	{
	  $changes[ $field ] = $this->$field;
	}
	$this->registry->getObject('db')->insertRecords( 'snippet_log', $changes );
  }

  public function listSnippets( $offset=1 )
  {
    $this->paginatedResult->setLimit($this->limit);
	$this->paginatedResult->setOffset( $offset-1);
	//TODO poner el link a busqueda por  tags
	$query="SELECT tbl.*, GROUP_CONCAT(DISTINCT tag_name SEPARATOR '') 
		As all_tags FROM( SELECT s.ID,s.title, s.code ,s.description, DATE_FORMAT( s.added,'%b %d %Y') as fecha , s.added as rawDate,
		s.rating,s.totalFav as faved,s.totalComments as comments, c.name as category,c.image_category as image_category, u.user_login as author, u.profile_image , CONCAT('<a href=\"snippets/tag/',t.tag_name,'\" class=\"label label-info\">',t.tag_name,'</a> ') as tag_name 
		FROM snippets s inner join category c on s.ID_category=c.ID inner join users u on s.ID_USER=u.ID inner join lista_tag_snippet l on s.ID=l.ID_Snippets 
		inner join tags t on l.ID_Tag=t.ID ) tbl GROUP BY tbl.id order by rawDate desc";
	$this->paginatedResult->setQuery( $query );
	$this->paginatedResult->setMethod( 'cache' );
	$this->paginatedResult->generatePagination();
	return $this->paginatedResult;
  }

  public function getHistory($idSnippet= 1) 
  {
    $this->paginatedResult->setLimit(1000);
    $this->paginatedResult->setOffset(0);
    $query="SELECT a.id, a.event, a.created, b.Title, c.user_login, d.imageEvent 
    FROM snippet_log a INNER JOIN snippets b ON a.ID_Snippet = b.ID 
    INNER JOIN users c ON a.ID_User = c.ID  INNER JOIN event d ON a.event = d.eventName 
    WHERE `ID_Snippet` =".$idSnippet. "  ORDER BY created  ";
    $this->paginatedResult->setQuery( $query );
    $this->paginatedResult->setMethod( 'cache' );
    $this->paginatedResult->generatePagination();
    return $this->paginatedResult;
  }
	
}
?>