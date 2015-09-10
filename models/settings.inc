<?php

require_once ("Object.inc");
/**
 * Settings model
 * - Agrega y gestiona los Settings
 */
class Settings extends Object{
	
  private $ID;
  private $key;
  private $value;
  private $limit = 10;
  private $saveable_fields = array( 'key','value');
	
	
  /**
  * Obtiene un Setting a partir de su ID
  * Se llama desde Admin_settings
  * @param String $settingID 
  * @return Object Setting
  */
  public function getSetting($settingID)
  {
    $query = "SELECT * FROM settings where id = ".$settingID;
    $this->registry->getObject('db')->executeQuery( $query );
    if( $this->registry->getObject('db')->numRows() > 0 )
    {
      $data = $this->registry->getObject('db')->getRows();
      $this->setID($data['ID']);
      $this->setKey($data['key']);
      $this->setValue(htmlentities($data['value']));
      return true;
    }
    return null;
  }
	
   /**
   * Genera lista de settings que coinciden con el criterio pasado paginados 
   * Este metodo se llama en Admin_settings desde el administrador
   * Devuelve un ResulSet con la siguiente informacion en caché:
   * ID del Setting
   * Nombre del Setting
   * Valor del Setting
   * @param int $offset, pagina de la busqueda
   * @param String $criteria, cadena de busqueda 
   * @return Object pagination object
   */
  public function search($offset = 1, $criteria = "")
  {
    $this->paginatedResult->setLimit($this->limit);
    $this->paginatedResult->setOffset($offset - 1);
    $query="SELECT s.ID as ID, s.key as clave, s.value as valor FROM settings s WHERE s.key like '%".$criteria."%' or s.value like '%".$criteria."%'";
    $this->paginatedResult->setQuery( $query );
    $this->paginatedResult->setMethod( 'cache' );
    $this->paginatedResult->generatePagination();
    return $this->paginatedResult;
  }


  /**
  * Metodo que verifica si un setting esta ya guardado
  * @param String $settingKey , Nombre del setting
  * @return ID del tag o false sino existe
  */
  public function isSaved($settingKey,$settingID = 0)
  {
    if ($settingKey == "") 
      return true;
 	  $query= "SELECT s.ID as id FROM settings s where s.key = '".$settingKey."'" ;
    $this->paginatedResult->setQuery( $query );
	  $this->paginatedResult->setMethod( 'cache' );
	  $this->paginatedResult->generatePagination();
	  if ($this->paginatedResult->getTotalRows() == 1)
    {  
	    $setting = $this->registry->getObject('db')->resultsFromCache($this->paginatedResult->getCache());
      if ($settingID == $setting["id"])
	      return false;
      else
        return true;
	  }
	  return false;
  }

   
  /*
  * Metodo que almacena un setting en la bbdd
  * @return ID del tag.
  *
  */
  public function save()
  {
    $changes = array();
	  foreach( $this->saveable_fields as $field )
	  {
	    $changes[ $field ] = $this->$field;
	  }
	  $isSaved = $this->isSaved($this->tag_name);
	
	  // Si el tag no esta guardado
	  if(!$isSaved)
    {
	    //lo guardamos
	    $this->registry->getObject('db')->insertRecords( 'tags', $changes );
	    $uid = $this->registry->getObject('db')->lastInsertID();
	    return $uid;  
	  }
	
	  //sino lo devolvemos
	  return $isSaved;
  }	
	

  /**
  * borra un tag a partir de su ID
  * @param int $snippetID 
  */
  public function delete($id)
  {
    $this->registry->getObject('db')->deleteRecords( 'tags',' id = '.$id,'1');
    $uid = $this->registry->getObject('db')->lastInsertID();
    return $uid;  
  }

  /**
  * actualiza el nombre del setting
  * @param int $tagID 
  */
  public function update($settingID, $settingKey, $settingValue)
  {
    $changes = array();
    $changes['key'] = $settingKey;
    $changes['value'] = $settingValue;
    $this->registry->getObject('db')->updateRecords('settings', $changes," id = ".$settingID );
    $uid = $this->registry->getObject('db')->lastInsertID();
    return $uid;  
  }


  /*
  * Metodos setter
  */

  public function setKey($key){
    $this->key= $key;
  }

  public function setValue($value){
    $this->value= $value;
  }

  public function setID($ID){
    $this->ID= $ID;
  }  

  public function getID(){
    return $this->ID;
  }

  public function getValue(){
    return $this->value;
  }
	
  public function getKey(){
    return $this->key;
  }
}
?>