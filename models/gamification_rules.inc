<?php

require_once ("Object.inc");
/**
* Clase Modelo para gestionar los datos de la tabla
* Gamification_Rules
*/
class Gamification_Rules extends Object{
	
  private $id;
  private $eventName;
  private $idBadge;
  private $threshold;
  private $experiencePoints;
  private $reputationPoints;
   	
  /**
  * Guarda un objeto Gamification_Rules y lo retorna como objeto
  * return objeto Gamification_Rules 
  */
  public function save($rule){
     //TODO poner logica de asignacion de valores
	 $this->registry->getObject('db')->insertRecords('gamification_rules',$ruleArray );	
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

}

?>