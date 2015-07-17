<?php

require_once ("Object.inc");
/**
 * Category model
 * - Agrega y gestiona las categorias
 */
class Category extends Object
{
	
  private $ID;
  private $name;
  private $image_name;
  private $description;
  private $saveable_fields = array( 'name', 'image_name','description'); 
  private $limit = 500; //poner en config
  
  /*
  * Metodo que guarda la categoria en BBDD
  */
  public function save()
  {
    $changes = array();
	foreach( $this->saveable_fields as $field )
	{
	  $changes[ $field ] = $this->$field;
	}
	$this->registry->getObject('db')->insertRecords( 'category', $changes );
	$uid = $this->registry->getObject('db')->lastInsertID();
	return $uid;  
  }	


  /**
  * Obtiene una categoria a partir de su ID
  * @param int $categoryID 
  * @return Object 
  */
  public function getCategory($categoryID)
  {
    $query = "SELECT c.ID, c.name as name_category, c.image_category as image_category , c.description as description FROM category c where c.name = '".$categoryID . "'" ;
	  $this->registry->getObject('db')->executeQuery( $query );
    if( $this->registry->getObject('db')->numRows() > 0 )
    {
      $data = $this->registry->getObject('db')->getRows();
      $this->setID($data['ID']);
      $this->setName($data['name_category']);
      $this->setDescription($data['description']);
      $this->setImageName($data['image_category']);
      return true;
    }
    return false;
  }
	
  /**
   * Genera lista de categorias
   * @param int $offset 
   * @return Object pagination object
   */
  public function listCategory( $offset=0 )
  {
    $this->paginatedResult->setLimit($this->limit);
	  $this->paginatedResult->setOffset( $offset );
	  $query = "SELECT s.ID as categoryID,s.name as categoryName FROM  category s order by s.name ASC" ;
	  $this->paginatedResult->setQuery( $query );
	  $this->paginatedResult->setMethod( 'cache' );
	  $this->paginatedResult->generatePagination();
	  return $this->paginatedResult;
  }

  /**
   * Genera lista de categorias con una seleccionada
   * @param int $offset , int $cateogryId
   * @return Object pagination object
   */
  public function listCategorySelected( $categoryId )
  {
    $this->paginatedResult->setLimit($this->limit);
    $this->paginatedResult->setOffset(0);
    $query = "SELECT s.ID as categoryID, s.name as categoryName, IF(ID =".$categoryId.",'selected','') as categorySelected FROM category s order by s.name ASC" ;
    $this->paginatedResult->setQuery( $query );
    $this->paginatedResult->setMethod( 'cache' );
    $this->paginatedResult->generatePagination();
    return $this->paginatedResult;
  }

  /**
   * Genera lista de snippets por categoria
   * @param int $offset 
   * @return Object pagination object
   */
  public function countSnippetByCategory()
  {
    $this->paginatedResult->setLimit($this->limit);
    $this->paginatedResult->setOffset(0);
    $query = "select count(*) as category_total, c.name as category_name, c.image_category as category_image from snippets s inner join category c on s.ID_category=c.ID group by c.name" ;
    $this->paginatedResult->setQuery( $query );
    $this->paginatedResult->setMethod( 'cache' );
    $this->paginatedResult->generatePagination();
    return $this->paginatedResult;
  }
	
  /**
   * Genera lista de tutoriales por categoria con el parent Root
   * @param int $offset 
   * @return Object pagination object
   */
  public function countTutsByCategory()
  {
    $this->paginatedResult->setLimit($this->limit);
    $this->paginatedResult->setOffset(0);
    $query = "SELECT c.name as category_name , c.description as category_desc, c.image_category as category_image, count(c.name) as total_tuts FROM page  p inner join category c on p.category = c.id WHERE p.published= 1 and parent = 0 group by c.name" ;
    $this->paginatedResult->setQuery( $query );
    $this->paginatedResult->setMethod( 'cache' );
    $this->paginatedResult->generatePagination();
    return $this->paginatedResult;
  }
	
  /**
   * Genera lista de tutoriales por nivel de dificultad de la categoria con el parent Root
   * @param int $offset 
   * @return Object pagination object
   */
  public function tutsByLevelCategory($categoryID)
  {
    $this->paginatedResult->setLimit($this->limit);
	  $this->paginatedResult->setOffset(0);
	  $query = "SELECT l.name as level_name, count(l.name) as level_total, c.name as category_name,
	  CASE 
	   when p.level = 1 then '<span class=\'fa fa-star\'></span>' 
	   when p.level = 2 then '<span class=\'fa fa-star\'></span><span class=\'fa fa-star\'></span><span class=\'fa fa-star\'></span>'
	   else '<span class=\'fa fa-star\'></span><span class=\'fa fa-star\'></span><span class=\'fa fa-star\'></span><span class=\'fa fa-star\'></span><span class=\'fa fa-star\'></span>'
	   end as level_stars 
	  FROM page p inner join category c on p.category = c.id inner join page_level l on p.level = l.ID WHERE p.published= 1 and p.parent = 0 and c.name ='".$categoryID."' group by l.name order by l.ID" ;
    $this->paginatedResult->setQuery( $query );
    $this->paginatedResult->setMethod( 'cache' );
    $this->paginatedResult->generatePagination();
    return $this->paginatedResult;
  }

  /**
   * Genera lista de tutoriales de la categoria 
   * definida y del nivel definido que sean del padre 0
   * @param int $offset 
   * @return Object pagination object
   */
  public function getTutsByLevelCategory($categoryName,$levelName)
  {
    $this->paginatedResult->setLimit($this->limit);
    $this->paginatedResult->setOffset(0);
    $query = "SELECT c.name as category_name ,c.image_category as category_image , l.name as level , p.title as tut_title, p.description_se as tut_description, p.url as tut_url FROM page p inner join category c on p.category = c.id inner join page_level l on p.level = l.ID WHERE p.published= 1 and parent = 0 and l.name = '".$levelName."' and c.name = '".$categoryName."'";
    $this->paginatedResult->setQuery( $query );
    $this->paginatedResult->setMethod( 'cache' );
    $this->paginatedResult->generatePagination();
    return $this->paginatedResult;
  }

  // Setter and Getters
  public function setID($id){ 
    $this->ID = $id; 
  }
  
  public function getID(){
    return $this->ID;
  }

  public function setName($name){ 
    $this->name = $name; 
  }
  
  public function getName(){
  	return $this->name;
  }

  public function setImageName($image){ 
  	$this->image_name = $image; 
  }
  
  public function getImageName(){
 	return $this->image_name;
  }

  public function setDescription($description){ 
  	$this->description = $description; 
  }
  
  public function getDescription(){
  	return $this->description;
  }

}
?>