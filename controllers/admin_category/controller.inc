<?php
 /**
 * Controlador para administracion de Category  browse / edit / delete / ban
 * @version 1.0
 * @author  Oscar Garcia
 */	
class Admin_categorycontroller{
	
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
                  
        case 'edit':
				    $this->edit(intval($this->parameter1));
					  break;	

				case 'update':
				    $this->update(intval($this->parameter1));
					  break;	

				  case 'register':
				  	$this->register();
					  break;

				 case 'ban':
				    $this->ban(intval($this->parameter1));
				    break;

				  case 'publish':
				    $this->publish(intval($this->parameter1));
				    break;

				  case 'delete':
				    $this->delete(intval($this->parameter1));
				    break;

				}
			}
		}else 
		{
	    
          // sino esta logeado redirecciona
	      header('Location: ../../home');  
        }  
	}
	

  /*
  * Metodo que inhabilita la categoria
  *
  **/
  private function ban($categoryID)
  {
    require_once( FRAMEWORK_PATH . 'models/category.inc');
	$category = new Category( $this->registry );
	$data = $category->updateStatus( $categoryID, 5);
	header('Location: /socialNetwork/admin_category/search'); 	
  } 

 /*
  * Metodo que habilita la categoria
  *
  **/
  private function publish($categoryID)
  {
    require_once( FRAMEWORK_PATH . 'models/category.inc');
	$category = new Category( $this->registry );
	$data = $category->updateStatus( $categoryID, 4);
	header('Location: /socialNetwork/admin_category/search'); 	
  } 


	/*
	* Metodo para buscar las categorias desde la pantalla de admin
	*/
    private function search($offset)
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
	  $this->registry->getObject('template')->getPage()->addTag('image','');
  }

  /*
  * Metodo que redirecciona a la plantilla de edit
  *
  **/
  private function edit($categoryID)
  {
    $this->registry->getObject('template')->buildFromTemplates(
	  	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
	  	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'category/'.$this->registry->getObject('constants')->getViewTpl(),
	  	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
	  	);
   
    require_once FRAMEWORK_PATH . 'controllers/admin_category/registrationcontroller.inc';
    require_once( FRAMEWORK_PATH . 'models/category.inc');
    
    $category = new Category( $this->registry );
    $category->getCategory($categoryID);

    $this->registry->getObject('template')->getPage()->addTag('error_msg','error-msg'); 
    $this->registry->getObject('template')->getPage()->addTag('error_text',''); 
    $this->registry->getObject('template')->getPage()->addTag('categoryID',$category->getID());	
    $this->registry->getObject('template')->getPage()->addTag('categoryName',$category->getName());	
	  $this->registry->getObject('template')->getPage()->addTag('categoryDescription',$category->getDescription());
	  $this->registry->getObject('template')->getPage()->addTag('image',$category->getImageName());
    $this->registry->getObject('template')->getPage()->addTag('image_front',$category->getImageNameFront());

  }


/*
  * Metodo que actualiza la categoria 
  * 
  */
  private function update($catID)
  {
    require_once( FRAMEWORK_PATH . 'models/category.inc');
    $category = new Category( $this->registry );
    $category->update($catID,$_POST['categoryName'],$_POST['categoryDescription'],$_POST['type'],$_POST['image'],$_POST['image_front']);
	header('Location: ../search'); 
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
	   $this->registry->getObject('template')->getPage()->addTag('image',$_POST['image']);
     }
	  	
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