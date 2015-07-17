<?php

require_once ("Object.inc");
/**
 * Comment_Snippet model
 * - Agrega y gestiona los comentarios para los snippets
 */
class Comment_Snippet extends Object{
	
	private $comment;
	private $id_user;
	private $id_snippet;
	private $added;
	private $limit = 1000;
	
	private $saveable_fields = array( 'comment','id_user','id_snippet','added');
		
	/**
	 * Genera lista de comentarios del snippet paginados 
	 * @param int $snippetID 
	 * @return Object pagination object
	 */
	public function getCommentsBySnippet( $snippetID )
	{
      $this->paginatedResult->setLimit($this->limit); //TODO poner no limit
      $this->paginatedResult->setOffset(0);
      $query = "SELECT c.comment as comment, DATE_FORMAT( c.added,'%d de %b %Y') as fecha, u.user_login as user , u.profile_image as image
		          FROM comment_snippet c inner join snippets s on c.ID_Snippet=s.ID inner 
				  join users u on c.ID_User=u.ID WHERE s.ID=". $snippetID ." ORDER BY c.added ASC" ;
      $this->paginatedResult->setQuery( $query );
      $this->paginatedResult->setMethod( 'cache' );
      $this->paginatedResult->generatePagination();
      $this->getComments($this->paginatedResult);
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
	  $this->registry->getObject('db')->insertRecords( 'comment_snippet', $changes );
	  $uid = $this->registry->getObject('db')->lastInsertID();
	  return $uid;
	}	
	
	/*
	* Metodos setter
	*
	*/
    public function setComment($comment){
	  $this->comment= $comment;
	}
	
	public function setIDUser($id_user){
	  $this->id_user= $id_user;
	}
	
	public function setIDSnippet($id_snippet){
	  $this->id_snippet= $id_snippet;
	}
	
	public function setAdded($added){
	  $this->added= $added;
	}
	
	
	/*
	* Metodo para mostrar los comentarios del snippet
	*
	*/
	public function getComments($result){
	
	if ($result->getTotalRows()!=0){
	  while ($value = $this->registry->getObject('db')->resultsFromCache($result->getCache()))
	    {
	      echo "<ul class=\"list-group\"><li class=\"list-group-item\">
		        <div class=\"row\"><div class=\"col-xs-2 col-md-1\">
				<img src=\"".$this->registry->getSetting('avatar_path').$value["image"]."\" style=\"width:80px; height:80px;\" class=\"img-circle img-responsive\" /></div>
				<div class=\"col-xs-10 col-md-11\"><div><div class=\"comment-info\"><span class=\"fa fa-comment\"></span> <label>".$value["user"]."</label> el ".$value["fecha"]."</div></div>
				<div class=\"comment-text\">".$value["comment"]."</div></div></div></li></ul>";  
	    }
	}else{
	 echo "<ul class=\"list-group\"><li class=\"list-group-item\"><span class=\"fa fa-comment\"></span> Se el primero en Comentar!</li></ul>";
	}
	 
	}

	
}
?>