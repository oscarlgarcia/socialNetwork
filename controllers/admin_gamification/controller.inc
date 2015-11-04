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
	* Metodo para buscar las reglas desde la pantalla de admin
	*/
    private function search($offset)
    {   
      $offset = ($offset<=0)?1:$offset;
      
      if (!isset($_SESSION['gamification_criteria'])){
      	$this->registry->getObject('util')->storeToSession('gamification_criteria',"");
      }

      if (isset($_POST['search'])){
      	$this->registry->getObject('util')->storeToSession('gamification_criteria',$_POST['search']);
      }

      require_once( FRAMEWORK_PATH . 'models/gamification_rules.inc');
	    $rule = new Gamification_Rules( $this->registry );
	    $pagination = $rule->search($offset,$_SESSION['gamification_criteria']);
	 
      if( $pagination->getTotalRows() == 0 )
      {
      	// no hay 
        $this->registry->getObject('template')->buildFromTemplates(
          $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
          $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'gamification/'.$this->registry->getObject('constants')->getNoResultsTpl(),
          $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
        );
        
        //Cargamos la busqueda
	      $this->registry->getObject('template')->getPage()->addTag('gamification.search',$_SESSION['gamification_criteria']);	
        // cargamos el total de settings
		    $this->registry->getObject('template')->getPage()->addTag( 'gamification_count', $pagination->getTotalRows() );
      }else
      {
         if(!$pagination->checkOffset($offset))
         {
         	  // invalid
            $this->registry->getObject('template')->buildFromTemplates(
              $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
              $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'gamification/'.$this->registry->getObject('constants')->getInvalidTpl(),
              $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
            );
         }else
	     { 
          $this->registry->getObject('template')->buildFromTemplates(
	         $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
	        $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'gamification/'.$this->registry->getObject('constants')->getListTpl(),
	        $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
	       );
		
		      //cargamos la info de cada regla
		      $this->registry->getObject('template')->getPage()->addTag( 'gamification', array( 'SQL', $pagination->getCache() ) );
          //Cargamos la busqueda
          $this->registry->getObject('template')->getPage()->addTag( 'gamification.search',$_SESSION['gamification_criteria']);	
          // cargamos el total de settings
		      $this->registry->getObject('template')->getPage()->addTag( 'gamification_count', $pagination->getTotalRows() );		
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
	  	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'gamification/'.$this->registry->getObject('constants')->getAddTpl(),
	  	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
	  	);
    
    // Cargamos el evento
    require_once( FRAMEWORK_PATH . 'models/event.inc');
    $evento = new Event( $this->registry );
    $pagination = $evento->listEvent();
    $this->registry->getObject('template')->getPage()->addTag( 'event', array( 'SQL', $pagination->getCache() ) ); 
    $this->registry->getObject('template')->getPage()->addTag('error_msg','error-msg'); 
    $this->registry->getObject('template')->getPage()->addTag('error_text',''); 
    $this->registry->getObject('template')->getPage()->addTag('eventName','');  
    $this->registry->getObject('template')->getPage()->addTag('threshold','0');
    $this->registry->getObject('template')->getPage()->addTag('title','');	
	  $this->registry->getObject('template')->getPage()->addTag('description','');
	  $this->registry->getObject('template')->getPage()->addTag('xp','0');
    $this->registry->getObject('template')->getPage()->addTag('rp','0');
    $this->registry->getObject('template')->getPage()->addTag('lp','0');
  }

 /*
  * Metodo que guarda el seeting en BBDD 
  * 
  */
  private function register(){
 
    require_once FRAMEWORK_PATH . 'controllers/admin_gamification/registrationcontroller.inc';
    require_once( FRAMEWORK_PATH . 'models/gamification_rules.inc');
    $rule = new Gamification_Rules( $this->registry );
    if ($rule->canSave($_POST['eventName'],$_POST['threshold']))
    {
      $rc = new Registrationcontroller( $this->registry,$this->registry->getObject('authenticate')->getUser()->getUserID());
	    header('Location: search'); 
    }else
    {
      $this->registry->getObject('template')->buildFromTemplates(
        $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
    	  $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'gamification/'.$this->registry->getObject('constants')->getAddTpl(),
    	  $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
    	);

      
      // Cargamos el evento
      require_once( FRAMEWORK_PATH . 'models/event.inc');
      $evento = new Event( $this->registry );
      $pagination = $evento->listEventSelected($_POST['eventName']);
      $this->registry->getObject('template')->getPage()->addTag( 'event', array('SQL', $pagination->getCache() ) ); 
      $this->registry->getObject('template')->getPage()->addTag('error_msg',''); 
      $this->registry->getObject('template')->getPage()->addTag('error_text','La regla ya existe'); 
      $this->registry->getObject('template')->getPage()->addTag('eventName',$_POST['eventName']);  
      $this->registry->getObject('template')->getPage()->addTag('image',$_POST['image']);  
      $this->registry->getObject('template')->getPage()->addTag('threshold',$_POST['threshold']);
      $this->registry->getObject('template')->getPage()->addTag('title',$_POST['title']);  
      $this->registry->getObject('template')->getPage()->addTag('description',$_POST['description']);
      $this->registry->getObject('template')->getPage()->addTag('xp',$_POST['xp']);
      $this->registry->getObject('template')->getPage()->addTag('rp',$_POST['rp']);
      $this->registry->getObject('template')->getPage()->addTag('lp',$_POST['lp']);
    }  	
  }

 
  /*
  * Metodo que borra la regla
  *
  **/
  private function delete($ruleID)
  {
    require_once( FRAMEWORK_PATH . 'models/gamification_rules.inc');
    $rule = new Gamification_Rules( $this->registry );
    $rule->delete( $ruleID );  
    header('Location: /socialNetwork/admin_gamification/search');
  } 


}
			
?>