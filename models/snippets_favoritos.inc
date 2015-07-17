<?php

require_once ("Object.inc");
/**
 * Snippets_Favoritos model
 * - Agrega y gestiona los snippets favoritos de un usuario
 */
class Snippets_Favoritos extends Object{
	
  private $idFav;
  private $ID_User;
  private $ID_Snippets;
  private $saveable_fields = array( 'ID_User', 'ID_Snippets');

  public function __construct( Registry $registry,$ID_User,$ID_Snippets)
  {
    parent::__construct($registry);
    $this->ID_User = $ID_User;
    $this->ID_Snippets = $ID_Snippets;
  }


  public function save()
  {
    $changes = array();
	foreach( $this->saveable_fields as $field )
	{
	  $changes[ $field ] = $this->$field;
	}
	$this->registry->getObject('db')->insertRecords( 'lista_favoritos_snippets', $changes );
	//$this->registry->getObject('db')->updateRecords( 'snippets',array('totalFav' => 'totalFav+1'),' id ='.$changes['ID_Snippets']);	
  }

  public function delete()
  {
    $this->registry->getObject('db')->deleteRecords( 'lista_favoritos_snippets','ID_Snippets='.$this->ID_Snippets.' and ID_User='.$this->ID_User,'1');
    //$this->registry->getObject('db')->updateRecords( 'snippets',array('totalFav' => 'totalFav-1'),' id = '.$this->ID_Snippets);	
  }
	
}
?>