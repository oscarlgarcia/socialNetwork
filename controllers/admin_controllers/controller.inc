<?php
 /**
 * Controlador para administracion de Controladores del site  browse / edit / delete 
 * @version 1.0
 * @author  Oscar Garcia
 */	
class Admin_controllerscontroller{
	
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
                  
                  case 'view':
				    $this->view(intval($this->parameter1));
					break;

				  case 'add':
				    $this->add();
					break;

				  case 'register':
				    $this->register();
					break;

				  case 'publish':
				    $this->publish(intval($this->parameter1));
				    break;

				  case 'ban':
				    $this->ban(intval($this->parameter1));
				    break;

				  case 'delete':
				    $this->delete(intval($this->parameter1));
				    break;
                  
                  default:
                    $this->search(1);  
				}
				
			}else
		   {
		     $this->search(1);
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
	* Metodo para buscar Controladores desde la pantalla de admin
	*/
    private function search($offset)
    {   
      $offset = ($offset<=0)?1:$offset;
      
      if (!isset($_SESSION['controller_criteria'])){
      	$this->registry->getObject('util')->storeToSession('controller_criteria',"");
      }

      if (isset($_POST['search'])){
      	$this->registry->getObject('util')->storeToSession('controller_criteria',$_POST['search']);
      }

      require_once( FRAMEWORK_PATH . 'models/controller.inc');
	  $controllers = new Controller( $this->registry );
	  $pagination = $controllers->search($offset , $_SESSION['controller_criteria']);
	 
      if(!$pagination->checkOffset($offset) )
      {
        $this->registry->getObject('template')->buildFromTemplates(
          $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
          $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'controllers/'.$this->registry->getObject('constants')->getNoResultsTpl(),
          $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
        );
        
        //Cargamos la busqueda
	    $this->registry->getObject('template')->getPage()->addTag('controller.search',$_SESSION['controller_criteria']);	
        // cargamos el total de snippets
		$this->registry->getObject('template')->getPage()->addTag( 'controller_count', $pagination->getTotalRows() );	

      }
	  else
	  { 
        $this->registry->getObject('template')->buildFromTemplates(
	    $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
	    $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'controllers/'.$this->registry->getObject('constants')->getListTpl(),
	    $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
	    );
		//cargamos la info de cada snippet
		$this->registry->getObject('template')->getPage()->addTag( 'controllers', array( 'SQL', $pagination->getCache() ) );
         
		//Cargamos la busqueda
	    $this->registry->getObject('template')->getPage()->addTag( 'controller.search',$_SESSION['controller_criteria']);	
        // cargamos el total de snippets
		$this->registry->getObject('template')->getPage()->addTag( 'controller_count', $pagination->getTotalRows() );		
		$pagination->showPagination($this->controller,$this->action,$this->parameter1,$this->parameter2);
	  }		
    }


  /*
   Metodo para agregar un controlador    
  */
  private function add()
  {
    require_once( FRAMEWORK_PATH . 'models/controller.inc');
    $this->registry->getObject('template')->buildFromTemplates(
    	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
    	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'controllers/'.$this->registry->getObject('constants')->getAddTpl(),
    	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
    	);
    $this->registry->getObject('template')->getPage()->addTag('error_msg','error-msg');	
	$this->registry->getObject('template')->getPage()->addTag('error_text','');
	$this->registry->getObject('template')->getPage()->addTag('controller_name','');	
	$this->registry->getObject('template')->getPage()->addTag('controller_description','');
  }
 
  
  /*
  * Metodo que guarda la pagina en BBDD 
  * 
  */
  private function register(){
 
     require_once FRAMEWORK_PATH . 'controllers/admin_controllers/registrationcontroller.inc';
     require_once( FRAMEWORK_PATH . 'models/controller.inc');
     $controller = new Controller( $this->registry );
     if ($controller->canSave($_POST['controller_name']))
     {
       $rc = new Registrationcontroller( $this->registry,$this->registry->getObject('authenticate')->getUser()->getUserID());
	   header('Location: search'); 
     }else
     {
       $this->registry->getObject('template')->buildFromTemplates(
    	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
    	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'controllers/'.$this->registry->getObject('constants')->getAddTpl(),
    	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
    	);
       $this->registry->getObject('template')->getPage()->addTag('error_msg',' ');	
	   $this->registry->getObject('template')->getPage()->addTag('error_text','El controlador ya existe');
	   $this->registry->getObject('template')->getPage()->addTag('controller_name',$_POST['controller_name']);	
	   $this->registry->getObject('template')->getPage()->addTag('controller_description',$_POST['controller_description']);
     }
	  	
  }
 
  
  /*
  * Metodo que borra el controlador
  *
  **/
  private function ban($controllerID)
  {
    require_once( FRAMEWORK_PATH . 'models/controller.inc');
	$controller = new Controller( $this->registry );
	$data = $controller->updateStatus( $controllerID, 5);
	header('Location: /socialNetwork/admin_controllers/search'); 	
  } 
 

  /*
  * Metodo para habilitar el controlador
  */
  public function publish($controllerID){
    require_once( FRAMEWORK_PATH . 'models/controller.inc');
	$controller = new Controller( $this->registry );
	$data = $controller->updateStatus( $controllerID, 4);
	header('Location: /socialNetwork/admin_controllers/search');
  }

  /*
  * Metodo para borrar el controlador
  */
  public function delete($controllerID){
    require_once( FRAMEWORK_PATH . 'models/controller.inc');
	$controller = new Controller( $this->registry );
	$deleted = $controller->delete($controllerID);
	header('Location: /socialNetwork/admin_controllers/search');
  }
 
 
	
}
			
?>