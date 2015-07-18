<?php

require_once ("Object.inc");

/**
 * Snippets model
 * - Agrega y gestiona los snippets
 */
class Snippets extends Object{
	
  private $ID;
  private $title;
  private $description;
  private $code;
  private $ID_category;
  private $ID_User;
  private $rating;
  private $totalVotes;
  private $added;
  private $limit = 5; //TODO poner en configs
  private $saveable_fields = array( 'title', 'description', 'code', 'ID_category', 'ID_User','rating','totalVotes','added');
	
  /**
   * Genera lista de snippets paginados
   * @param int $offset 
   * @return Object pagination object
   */
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
	
  /**
   * Genera lista de snippets populares paginados
   * @param int $offset 
   * @return Object pagination object
   */
  public function listPopularSnippets( $offset=1 )
  {
    $this->paginatedResult->setLimit($this->limit);
	$this->paginatedResult->setOffset( $offset-1 );
	$query="SELECT tbl.*, GROUP_CONCAT(DISTINCT tag_name SEPARATOR '') 
		As all_tags FROM( SELECT s.ID,s.title, s.code ,s.description, DATE_FORMAT( s.added,'%b %d %Y') as fecha , 
		s.rating as rating,s.totalFav as faved,s.totalComments as comments, c.name as category, c.image_category as image_category, u.user_login as author,u.profile_image , CONCAT('<a href=\"snippets/tag/',t.tag_name,'\" class=\"label label-info\">',t.tag_name,'</a> ') as tag_name 
		FROM snippets s inner join category c on s.ID_category=c.ID inner join users u on s.ID_USER=u.ID inner join lista_tag_snippet l on s.ID=l.ID_Snippets 
		inner join tags t on l.ID_Tag=t.ID ) tbl GROUP BY tbl.id order by rating desc ";
	$this->paginatedResult->setQuery( $query );
	$this->paginatedResult->setMethod( 'cache' );
	$this->paginatedResult->generatePagination();
	return $this->paginatedResult;
  }
	
  /**
  * Genera lista de snippets favoritos paginados
  * @param int $offset 
  * @return Object pagination object
  */
  public function listFavorites( $offset=1 )
  {
	$this->paginatedResult->setLimit($this->limit);
	$this->paginatedResult->setOffset( $offset-1 );
	$query="SELECT tbl.*, GROUP_CONCAT(DISTINCT tag_name SEPARATOR '') 
		As all_tags FROM( SELECT s.ID,s.title, s.code ,s.description, DATE_FORMAT( s.added,'%b %d %Y') as fecha , 
		s.rating as rating,s.totalFav as faved,s.totalComments as comments, c.name as category, c.image_category as image_category, u.user_login as author,u.profile_image , CONCAT('<a href=\"snippets/tag/',t.tag_name,'\" class=\"label label-info\">',t.tag_name,'</a> ') as tag_name 
		FROM snippets s inner join category c on s.ID_category=c.ID inner join users u on s.ID_USER=u.ID inner join lista_tag_snippet l on s.ID=l.ID_Snippets 
		inner join tags t on l.ID_Tag=t.ID ) tbl GROUP BY tbl.id order by faved desc ";
	$this->paginatedResult->setQuery( $query );
	$this->paginatedResult->setMethod( 'cache' );
	$this->paginatedResult->generatePagination();
	return $this->paginatedResult;
  }
	
	
  /**
  * Genera lista de snippets mas comentados paginados
  * @param int $offset 
  * @return Object pagination object
  */
  public function listCommentedSnippets( $offset=1 )
  {
	$this->paginatedResult->setLimit($this->limit);
	$this->paginatedResult->setOffset( $offset-1);
	//TODO poner el link a busqueda por  tags
	$query="SELECT tbl.*, GROUP_CONCAT(DISTINCT tag_name SEPARATOR '') 
		As all_tags FROM( SELECT s.ID,s.title, s.code ,s.description, DATE_FORMAT( s.added,'%b %d %Y') as fecha , s.added as rawDate,
		s.rating,s.totalFav as faved,s.totalComments as comments, c.name as category,c.image_category as image_category, u.user_login as author,u.profile_image , CONCAT('<a href=\"snippets/tag/',t.tag_name,'\" class=\"label label-info\">',t.tag_name,'</a> ') as tag_name 
		FROM snippets s inner join category c on s.ID_category=c.ID inner join users u on s.ID_USER=u.ID inner join lista_tag_snippet l on s.ID=l.ID_Snippets 
		inner join tags t on l.ID_Tag=t.ID ) tbl GROUP BY tbl.id order by comments DESC";
	$this->paginatedResult->setQuery( $query );
	$this->paginatedResult->setMethod( 'cache' );
	$this->paginatedResult->generatePagination();
	return $this->paginatedResult;
  }
	
