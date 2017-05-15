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
  public function canSave($categoryTypeName){
    $query = "SELECT ID FROM category_type where name = '".$categoryTypeName."'";
    $this->registry->getObject('db')->executeQuery( $query );
    if( $this->registry->getObject('db')->numRows() > 0 )
      return false;
    else
      return true;
  }

  /**
  * borra un tipo de categoria a partir de su ID
  * @param int $categoryID 
  */
  public function delete($categoryTypeID)
  {
    $this->registry->getObject('db')->deleteRecords( 'category_type',' id = '.$categoryTypeID,'1');
    $uid = $this->registry->getObject('db')->lastInsertID();
    return $uid;  
  }



  /**
  * Metodo que comprueba si ese tipo de categoria tiene algun recurso asignado
  * La idea es que no deje borrar la misma si hay algun recurso que lo contenga
  * @param $catID
  * @return True si no hay resurso asignado ( puede ser borrado),
  * False si hay algun recurso ( no puede borrarse)
  */
  public function canErase($catID)
  {
    $query = "SELECT c.ID  from category c inner join category_type ct on c.category_type=ct.id WHERE ct.ID =".$catID;
    $this->paginatedResult->setQuery( $query );
    $this->paginatedResult->setMethod( 'cache' );
    $this->paginatedResult->generatePagination();
    if ($this->paginatedResult->getTotalRows()==0)
    {  
      return true;
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
    $query="SELECT ct.ID as ID, ct.name as name, 'success' as class, IFNULL(count(c.id),0) as total  FROM category_type ct left join category c on ct.ID = c.category_type where ct.name like '%".$criteria."%'  group by ct.name order by ct.name ASC";
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