<?php

require_once ("Object.inc");
/**
 * Links model
 * - Agrega y gestiona los Links
 */
class Links extends Object{
	
  private $ID;
  private $title;
  private $description;
  private $url;
  private $ID_User;
  private $rating;
  private $totalVotes;
  private $added;
  private $limit = 5; //TODO poner en configs
  private $saveable_fields = array( 'title', 'description', 'url', 'ID_User','rating','totalVotes','added');
	
  /**
   * Genera lista de links paginados
   * @param int $offset 
   * @return Object pagination object
   */
  public function listLinks( $offset=1,$order)
  {
    $this->paginatedResult->setLimit($this->limit);
	$this->paginatedResult->setOffset( $offset-1);
	//TODO poner el link a busqueda por  tags
	$query="SELECT tbl.*, GROUP_CONCAT(DISTINCT tag_name SEPARATOR '') 
		As all_tags FROM( SELECT l.ID,l.title, l.url ,l.description, DATE_FORMAT( l.added,'%b %d %Y') as fecha , l.added as rawDate,
		l.rating,l.totalFav as faved,l.totalComments as comments, u.user_login as author,u.profile_image , CONCAT('<a href=\"links/tag/',t.tag_name,'\" class=\"label label-info\">',t.tag_name,'</a> ') as tag_name 
		FROM links l inner join users u on l.ID_USER=u.ID inner join list_tags_links lt on l.ID=lt.ID_Links 
		inner join tags t on lt.ID_Tags=t.ID ) tbl GROUP BY tbl.id order by ".$order." desc";
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
		As all_tags FROM( SELECT l.ID,l.title, l.url,l.description, DATE_FORMAT( l.added,'%b %d %Y') as fecha , 
		l.rating as rating,l.totalFav as faved,l.totalComments as comments, u.user_login as author, u.profile_image , CONCAT('<a href=\"links/tag/',t.tag_name,'\" class=\"label label-info\">',t.tag_name,'</a> ') as tag_name 
		FROM links l inner join users u on l.ID_User=u.ID inner join list_tags_links lt on l.ID=lt.ID_Links
		inner join tags t on lt.ID_Tags=t.ID where u.user_login='".$username."' ) tbl GROUP BY tbl.id ";
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
		As all_tags FROM( SELECT l.ID, l.title, l.url ,l.description, DATE_FORMAT( l.added,'%b %d %Y') as fecha , 
		l.rating as rating,l.totalFav as faved,l.totalComments as comments, u.user_login as author, u.profile_image , CONCAT('<a href=\"links/tag/',t.tag_name,'\" class=\"label label-info\">',t.tag_name,'</a> ') as tag_name 
		FROM links l inner join users u on l.ID_USER=u.ID inner join list_tags_links lt on l.ID=lt.ID_Links 
		inner join tags t on lt.ID_Tags=t.ID where t.tag_name='".$tag."' ) tbl GROUP BY tbl.id ";
	$this->paginatedResult->setQuery( $query );
	$this->paginatedResult->setMethod( 'cache' );
	$this->paginatedResult->generatePagination();
	return $this->paginatedResult;
  }
	
	
  /**
   * Genera lista de usuarios que mas han creado links
   * @return 
   */
  public function topContributors()
  {
    $this->paginatedResult->setLimit(35);
    $this->paginatedResult->setOffset(0);
    $query = "SELECT  count(b.id) as total , b.user_login, b.profile_image FROM links a inner join users b on a.ID_User = b.ID group by b.user_login order by total DESC";
    $this->paginatedResult->setQuery( $query );
	$this->paginatedResult->setMethod( 'cache' );
	$this->paginatedResult->generatePagination();
	return $this->paginatedResult;
  }
	
  /**
   * Genera lista de tags mas usados
   * @return Object pagination object
   */
  public function topTags()
  {
    $this->paginatedResult->setLimit(15); 
	$this->paginatedResult->setOffset(0);
	$query = "SELECT count(a.tag_name) total, a.tag_name as name FROM tags a inner join list_tags_links b on a.ID=b.ID_tags group by a.tag_name order by total desc";
	$this->paginatedResult->setQuery( $query );
	$this->paginatedResult->setMethod( 'cache' );
	$this->paginatedResult->generatePagination();
	return $this->paginatedResult;
  }
	
  /**
   * Obtiene un snippet a partir de su ID
   * @param int $linkId 
   * @return Object 
   */
  public function getLink($linkId)
  {
    $query = "SELECT s.ID_User, s.ID,s.title, s.url ,s.description, s.added, s.rating FROM links s where s.ID=".$linkId ;
	$this->registry->getObject('db')->executeQuery( $query );
	if( $this->registry->getObject('db')->numRows() > 0 )
	{
	  $data = $this->registry->getObject('db')->getRows();
	  $tempo['ID']=$data['ID'];
	  $tempo['ID_User']=$data['ID_User'];
	  $tempo['title']=$data['title'];
	  $tempo['url']= utf8_decode($data['url']);
	  $tempo['description']=$data['description'];
	  $tempo['added']=$data['added'];
	  $tempo['rating']=$data['rating'];
	  return $tempo;
	}
	return null;
  }
	
  public function isFavorited($idLink,$idUser)
  {
    $query = "SELECT ID, ID_Links, ID_Users FROM list_favorites_links where ID_Links=".$idLink ." and ID_Users=".$idUser ;
	$this->paginatedResult->setQuery( $query );
	$this->paginatedResult->setMethod( 'cache' );
	$this->paginatedResult->generatePagination();
	if ($this->paginatedResult->getTotalRows()==1)
	{  
	  return true;
	}
	return false;
  }

  public function save()
  {
    $changes = array();
	foreach( $this->saveable_fields as $field )
	{
	  $changes[ $field ] = $this->$field;
	}
	$this->registry->getObject('db')->insertRecords( 'links', $changes );
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
   
  public function setURL($url){
    $this->url=$url;
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