  /**
  * Genera lista de snippets por categoria paginados
  * @param string categoria, int $offset 
  * @return Object pagination object
  */
  public function listByCategory( $category,$offset=1 )
  {
	$this->paginatedResult->setLimit($this->limit);
	$this->paginatedResult->setOffset( $offset-1 );
	$query="SELECT tbl.*, GROUP_CONCAT(DISTINCT tag_name SEPARATOR '') 
		As all_tags FROM( SELECT s.ID,s.title, s.code ,s.description, DATE_FORMAT( s.added,'%b %d %Y') as fecha , 
		s.rating as rating,s.totalFav as faved,s.totalComments as comments, c.name as category, c.image_category as image_category, u.user_login as author,u.profile_image , CONCAT('<a href=\"snippets/tag/',t.tag_name,'\" class=\"label label-info\">',t.tag_name,'</a> ') as tag_name 
		FROM snippets s inner join category c on s.ID_category=c.ID inner join users u on s.ID_USER=u.ID inner join lista_tag_snippet l on s.ID=l.ID_Snippets 
		inner join tags t on l.ID_Tag=t.ID where c.name='".$category."' ) tbl GROUP BY tbl.id ";
	$this->paginatedResult->setQuery( $query );
	$this->paginatedResult->setMethod( 'cache' );
	$this->paginatedResult->generatePagination();
	return $this->paginatedResult;
  }
	
  /**
  * Genera lista de snippets por usuario paginados
  * @param string username, int $offset 
  * @return Object pagination object
  */
  public function listByUsername( $username,$offset=1 )
  {
	$this->paginatedResult->setLimit($this->limit);
	$this->paginatedResult->setOffset( $offset-1 );
	$query="SELECT tbl.*, GROUP_CONCAT(DISTINCT tag_name SEPARATOR '') 
		As all_tags FROM( SELECT s.ID,s.title, s.code ,s.description, DATE_FORMAT( s.added,'%b %d %Y') as fecha , 
		s.rating as rating,s.totalFav as faved,s.totalComments as comments, c.name as category, c.image_category as image_category, u.user_login as author,u.profile_image , CONCAT('<a href=\"snippets/tag/',t.tag_name,'\" class=\"label label-info\">',t.tag_name,'</a> ') as tag_name 
		FROM snippets s inner join category c on s.ID_category=c.ID inner join users u on s.ID_USER=u.ID inner join lista_tag_snippet l on s.ID=l.ID_Snippets 
		inner join tags t on l.ID_Tag=t.ID where u.user_login='".$username."' ) tbl GROUP BY tbl.id ";
    $this->paginatedResult->setQuery( $query );
	$this->paginatedResult->setMethod( 'cache' );
	$this->paginatedResult->generatePagination();
	return $this->paginatedResult;
  }
	
  /**
  * Genera lista de snippets por tag paginados
  * @param string tag, int $offset 
  * @return Object pagination object
  */
  public function listByTag( $tag,$offset=1 )
  {
 	$this->paginatedResult->setLimit($this->limit);
	$this->paginatedResult->setOffset( $offset -1);
	$query="SELECT tbl.*, GROUP_CONCAT(DISTINCT tag_name SEPARATOR '') 
		As all_tags FROM( SELECT s.ID,s.title, s.code ,s.description, DATE_FORMAT( s.added,'%b %d %Y') as fecha , 
		s.rating as rating,s.totalFav as faved,s.totalComments as comments, c.name as category, c.image_category as image_category, u.user_login as author,u.profile_image , CONCAT('<a href=\"snippets/tag/',t.tag_name,'\" class=\"label label-info\">',t.tag_name,'</a> ') as tag_name 
		FROM snippets s inner join category c on s.ID_category=c.ID inner join users u on s.ID_USER=u.ID inner join lista_tag_snippet l on s.ID=l.ID_Snippets 
		inner join tags t on l.ID_Tag=t.ID where t.tag_name='".$tag."' ) tbl GROUP BY tbl.id ";
	$this->paginatedResult->setQuery( $query );
	$this->paginatedResult->setMethod( 'cache' );
	$this->paginatedResult->generatePagination();
	return $this->paginatedResult;
  }
	
