<?php
 /**
 * Controlador para administracion de Settings  browse / edit / delete / ban
 * @version 1.0
 * @author  Oscar Garcia
 */	
class Admin_settingscontroller{
	
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
				    $this->view($this->parameter1);
					break;

				  case 'update':
				    $this->update(intval($this->parameter1));
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
	* Metodo para buscar los Settings desde la pantalla de admin
	*/
    private function search($offset)
    {   
      $offset = ($offset<=0)?1:$offset;
      
      if (!isset($_SESSION['setting_criteria'])){
      	$this->registry->getObject('util')->storeToSession('setting_criteria',"");
      }

      if (isset($_POST['search'])){
      	$this->registry->getObject('util')->storeToSession('setting_criteria',$_POST['search']);
      }

      require_once( FRAMEWORK_PATH . 'models/settings.inc');
	  $settings = new Settings( $this->registry );
	  $pagination = $settings->search($offset,$_SESSION['setting_criteria']);
	 
      if(!$pagination->checkOffset($offset) )
      {
        $this->registry->getObject('template')->buildFromTemplates(
          $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
          $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'settings/'.$this->registry->getObject('constants')->getInvalidTpl(),
          $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
        );
        
        //Cargamos la busqueda
	    $this->registry->getObject('template')->getPage()->addTag('settings.search',$_SESSION['setting_criteria']);	
        // cargamos el total de settings
		$this->registry->getObject('template')->getPage()->addTag( 'settings_count', $pagination->getTotalRows() );	

      }
	  else
	  { 
        $this->registry->getObject('template')->buildFromTemplates(
	    $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
	    $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'settings/'.$this->registry->getObject('constants')->getListTpl(),
	    $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
	    );
		//cargamos la info de cada snippet
		$this->registry->getObject('template')->getPage()->addTag( 'settings', array( 'SQL', $pagination->getCache() ) );
         
		//Cargamos la busqueda
	    $this->registry->getObject('template')->getPage()->addTag( 'settings.search',$_SESSION['setting_criteria']);	
        // cargamos el total de settings
		$this->registry->getObject('template')->getPage()->addTag( 'settings_count', $pagination->getTotalRows() );		
		$pagination->showPagination($this->controller,$this->action,$this->parameter1,$this->parameter2);
	  }		
    }

  /*
  * Metodo que redirecciona a la plantilla de ver
  *
  **/
  private function view($tagName)
  {
  	require_once( FRAMEWORK_PATH . 'models/settings.inc');
	$setting = new Settings( $this->registry );
	// Si no encontramos el tag
    if(!$tag->getTag( $this->registry->getObject('db')->sanitizeData($tagName) ) )
	{
	  //pantalla de error
	  $this->registry->getObject('template')->buildFromTemplates(
	  	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
	  	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'settings/'.$this->registry->getObject('constants')->getInvalidTpl(),
	  	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
	  	);
	}
	else
	{ 
	  $this->registry->getObject('template')->buildFromTemplates(
	  	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
	  	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'settings/'.$this->registry->getObject('constants')->getViewTpl(),
	  	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
	  	);
		
	  // Cargamos los datos
	  $this->registry->getObject('template')->getPage()->addTag('error_msg','error-msg'); 
      $this->registry->getObject('template')->getPage()->addTag('error_text',''); 
	  $this->registry->getObject('template')->getPage()->addTag('tag_name',$tag->getTagName());
	  $this->registry->getObject('template')->getPage()->addTag('id',$tag->getID());

	  // Cargamos los tags 
	  $list = $tag->getTags();
	  $this->registry->getObject('template')->getPage()->addTag('tag',array('SQL',$list->getCache()));

	  //Cargamos los Snippets
	   $this->registry->getObject('template')->getPage()->addTag('snippets',array('SQL', $tag->getAllSnippets()->getCache()));
      
      //Cargamos los links
	   $this->registry->getObject('template')->getPage()->addTag('links',array('SQL', $tag->getAllLinks()->getCache()));
	   //Cargamos los pages
	   $this->registry->getObject('template')->getPage()->addTag('pages',array('SQL', $tag->getAllPages()->getCache()));
       //Cargamos las imagenes
	   $this->registry->getObject('template')->getPage()->addTag('media',array('SQL', $tag->getAllImages()->getCache()));

	   
   }
  }


 /*
  * Metodo que actualiza el tag
  *
  **/
  private function update($tagID)
  {
    require_once( FRAMEWORK_PATH . 'models/tags.inc');
    $tag = new tags( $this->registry );
    if(!$tag->loadTag($tagID) )
    {
      //pantalla de error
	  $this->registry->getObject('template')->buildFromTemplates(
	  	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
	  	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'settings/'.$this->registry->getObject('constants')->getInvalidTpl(),
	  	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
	  	);
	}
	else
	{ 
	  if (isset($_POST['tag_name']))
        $name_cleaned = $this->registry->getObject('db')->sanitizeData($_POST['tag_name']);
      else
      	$name_cleaned = "";
      if (!$tag->isSaved($name_cleaned) ) // Si este tag no existe ya
      {
        $tag->updateTagName($tagID, $name_cleaned); 
        header('Location: /socialNetwork/admin_tags/search');  
      }
      else
      {
        $this->registry->getObject('template')->buildFromTemplates(
	  	  $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
	  	  $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'settings/'.$this->registry->getObject('constants')->getViewTpl(),
	  	  $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
	  	);
        
        $this->registry->getObject('template')->getPage()->addTag('error_msg',''); 
        $this->registry->getObject('template')->getPage()->addTag('error_text','Este Tag ya Existe'); 
	    $this->registry->getObject('template')->getPage()->addTag('tag_name',$tag->getTagName());
	    $this->registry->getObject('template')->getPage()->addTag('id',$tag->getID());
      }
    }    
  } 


  /*
  * Metodo que reasigna el tag
  *
  **/
  private function reasig($sourceID)
  {
    require_once( FRAMEWORK_PATH . 'models/tags.inc');
    $tag = new tags( $this->registry );
    $destID =$_POST['tag_select'];
    if ($tag->exist($sourceID) )
    {
      $tag->reasig($sourceID, $destID); 
      header('Location: /socialNetwork/admin_tags/search');  
    }else
    {
      $this->registry->getObject('template')->buildFromTemplates(
	  	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
	  	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'settings/'.$this->registry->getObject('constants')->getInvalidTpl(),
	  	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
	  	);
    } 
  }

  /*
  * Metodo que borra el tag
  *
  **/
  private function delete($tagID)
  {
    require_once( FRAMEWORK_PATH . 'models/tags.inc');
    $tag = new tags( $this->registry );
    if ($tag->canErase($tagID) )
    {
       $tag->delete( $tagID );   
    }      
    header('Location: /socialNetwork/admin_tags/search');
  } 


}
			
?>