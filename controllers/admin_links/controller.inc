<?php
 /**
 * Controlador para administracion de links  browse / edit / delete / ban
 * @version 1.0
 * @author  Oscar Garcia
 */	
class Admin_linkscontroller{
	
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

                  case 'listByUser':
				    $this->listByUser($this->parameter1,intval($this->parameter2));
				    break;

				  case 'history':
				    $this->history(intval($this->parameter1));
				    break;

				  case 'view':
				    $this->view(intval($this->parameter1));
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
	* Metodo para buscar Links desde la pantalla de admin
	*/
    private function search($offset)
    {   
      $offset = ($offset<=0)?1:$offset;
      
      if (!isset($_SESSION['link_criteria'])){
      	$this->registry->getObject('util')->storeToSession('link_criteria',"");
      }

      if (isset($_POST['search'])){
      	$this->registry->getObject('util')->storeToSession('link_criteria',$_POST['search']);
      }

      require_once( FRAMEWORK_PATH . 'models/links.inc');
	  $links = new Links( $this->registry );
	  $pagination = $links->search($offset,$_SESSION['link_criteria']);
	 
      if($pagination->getTotalRows() == 0  )
      {
      	// no hay 
        $this->registry->getObject('template')->buildFromTemplates(
          $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
          $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'links/'.$this->registry->getObject('constants')->getNoResultsTpl(),
          $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
        );
        
        //Cargamos la busqueda
	    $this->registry->getObject('template')->getPage()->addTag('links.search',$_SESSION['link_criteria']);	
        // cargamos el total de links
		$this->registry->getObject('template')->getPage()->addTag( 'links_count', $pagination->getTotalRows() );	

      }else
      {
        if (!$pagination->checkOffset($offset))
        {
          // invalid
          $this->registry->getObject('template')->buildFromTemplates(
            $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
            $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'links/'.$this->registry->getObject('constants')->getInvalidTpl(),
            $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
          );
        
        }else
	    { 
          $this->registry->getObject('template')->buildFromTemplates(
	        $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
	        $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'links/'.$this->registry->getObject('constants')->getListTpl(),
	        $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
	      );
		
		  //cargamos la info de cada snippet
		  $this->registry->getObject('template')->getPage()->addTag( 'links', array( 'SQL', $pagination->getCache() ) );
         
		  //Cargamos la busqueda
	      $this->registry->getObject('template')->getPage()->addTag( 'links.search',$_SESSION['link_criteria']);	
        
          // cargamos el total de links
		  $this->registry->getObject('template')->getPage()->addTag( 'links_count', $pagination->getTotalRows() );		
		  $pagination->showPagination($this->controller,$this->action,$this->parameter1,$this->parameter2);
	    }
      }
    }
	
  /*
  * Busca links de un usuario en particular
  */
  private function listByUser($username,$offset){

  	$offset = ($offset<=0)?1:$offset;
    require_once( FRAMEWORK_PATH . 'models/links.inc');
    $links = new Links( $this->registry );
	$pagination = $links->searchByUser($offset, $username );
    
    if(!$pagination->checkOffset($offset) )
      {
        $this->registry->getObject('template')->buildFromTemplates(
          $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
          $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'links/'.$this->registry->getObject('constants')->getNoResultsTpl(),
          $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
        );
        
        //Cargamos la busqueda
	    $this->registry->getObject('template')->getPage()->addTag('links.search',$_SESSION['link_criteria']);	
        // cargamos el total de links
		$this->registry->getObject('template')->getPage()->addTag( 'links_count', $pagination->getTotalRows() );	

      }
	  else
	  { 
        $this->registry->getObject('template')->buildFromTemplates(
	    $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
	    $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'links/'.$this->registry->getObject('constants')->getListTpl(),
	    $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
	    );
		//cargamos la info de cada snippet
		$this->registry->getObject('template')->getPage()->addTag( 'links', array( 'SQL', $pagination->getCache() ) );
         
		//Cargamos la busqueda
	    $this->registry->getObject('template')->getPage()->addTag( 'links.search',$_SESSION['link_criteria']);	
        // cargamos el total de links
		$this->registry->getObject('template')->getPage()->addTag( 'links_count', $pagination->getTotalRows() );	
		$pagination->showPagination($this->controller,$this->action,$this->parameter1,$this->parameter2);
	  }		

  }

