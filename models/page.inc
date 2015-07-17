<?php

require_once ("Object.inc");
/**
 * Pages model
 * - Agrega y gestiona las Paginas
 */
class Pages extends Object{
	
  private $ID;
  private $url;
  private $body;
  private $parent;
  private $category;
  private $created;
  private $ordenation;
  private $published;
  private $updated;
  private $title;
  private $type;
  private $level;
  private $keywords_se;
  private $description_se;
  private $associated;
  private $vars;
  private $limit = 500;
	private $saveable_fields = array( 'url', 'body', 'parent','category', 'created', 'ordenation','published','updated','title', 'type','level', 'keywords_se', 'description_se');
		
	
  /**
  * Genera lista de pages 
	* @param int $offset 
	* @return Object pagination object
	*/
	public function listPagesAsTree()
	{
		require_once( FRAMEWORK_PATH . 'lib/pagesTree/pagesTree.class.inc');
		$tree = new PagesTree( $this->registry );
		$query = "SELECT id as page_id, title as page_title, parent as page_parent FROM page order by parent";
		$this->registry->getObject('db')->executeQuery( $query );
		$pages = $this->initArray();
		while( $data = $this->registry->getObject('db')->getRows() ){
       $tempo['ID'] = $data['page_id'];
		   $tempo['title'] = $data['page_title'];
		   $tempo['parent'] = $data['page_parent'];
		   $pages[] = $tempo;
		}
		return $tree->showTree($tree->pagesAsTree($pages));
	}

  /**
  * Metodo que inicializa un Array
  */
  private function initArray()
  {
    $pages = array();
    $temp['ID'] = 0;
    $temp['title'] = "Root";
    $temp['parent'] = -1;
    $pages[] = $temp;
    return $pages; 
  }

  /**
   * Obtiene una pagina a partir de su ID
   * @param int $pageId 
   * @return Object 
   */
  public function getPage($pageId)
  {
    $query = "SELECT p.ID as ID, p.title as title, p.url as url, p.body as body, p.category as category, p.keywords_se as keywords, p.description_se as description, p.type as type ,p.level as level,p.published as published, p.parent as parent FROM page p where p.ID=".$pageId ;
    $this->registry->getObject('db')->executeQuery( $query );
    if( $this->registry->getObject('db')->numRows() > 0 )
    {
      $data = $this->registry->getObject('db')->getRows();
      $this->setID($data['ID']);
      $this->setTitle($data['title']);
      $this->setUrl($data['url']);
      $this->setBody($data['body']);
      $this->setParent($data['parent']);
      $this->setKeywordsSEO($data['keywords']);
      $this->setCategory($data['category']);
      $this->setType($data['type']);
      $this->setLevel($data['level']);
      $this->setDescriptionSEO($data['description']);
      $this->setPublished($data['published']);
      return true;
    }
    return false;
  }


  /**
   * Obtiene una pagina a partir de su URL
   * @param String $URL 
   * @return Object 
   */
  public function getPageByURL($url)
  {
    require_once( FRAMEWORK_PATH . 'models/page_level.inc');
    require_once( FRAMEWORK_PATH . 'models/category.inc');
    $query = "SELECT p.ID as ID, p.title as title, p.url as url, p.body as body, p.category as category, p.keywords_se as keywords, p.description_se as description, p.type as type ,p.level as level, p.parent as parent, c.name as category_name, l.name as level_name FROM page p inner join category c on p.category = c.ID inner join page_level l on p.level = l.ID where p.published = 1 and p.url = '".$url."'" ;
    $this->registry->getObject('db')->executeQuery( $query );
    if( $this->registry->getObject('db')->numRows() > 0 )
    {
      $data = $this->registry->getObject('db')->getRows();
      $this->setID($data['ID']);
      $this->setTitle($data['title']);
      $this->setUrl($data['url']);
      $this->setBody($this->replaceCodemirror($data['body']));
      $this->setParent($data['parent']);
      $this->setKeywordsSEO($data['keywords']);
      $cat = new Category( $this->registry );
      $cat->setName($data['category_name']);
      $cat->setID($data['category']);
      $level = new PageLevel( $this->registry );
      $level->setID($data['level']);
      $level->setName($data['level_name']);
      $this->setCategory($cat);
      $this->setType($data['type']);
      $this->setLevel($level);
      $this->setDescriptionSEO($data['description']);
      $this->setPublished(1);
      return true;
    }
    return false;
  }

