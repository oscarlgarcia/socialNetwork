<?php

require_once ("Object.inc");

/**
* Clase Modelo para gestionar los datos de la tabla
* badges_achieved
*/
class Badges_Achieved extends Object{
	
   private $id;
   private $idBadge;
   private $idUser;
	
	public function save($idBadge,$idUser)
	{
	  $badge['ID_Badge']=$idBadge;
    $badge['ID_User']=$idUser;
    $badge['showed']=0;
    $this->registry->getObject('db')->insertRecords( 'badges_achieved',$badge);	
  } 
	
}

?>