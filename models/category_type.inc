<?php

require_once ("Object.inc");
/**
 * Category model
 * - Agrega y gestiona las categorias
 */
class Category_Type extends Object
{
	
  private $ID;
  private $name;
  private $saveable_fields = array( 'name'); 
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
	  $this->registry->getObject('db')->insertRecords( 'category_type', $changes );
	  $uid = $this->registry->getObject('db')->lastInsertID();
	  return $uid;  
  }	


  /**
  * Metodo que valida si una tipo de categoria ya se ha guardado
  * @param $categoryName, nombre del controlador
  * @return true, si el nombre puede guardarse, false si no
  */
  public function canSave($categoryName){
    $query = "SELECT ID FROM category_type where name = '".$categoryName."'";
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
    $this->registry->getObject('db')->deleteRecords( 'category_type',' id = '.$categoryID,'1');
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
  public function getCategoryType($categoryID)
  {
    $query = "SELECT c.ID, c.name as name_category, md.url as image_category ,md.ID as image_id, c.description as description FROM category c inner join media md on md.ID = c.image_category where c.id = '".$categoryID . "'" ;
	  $this->registry->getObject('db')->executeQuery( $query );
    if( $this->registry->getObject('db')->numRows() > 0 )
    {
      $data = $this->registry->getObject('db')->getRows();
      $this->setID($data['ID']);
      $this->setName($data['name_category']);
      $this->setDescription($data['description']);
      $this->setImageName($data['image_id']);
      return true;
    }
    return false;
  }
	
  /**
   * Genera lista de tipos de categorias
   * @param int $offset 
   * @return Object pagination object
   */
  public function listCategoryType( $offset=0)
  {
    $this->paginatedResult->setLimit($this->limit);
	  $this->paginatedResult->setOffset( $offset );
	  $query = "SELECT s.ID as category_type_ID,s.name as category_type_Name FROM  category_type s order by s.name ASC" ;
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
  public function listCategoryTypeSelected( $categoryId )
  {
    $this->paginatedResult->setLimit($this->limit);
    $this->paginatedResult->setOffset(0);
    $query = "SELECT s.ID as category_type_ID, s.name as category_type_Name, IF(ID =".$categoryId.",'selected','') as category_type_Selected FROM category_type s order by s.name ASC" ;
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

}
?>