  /*
  * Devuelve los hijos de una page determinada
  */
  public function getChilds()
  {
    $this->paginatedResult->setLimit($this->limit);
    $this->paginatedResult->setOffset(0);
    $query = "SELECT p.title as related_title, p.url as related_url FROM page p where p.published = 1 and p.parent = ".$this->ID ;
    $this->paginatedResult->setQuery( $query );
    $this->paginatedResult->setMethod( 'cache' );
    $this->paginatedResult->generatePagination();
    return $this->paginatedResult;
  }

  /*
  * Metodo que comprueba si la url ya existe
  * Si existe le añade un contador
  */
  public function checkAvailability($url)
  {
    $query = "SELECT url FROM Page where url = '".$url."' and ID != ".$this->getID();
    $this->registry->getObject('db')->executeQuery( $query );
    if( $this->registry->getObject('db')->numRows() > 0 )
    {
      return $url."-".($this->registry->getObject('db')->numRows()+1);
    }
    return $url;
  }
  
  /*
  * Elimina los tags relacionados de esta page
  */
  public function deleteTags()
  {
    $query = "DELETE from list_tag_page where ID_Page = ".$this->ID ;
    $this->registry->getObject('db')->executeQuery( $query );  
  }


  public function save()
	{
    $changes = array();
	  foreach( $this->saveable_fields as $field )
	  {
	    $changes[ $field ] = $this->$field;
	  }
	  $this->registry->getObject('db')->insertRecords( 'page', $changes );
	  $uid = $this->registry->getObject('db')->lastInsertID();
	  return $uid;  
	}	

  public function update()
  {
    $changes = array();
    foreach( $this->saveable_fields as $field )
    {
      $changes[ $field ] = $this->$field;
    }
    $this->registry->getObject('db')->updateRecords('page', $changes," id = ".$this->ID );
    $uid = $this->registry->getObject('db')->lastInsertID();
    return $uid;  
  }
	
  	
  // Setter and Getter
  public function setTitle($title){ 
  	$this->title = $title; 
  }
  
  public function getTitle(){
  	return $this->title;
  }

  public function setUrl($url){ 
  	$this->url = $url; 
  }
  
  public function getUrl(){
  	return $this->url;
  }

  public function setBody($body){ 
  	$this->body = $body; 
  }
  
  public function getBody(){
  	return $this->body;
  }

  public function setParent($parent){ 
  	$this->parent = $parent; 
  }
  
  public function getParent(){
  	return $this->parent;
  }

  public function setCreated($created){ 
  	$this->created = $created; 
  }
  
  public function getCreated(){
  	return $this->created;
  }

  public function setOrdenation($ordenation){ 
  	$this->ordenation = $ordenation; 
  }
  
  public function getOrdenation(){
  	return $this->ordenation;
  }
  

  public function setPublished($published){ 
  	$this->published = $published; 
  }
  
  public function isPublished(){
  	return $this->published;
  }

  public function setUpdated($updated){ 
  	$this->updated = $updated; 
  }
  
  public function getUpdated(){
  	return $this->updated;
  }

  public function setAssociated($associated){ 
  	$this->associated = $associated; 
  }
  
  public function getAssociated(){
  	return $this->associated;
  }

  public function setType($type){ 
  	$this->type = $type; 
  }
  
  public function getType(){
  	return $this->type;
  }


  public function setLevel($level){ 
    $this->level = $level; 
  }
  
  public function getLevel(){
    return $this->level;
  }

  public function setKeywordsSEO($keywords_se){ 
  	$this->keywords_se = $keywords_se; 
  }
  
  public function getKeywordsSEO(){
  	return $this->keywords_se;
  }

  public function setDescriptionSEO($description_se){ 
  	$this->description_se = $description_se; 
  }
  
  public function getDescriptionSEO(){
  	return $this->description_se;
  }

  public function setVars($vars){ 
  	$this->vars = $vars; 
  }
  
  public function getVars(){
  	return $this->vars;
  }

  public function setCategory($category){ 
    $this->category = $category; 
  }
  
  public function getCategory(){
    return $this->category;
  }

  public function setId($id){

    $this->ID = $id;
  }
  public function getId(){
    return $this->ID;
  }

}
?>