<?php
 /**
 * Controlador para admisnitracion de CMS browse / edit / delete / ban
 * @version 1.0
 * @author  Oscar Garcia
 */	
class Admin_cmscontroller{
	
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
					case 'browse':
					  $this->browse();
					  break;
					  
				   case 'preview':
  				    $this->browse();
					  break;

					case 'edit':
					  $this->view(intval($this->parameter1));
					  break;

          case 'update':
            $this->update(intval($this->parameter1));
            break;

				  case 'register':
				    $this->register();
				    break;

					default:
					  $this->add();
					  break;
				}
				
			}else
		   {
		      $this->add();
		   }
		   
		}else 
		{
	           // sino esta logeado redirecciona
        header('Location: ../home');      	
      }
      
	}
	

  /*
  * Metodo para ver una page
  *
  *
  */
	function view($id_page){
    require_once( FRAMEWORK_PATH . 'models/page.inc'); 
    require_once( FRAMEWORK_PATH . 'models/page_type.inc'); 
    require_once( FRAMEWORK_PATH . 'models/category.inc');
    require_once( FRAMEWORK_PATH . 'models/page_level.inc');
    $categories = new Category( $this->registry );
    $pages = new Pages( $this->registry );
    $types = new PageType( $this->registry );
    $level = new PageLevel( $this->registry );

    $this->registry->getObject('template')->buildFromTemplates(
    	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base')).$this->registry->getObject('constants')->getHeaderTpl(), 
     	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'cms/'.$this->registry->getObject('constants')->getViewTpl(),
     	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
    );

    if ($pages->getPage($id_page)){
        
      // Cargamos los datos
      $pagination = $categories->listCategorySelected($pages->getCategory()); 
      $typesPagination = $types->listTypesSelected($pages->getType());
      $this->registry->getObject('template')->getPage()->addTag( 'id', $pages->getId());
      $this->registry->getObject('template')->getPage()->addTag( 'title', $pages->getTitle());
      $this->registry->getObject('template')->getPage()->addTag( 'url',  $pages->getUrl());
      $this->registry->getObject('template')->getPage()->addTag( 'body', $pages->getBody());
      $this->registry->getObject('template')->getPage()->addTag( 'parent', $pages->getParent());
      $this->registry->getObject('template')->getPage()->addTag( 'keywords', $pages->getKeywordsSEO());
      $this->registry->getObject('template')->getPage()->addTag( 'category', array( 'SQL', $pagination->getCache() ) ); 
      $pagination = $level->listLevelSelected($pages->getLevel());
      $this->registry->getObject('template')->getPage()->addTag( 'level', array( 'SQL', $pagination->getCache() ) ); 

      if ($pages->isPublished()) {
       $this->registry->getObject('template')->getPage()->addTag('page_publish_yes', 'active');
       $this->registry->getObject('template')->getPage()->addTag('page_publish_yes_selected','checked');
       $this->registry->getObject('template')->getPage()->addTag('page_publish_no','');
       $this->registry->getObject('template')->getPage()->addTag('page_publish_no_selected','');
      }else{
       $this->registry->getObject('template')->getPage()->addTag('page_publish_no', 'active');
       $this->registry->getObject('template')->getPage()->addTag('page_publish_no_selected','checked');
       $this->registry->getObject('template')->getPage()->addTag('page_publish_yes', '');
       $this->registry->getObject('template')->getPage()->addTag('page_publish_yes_selected','');
      }
      $this->registry->getObject('template')->getPage()->addTag( 'type', array( 'SQL', $typesPagination->getCache() ) ); 
      $this->registry->getObject('template')->getPage()->addTag('error_msg','error-msg'); 
      $this->registry->getObject('template')->getPage()->addTag('error_text',''); 
      $this->registry->getObject('template')->getPage()->addTag( 'description', $pages->getDescriptionSEO());
      $this->registry->getObject('template')->getPage()->addTag('page_tree',$pages->listPagesAsTree());
    }
  }


  /*
  * Metodo para actualizar una page
  *
  */
  function update($id_page){
  

      require_once( FRAMEWORK_PATH . 'models/page.inc'); 
      $page = new Pages( $this->registry );
      $page->setId($id_page);
      $page->setTitle( htmlentities($this->registry->getObject('db')->sanitizeData( $_POST['title'] ),ENT_COMPAT,'UTF-8') );
      $page->setUrl( htmlentities($this->registry->getObject('db')->sanitizeData( $_POST['url']),ENT_COMPAT,'UTF-8'));
      $page->setBody( $this->registry->getObject('db')->sanitizeData( $_POST['editor'] ) ); 
      $page->setParent( $this->registry->getObject('db')->sanitizeData($_POST['parent']));
      $page->setPublished($this->registry->getObject('db')->sanitizeData($_POST['publish']));
      $page->setOrdenation(0);     
      $page->setCreated(date("Y-m-d H:i:s")); // fecha de ahora  
      $page->setUpdated(date("Y-m-d H:i:s")); // fecha de ahora
      $page->setLevel($this->registry->getObject('db')->sanitizeData($_POST['level']));
      $page->setType($this->registry->getObject('db')->sanitizeData($_POST['type']));
      $page->setKeywordsSEO( $this->registry->getObject('db')->sanitizeData($_POST['keywords']));
      $page->setDescriptionSEO( $this->registry->getObject('db')->sanitizeData($_POST['description']));
      $page->setCategory($this->registry->getObject('db')->sanitizeData($_POST['category']));
      $page->update();

      


    require_once FRAMEWORK_PATH . 'controllers/admin_cms/registrationcontroller.inc';
    $rc = new Registrationcontroller( $this->registry,$this->registry->getObject('authenticate')->getUser()->getUserID(),$id_page);
    $this->browse();
  }


  /*
	* Metodo para buscar pages
	*
	*/
    private function browse()
    {   		
	  require_once( FRAMEWORK_PATH . 'models/page.inc');   
      $pages = new Pages( $this->registry );
      $this->registry->getObject('template')->buildFromTemplates(
      	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base')).$this->registry->getObject('constants')->getHeaderTpl(), 
      	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'cms/'.$this->registry->getObject('constants')->getListTpl(),
      	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
      	);
      $this->registry->getObject('template')->getPage()->addTag( 'page_tree', $pages->listPagesAsTree() );
    }	


  /*
   Metodo para agregar paginas    
  */
  private function add()
  {
    require_once( FRAMEWORK_PATH . 'models/category.inc');
    require_once( FRAMEWORK_PATH . 'models/page.inc');
    require_once( FRAMEWORK_PATH . 'models/page_type.inc');
    require_once( FRAMEWORK_PATH . 'models/media.inc');
    require_once( FRAMEWORK_PATH . 'models/page_level.inc');
    $categories = new Category( $this->registry );
	  $pagination = $categories->listCategory();
    $this->registry->getObject('template')->buildFromTemplates(
    	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
    	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'cms/'.$this->registry->getObject('constants')->getAddTpl(),
    	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
    	);
    $this->registry->getObject('template')->getPage()->addTag('error_msg','error-msg');	
	  $this->registry->getObject('template')->getPage()->addTag('error_text','');	
    $this->registry->getObject('template')->getPage()->addTag( 'category', array( 'SQL', $pagination->getCache() ) ); 

    $pages = new Pages( $this->registry );
    $this->registry->getObject('template')->getPage()->addTag( 'page_tree', $pages->listPagesAsTree() );
    $types = new PageType( $this->registry );
    $pagination = $types->listTypes();
    $this->registry->getObject('template')->getPage()->addTag( 'type', array( 'SQL', $pagination->getCache() ) );
  
        
    $level = new PageLevel( $this->registry );
    $pagination = $level->listLevel();
    $this->registry->getObject('template')->getPage()->addTag( 'level', array( 'SQL', $pagination->getCache() ) ); 
  }
 
 /*
  * Metodo que guarda la pagina en BBDD 
  * 
  */
  private function register(){
 
    require_once FRAMEWORK_PATH . 'controllers/admin_cms/registrationcontroller.inc';
	  $rc = new Registrationcontroller( $this->registry,$this->registry->getObject('authenticate')->getUser()->getUserID());
	  header('Location: add');  	
  }
  
}		
?>