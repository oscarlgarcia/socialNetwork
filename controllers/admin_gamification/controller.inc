<?php
 /**
 * Controlador para administracion de Gamificacion  browse / edit / delete / ban
 * @version 1.0
 * @author  Oscar Garcia
 */	
class Admin_gamificationcontroller{
	
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
		// Comprobamos unicamente si estamos logeados
		if( $this->registry->getObject('authenticate')->isLoggedIn() )
      {
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
			  
			   switch( $urlBits[1] )
				{
					
				  case 'search':
  			    $this->search(intval($this->parameter1));
				    break;

				  case 'add':
				    $this->add();
					  break;	

				  case 'image_browse':
            $this->image_browse();
            break;

          case 'image_upload':
			      $this->upload();
			      break;

				  case 'register':
				  	$this->register();
					  break;

				 case 'delete':
				    $this->delete(intval($this->parameter1));
				    break;

				}
				
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
	* Metodo para buscar las categorias desde la pantalla de admin
	*/
    private function search($offset)
    {   
      $offset = ($offset<=0)?1:$offset;
      
      if (!isset($_SESSION['rule_criteria'])){
      	$this->registry->getObject('util')->storeToSession('rule_criteria',"");
      }

      if (isset($_POST['search'])){
      	$this->registry->getObject('util')->storeToSession('rule_criteria',$_POST['search']);
      }

      require_once( FRAMEWORK_PATH . 'models/gamification_rules.inc');
	    $rule = new Category( $this->registry );
	    $pagination = $rule->search($offset,$_SESSION['rule_criteria']);
	 
      if( $pagination->getTotalRows() == 0 )
      {
      	// no hay 
        $this->registry->getObject('template')->buildFromTemplates(
          $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
          $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'category/'.$this->registry->getObject('constants')->getNoResultsTpl(),
          $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
        );
        
        //Cargamos la busqueda
	      $this->registry->getObject('template')->getPage()->addTag('category.search',$_SESSION['rule_criteria']);	
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
          $this->registry->getObject('template')->getPage()->addTag( 'category.search',$_SESSION['rule_criteria']);	
          // cargamos el total de settings
		      $this->registry->getObject('template')->getPage()->addTag( 'category_count', $pagination->getTotalRows() );		
		      $pagination->showPagination($this->controller,$this->action,$this->parameter1,$this->parameter2);
	      }		
      }
    }


  /*
  * Metodo que redirecciona a la plantilla de add
  *
  **/
  private function add()
  {
    $this->registry->getObject('template')->buildFromTemplates(
	  	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
	  	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'category/'.$this->registry->getObject('constants')->getAddTpl(),
	  	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
	  	);
    
      $this->registry->getObject('template')->getPage()->addTag('error_msg','error-msg'); 
      $this->registry->getObject('template')->getPage()->addTag('error_text',''); 
      $this->registry->getObject('template')->getPage()->addTag('categoryName','');	
	  $this->registry->getObject('template')->getPage()->addTag('categoryDescription','');
	  $this->registry->getObject('template')->getPage()->addTag('categoryImage','');
  }

 /*
  * Metodo que guarda el seeting en BBDD 
  * 
  */
  private function register(){
 
    require_once FRAMEWORK_PATH . 'controllers/admin_category/registrationcontroller.inc';
    require_once( FRAMEWORK_PATH . 'models/category.inc');
     $category = new Category( $this->registry );
     if ($category->canSave($_POST['categoryName']))
     {
       $rc = new Registrationcontroller( $this->registry,$this->registry->getObject('authenticate')->getUser()->getUserID());
	   header('Location: search'); 
     }else
     {
       $this->registry->getObject('template')->buildFromTemplates(
    	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
    	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'category/'.$this->registry->getObject('constants')->getAddTpl(),
    	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
    	);
       $this->registry->getObject('template')->getPage()->addTag('error_msg',' ');	
	   $this->registry->getObject('template')->getPage()->addTag('error_text','La categoria ya existe');
	   $this->registry->getObject('template')->getPage()->addTag('categoryName',$_POST['categoryName']);	
	   $this->registry->getObject('template')->getPage()->addTag('categoryDescription',$_POST['categoryDescription']);
	   $this->registry->getObject('template')->getPage()->addTag('categoryImage',$_POST['categoryImage']);
     }
	  	
  }
 
 /*
  * Metodo para subir imagenes
  * TODO poner en lib
  * 
  */
  private function upload()
  {
    require_once( FRAMEWORK_PATH . 'lib/imageUpload/Upload.class.inc');
    $upload = new Upload($this->registry);
  }

  /*
  * Metodo para buscar imagenes
  */
   private function image_browse(){
     require_once( FRAMEWORK_PATH . 'models/media.inc');   
     $media = new Media($this->registry);
     echo $media->search($_POST['image_search']);
     exit();
   }

  /*
  * Metodo que borra la categoria
  *
  **/
  private function delete($catID)
  {
    require_once( FRAMEWORK_PATH . 'models/category.inc');
    $category = new Category( $this->registry );

    if ($category->canErase($catID) )
    {
       $category->delete( $catID );  
    }
    header('Location: /socialNetwork/admin_category/search');
  } 


}
			
?>