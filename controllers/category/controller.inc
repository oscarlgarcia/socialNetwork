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
			 
       $this->showFeatures(intval($this->parameter1));
          
			}
		
	}
	

  

	/*
	* Metodo para buscar las categorias desde la pantalla de admin
	*/
    private function showFeatures($offset)
    {   
      $offset = ($offset<=0)?1:$offset;
      
      if (!isset($_SESSION['category_criteria'])){
      	$this->registry->getObject('util')->storeToSession('category_criteria',"");
      }

      if (isset($_POST['search'])){
      	$this->registry->getObject('util')->storeToSession('category_criteria',$_POST['search']);
      }

      require_once( FRAMEWORK_PATH . 'models/category.inc');
	    $category = new Category( $this->registry );
	    $pagination = $category->search($offset,$_SESSION['category_criteria']);
	 
      if( $pagination->getTotalRows() == 0 )
      {
      	// no hay 
        $this->registry->getObject('template')->buildFromTemplates(
          $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
          $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'category/'.$this->registry->getObject('constants')->getNoResultsTpl(),
          $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
        );
        
        //Cargamos la busqueda
	    $this->registry->getObject('template')->getPage()->addTag('category.search',$_SESSION['category_criteria']);	
        // cargamos el total de settings
		$this->registry->getObject('template')->getPage()->addTag( 'category_count', $pagination->getTotalRows() );
      }else
      {
         if(!$pagination->checkOffset($offset))
         {
         	// invalid
            $this->registry->getObject('template')->buildFromTemplates(
              $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
              $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'category/'.$this->registry->getObject('constants')->getInvalidTpl(),
              $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
            );
         }else
	     { 
           $this->registry->getObject('template')->buildFromTemplates(
	        $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
	        $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'category/'.$this->registry->getObject('constants')->getListTpl(),
	        $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
	       );
		
		  //cargamos la info de cada snippet
		  $this->registry->getObject('template')->getPage()->addTag( 'category', array( 'SQL', $pagination->getCache() ) );

         $this->registry->getObject('template')->getPage()->addTag( 'category_image_path', $this->registry->getSetting('language_path') );
		  //Cargamos la busqueda
	      $this->registry->getObject('template')->getPage()->addTag( 'category.search',$_SESSION['category_criteria']);	
          // cargamos el total de settings
		  $this->registry->getObject('template')->getPage()->addTag( 'category_count', $pagination->getTotalRows() );		
		  $pagination->showPagination($this->controller,$this->action,$this->parameter1,$this->parameter2);
	    }		
      }
    }



}
			
?>