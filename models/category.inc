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
  private $image_category;
  private $description;
  private $category_type;
  private $enable;
  private $saveable_fields = array( 'name', 'image_category','description','category_type','enable'); 
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
  * Metodo que valida si una categoria ya se ha guardado
  * @param $categoryName, nombre del controlador
  * @return true, si el nombre puede guardarse, false si no
  */
  public function canSave($categoryName){
    $query = "SELECT ID FROM category where name = '".$categoryName."'";
    $this->registry->getObject('db')->executeQuery( $query );
    if( $this->registry->getObject('db')->numRows() > 0 )
      return false;
    else
      return true;
  }

  /**
  * borra una categoria a partir de su ID
  * @param int $categoryID 
  */
  public function delete($categoryID)
  {
    $this->registry->getObject('db')->deleteRecords( 'category',' id = '.$categoryID,'1');
    $uid = $this->registry->getObject('db')->lastInsertID();
    return $uid;  
  }

  /**
  * actualiza el estatus de la categoria a partir de su ID
  * @param int $categoryID 
  */
  public function updateStatus($categoryID, $status)
  {
    $changes = array();
    $changes['enable'] = $status;
    $this->registry->getObject('db')->updateRecords('category', $changes," id = ".$categoryID );
    $uid = $this->registry->getObject('db')->lastInsertID();
    return $uid;  
  }
  

  /**
  * actualiza los datos  de la categoria a partir de su ID
  * @param int $categoryID 
  */
  public function update($categoryID,$name, $description,$type,$image)
  {
    $changes = array();
    $changes['name'] = $name;
    $changes['description'] = $description;
    $changes['image_category'] = $image;
    $changes['category_type'] = $type;
    $this->registry->getObject('db')->updateRecords('category', $changes," id = ".$categoryID );
    $uid = $this->registry->getObject('db')->lastInsertID();
    return $uid;  
  }


  /**
  * Metodo que comprueba si esa categoria tiene algun recurso asignado
  * La idea es que no deje borrar la misma si hay algun recurso que lo contenga
  * @param $catID
  * @return True si no hay resurso asignado ( puede ser borrado),
  * False si hay algun recurso ( no puede borrarse)
  */
  public function canErase($catID)
  {
    $query = "SELECT count(DISTINCT cs.ID) as snippets, count(DISTINCT cp.ID) as pages FROM category c left join snippets cs on cs.ID_Category = c.id left join page cp on cp.Category = c.ID WHERE c.ID =".$catID;
    $this->paginatedResult->setQuery( $query );
    $this->paginatedResult->setMethod( 'cache' );
    $this->paginatedResult->generatePagination();
    if ($this->paginatedResult->getTotalRows()==1)
    {  
      $tag = $this->registry->getObject('db')->resultsFromCache($this->paginatedResult->getCache());
      $temp['snippets'] = intval($tag["snippets"]);
      $temp['pages'] = intval($tag["pages"]);
      if ( $temp['snippets'] == 0 && $temp['pages'] == 0 )
        return true;
      return false;
    }
    return false;
  }




  /**
  * Obtiene una categoria a partir de su ID
  * @param int $categoryID 
  * @return Object 
  */
  public function getCategory($categoryID)
  {
    $query = "SELECT c.ID, c.name as name_category, md.url as image_category ,md.ID as image_id, c.description as description, c.category_type as type FROM category c inner join media md on md.ID = c.image_category where c.id = '".$categoryID . "'" ;
	  $this->registry->getObject('db')->executeQuery( $query );
    if( $this->registry->getObject('db')->numRows() > 0 )
    {
      $data = $this->registry->getObject('db')->getRows();
      $this->setID($data['ID']);
      $this->setName($data['name_category']);
      $this->setDescription($data['description']);
      $this->setImageName($data['image_id']);
      $this->setCategoryType($data['type']);
      return true;
    }
    return false;
  }
	
  /**
   * Genera lista de categorias pasando el tipo
   * Mostrara aquella aprobadas
   * @param int $offset 
   * @return Object pagination object
   */
  public function listCategory( $offset=0, $type= 1)
  {
    $this->paginatedResult->setLimit($this->limit);
	  $this->paginatedResult->setOffset( $offset );
	  $query = "SELECT s.ID as categoryID,s.name as categoryName FROM  category s where category_type=".$type." and enable = 4 order by s.name ASC" ;
	  $this->paginatedResult->setQuery( $query );
	  $this->paginatedResult->setMethod( 'cache' );
	  $this->paginatedResult->generatePagination();
	  return $this->paginatedResult;
  }

   /**
   * Genera lista de categorias que coinciden con el criterio pasado paginados 
   * Este metodo se llama en Admin_category desde el administrador
   * Devuelve un ResulSet con la siguiente informacion en caché:
   * ID de la categoria
   * Nombre de la categoria
   * Imagen
   * Descripcion
   * @param int $offset, pagina de la busqueda
   * @param String $criteria, cadena de busqueda 
   * @return Object pagination object
   */
  public function search($offset = 1, $criteria = "")
  {
    $this->paginatedResult->setLimit(10);
    $this->paginatedResult->setOffset($offset - 1);
    $query="SELECT c.ID as ID, c.name as categoryName, md.url as categoryImage, c.description as categoryDescripition, t.name as categoryType, s.status_class as class FROM category c inner join media md on md.ID = c.image_category inner join operational_status s  on c.enable = s.ID  inner join category_type t  on c.category_type = t.ID  where c.name like '%".$criteria."%' or c.image_category  like '%".$criteria."%' or c.description like '%".$criteria."%' order by c.name ASC";

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
    $query = "select count(*) as category_total, c.name as category_name from snippets s inner join category c on s.ID_category=c.ID group by c.name" ;
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
    $query = "SELECT c.name as category_name , c.description as category_desc, md.url as category_image, count(c.name) as total_tuts FROM page  p inner join category c on p.category = c.id inner join media md on md.ID = c.image_category WHERE p.published= 1 and parent = 0 group by c.name" ;
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
    $query = "SELECT c.name as category_name , md.url as category_image , l.name as level , p.title as tut_title, p.description_se as tut_description, p.url as tut_url FROM page p inner join category c on p.category = c.id  inner join media md on md.ID = c.image_category inner join page_level l on p.level = l.ID WHERE p.published= 1 and parent = 0 and l.name = '".$levelName."' and c.name = '".$categoryName."'";
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

  public function setEnable($enable){ 
    $this->enable = $enable; 
  }
  
  public function isEnable(){
    return $this->enable;
  }

  public function setImageName($image){ 
  	$this->image_category = $image; 
  }
  
  public function getImageName(){
 	return $this->image_category;
  }

  public function setDescription($description){ 
  	$this->description = $description; 
  }
  
  public function getDescription(){
  	return $this->description;
  }

  public function setCategoryType($type){ 
    $this->category_type = $type; 
  }
  
  public function getCategoryType(){
    return $this->category_type;
  }
}
?>