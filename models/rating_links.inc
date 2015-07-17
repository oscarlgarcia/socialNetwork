<?php

require_once ("Object.inc");
/**
 *  rating_links model
 * - Agrega y gestiona los rating para los links
 */
class Rating_Links extends Object{
	
  private $vote;
  private $id_users;
  private $id_links;
  private $saveable_fields = array( 'vote','id_users','id_links');


  /*
  *  Metodo que determina si el link ha sido rankeado por el usuario
  *  $linkID, El Id del link
  *  $userID, El ID del Usuario
  *  @return boolean, True si ha sido rankeado, False si no. 
  */	
  public function isRatedByUser($linkID,$userID)
  {
    require_once( FRAMEWORK_PATH . 'lib/pagination/pagination.class.inc');
	$paginate = new Pagination( $this->registry );
	$query = "SELECT * FROM rating_links where ID_Users=".$userID." and ID_links=".$linkID ;
	$paginate->setQuery( $query );
	$paginate->setMethod( 'cache' );
	$paginate->generatePagination();
	if ($paginate->getTotalRows()>0)
	{  
	  return true;
	}
	return false;
  }
	
  /*
  * Metodo que almacena un comentario en la bbdd
  * @return ID del comentario.
  *
  */
  public function save()
  {
    $changes = array();
	foreach( $this->saveable_fields as $field )
	{
	  $changes[ $field ] = $this->$field;
	}
	$this->registry->getObject('db')->insertRecords( 'rating_links', $changes );
	$uid = $this->registry->getObject('db')->lastInsertID();
	return $uid;
  }	
	
  /*
  * Metodos setter
  *
  */
  public function setVoto($vote){
    $this->vote= $vote;
  }
	
  public function setIDUser($id_users){
    $this->id_users= $id_users;
  }
	
  public function setIDLink($id_links){
    $this->id_links= $id_links;
  }
		
}
?>