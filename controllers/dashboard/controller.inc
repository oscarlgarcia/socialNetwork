<?php
 /**
 * Controlador para snippets new/ browse /
 * @version 1.0
 * @author  Oscar Garcia
 */	
class Dashboardcontroller{
	
	/**
	 * Referencia del objeto registro
	 */
	private $registry;
	
	private $controller;
	
	private $action;
	
	private $parameter1;
	
	private $parameter2;
	
	/**
	 * Referencia del modelo
	 */
	private $model;
	
	/**
	 * Constructor del controlador - direct call a false cuando esta embebido a traves de otro controlador
	 * @param Registry $registry nuestro objeto registro
	 * @param bool $directCall - TRUE si lo llamamos a traves del framework, o FALSE si es por otra via
	 */
	public function __construct( Registry $registry, $directCall )
	{
		$this->registry = $registry;
		// Comprobamos unicamente si estamos logeados
		if( $this->registry->getObject('authenticate')->isLoggedIn() )
        {
	      $this->showDashboard();		
		}
		else 
		{
	       header('Location: home');    	
        }
      
	}
	
	/*
	* Metodo para mostrar el dashboard
	*
	*/
  private function showDashboard()
  {
    //Si es Admin
    if($this->registry->getObject('authenticate')->getUser()->isAdmin())
    {
      $this->registry->getObject('template')->buildFromTemplates(
        $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base')).$this->registry->getObject('constants')->getHeaderTpl(),
        $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base')).$this->registry->getObject('constants')->getDashboardTpl(),
        $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base')).$this->registry->getObject('constants')->getFooterTpl()
      );
    }else
    { //Si es usuario normal
      $this->registry->getObject('template')->buildFromTemplates(
        $this->registry->getObject('constants')->getHeaderTpl(), 
        $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_logged_base')).$this->registry->getObject('constants')->getDashboardTpl(), 
        $this->registry->getObject('constants')->getFooterTpl()
      );
    }	
  }	
}
			
?>