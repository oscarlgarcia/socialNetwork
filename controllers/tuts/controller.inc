<?php
 /**
 * Controlador para Tutoriales browse /
 * @version 1.0
 * @author  Oscar Garcia
 */	
class Tutscontroller{
	
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
		require_once( FRAMEWORK_PATH . 'models/category.inc');
		$this->registry = $registry;
		// leemos el url para obtener el action
		$urlBits = $this->registry->getObject('url')->getURLBits();
        
		// Comprobamos unicamente si estamos logeados
		if( $this->registry->getObject('authenticate')->isLoggedIn() )
        {
	      //   $urlBits[0] -> Controlador
		  //   $urlBits[1] -> Action
		  //   $urlBits[2] -> Parametro 1
		  //   $urlBits[3] -> Parametro 2
		  $this->controller= $urlBits[0];
   		  if( isset( $urlBits[1] ) )   // Si viene algun action 
  		  {
  		  	$this->action = $urlBits[1]; // asignamos el action 

  		  	if(isset( $urlBits[2] )) { // Comprobamos si hay el parametro 1
  		  	  $this->parameter1 = $urlBits[2];	
  		  	}

			// debemos comprobar si existe la categoria
            $category = new Category( $this->registry );
			if($category->getCategory( $this->action )){
              $this->category($category,$this->parameter1);
			}else{

			  // si no existe es por que es una URL de una pagina
			  $this->showTut($this->action);
			}	
				
		  }else {
		   	
		   	// Si no pasamos action mostramos todas las categorias
		    $this->browse(1);
		  }
		   
		}else 
		{
	       // sino esta logeado redirecciona
	       $this->registry->getObject('template')->buildFromTemplates(
	       	$this->registry->getObject('constants')->getHeaderTpl(), 
	       	$this->registry->getObject('constants')->getMainTpl(), 
	       	$this->registry->getObject('constants')->getFooterTpl()
	       	);   	
      }
      
	}
	
	
	
   /*
	* Metodo para buscar todos los 
	* Tutoriales de todas las categorias
	*
	*
	*/
    private function browse($offset=1)
    {   
      
      $offset=($offset<=0)?1:$offset;
	  $this->registry->getObject('template')->buildFromTemplates(
	    $this->registry->getObject('constants')->getHeaderTpl(), 
		$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_logged_base')).'tuts/'.$this->registry->getObject('constants')->getMainTpl(), 
			$this->registry->getObject('constants')->getFooterTpl()
	  );	

	  //cargamos el total de snippet por categoria
	  require_once( FRAMEWORK_PATH . 'models/category.inc');
	  $category = new Category( $this->registry );
	  $pagination =$category->countTutsByCategory();
	  $this->registry->getObject('template')->getPage()->addTag( 'langs', array( 'SQL', $pagination->getCache() ) );

  }	


   /*
	* Metodo para buscar por categoria
	* y por nivel
	*/
    private function category($category , $levelName = '')
    {   
  	  require_once( FRAMEWORK_PATH . 'models/page_level.inc');
	  
	  if ( $category->getID() == null ){
        
        $this->registry->getObject('template')->buildFromTemplates(
	    	$this->registry->getObject('constants')->getHeaderTpl(), 
	    	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_logged_base')).'404/'.$this->registry->getObject('constants')->get404Tpl(), 
	    	$this->registry->getObject('constants')->getFooterTpl()
	    	);

	  }else{
        
	  	// Si viene levelName 
	  	if(!isset($levelName)){

	  	  // mostramos plantilla de cursos de ese nivel
          $this->registry->getObject('template')->buildFromTemplates(
		    $this->registry->getObject('constants')->getHeaderTpl(), 
		    $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_logged_base')).'tuts/'.$this->registry->getObject('constants')->getCategoryTpl(), 
		    $this->registry->getObject('constants')->getFooterTpl()
		  );

          // cargamos los niveles que tenga
		  $pagination = $category->tutsByLevelCategory($category->getName());
          $this->registry->getObject('template')->getPage()->addTag( 'langs', array( 'SQL', $pagination->getCache() ) ); 

	  	}else{
          // sino mostramos plantilla de todos los niveles
          $this->registry->getObject('template')->buildFromTemplates(
		    $this->registry->getObject('constants')->getHeaderTpl(), 
		    $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_logged_base')).'tuts/'.$this->registry->getObject('constants')->getListTpl(), 
		    $this->registry->getObject('constants')->getFooterTpl()
		  );

		  // cargamos los tutoriales para ese nivel
		  $pagination = $category->getTutsByLevelCategory($category->getName(),$levelName);
          $this->registry->getObject('template')->getPage()->addTag( 'tuts', array( 'SQL', $pagination->getCache() ) );

          $this->registry->getObject('template')->getPage()->addTag( 'category_level', $levelName);

	  	}
	  	
        $this->registry->getObject('template')->getPage()->addTag( 'category_image', $category->getImageName() ); 
        $this->registry->getObject('template')->getPage()->addTag( 'category_name', $category->getName() ); 
        $this->registry->getObject('template')->getPage()->addTag( 'category_description', $category->getDescription() ); 
        
	  }

	  
      

    }



    /*
	* Metodo para buscar el tutorial
	*
	*/
    private function showTut($url){
      
      require_once( FRAMEWORK_PATH . 'models/page.inc');
      require_once( FRAMEWORK_PATH . 'models/tags_page.inc');
      $page = new Pages( $this->registry );
      if (!$page->getPageByURL($url)){
        $this->registry->getObject('template')->buildFromTemplates(
	      $this->registry->getObject('constants')->getHeaderTpl(), 
	      $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_logged_base')).'404/'.$this->registry->getObject('constants')->get404Tpl(), 
	      $this->registry->getObject('constants')->getFooterTpl()
	    );

      }else{

      	// mostramos plantilla de pagina
        $this->registry->getObject('template')->buildFromTemplates(
		  $this->registry->getObject('constants')->getHeaderTpl(), 
		  $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_logged_base')).'tuts/'.$this->registry->getObject('constants')->getViewTpl(), 
		  $this->registry->getObject('constants')->getFooterTpl()
		);
        
        $this->registry->getObject('template')->getPage()->addTag( 'category_name', $page->getCategory()->getName()); 
        $this->registry->getObject('template')->getPage()->addTag( 'level_name', $page->getLevel()->getName() ); 
        $this->registry->getObject('template')->getPage()->addTag( 'title', $page->getTitle() ); 
        $this->registry->getObject('template')->getPage()->addTag( 'body', $page->getBody() ); 
      

        // Cargamos los tags
      $tags= new Tags_Page( $this->registry );
      $pagination = $tags->getRelatedPage($page->getID());
       if( $pagination->getNumRowsPage() > 0 )
	   {
         $this->registry->getObject('template')->getPage()->addTag( 'related', array( 'SQL', $pagination->getCache() ) );
       }


      }


       

    }


  
	
}
			
?>