  /**
  * Genera lista de snippets paginados
  * @param int $criterio 
  * @return Object pagination object
  */
  public function search($criteria )
  {
    $this->paginatedResult->setLimit(100);
	$this->paginatedResult->setOffset(0);
	$query="SELECT ID, title, DATE_FORMAT( added,'%b %d %Y') as fecha FROM snippets  where (title like '%".$criteria."%' ) order by fecha desc";
	$this->paginatedResult->setQuery( $query );
	$this->paginatedResult->setMethod( 'cache' );
	$this->paginatedResult->generatePagination();
	return $this->paginatedResult;
  }
	
	/**
	 * Genera lista de usuarios que mas han creado snippets
	 * @return  ResultSet, un resultSet de los contribuidores
	 */
	public function topSnippetsContributors()
	{
	  $this->paginatedResult->setLimit(35);
	  $this->paginatedResult->setOffset(0);
	  $query = "SELECT  count(b.id) as total , b.user_login, b.profile_image FROM snippets a inner join users b on a.ID_User = b.ID group by b.user_login order by total DESC";
	  $this->paginatedResult->setQuery( $query );
	  $this->paginatedResult->setMethod( 'cache' );
	  $this->paginatedResult->generatePagination();
	  return $this->paginatedResult;
	}

    /**
	* Obtiene un snippet a partir de su ID
	* @param int $snippetID 
	* @return Object 
	*/
	public function getSnippet($snippetId)
	{
	  $query = "SELECT s.ID_User, s.ID,s.title, s.code ,s.description, s.added, s.rating, c.name as category FROM snippets s inner join category c on s.ID_category=c.ID where s.ID=".$snippetId ;
	  $this->registry->getObject('db')->executeQuery( $query );
	  if( $this->registry->getObject('db')->numRows() > 0 )
	  {
	    $data = $this->registry->getObject('db')->getRows();
		$tempo['ID']=$data['ID'];
		$tempo['ID_User']=$data['ID_User'];
		$tempo['title']=$data['title'];
		$tempo['code']= utf8_decode($data['code']);
		$tempo['description']=$data['description'];
		$tempo['added']=$data['added'];
		$tempo['rating']=$data['rating'];
		$tempo['category']=$data['category'];	  
		return $tempo;
	  }
	  return null;
	}
	
  /**
  * borra un snippet a partir de su ID
  * @param int $snippetID 
  */
  public function delete($id)
  {
    $this->registry->getObject('db')->deleteRecords( 'snippets',' id = '.$id,'1');
	$uid = $this->registry->getObject('db')->lastInsertID();
	return $uid;  
  }
	
  /*
  * Metodo que detemina si el usuario ha marcado como favorito el snippet
  * @param int, $snippetID ID del snippet
  * @param int, $userID ID del usuario
  * @return boolean, True si ha marcado como favorito, False si no
  */
  public function isFavorited($snippetID,$userID)
  {
    $query = "SELECT ID, ID_Snippets, ID_User FROM lista_favoritos_snippets where ID_Snippets=".$snippetID ." and ID_User=".$userID ;
	$this->paginatedResult->setQuery( $query );
	$this->paginatedResult->setMethod( 'cache' );
	$this->paginatedResult->generatePagination();
	if ($this->paginatedResult->getTotalRows()==1)
	{  
	  return true;
	}
	return false;
  }

  /**
  * Metodo que guarda el snippet
  */
  public function save()
  {
    $changes = array();
	foreach( $this->saveable_fields as $field )
	{
	  $changes[ $field ] = $this->$field;
	}
	$this->registry->getObject('db')->insertRecords( 'snippets', $changes );
	$uid = $this->registry->getObject('db')->lastInsertID();
	return $uid;  
  }	
	
  /*
  * Metodos setter y getter
  *
  */
  public function getID(){
    $this->ID;
  }
   
  public function setTitle($title){
    $this->title=$title;
  }
   
  public function getTitle(){
    return $this->title;
  }
   
  public function setDescription($description){
    $this->description=$description;
  }
   
  public function setCode($code){
    $this->code=$code;
  }  
	
  public function setCategory($category){
    $this->ID_category=$category;
  }
	
  public function setIdUser($idUser){
    $this->ID_User=$idUser;
  }	
   
  public function setTotalVotes($total){
    $this->totalVotes=$total;
  }
   
  public function setRating($rating){
    $this->rating=$rating;
  }
   
  public function setAdded($added){
    $this->added=$added;
  } 
	
}
?>