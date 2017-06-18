<?php
 /**
 * Controlador para administracion de Category  browse / edit / delete / ban
 * @version 1.0
 * @author  Oscar Garcia
 */	
class Categorycontroller{
	
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
		// leemos el url para obtener el action
		$urlBits = $this->registry->getObject('url')->getURLBits();

	    //   $urlBits[0] -> Controlador
		  //   $urlBits[1] -> Action
		  //   $urlBits[2] -> Parametro 1
		  //   $urlBits[3] -> Parametro 2
		  $this->controller= $urlBits[0];
   	  if( isset( $urlBits[1] ) )   // Si viene algun action debemos comprobar si existe
  		{
		    $this->action=$urlBits[1]; // asignamos el action 
			   
			  if(isset( $urlBits[2] )) { // Comprobamos el parametro 1
  		 	  $this->parameter1= $urlBits[2];	
  		  }
			  
			  if(isset( $urlBits[3] )) {  // Comprobamos el parametro 2
  		 	  $this->parameter2= $urlBits[3];	
  		  }
			 
          $this->showFeatures($this->action);
          
			}
		
	}
	

  

	/*
	* Metodo para buscar las categorias desde la pantalla de admin
	*/
    private function showFeatures($categoryName)
    {   
     
       require_once( FRAMEWORK_PATH . 'models/category.inc');
       require_once( FRAMEWORK_PATH . 'models/page.inc');
       $category = new Category( $this->registry );
       $page= new Pages($this->registry);
       
       if ($category->getCategoryByName($categoryName))
       {
         $this->registry->getObject('template')->buildFromTemplates(
           $this->registry->getObject('constants')->getHeaderTpl(), 
           $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_logged_base') ).'category/'.$this->registry->getObject('constants')->getListTpl(),
           $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_logged_base') ).$this->registry->getObject('constants')->getFooterTpl()
          );
        
        $this->registry->getObject('template')->getPage()->addTag('category_name',$category->getName());
        $this->registry->getObject('template')->getPage()->addTag('category_description',$category->getDescription());
        $this->registry->getObject('template')->getPage()->addTag('category_image',$category->getImageName());
        $this->registry->getObject('template')->getPage()->addTag('category_image_front',$category->getImageNameFront());

        //buscamos tutoriales
        $pagination = $page->getListPageByCategoryType($category->getId(),1);
     $this->registry->getObject('template')->getPage()->addTag('category_tuts',array( 'SQL', $pagination->getCache()));

       }
        
      
    }



}
			
?>