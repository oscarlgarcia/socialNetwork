<?php

class Object{

  public $registry;
  public $paginatedResult;
	
  public function __construct( Registry $registry )
  {
    require_once( FRAMEWORK_PATH . 'lib/pagination/pagination.class.inc');
    $this->paginatedResult = new Pagination( $registry );
    $this->registry = $registry;
  }

  
  /*
  * Cambia los tags de la bd de PAge de code para mostrar el contenido
  */
  protected function replaceCodemirror($data){

  	$toFind[] = $this->registry->getSetting($this->registry->getObject('constants')->getConstant('code_open'));
  	$toFind[] = $this->registry->getSetting($this->registry->getObject('constants')->getConstant('code_close'));
  	$toClose[] = $this->registry->getSetting($this->registry->getObject('constants')->getConstant('code_open_replace'));
  	$toClose[] = $this->registry->getSetting($this->registry->getObject('constants')->getConstant('code_close_replace'));
    return str_replace($toFind,$toClose,$data);

  }

  

	
}

?>