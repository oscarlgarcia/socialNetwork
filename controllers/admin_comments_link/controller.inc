<?php
 /**
 * Controlador para administracion de los comentarios de links  browse / edit / delete / ban
 * @version 1.0
 * @author  Oscar Garcia
 */	
class Admin_comments_linkcontroller{
	
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
                  
                  case 'delete':
				    $this->delete(intval($this->parameter1));
				    break;

				  case 'publish':
				    $this->publish(intval($this->parameter1));
				    break;

				  case 'ban':
				    $this->ban(intval($this->parameter1));
				    break;

				 case 'listByUser':
				    $this->listByUser($this->parameter1,intval($this->parameter2));
				    break;

				 case 'listByLink':
  				    $this->listByLink(intval($this->parameter1));
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
	* Metodo para buscar comentarios  desde la pantalla de admin
	*/
    private function search($offset)
    {   


      $offset = ($offset<=0)?1:$offset;
      
      if (!isset($_SESSION['comments_links_criteria'])){
      	$this->registry->getObject('util')->storeToSession('comments_links_criteria',"");
      }

      if (isset($_POST['search'])){
      	$this->registry->getObject('util')->storeToSession('comments_links_criteria',$_POST['search']);
      }

      require_once( FRAMEWORK_PATH . 'models/comments_links.inc');
	  $comments = new Comments_Links( $this->registry );
	  $pagination = $comments->search($offset,$_SESSION['comments_links_criteria']);
	 
      if( $pagination->getTotalRows() == 0  )
      {
        // no hay
        $this->registry->getObject('template')->buildFromTemplates(
          $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
          $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'comments_link/'.$this->registry->getObject('constants')->getNoResultsTpl(),
          $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
        );
        
        //Cargamos la busqueda
	    $this->registry->getObject('template')->getPage()->addTag('comments_link.search',$_SESSION['comments_links_criteria']);	
        // cargamos el total de snippets
		$this->registry->getObject('template')->getPage()->addTag( 'comments_link_count', $pagination->getTotalRows() );	

      }else
      {
        if (!$pagination->checkOffset($offset))
        {
          // invalid
          $this->registry->getObject('template')->buildFromTemplates(
            $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
            $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'comments_link/'.$this->registry->getObject('constants')->getInvalidTpl(),
            $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
          );

        }else
	    { 
          $this->registry->getObject('template')->buildFromTemplates(
	        $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
	        $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'comments_link/'.$this->registry->getObject('constants')->getListTpl(),
	        $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
	      );
		
		  //cargamos la info de cada snippet
		  $this->registry->getObject('template')->getPage()->addTag( 'comments_link', array( 'SQL', $pagination->getCache() ) );
         
		  //Cargamos la busqueda
	      $this->registry->getObject('template')->getPage()->addTag( 'comments_link.search',$_SESSION['comments_links_criteria']);	
          // cargamos el total de snippets
		  $this->registry->getObject('template')->getPage()->addTag( 'comments_link_count', $pagination->getTotalRows() );		
		  $pagination->showPagination($this->controller,$this->action,$this->parameter1,$this->parameter2);
	    }		
      }
    }

