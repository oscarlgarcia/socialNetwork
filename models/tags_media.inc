<?php

require_once ("Object.inc");
/**
 * Tags_Media model
 * - Agrega y gestiona los Tags_snippet
 */
class Tags_Media extends Object{
	
  private $id_tag;
  private $id_media;
  private $limit = 100;
  private $saveable_fields = array('id_tag','id_media');
		
  /**
  * Genera lista de tags paginados por media
  * @param int $id_media
  * @return Object pagination object
  */
  public function listTagsByMedia( $id_media )
  {
    $this->paginatedResult->setLimit($this->limit); //TODO poner no limit
    $this->paginatedResult->setOffset(0);
    $query = "SELECT t.ID as id , t.tag_name as tag_name FROM tags t inner join list_media_tags l on t.ID=l.ID_Tag and l.ID_media=".$id_media ;
    $this->paginatedResult->setQuery( $query );
    $this->paginatedResult->setMethod( 'cache' );
    $this->paginatedResult->generatePagination();
    return $this->paginatedResult;
  }
	
  /*
  * Metodo que almacena un tag_media en la bbdd
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
    $this->registry->getObject('db')->insertRecords( 'list_media_tags', $changes );
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
	
  public function setIDMedia($id){
    $this->id_media = $id;
  }
	
}
?>