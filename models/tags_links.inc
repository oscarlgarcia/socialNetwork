<?php

require_once ("Object.inc");
/**
 * Tags_links model
 * - Agrega y gestiona los Tags_snippet
 */
class Tags_Links extends Object{
	
  private $id_tags;
  private $id_links;
  private $limit = 100;
  private $saveable_fields = array('id_tags','id_links');
		
  /**
  * Genera lista de tags paginados por links
  * @param int $id_link
  * @return Object pagination object
  */
  public function listTagsByLink( $id_link )
  {
    require_once( FRAMEWORK_PATH . 'lib/pagination/pagination.class.inc');
    $this->paginatedResult = new Pagination( $this->registry );
    $this->paginatedResult->setLimit($this->limit); //TODO poner no limit
    $this->paginatedResult->setOffset(0);
    $query = "SELECT t.ID as id , t.tag_name as tag_name FROM tags t inner join list_tags_links l on t.ID=l.ID_tags and l.ID_links=".$id_link ;
    $this->paginatedResult->setQuery( $query );
    $this->paginatedResult->setMethod( 'cache' );
    $this->paginatedResult->generatePagination();
    return $this->paginatedResult;
	}
	
  /**
  * Genera lista de snippets 
  * @param int $id_snippet 
  * @return Object pagination object
  */	
  public function getRelatedSnippets($id_snippet)
  {
    $this->paginatedResult->setLimit(6); //TODO poner no limit
    $this->paginatedResult->setOffset(0);
    $query = "SELECT Concat(LEFT(s.title,50),'...') as related_title, s.title as full_title, A2.ID_Snippets as related_ID, md.url as related_image_category , count(A2.ID_Tag) AS matches FROM lista_tag_snippet A1 
      JOIN lista_tag_snippet A2 ON A1.ID_Tag=A2.ID_Tag inner join snippets s on A2.ID_Snippets = s.ID inner join category c on s.ID_Category = c.ID inner join media md on md.ID = c.image_category
      WHERE A1.ID_Snippets = ".$id_snippet." GROUP BY A2.ID_Snippets ORDER BY matches DESC";
    $this->paginatedResult->setQuery( $query );
    $this->paginatedResult->setMethod( 'cache' );
    $this->paginatedResult->generatePagination();
    return $this->paginatedResult;
  }
	
  /*
  * Metodo que almacena un tag_snippet en la bbdd
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
	$this->registry->getObject('db')->insertRecords( 'list_tags_links', $changes );
	$uid = $this->registry->getObject('db')->lastInsertID();
	return $uid;
  }	
	
  /*
  * Metodos setter
  *
  */
  public function setIDTag($id){
    $this->id_tags= $id;
  }

  public function setIDLinks($id){
    $this->id_links= $id;
  }
	
}
?>