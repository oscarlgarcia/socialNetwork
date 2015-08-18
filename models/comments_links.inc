<?php

require_once ("Object.inc");
/**
 * Comments_Links model
 * - Agrega y gestiona los comentarios para los links
 */
class Comments_Links extends Object{
	
	private $comment;
	private $id_user;
	private $id_link;
	private $added;
	private $limit = 10; 	
	private $saveable_fields = array( 'comment','id_user','id_link','added');
		
	/**
	 * Genera lista de comentarios de links paginados
	 * Se llama en Links
	 * Devuelve un ojeto 
	 * Comentario
	 * Fecha
	 * User
	 * imagen de user
	 * @param int $linkID 
	 * @return Object pagination object
	 */
	public function getCommentsByLink( $linkID )
	{
		
		$this->paginatedResult->setLimit($this->limit); //TODO poner no limit
		$this->paginatedResult->setOffset(0);
		$query = "SELECT c.comment as comment, DATE_FORMAT( c.added,'%d de %b %Y') as fecha, u.user_login as user , u.profile_image as image
		          FROM comments_links c inner join links s on c.id_link=s.ID inner 
				  join users u on c.ID_User=u.ID WHERE c.approved = 4 and s.ID=". $linkID ." ORDER BY c.added ASC" ;
		$this->paginatedResult->setQuery( $query );
		$this->paginatedResult->setMethod( 'cache' );
		$this->paginatedResult->generatePagination();
		$this->getComments($this->paginatedResult);
	}
		

    /**
	 * Genera lista de comentarios de links pendientes de aprobar
	 * Este metodo se llama en admin_comments_link
	 * Devuelve un ojeto 
	 * ID
	 * Comentario
	 * fecha
	 * usuario
	 * css
	 * ID de link al que pertenece
	 * Titulo del link al que pertenece
	 * @param int $offset, el offset de la busqueda.
	 * @param String $criteria, la cadena de busqueda
	 * @return Object pagination object
	 */
	public function search( $offset = 1 , $criteria )
	{
      $this->paginatedResult->setLimit( $this->limit);
      $this->paginatedResult->setOffset($offset  - 1 );
      $query = "SELECT c.ID, c.comment as comment, DATE_FORMAT( c.added,'%d de %b %Y') as dateAdded, u.user_login as user, u.id as user_id, c.approved, op.status_class as class , l.id as snippet_id, l.title as title FROM comments_links c inner join links l on c.ID_Link = l.ID inner join users u on c.ID_User = u.ID inner join operational_status op on op.ID = c.approved WHERE c.comment like '%". $criteria ."%' ORDER BY c.added ASC";
      $this->paginatedResult->setQuery( $query );
      $this->paginatedResult->setMethod( 'cache' );
      $this->paginatedResult->generatePagination();
      return $this->paginatedResult;
	}



/**
   * Genera lista de comentarios de Link que coinciden con el usuario pasado paginados 
   * Este metodo se llama en admin_comments_link desde el administrador
   * Devuelve un ResulSet con la siguiente informacion en caché:
   * ID
   * Comentario
   * fecha
   * usuario
   * css
   * ID de snippet al que pertenece
   * Titulo del snippet al que pertenece
   * @param int $offset
   * @param string username, Usuario 
   * @return Object pagination object
   */
  public function searchByUser($offset = 1, $username)
  {
    $this->paginatedResult->setLimit($this->limit);
    $this->paginatedResult->setOffset($offset - 1);
    $query = "SELECT c.ID, c.comment as comment, DATE_FORMAT( c.added,'%d de %b %Y') as dateAdded, u.user_login as user, u.id as user_id, c.approved, op.status_class as class , s.id as snippet_id, s.title as title FROM comments_links c inner join links s on c.ID_Link = s.ID inner join users u on c.ID_User = u.ID inner join operational_status op on op.ID = c.approved WHERE u.user_login = '".$username."' ORDER BY c.added ASC";
    $this->paginatedResult->setQuery( $query );
    $this->paginatedResult->setMethod( 'cache' );
    $this->paginatedResult->generatePagination();
    return $this->paginatedResult;
  }
	

	/**
   * Genera lista de comentarios de link que coinciden con el snippet pasado paginados 
   * Este metodo se llama en admin_comments_link desde el administrador
   * Devuelve un ResulSet con la siguiente informacion en caché:
   * ID
   * Comentario
   * fecha
   * usuario
   * css
   * ID de snippet al que pertenece
   * Titulo del snippet al que pertenece
   * @param int $offset
   * @param string linkID, link 
   * @return Object pagination object
   */
  public function searchByLink($linkID)
  {
    $this->paginatedResult->setLimit(1000000);
    $this->paginatedResult->setOffset(0);
    $query = "SELECT c.ID, c.comment as comment, DATE_FORMAT( c.added,'%d de %b %Y') as dateAdded, u.user_login as user, u.id as user_id, c.approved, op.status_class as class , s.id as snippet_id, s.title as title FROM comments_links c inner join links s on c.ID_Link = s.ID inner join users u on c.ID_User = u.ID inner join operational_status op on op.ID = c.approved WHERE s.ID = '".$linkID."' ORDER BY c.added ASC";
    $this->paginatedResult->setQuery( $query );
    $this->paginatedResult->setMethod( 'cache' );
    $this->paginatedResult->generatePagination();
    return $this->paginatedResult;
  }
	

   /**
    * borra un comentario a partir de su ID
    * @param int $commentID 
    */
  public function delete($commentID)
  {
    $this->registry->getObject('db')->deleteRecords( 'comments_links',' id = '.$commentID,'1');
	$uid = $this->registry->getObject('db')->lastInsertID();
	return $uid;  
  }

  /**
  * actualiza el estatus del comentario a partir de su ID
  * @param int $commentID 
  */
  public function updateStatus($commentID, $status)
  {
  	$changes = array();
  	$changes['approved'] = $status;
    $this->registry->getObject('db')->updateRecords('comments_links', $changes," id = ".$commentID );
    $uid = $this->registry->getObject('db')->lastInsertID();
    return $uid;  
  }



	/*
	* Metodo que almacena un comentario de link en la bbdd
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
	  $this->registry->getObject('db')->insertRecords( 'comments_links', $changes );
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
	
	public function setIDLink($id_link){
	  $this->id_link= $id_link;
	}
	
	public function setAdded($added){
	  $this->added= $added;
	}
	
	
	/*
	* Metodo para mostrar los comentarios 
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