  /*
  * Metodo que redirecciona a la plantilla de ver
  *
  **/
  private function view($linkID)
  {
  	require_once( FRAMEWORK_PATH . 'models/links.inc');
	$link = new Links( $this->registry );
	$data = $link->getLink( $linkID );
	// Si no encontramos el link
    if( $data == null )
	{
	  //pantalla de error
	  $this->registry->getObject('template')->buildFromTemplates(
          $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
          $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'links/'.$this->registry->getObject('constants')->getInvalidTpl(),
          $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
        );
	}
	else
	{ 
	  //Si lo encontramos 
	  // Definimos la pagina de view 
	  require_once( FRAMEWORK_PATH . 'models/tags_links.inc');
	  $this->registry->getObject('template')->buildFromTemplates(
	  	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
	  	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'links/'.$this->registry->getObject('constants')->getViewTpl(),
	  	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
	  	);
		
	  // Cargamos los datos
	  $this->registry->getObject('template')->getPage()->addTag('title',$data['title']);
	  $this->registry->getObject('template')->getPage()->addTag('id',$data['ID']);
	  $this->registry->getObject('template')->getPage()->addTag('description',$data['description']);
	  $this->registry->getObject('template')->getPage()->addTag('url',$data['url']);
	   
	  // Cargamos los tags
      $tags= new Tags_Links( $this->registry );
      $pagination = $tags->listTagsByLink($linkID);
      if( $pagination->getNumRowsPage() > 0 )
	  {
        $this->registry->getObject('template')->getPage()->addTag( 'tags', array( 'SQL', $pagination->getCache() ) );    	  
      }
   }		
  }


 /*
  * Metodo que redirecciona a la plantilla de historial
  *
  **/
  private function history($linkID)
  {
    require_once( FRAMEWORK_PATH . 'models/links.inc');
	$link = new Links( $this->registry );
	$linkData = $link->getLink( $linkID );  	
  	  
  	require_once( FRAMEWORK_PATH . 'models/link_log.inc');
    $link_log = new Link_Log( $this->registry );
    
	$logData = $link_log->getHistory( $linkID );
	
	// Si no encontramos datos 
    if( $logData->getTotalRows()<=0 )
	{
	  //pantalla de error
	  $this->registry->getObject('template')->buildFromTemplates(
          $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
          $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'links/'.$this->registry->getObject('constants')->getInvalidTpl(),
          $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
        );
	}
	else
	{   
	  //Si lo encontramos  
	  $this->registry->getObject('template')->buildFromTemplates(
	  	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
	   	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'links/'.$this->registry->getObject('constants')->getHistoryTpl(),
	   	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
	   	);
      //cargamos la info de cada usuario
	  $this->registry->getObject('template')->getPage()->addTag( 'logs', array( 'SQL', $logData->getCache() ) );
	  $this->registry->getObject('template')->getPage()->addTag('title',$linkData['title']);
	  $this->registry->getObject('template')->getPage()->addTag('id',$linkData['ID']);
	  $this->registry->getObject('template')->getPage()->addTag('description',$linkData['description']);  
    }
   
  }





  /*
  * Metodo que borra el link
  *
  **/
  private function delete($linkID)
  {
    require_once( FRAMEWORK_PATH . 'models/links.inc');
    $links = new Links( $this->registry );
    $deleted = $links->delete( $linkID );
    header('Location: /socialNetwork/admin_links/search');   
  } 
  

   /*
  * Metodo para publicar los links
  *  TODO asignar los puntos por gamificacion solo cuando sean publicados no cuando 
  *  el usuario lo postee
  */
  public function publish($linkID){
    require_once( FRAMEWORK_PATH . 'models/links.inc');
	$links = new Links( $this->registry );
	$deleted = $links->updateStatus( $linkID, 4);
	header('Location: /socialNetwork/admin_links/search');
  }

  /*
  * Metodo para banear los links
  *  TODO quitar los puntos por gamificacion solo cuando sean baneado 
  */
  public function ban($linkID){
    require_once( FRAMEWORK_PATH . 'models/links.inc');
	$links = new Links( $this->registry );
	$deleted = $links->updateStatus( $linkID,5);
	header('Location: /socialNetwork/admin_links/search');
  }
	


}
			
?>