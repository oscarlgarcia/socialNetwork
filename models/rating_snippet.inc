<?php

require_once ("Object.inc");
/**
 * Comment_Snippet model
 * - Agrega y gestiona los comentarios para los snippets
 */
class Rating_Snippet extends Object{
	
  private $voto;
  private $id_user;
  private $id_snippet;
  private $saveable_fields = array( 'voto','id_user','id_snippet');
	
  /*
  * Metodo que determina si un usuario ha rankeado un snippet
  * $snippetID, Id del Snippet
  * $userID, ID del usuario
  * @return boolean, True si lo ha rankeado, False si no
  */
  public function isRatedByUser($snippetID,$userID)
  {
    $query = "SELECT * FROM rating_snippet where ID_User=".$userID." and ID_Snippet=".$snippetID ;
	$this->paginatedResult->setQuery( $query );
	$this->paginatedResult->setMethod( 'cache' );
	$this->paginatedResult->generatePagination();
	if ($this->paginatedResult->getTotalRows()>0)
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
	$this->registry->getObject('db')->insertRecords( 'rating_snippet', $changes );
	$uid = $this->registry->getObject('db')->lastInsertID();
	return $uid;
  }	
	
  /*
  * Metodos setter
  *
  */
  public function setVoto($voto){
    $this->voto= $voto;
  }
	
  public function setIDUser($id_user){
    $this->id_user= $id_user;
  }
	
  public function setIDSnippet($id_snippet){
    $this->id_snippet= $id_snippet;
  }
		
}
?>