   /*
  * Busca comentarios de un usuario en particular
  */
  private function listByUser( $username , $offset ){

  	$offset = ($offset<=0)?1:$offset;
    require_once( FRAMEWORK_PATH . 'models/comments_links.inc');
    $comments = new Comments_Links( $this->registry );
	$pagination = $comments->searchByUser($offset, $username );
    
    if(!$pagination->checkOffset($offset) )
      {
        $this->registry->getObject('template')->buildFromTemplates(
          $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
          $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'comments_link/'.$this->registry->getObject('constants')->getNoResultsTpl(),
          $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
        );
        
        //Cargamos la busqueda
	    $this->registry->getObject('template')->getPage()->addTag('comments_link.search',$_SESSION['comments_links_criteria']);	
        // cargamos el total de snippets
		$this->registry->getObject('template')->getPage()->addTag( 'comments_link_count', $pagination->getTotalRows() );	

      }
	  else
	  { 
        $this->registry->getObject('template')->buildFromTemplates(
	    $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
	    $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'comments_link/'.$this->registry->getObject('constants')->getListTpl(),
	    $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
	    );
		//cargamos la info de cada snippet
		$this->registry->getObject('template')->getPage()->addTag( 'comments_link', array( 'SQL', $pagination->getCache() ) );
         
		//Cargamos la busqueda
	    $this->registry->getObject('template')->getPage()->addTag( 'comments_link.search',$_SESSION['comments_links_criteria']);	
        // cargamos el total de snippets
		$this->registry->getObject('template')->getPage()->addTag( 'comments_link_count', $pagination->getTotalRows() );	
		$pagination->showPagination($this->controller,$this->action,$this->parameter1,$this->parameter2);
	  }		

  }

  /*
  * Busca comentarios de un usuario en particular
  */
  private function listByLink( $linkID){

  	require_once( FRAMEWORK_PATH . 'models/comments_links.inc');
    $comments = new Comments_Links( $this->registry );
	$pagination = $comments->searchByLink( $linkID );
    
    if(!$pagination->checkOffset(1) )
      {
        $this->registry->getObject('template')->buildFromTemplates(
          $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
          $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'comments_link/'.$this->registry->getObject('constants')->getNoResultsTpl(),
          $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
        );
        //Cargamos la busqueda
	    $this->registry->getObject('template')->getPage()->addTag('comments_link.search',$_SESSION['comments_links_criteria']);	
        // cargamos el total de snippets
		$this->registry->getObject('template')->getPage()->addTag( 'comments_link_count', $pagination->getTotalRows() );	

      }
	  else
	  { 
        $this->registry->getObject('template')->buildFromTemplates(
	    $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
	    $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'comments_link/'.$this->registry->getObject('constants')->getListTpl(),
	    $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
	    );
		//cargamos la info de cada snippet
		$this->registry->getObject('template')->getPage()->addTag( 'comments_link', array( 'SQL', $pagination->getCache() ) );
         
		//Cargamos la busqueda
	    $this->registry->getObject('template')->getPage()->addTag( 'comments_link.search',$_SESSION['comments_links_criteria']);	
        // cargamos el total de snippets
		$this->registry->getObject('template')->getPage()->addTag( 'comments_link_count', $pagination->getTotalRows() );	
		$pagination->showPagination($this->controller,$this->action,$this->parameter1,$this->parameter2);
	  }		

  }



  /*
  * Metodo que borra el comentario
  *
  **/
  private function delete($commentID)
  {
  	require_once( FRAMEWORK_PATH . 'models/comments_links.inc');
	$comment = new Comments_Links( $this->registry );
	$deleted = $comment->delete( $commentID );
	header('Location: /socialNetwork/admin_comments_link/search');  	
  } 
 

  /*
  * Metodo para publicar los comentarios
  *  TODO asignar los puntos por gamificacion solo cuando sean publicados no cuando 
  *  el usuario lo postee
  */
  public function publish($commentID){
    require_once( FRAMEWORK_PATH . 'models/comments_links.inc');
	$comment = new Comments_Links( $this->registry );
	$deleted = $comment->updateStatus( $commentID, 4);
	header('Location: /socialNetwork/admin_comments_link/search');
  }

  /*
  * Metodo para banear los comentarios
  *  TODO quitar los puntos por gamificacion solo cuando sean baneado 
  */
  public function ban($commentID){
    require_once( FRAMEWORK_PATH . 'models/comments_links.inc');
	$comment = new Comments_Links( $this->registry );
	$deleted = $comment->updateStatus( $commentID,5);
	header('Location: /socialNetwork/admin_comments_link/search');
  }
 
 
	
}
			
?>