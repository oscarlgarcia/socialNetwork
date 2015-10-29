<?php

require_once ("Object.inc");
/**
* Clase Modelo para gestionar los datos de la tabla
* Gamification_Rules
*/
class Gamification_Rules extends Object{
	
  private $id;
  private $eventName;
  private $id_Badge;
  private $threshold;
  private $experience_points;
  private $reputation_points;
  private $level_points;
  private $saveable_fields = array( 'eventName', 'id_Badge','threshold','experience_points','reputation_points','level_points'); 
  private $limit = 10; //poner en config
   	

  /**
  * Guarda un objeto Gamification_Rules y lo retorna como objeto
  * return objeto Gamification_Rules 
  */
  public function save()
  {
    $changes = array();
    foreach( $this->saveable_fields as $field )
    {
      $changes[ $field ] = $this->$field;
    }
    $this->registry->getObject('db')->insertRecords( 'gamification_rules', $changes );
    $uid = $this->registry->getObject('db')->lastInsertID();
    return $uid;  
  } 

	
  /**
  * Busca reglas relacionadas con el evento
  * Return un array con las reglas encontradas
  * 
  */
  public function findRuleByEvent($event) {
    
    $sql = "SELECT * FROM gamification_rules WHERE eventName='{$event}'";
    $this->registry->getObject('db')->executeQuery($sql);
    $rows=array();
	while( $row = $this->registry->getObject('db')->getRows() )
    { 
      $rows[] = $row;
    }      
    return $rows;
  }



  /**
   * Genera lista de reglas  que coinciden con el criterio pasado paginados 
   * Este metodo se llama en Admin_gamification desde el administrador
   * Devuelve un ResulSet con la siguiente informacion en caché:
   * ID de la regla
   * evento que la dispara
   * Id del Badge que se gana
   * Umbral que se debe alcanzar
   * puntos de experiencia
   * Puntos de reputacion
   * Puntos de nivel
   * @param int $offset, pagina de la busqueda
   * @param String $criteria, cadena de busqueda 
   * @return Object pagination object
   */
  public function search($offset = 1, $criteria = "")
  {
    $this->paginatedResult->setLimit($this->limit);
    $this->paginatedResult->setOffset($offset - 1);
    $query="SELECT r.ID as ID, r.eventName as name, r.threshold as threshold, r.experience_points as xp, r.reputation_points as rp, r.level_points as lp, m.url as image from gamification_rules r inner join badges b on r.ID_Badge = b.ID inner join media m on m.ID = b.media_id where r.eventName like '%".$criteria."%'";
    $this->paginatedResult->setQuery( $query );
    $this->paginatedResult->setMethod( 'cache' );
    $this->paginatedResult->generatePagination();
    return $this->paginatedResult;
  }



  /**
  * borra una regla a partir de su ID
  * @param int $ruleID 
  */
  public function delete($ruleID)
  {
    $this->registry->getObject('db')->deleteRecords( 'gamification_rules',' id = '.$ruleID,'1');
    $uid = $this->registry->getObject('db')->lastInsertID();
    return $uid;  
  }


  /**
  * Metodo que valida si una regla ya se ha guardado
  * @param $eventName, nombre del evento
  * @param $threshold, umbral de activacion
  * @return true, si el nombre puede guardarse, false si no
  */
  public function canSave($eventName, $threshold){
    $query = "SELECT ID FROM gamification_rules where eventName = '".$eventName."' and threshold = ".$threshold;
    $this->registry->getObject('db')->executeQuery( $query );
    if( $this->registry->getObject('db')->numRows() > 0 )
      return false;
    else
      return true;
  }


  public function getID(){
    return $this->id;
  }

  public function setID($value){
    $this->id = $value;
  }


  public function getEventName(){
    return $this->eventName;
  }

  public function setEventName($value){
    $this->eventName = $value;
  }

  public function getIDBadge(){
    return $this->id_Badge;
  }

  public function setIDBadge($value){
    $this->id_Badge = $value;
  }

  public function getThreshold(){
    return $this->threshold;
  }

  public function setThreshold($value){
    $this->threshold = $value;
  }

  public function getExperiencePoints(){
    return $this->experience_points;
  }

  public function setExperiencePoints($value){
    $this->experience_points = $value;
  }

  public function getReputationPoints(){
    return $this->reputation_points;
  }

  public function setReputationPoints($value){
    $this->reputation_points = $value;
  }

  public function getLevel_points(){
    return $this->level_points;
  }

  public function setLevel_points($value){
    $this->level_points = $value;
  }




}

?>