<?php

require_once ("Object.inc");
/**
 * Tags_snippet model
 * - Agrega y gestiona los Tags_snippet
 */
class Tags_Page extends Object{
	
  private $id_tag;
  private $id_page;
  private $limit = 100;
  private $saveable_fields = array('id_tag','id_page');

  /**
  * Genera lista de tags paginados por Page
  * @param int $id_page 
  * @return Object pagination object
  */
  public function listTagsByPage( $id_page )
  {
    $this->paginatedResult->setLimit($this->limit); //TODO poner no limit
    $this->paginatedResult->setOffset(0);
    $query = "SELECT t.ID as id , t.tag_name as tag_name FROM tags t inner join list_tag_page l on t.ID=l.ID_Tag and l.ID_Page =".$id_page ;
    $this->paginatedResult->setQuery( $query );
    $this->paginatedResult->setMethod( 'cache' );
    $this->paginatedResult->generatePagination();
    return $this->paginatedResult;
  }
	
  /**
  * Genera lista de Page 
  * @param int $id_page 
  * @return Object pagination object
  */	
  public function getRelatedPage($id_page)
  {
    $this->paginatedResult->setLimit(6); //TODO poner no limit
    $this->paginatedResult->setOffset(0);
    $query = "SELECT Concat(LEFT(s.title,50),'...') as related_title, s.title as full_title, s.url as related_url, count(A2.ID_Tag) AS matches, md.url as related_image  FROM list_tag_page A1 JOIN list_tag_page A2 ON A1.ID_Tag=A2.ID_Tag inner join Page s on A2.ID_Page =  s.ID inner join category c on s.category = c.ID inner join media md on md.ID = c.image_category WHERE A1.ID_Page = ".$id_page." GROUP BY A2.ID_Page ORDER BY matches DESC";
    $this->paginatedResult->setQuery( $query );
    $this->paginatedResult->setMethod( 'cache' );
    $this->paginatedResult->generatePagination();
    return $this->paginatedResult;
  }
	
  /*
  * Metodo que almacena un tag_page en la bbdd
  * @return ID del tag.
  *
  */
  public function save()
  {
    $changes = array();
	foreach( $this->saveable_fields as $field )
	{
	  $changes[ $field ] = $this->$field;
	}
	
    //lo guardamos
	$this->registry->getObject('db')->insertRecords( 'list_tag_page', $changes );
	$uid = $this->registry->getObject('db')->lastInsertID();
	return $uid;
  }	
	
  /*
  * Metodos setter
  *
  */
  public function setIDTag($id){
    $this->id_tag= $id;
  }
	
  public function setIDPage($id){
    $this->id_page = $id;
  }

}
?>