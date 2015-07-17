<?php
 /**
 * Controlador para administracion de snippets  browse / edit / delete / ban
 * @version 1.0
 * @author  Oscar Garcia
 */	
class Admin_snippetscontroller{
	
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
					  $this->browse(intval($this->parameter1));
					  break;
					  
				   case 'search':
  				     $this->search(intval($this->parameter1));
					  break;

					case 'view':
					  $this->view(intval($this->parameter1));
					  break;
					  
				   case 'history':
					  $this->history(intval($this->parameter1));
					  break;
					  
					case 'delete':
					  $this->delete(intval($this->parameter1));
					  break;
				}
				
			}else
		   {
		     //$this->action="browse";
			  //$this->browse(1);
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
	* Metodo para buscar snippets
	*
	*
	*/
    private function browse($offset=1)
    {   
      $offset=($offset<=0)?1:$offset;
  	   require_once( FRAMEWORK_PATH . 'models/snippets.inc');
	   $snippets = new Snippets( $this->registry );
	   $pagination = $snippets->listSnippets( $offset );
	 
      if(!$pagination->checkOffset($offset) )
        $this->registry->getObject('template')->buildFromTemplates(
        	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
        	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'snippets/'.$this->registry->getObject('constants')->getInvalidTpl(),
        	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
        	);
	   else
	  { 

	    $this->registry->getObject('template')->buildFromTemplates(
	    	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
	    	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'snippets/'.$this->registry->getObject('constants')->getListTpl(),
	    	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
	    	);
		 //cargamos la info de cada snippet
		 $this->registry->getObject('template')->getPage()->addTag( 'snippets', array( 'SQL', $pagination->getCache() ) );
         
		 //Cargamos la busqueda
	     $this->registry->getObject('template')->getPage()->addTag( 'snippet.search',"");	
         // cargamos el total de snippets
		 $this->registry->getObject('template')->getPage()->addTag( 'snippets_count', $pagination->getTotalRows() );		
		 $pagination->showPagination($this->controller,$this->action,$this->parameter1,$this->parameter2);
	  }		
	 
  }	
   
   /*
	* Metodo para buscar snippets con query
	*
	*
	*/
    private function search()
    {   
  	   require_once( FRAMEWORK_PATH . 'models/snippets.inc');
	   $snippet = new Snippets($this->registry );
	   $pagination = $snippet->search($_POST['search']);
	 
      if($pagination->getTotalRows()<=0)
        $this->registry->getObject('template')->buildFromTemplates(
        	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
        	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'snippets/'.$this->registry->getObject('constants')->getNoResultsTpl(),
        	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
        	);
	   else
	  { 

	    $this->registry->getObject('template')->buildFromTemplates(
	    	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
	    	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'snippets/'.$this->registry->getObject('constants')->getListTpl(),
	    	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
	    	);
		 //cargamos la info de cada usuario
		 $this->registry->getObject('template')->getPage()->addTag( 'snippets', array( 'SQL', $pagination->getCache() ) );
         //Cargamos la busqueda
	     $this->registry->getObject('template')->getPage()->addTag( 'snippet.search',$_POST['search']);	
		 
         // cargamos el total de usuarios
		 $this->registry->getObject('template')->getPage()->addTag( 'snippets_count', $pagination->getTotalRows() );		
		 $pagination->showPagination($this->controller,$this->action,$this->parameter1,$this->parameter2);
	  }		
	 
  }	
  
  
  
  /*
  * Metodo que redirecciona a la plantilla de historial
  *
  **/
  private function history($snippetID)
  {
    require_once( FRAMEWORK_PATH . 'models/snippets.inc');
	$snippets = new Snippets( $this->registry );
	$snippetData = $snippets->getSnippet( $snippetID );  	
  	  
  	require_once( FRAMEWORK_PATH . 'models/snippet_log.inc');
    $data = new Snippet_Log( $this->registry );
    
	$logData = $data->getHistory( $snippetID );
	
	// Si no encontramos datos 
    if( $logData->getTotalRows()<=0 )
	{
	  //pantalla de error
	  $this->registry->getObject('template')->buildFromTemplates(
	   	$this->registry->getObject('constants')->getHeaderTpl(), 
	   	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'snippets/'.$this->registry->getObject('constants')->getInvalidTpl(), 
	   	$this->registry->getObject('constants')->getFooterTpl()
	   	);
	}
	else
	{   
	  //Si lo encontramos 
	  // Definimos la pagina de 
	  $this->registry->getObject('template')->buildFromTemplates(
	  	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
	   	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'snippets/'.$this->registry->getObject('constants')->getHistoryTpl(),
	   	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
	   	);
      //cargamos la info de cada usuario
	  $this->registry->getObject('template')->getPage()->addTag( 'logs', array( 'SQL', $logData->getCache() ) );
	  $this->registry->getObject('template')->getPage()->addTag('title',$snippetData['title']);
	  $this->registry->getObject('template')->getPage()->addTag('id',$snippetData['ID']);
	  $this->registry->getObject('template')->getPage()->addTag('description',$snippetData['description']);  
    }
   
  }


  /*
  * Metodo que redirecciona a la plantilla de ver
  *
  **/
  private function view($snippetID)
  {
  	require_once( FRAMEWORK_PATH . 'models/snippets.inc');
  	require_once( FRAMEWORK_PATH . 'models/tags_snippet.inc');
	$snippets = new Snippets( $this->registry );
	$snippetData = $snippets->getSnippet( $snippetID );
	// Si no encontramos el snippet
    if( $snippetData==null )
	{
	  //pantalla de error
	  $this->registry->getObject('template')->buildFromTemplates(
	  	$this->registry->getObject('constants')->getHeaderTpl(), 
	  	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'snippets/'.$this->registry->getObject('constants')->getInvalidTpl(), 
	  	$this->registry->getObject('constants')->getFooterTpl()
	  	);
	}
	else
	{ 
	  //Si lo encontramos 
	  // Definimos la pagina de view 
	  $this->registry->getObject('template')->buildFromTemplates(
	  	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
	  	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'snippets/'.$this->registry->getObject('constants')->getViewTpl(),
	  	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
	  	);
		
	  // Cargamos los datos
	  $this->registry->getObject('template')->getPage()->addTag('title',$snippetData['title']);
	  $this->registry->getObject('template')->getPage()->addTag('id',$snippetData['ID']);
	  $this->registry->getObject('template')->getPage()->addTag('description',$snippetData['description']);
	  $this->registry->getObject('template')->getPage()->addTag('code',$snippetData['code']);
	   
	  // Cargamos los tags
      $tags= new Tags_Snippet( $this->registry );
      $pagination = $tags->listTagsBySnippet($snippetID);
      if( $pagination->getNumRowsPage() > 0 )
	  {
        $this->registry->getObject('template')->getPage()->addTag( 'tags', array( 'SQL', $pagination->getCache() ) );    	  
      }
   }		
  }
 



 
  /*
  * Metodo que borra el snippet
  *
  **/
  private function delete($snippetID)
  {
  	require_once( FRAMEWORK_PATH . 'models/snippets.inc');
	$snippets = new Snippets( $this->registry );
	$deleted = $snippets->delete( $snippetID );
	header('Location: /socialNetwork/admin_snippets/browse');  	
  } 
 
 
 
 
	
}
			
?>