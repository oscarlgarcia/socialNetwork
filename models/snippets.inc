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
  private $ID_status;

  private $limit = 10; //TODO poner en configs
  private $saveable_fields = array( 'title', 'description', 'code', 'ID_category', 'ID_User','rating','totalVotes','added','ID_status');
  /**
   * Genera lista de snippets aprobados para publicación ( Id_status = 4) paginados 
   * Este metodo se llama en Snippets desde el usuario
   * Devuelve un ResulSet con la siguiente informacion en caché:
   * - ID
   * - Title
   * - Code
   * - descripcion
   * - Fecha ( Friendly format)
   * - Fecha ( raw para ordenacion)
   * - rating
   * - faved
   * - Comments
   * - category
   * - image category
   * - autor
   * - profile_image
   * - tag name
   * - All tags
   * @param int $offset 
   * @return Object pagination object
   */
  public function listSnippets( $offset=1 )
  {
	  $this->paginatedResult->setLimit($this->limit);
	  $this->paginatedResult->setOffset( $offset-1);
		//TODO poner el link a busqueda por  tags
	  $query="SELECT tbl.*, GROUP_CONCAT(DISTINCT tag_name SEPARATOR '') 
		As all_tags FROM( SELECT s.ID,s.title, s.description, DATE_FORMAT( s.added,'%d %b %Y %T') as fecha , s.added as rawDate,                                          
		s.rating,s.totalFav as faved,s.totalComments as comments, c.name as category, md.url as image_category, u.user_login as author, u.profile_image , CONCAT('<a href=\"snippets/tag/',t.tag_name,'\" class=\"label label-info\">',t.tag_name,'</a> ') as tag_name 
		FROM snippets s inner join category c on s.ID_category=c.ID inner join media md on md.id = c.image_category inner join users u on s.ID_USER=u.ID inner join lista_tag_snippet l on s.ID=l.ID_Snippets 
		inner join tags t on l.ID_Tag=t.ID where s.id_status = 4 ) tbl GROUP BY tbl.id order by rawDate desc";
	  $this->paginatedResult->setQuery( $query );
	  $this->paginatedResult->setMethod( 'cache' );
	  $this->paginatedResult->generatePagination();
	  return $this->paginatedResult;
  }
	
  /**
   * Genera lista de snippets populares aprobados para publicación ( Id_status = 4) paginados 
   * Este metodo se llama en Snippets desde el usuario
   * Devuelve un ResulSet con la siguiente informacion en caché:
   * - ID
   * - Title
   * - Code
   * - descripcion
   * - Fecha ( Friendly format)
   * - Fecha ( raw para ordenacion)
   * - rating
   * - faved
   * - Comments
   * - category
   * - image category
   * - autor
   * - profile_image
   * - tag name
   * - All tags
   * @param int $offset 
   * @return Object pagination object
   */
  public function listPopularSnippets( $offset=1 )
  {
    $this->paginatedResult->setLimit($this->limit);
	  $this->paginatedResult->setOffset( $offset-1 );
	  $query="SELECT tbl.*, GROUP_CONCAT(DISTINCT tag_name SEPARATOR '') 
		As all_tags FROM( SELECT s.ID,s.title, s.code ,s.description, DATE_FORMAT( s.added,'%d %b %Y %T') as fecha , 
		s.rating as rating,s.totalFav as faved,s.totalComments as comments, c.name as category, md.url as image_category, u.user_login as author,u.profile_image , CONCAT('<a href=\"snippets/tag/',t.tag_name,'\" class=\"label label-info\">',t.tag_name,'</a> ') as tag_name 
		FROM snippets s inner join category c on s.ID_category=c.ID inner join media md on md.ID = c.image_category inner join users u on s.ID_USER=u.ID inner join lista_tag_snippet l on s.ID=l.ID_Snippets 
		inner join tags t on l.ID_Tag=t.ID where s.id_status = 4 ) tbl GROUP BY tbl.id order by rating desc ";
	  $this->paginatedResult->setQuery( $query );
	  $this->paginatedResult->setMethod( 'cache' );
	  $this->paginatedResult->generatePagination();
	  return $this->paginatedResult;
  }
	
  /**
   * Genera lista de snippets favoritos aprobados para publicación ( Id_status = 4) paginados 
   * Este metodo se llama en Snippets desde el usuario
   * Devuelve un ResulSet con la siguiente informacion en caché:
   * - ID
   * - Title
   * - Code
   * - descripcion
   * - Fecha ( Friendly format)
   * - Fecha ( raw para ordenacion)
   * - rating
   * - faved
   * - Comments
   * - category
   * - image category
   * - autor
   * - profile_image
   * - tag name
   * - All tags
  * @param int $offset 
  * @return Object pagination object
  */
  public function listFavorites( $offset=1 )
  {
	$this->paginatedResult->setLimit($this->limit);
	$this->paginatedResult->setOffset( $offset-1 );
	$query="SELECT tbl.*, GROUP_CONCAT(DISTINCT tag_name SEPARATOR '') 
		As all_tags FROM( SELECT s.ID,s.title, s.code ,s.description, DATE_FORMAT( s.added,'%d %b %Y %T') as fecha , 
		s.rating as rating,s.totalFav as faved,s.totalComments as comments, c.name as category, md.url as image_category, u.user_login as author,u.profile_image , CONCAT('<a href=\"snippets/tag/',t.tag_name,'\" class=\"label label-info\">',t.tag_name,'</a> ') as tag_name 
		FROM snippets s inner join category c on s.ID_category=c.ID inner join media md on md.ID = c.image_category inner join users u on s.ID_USER=u.ID inner join lista_tag_snippet l on s.ID=l.ID_Snippets 
		inner join tags t on l.ID_Tag=t.ID where s.id_status = 4 ) tbl GROUP BY tbl.id order by faved desc ";
	$this->paginatedResult->setQuery( $query );
	$this->paginatedResult->setMethod( 'cache' );
	$this->paginatedResult->generatePagination();
	return $this->paginatedResult;
  }
	
	
  /**
   * Genera lista de snippets mas comentados aprobados para publicación ( Id_status = 4) paginados
   * Este metodo se llama en Snippets desde el usuario 
   * Devuelve un ResulSet con la siguiente informacion en caché:
   * - ID
   * - Title
   * - Code
   * - descripcion
   * - Fecha ( Friendly format)
   * - Fecha ( raw para ordenacion)
   * - rating
   * - faved
   * - Comments
   * - category
   * - image category
   * - autor
   * - profile_image
   * - tag name
   * - All tags
  * @param int $offset 
  * @return Object pagination object
  */
  public function listCommentedSnippets( $offset=1 )
  {
	$this->paginatedResult->setLimit($this->limit);
	$this->paginatedResult->setOffset( $offset-1);
	//TODO poner el link a busqueda por  tags
	$query="SELECT tbl.*, GROUP_CONCAT(DISTINCT tag_name SEPARATOR '') 
		As all_tags FROM( SELECT s.ID,s.title, s.code ,s.description, DATE_FORMAT( s.added,'%d %b %Y %T') as fecha , s.added as rawDate,
		s.rating,s.totalFav as faved,s.totalComments as comments, c.name as category, md.url as image_category, u.user_login as author,u.profile_image , CONCAT('<a href=\"snippets/tag/',t.tag_name,'\" class=\"label label-info\">',t.tag_name,'</a> ') as tag_name 
		FROM snippets s inner join category c on s.ID_category=c.ID inner join media md on md.ID = c.image_category inner join users u on s.ID_USER=u.ID inner join lista_tag_snippet l on s.ID=l.ID_Snippets 
		inner join tags t on l.ID_Tag=t.ID  where s.id_status = 4 ) tbl GROUP BY tbl.id order by comments DESC";
	$this->paginatedResult->setQuery( $query );
	$this->paginatedResult->setMethod( 'cache' );
	$this->paginatedResult->generatePagination();
	return $this->paginatedResult;
  }
	
  /**
   * Genera lista de snippets por la categoria aprobados para publicación ( Id_status = 4) paginados
   * Este metodo se llama en Snippets desde el usuario 
   * Devuelve un ResulSet con la siguiente informacion en caché:
   * - ID
   * - Title
   * - Code
   * - descripcion
   * - Fecha ( Friendly format)
   * - Fecha ( raw para ordenacion)
   * - rating
   * - faved
   * - Comments
   * - category
   * - image category
   * - autor
   * - profile_image
   * - tag name
   * - All tags
  * @param string categoria
  * @param int $offset 
  * @return Object pagination object
  */
  public function listByCategory( $category,$offset=1 )
  {
	$this->paginatedResult->setLimit($this->limit);
	$this->paginatedResult->setOffset( $offset-1 );
	$query="SELECT tbl.*, GROUP_CONCAT(DISTINCT tag_name SEPARATOR '') 
		As all_tags FROM( SELECT s.ID,s.title, s.code ,s.description, DATE_FORMAT( s.added,'%d %b %Y %T') as fecha , 
		s.rating as rating,s.totalFav as faved,s.totalComments as comments, c.name as category, md.url as image_category, u.user_login as author,u.profile_image , CONCAT('<a href=\"snippets/tag/',t.tag_name,'\" class=\"label label-info\">',t.tag_name,'</a> ') as tag_name 
		FROM snippets s inner join category c on s.ID_category=c.ID inner join media md on md.ID = c.image_category inner join users u on s.ID_USER=u.ID inner join lista_tag_snippet l on s.ID=l.ID_Snippets 
		inner join tags t on l.ID_Tag=t.ID where c.name='".$category."' and s.id_status = 4 ) tbl GROUP BY tbl.id ";
	$this->paginatedResult->setQuery( $query );
	$this->paginatedResult->setMethod( 'cache' );
	$this->paginatedResult->generatePagination();
	return $this->paginatedResult;
  }
	
  /**
   * Genera lista de snippets por el usuario aprobados para publicación ( Id_status = 4) paginados 
   * Este metodo se llama en Snippets desde el usuario
   * Devuelve un ResulSet con la siguiente informacion en caché:
   * - ID
   * - Title
   * - Code
   * - descripcion
   * - Fecha ( Friendly format)
   * - Fecha ( raw para ordenacion)
   * - rating
   * - faved
   * - Comments
   * - category
   * - image category
   * - autor
   * - profile_image
   * - tag name
   * - All tags
  * @param string username
  * @param int $offset 
  * @return Object pagination object
  */
  public function listByUsername( $username,$offset=1 )
  {
	$this->paginatedResult->setLimit($this->limit);
	$this->paginatedResult->setOffset( $offset-1 );
	$query="SELECT tbl.*, GROUP_CONCAT(DISTINCT tag_name SEPARATOR '') 
		As all_tags FROM( SELECT s.ID,s.title, s.code ,s.description, DATE_FORMAT( s.added,'%d %b %Y %T') as fecha , 
		s.rating as rating,s.totalFav as faved,s.totalComments as comments, c.name as category, md.url as image_category, u.user_login as author,u.profile_image , CONCAT('<a href=\"snippets/tag/',t.tag_name,'\" class=\"label label-info\">',t.tag_name,'</a> ') as tag_name 
		FROM snippets s inner join category c on s.ID_category=c.ID inner join media md on md.ID = c.image_category inner join users u on s.ID_USER=u.ID inner join lista_tag_snippet l on s.ID=l.ID_Snippets 
		inner join tags t on l.ID_Tag=t.ID where u.user_login='".$username."' and s.id_status = 4) tbl GROUP BY tbl.id ";
    $this->paginatedResult->setQuery( $query );
	$this->paginatedResult->setMethod( 'cache' );
	$this->paginatedResult->generatePagination();
	return $this->paginatedResult;
  }
	
  /**
   * Genera lista de snippets por tag aprobados para publicación ( Id_status = 4) paginados 
   * Este metodo se llama en Snippets desde el usuario 
   * Devuelve un ResulSet con la siguiente informacion en caché:
   * - ID
   * - Title
   * - Code
   * - descripcion
   * - Fecha ( Friendly format)
   * - Fecha ( raw para ordenacion)
   * - rating
   * - faved
   * - Comments
   * - category
   * - image category
   * - autor
   * - profile_image
   * - tag name
   * - All tags
  * @param string tag
  * @param int $offset 
  * @return Object pagination object
  */
  public function listByTag( $tag, $offset = 1 )
  {

 	  $this->paginatedResult->setLimit($this->limit);
	  $this->paginatedResult->setOffset( $offset -1);
	  $query="SELECT tbl.*, GROUP_CONCAT(DISTINCT tag_name SEPARATOR '') 
		As all_tags FROM( SELECT s.ID,s.title, s.code ,s.description, DATE_FORMAT( s.added,'%d %b %Y %T') as fecha , 
		s.rating as rating,s.totalFav as faved,s.totalComments as comments, c.name as category, md.url as image_category, u.user_login as author,u.profile_image , CONCAT('<a href=\"snippets/tag/',t.tag_name,'\" class=\"label label-info\">',t.tag_name,'</a> ') as tag_name 
		FROM snippets s inner join category c on s.ID_category=c.ID inner join media md on md.ID = c.image_category inner join users u on s.ID_USER=u.ID inner join lista_tag_snippet l on s.ID=l.ID_Snippets 
		inner join tags t on l.ID_Tag=t.ID where t.tag_name='".$tag."' and s.id_status = 4 ) tbl GROUP BY tbl.id ";
	  $this->paginatedResult->setQuery( $query );
	  $this->paginatedResult->setMethod( 'cache' );
	  $this->paginatedResult->generatePagination();
	  return $this->paginatedResult;
  }


  /**
   * Genera lista de snippets que coinciden con el criterio pasado paginados 
   * Este metodo se llama en Admin_Snippets desde el administrador
   * Devuelve un ResulSet con la siguiente informacion en caché:
   * - ID
   * - Title
   * - Fecha ( Friendly format)
   * - rating
   * - Status
   * - faved
   * - Comments
   * - category
   * - autor
   * - class. La CSS class del snippet ( dependiendo de su estatus)
   * - User_id
   * @param int $criterio 
   * @return Object pagination object
   */
  public function search($offset = 1, $criteria = "")
  {
    $this->paginatedResult->setLimit($this->limit);
	  $this->paginatedResult->setOffset($offset - 1);
	  $query="SELECT s.ID,s.title, DATE_FORMAT( s.added,'%d %b %Y %T') as fecha, s.rating, s.id_status, s.totalFav as faved, s.totalComments as comments, c.name as category, u.user_login as author,u.id as user_id, o.status_class as class	FROM snippets s inner join category c on s.ID_category = c.ID inner join users u on s.ID_USER = u.ID inner join operational_status o on s.ID_Status = o.ID where s.title like '%".$criteria."%'  group by ID order by added desc";
	  $this->paginatedResult->setQuery( $query );
	  $this->paginatedResult->setMethod( 'cache' );
	  $this->paginatedResult->generatePagination();
	  return $this->paginatedResult;
  }

  /**
   * Genera lista de snippets que coinciden con el usuario pasado paginados 
   * Este metodo se llama en Admin_Snippets desde el administrador
   * Devuelve un ResulSet con la siguiente informacion en caché:
   * - ID
   * - Title
   * - Fecha ( Friendly format)
   * - rating
   * - Status
   * - faved
   * - Comments
   * - category
   * - autor
   * - class. La CSS class del snippet ( dependiendo de su estatus)
   * @param int $criterio 
   * @return Object pagination object
   */
  public function searchByUser($offset = 1, $username)
  {
    $this->paginatedResult->setLimit($this->limit);
    $this->paginatedResult->setOffset($offset - 1);
    $query="SELECT s.ID,s.title, DATE_FORMAT( s.added,'%d %b %Y %T') as fecha, s.rating, s.id_status, s.totalFav as faved, s.totalComments as comments, c.name as category, u.user_login as author,u.id as user_id, o.status_class as class FROM snippets s inner join category c on s.ID_category = c.ID inner join users u on s.ID_USER = u.ID inner join operational_status o on s.ID_Status = o.ID where u.user_login = '".$username."' group by ID order by added desc";

    $this->paginatedResult->setQuery( $query );
    $this->paginatedResult->setMethod( 'cache' );
    $this->paginatedResult->generatePagination();
    return $this->paginatedResult;
  }
	
	/**
	 * Genera lista de usuarios que mas han creado snippets
   * Este metodo se llama en Snippets desde el usuario
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
  * Se llama tanto desde User como desde admin
	* @param int $snippetID 
	* @return Object 
	* - ID del snippet
	* - Id del user
	* - Titulo
	* - Codigo
	* - Descripcion
	* - fecha en que se agrego
	* - rating
	* - categoria
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

  /**
  * actualiza el estatus del snippet a partir de su ID
  * @param int $snippetID 
  */
  public function updateStatus($id, $status)
  {
  	$changes = array();
  	$changes['ID_Status'] = $status;
    $this->registry->getObject('db')->updateRecords('snippets', $changes," id = ".$id );
    $uid = $this->registry->getObject('db')->lastInsertID();
    return $uid;  
  }
	
  /*
  * Metodo que detemina si el usuario ha marcado como favorito el snippet
  * Este metodo se llama en Snippets desde el user
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
    $this->title = $title;
  }
   
  public function getTitle(){
    return $this->title;
  }
   
  public function setDescription($description){
    $this->description = $description;
  }
   
  public function setCode($code){
    $this->code = $code;
  }  
	
  public function setCategory($category){
    $this->ID_category = $category;
  }
	
  public function setIdUser($idUser){
    $this->ID_User = $idUser;
  }	
   
  public function setTotalVotes($total){
    $this->totalVotes = $total;
  }
   
  public function setRating($rating){
    $this->rating = $rating;
  }
   
  public function setAdded($added){
    $this->added = $added;
  } 

  public function setOperationalStatus($ID_status){
    $this->ID_status = $ID_status;
  }
   
  public function getOperationalStatus(){
    return $this->ID_status;
  } 

  
	
}
?>