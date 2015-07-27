<?php
 /**
 * Controlador para admisnitracion de usuarios browse / edit / delete / ban
 * @version 1.0
 * @author  Oscar Garcia
 */	
class Admin_userscontroller{
	
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
					  //$this->view(intval($this->parameter1));
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
	* Metodo para buscar usuarios
	*
	*
	*/
    private function search($offset=1)
    {   
      $offset=($offset<=0)?1:$offset;
      if (!isset($_SESSION['user_criteria'])){
      	$this->registry->getObject('util')->storeToSession('user_criteria',"");
      }

      if (isset($_POST['search'])){
      	$this->registry->getObject('util')->storeToSession('user_criteria',$_POST['search']);
      }


  	   require_once( FRAMEWORK_PATH . 'models/user.inc');
	   $users = new UserModel( $this->registry );
	   $pagination = $users->search($offset,$_SESSION['user_criteria']);

      if(!$pagination->checkOffset($offset) )
        $this->registry->getObject('template')->buildFromTemplates(
        	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base')).$this->registry->getObject('constants')->getHeaderTpl(), 
        	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'users/'.$this->registry->getObject('constants')->getInvalidTpl(),
        	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
        	);
	   else
	  { 

	    $this->registry->getObject('template')->buildFromTemplates(
	    	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
	    	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'users/'.$this->registry->getObject('constants')->getListTpl(),
	    	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
	    	);
		 //cargamos la info de cada usuario
		 $this->registry->getObject('template')->getPage()->addTag( 'users', array( 'SQL', $pagination->getCache() ) );
         
		 //Cargamos la busqueda
	     $this->registry->getObject('template')->getPage()->addTag( 'user.search',$_SESSION['user_criteria']);	
         // cargamos el total de usuarios
		 $this->registry->getObject('template')->getPage()->addTag( 'users_count', $pagination->getTotalRows() );		
		 $pagination->showPagination($this->controller,$this->action,$this->parameter1,$this->parameter2);
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
	require_once( FRAMEWORK_PATH . 'models/rating_snippet.inc');
	$snippets = new Snippets( $this->registry );
	$snippetData = $snippets->getSnippet( $snippetID );
	// Si no encontramos el snippet
    if( $snippetData==null )
	{
	  //pantalla de error
	  $this->registry->getObject('template')->buildFromTemplates(
	  	$this->registry->getObject('constants')->getHeaderTpl(), 
	  	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_logged_base')).'snippets/'.$this->registry->getObject('constants')->getInvalidTpl(), 
	  	$this->registry->getObject('constants')->getFooterTpl()
	  	);
	  //cargamos el total de snippets por categoria
	  require_once( FRAMEWORK_PATH . 'models/category.inc');
	  $category = new Category( $this->registry );
	  $pagination =$category->countSnippetByCategory();
	  $this->registry->getObject('template')->getPage()->addTag( 'langs', array( 'SQL', $pagination->getCache() ) );  
	}
	else
	{ 
	  //Si lo encontramos 
	  // Definimos la pagina de view 
	  $this->registry->getObject('template')->buildFromTemplates(
	  	$this->registry->getObject('constants')->getHeaderTpl(), 
	  	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_logged_base')).'snippets/'.$this->registry->getObject('constants')->getViewTpl(), 
	  	$this->registry->getObject('constants')->getFooterTpl()
	  	);
	  // Cargamos los datos
	  $this->registry->getObject('template')->getPage()->addTag('title',$snippetData['title']);
	  $this->registry->getObject('template')->getPage()->addTag('description',$snippetData['description']);
	  $this->registry->getObject('template')->getPage()->addTag('code',$snippetData['code']);
	  $this->registry->getObject('template')->getPage()->addTag('rating',$snippetData['rating']);
	  $this->registry->getObject('template')->getPage()->addTag('category',$snippetData['category']);
	  
	  // Comprobamos si el usuario lo ha guardado como favorito
	  // Si es asi colocamos la action y el icono correspondiente
	  if($snippets->isFavorited($snippetID,$this->registry->getObject('authenticate')->getUser()->getUserID())){
	    $this->registry->getObject('template')->getPage()->addTag( 'action', "unfav" );
		$this->registry->getObject('template')->getPage()->addTag( 'fav_msg', "glyphicon-heart" );  
	  }else
	  {
	    $this->registry->getObject('template')->getPage()->addTag( 'action',"fav"); 
		$this->registry->getObject('template')->getPage()->addTag( 'fav_msg', "glyphicon-heart-empty" ); 
	  }
	  
	  
	  // Cargamos los tags
      $tags= new Tags_Snippet( $this->registry );
      $pagination = $tags->listTagsBySnippet($snippetID);
      if( $pagination->getNumRowsPage() > 0 )
	  {
        $this->registry->getObject('template')->getPage()->addTag( 'tags', array( 'SQL', $pagination->getCache() ) );    	  
      }
	
	  // Validamos el rating
	  // Si puede o no hacer rating
	  $rated= new Rating_Snippet( $this->registry );
      $this->registry->getObject('template')->getPage()->addTag( 'rating_readonly',$rated->isRatedByUser($snippetID,$this->registry->getObject('authenticate')->getUser()->getUserID()) );  
      
	  // cargamos los related
	  $pagination =$tags->getRelatedSnippets($snippetID);
      if( $pagination->getNumRowsPage() > 0 )
	  {
        $this->registry->getObject('template')->getPage()->addTag( 'related', array( 'SQL', $pagination->getCache() ) );    	  
      }	
	  
	  //Guardamos la info en session para los metodos AJAX
	  $this->registry->getObject('util')->storeToSession('snippet',$snippets->getSnippet($snippetID));
    }		
  }
 

	

	
}
			
?>