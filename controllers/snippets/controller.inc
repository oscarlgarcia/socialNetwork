<?php
 /**
 * Controlador para snippets new/ browse /
 * @version 1.0
 * @author  Oscar Garcia
 */	
class Snippetscontroller{
	
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
					
					case 'popular':
					  $this->popular(intval($this->parameter1));
					  break;
					
					case 'favorites':
					  $this->favorites(intval($this->parameter1));
					  break;
					
                    case 'commented':
					  $this->commented(intval($this->parameter1));
					  break;					
					
					case 'category':
					  $this->categorySearch($this->parameter1,intval($this->parameter2));
					  break;
					
					case 'user':
					  $this->usernameSearch($this->parameter1,intval($this->parameter2));
					  break;
					
					case 'tag':
					  $this->tagSearch($this->parameter1,intval($this->parameter2));
					  break;
					
					case 'view':
					  $this->view(intval($this->parameter1));
					  break;
					
					case 'add':
					  $this->addSnippet();
					  break;
					  
					case 'register':
					  $this->registerSnippet();
					  break;
					  
					case 'fav':
					  $this->saveFavorite();
					  break;
					  
				    case 'unfav':
					  $this->deleteFavorite();
					  break;  
					  
				    case 'comment':
				      $this->comment();
					  break;
				   
				    case 'show_comment':
				      $this->showComments();
					  break; 
					 
				    case 'rating':
				      $this->rating();
					  break; 
				}
				
			}else
		   {
		      $this->action="browse";
			  $this->browse(1);
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
	* Metodo para buscar por snippets con mas rating
	*
	*
	*/
  private function popular($offset=1)
  {
      //validamos el offset
      $offset=($offset<=0)?1:$offset;
  	  require_once( FRAMEWORK_PATH . 'models/snippets.inc');
	  $snippets = new Snippets( $this->registry );
	  $pagination = $snippets->listPopularSnippets( $offset );
	  if( !$pagination->checkOffset($offset) )
	    $this->registry->getObject('template')->buildFromTemplates(
	    	$this->registry->getObject('constants')->getHeaderTpl(), 
	    	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_logged_base')).'404/'.$this->registry->getObject('constants')->get404Tpl(), 
	    	$this->registry->getObject('constants')->getFooterTpl()
	    	);
	  else
	  { 
		$this->registry->getObject('template')->buildFromTemplates(
			$this->registry->getObject('constants')->getHeaderTpl(), 
			$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_logged_base')).'snippets/'.$this->registry->getObject('constants')->getListTpl(), 
			$this->registry->getObject('constants')->getFooterTpl()
			);
		//cargamos la info de cada snippet
		$this->registry->getObject('template')->getPage()->addTag( 'snippet', array( 'SQL', $pagination->getCache() ) );
		// cargamos el action 
		$this->registry->getObject('template')->getPage()->addTag( 'controller', $this->action );
		// cargamos los tipos de ordenacion y los textos a mostrar
		$this->registry->getObject('template')->getPage()->addTag( 'order_controller1', 'browse' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_text1', 'Recientes' ); 	
		$this->registry->getObject('template')->getPage()->addTag( 'order_controller2', 'favorites' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_text2', 'Favoritos' );
		$this->registry->getObject('template')->getPage()->addTag( 'order_controller3', 'commented' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_text3', 'Mas comentados' );
	    // cargamos el texto sobre que ordenacion es la aplicada
        $this->registry->getObject('template')->getPage()->addTag( 'ordered_by', ' con más calificación de Rating' );	
		// cargamos el total de snippets
		$this->registry->getObject('template')->getPage()->addTag( 'snippets_count', $pagination->getTotalRows() );		
		$pagination->showPagination($this->controller,$this->action,$this->parameter1,$this->parameter2);
		
		//Cargamos los top contributors
        $pagination = $snippets->topSnippetsContributors();     
        $this->registry->getObject('template')->getPage()->addTag( 'contributors', array( 'SQL', $pagination->getCache() ) ); 
    	$this->registry->getObject('template')->getPage()->addTag( 'topUserURL', $this->registry->getSetting('avatar_path')); 
	
	    //Cargamos los top tags
	    require_once( FRAMEWORK_PATH . 'models/tags.inc');
	    $tags = new Tags( $this->registry );
	    $pagination = $tags->topSnippetTags();
	    $this->registry->getObject('template')->getPage()->addTag( 'tags', array( 'SQL', $pagination->getCache() ) ); 
	  }
	  
	//cargamos el total de snippet por categoria
	 require_once( FRAMEWORK_PATH . 'models/category.inc');
	 $category = new Category( $this->registry );
	 $pagination =$category->countSnippetByCategory();
	 $this->registry->getObject('template')->getPage()->addTag( 'langs', array( 'SQL', $pagination->getCache() ) ); 	
	  
  }
	
   /*
	* Metodo para buscar por snippets ordenados por el mas reciente
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
	    	$this->registry->getObject('constants')->getHeaderTpl(), 
	    	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_logged_base')).'404/'.$this->registry->getObject('constants')->get404Tpl(), 
	    	$this->registry->getObject('constants')->getFooterTpl()
	    	);
	  else
	  { 
		$this->registry->getObject('template')->buildFromTemplates(
			$this->registry->getObject('constants')->getHeaderTpl(), 
			$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_logged_base')).'snippets/'.$this->registry->getObject('constants')->getListTpl(), 
			$this->registry->getObject('constants')->getFooterTpl()
			);
		//cargamos la info de cada snippet
		$this->registry->getObject('template')->getPage()->addTag( 'snippet', array( 'SQL', $pagination->getCache() ) );
		// cargamos el action 
		$this->registry->getObject('template')->getPage()->addTag( 'controller', $this->action ); 
		// cargamos los tipos de ordenacion y los textos a mostrar
		$this->registry->getObject('template')->getPage()->addTag( 'order_controller1', 'popular' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_text1', 'Rating' );
		$this->registry->getObject('template')->getPage()->addTag( 'order_controller2', 'favorites' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_text2', 'Favoritos' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_controller3', 'commented' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_text3', 'Mas comentados' );
		// cargamos el texto sobre que ordenacion es la aplicada
		$this->registry->getObject('template')->getPage()->addTag( 'ordered_by', ' más recientes' );
		// cargamos el total de snippets
		$this->registry->getObject('template')->getPage()->addTag( 'snippets_count', $pagination->getTotalRows() );		
		
		$pagination->showPagination($this->controller,$this->action,$this->parameter1,$this->parameter2);
		
		//Cargamos los top contributors
        $pagination = $snippets->topSnippetsContributors();     
        $this->registry->getObject('template')->getPage()->addTag( 'contributors', array( 'SQL', $pagination->getCache() ) ); 
	    $this->registry->getObject('template')->getPage()->addTag( 'topUserURL', $this->registry->getSetting('avatar_path')); 
	
    	//Cargamos los top tags
    	require_once( FRAMEWORK_PATH . 'models/tags.inc');
    	$tags = new Tags( $this->registry );
	    $pagination = $tags->topSnippetTags();
	    $this->registry->getObject('template')->getPage()->addTag( 'tags', array( 'SQL', $pagination->getCache() ) ); 
	  }		
	  
	//cargamos el total de snippet por categoria
	 require_once( FRAMEWORK_PATH . 'models/category.inc');
	 $category = new Category( $this->registry );
	 $pagination =$category->countSnippetByCategory();
	 $this->registry->getObject('template')->getPage()->addTag( 'langs', array( 'SQL', $pagination->getCache() ) ); 	
  }	
  
     /*
	* Metodo para buscar por snippets ordenados por los mas favs
	*
	*
	*/
	
  private function favorites($offset=1)
  { 
      $offset=($offset<=0)?1:$offset;
  	  require_once( FRAMEWORK_PATH . 'models/snippets.inc');
	  $snippets = new Snippets( $this->registry );
	  $pagination = $snippets->listFavorites( $offset );
	  
      if(!$pagination->checkOffset($offset) )
	    $this->registry->getObject('template')->buildFromTemplates(
	    	$this->registry->getObject('constants')->getHeaderTpl(), 
	    	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_logged_base')).'404/'.$this->registry->getObject('constants')->get404Tpl(), 
	    	$this->registry->getObject('constants')->getFooterTpl()
	    	);
	  else
	  { 
		$this->registry->getObject('template')->buildFromTemplates(
			$this->registry->getObject('constants')->getHeaderTpl(), 
			$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_logged_base')).'snippets/'.$this->registry->getObject('constants')->getListTpl(), 
			$this->registry->getObject('constants')->getFooterTpl()
			);
		//cargamos la info de cada snippet
		$this->registry->getObject('template')->getPage()->addTag( 'snippet', array( 'SQL', $pagination->getCache() ) );
		// cargamos el action 
		$this->registry->getObject('template')->getPage()->addTag( 'controller', $this->action ); 
		// cargamos los tipos de ordenacion y los textos a mostrar
		$this->registry->getObject('template')->getPage()->addTag( 'order_controller1', 'popular' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_text1', 'Rating' );
		$this->registry->getObject('template')->getPage()->addTag( 'order_controller2', 'browse' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_text2', 'Recientes' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_controller3', 'commented' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_text3', 'Mas comentados' );
        // cargamos el texto sobre que ordenacion es la aplicada		
        $this->registry->getObject('template')->getPage()->addTag( 'ordered_by', ' más veces marcado como Favorito' );		
		// cargamos el total de snippets
		$this->registry->getObject('template')->getPage()->addTag( 'snippets_count', $pagination->getTotalRows() );		
		$pagination->showPagination($this->controller,$this->action,$this->parameter1,$this->parameter2);
		
		  //Cargamos los top contributors
        $pagination = $snippets->topSnippetsContributors();     
        $this->registry->getObject('template')->getPage()->addTag( 'contributors', array( 'SQL', $pagination->getCache() ) ); 
	    $this->registry->getObject('template')->getPage()->addTag( 'topUserURL', $this->registry->getSetting('avatar_path')); 
	
	    //Cargamos los top tags
	    require_once( FRAMEWORK_PATH . 'models/tags.inc');
	    $tags = new Tags( $this->registry );
	    $pagination = $tags->topSnippetTags();
	    $this->registry->getObject('template')->getPage()->addTag( 'tags', array( 'SQL', $pagination->getCache() ) ); 
	  }	
     
     //cargamos el total de snippet por categoria
	 require_once( FRAMEWORK_PATH . 'models/category.inc');
	 $category = new Category( $this->registry );
	 $pagination =$category->countSnippetByCategory();
	 $this->registry->getObject('template')->getPage()->addTag( 'langs', array( 'SQL', $pagination->getCache() ) ); 	
	 	 
  }	
  
  private function commented($offset=1)
  { 
      $offset=($offset<=0)?1:$offset;
  	  require_once( FRAMEWORK_PATH . 'models/snippets.inc');
	  $snippets = new Snippets( $this->registry );
	  $pagination = $snippets->listCommentedSnippets( $offset );
	  
      if(!$pagination->checkOffset($offset) )
	    $this->registry->getObject('template')->buildFromTemplates(
	    	$this->registry->getObject('constants')->getHeaderTpl(), 
	    	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_logged_base')).'404/'.$this->registry->getObject('constants')->get404Tpl(),
	    	$this->registry->getObject('constants')->getFooterTpl()
	    	);
	  else
	  { 
		$this->registry->getObject('template')->buildFromTemplates(
			$this->registry->getObject('constants')->getHeaderTpl(), 
			$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_logged_base')).'snippets/'.$this->registry->getObject('constants')->getListTpl(), 
			$this->registry->getObject('constants')->getFooterTpl()
			);
		//cargamos la info de cada snippet
		$this->registry->getObject('template')->getPage()->addTag( 'snippet', array( 'SQL', $pagination->getCache() ) );
		// cargamos el action 
		$this->registry->getObject('template')->getPage()->addTag( 'controller', $this->action ); 
		// cargamos los tipos de ordenacion y los textos a mostrar
		$this->registry->getObject('template')->getPage()->addTag( 'order_controller1', 'popular' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_text1', 'Rating' );
		$this->registry->getObject('template')->getPage()->addTag( 'order_controller2', 'browse' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_text2', 'Recientes' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_controller3', 'favorites' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_text3', 'Favoritos' );
        // cargamos el texto sobre que ordenacion es la aplicada		
        $this->registry->getObject('template')->getPage()->addTag( 'ordered_by', ' más Comentados' );		
		// cargamos el total de snippets
		$this->registry->getObject('template')->getPage()->addTag( 'snippets_count', $pagination->getTotalRows() );		
		$pagination->showPagination($this->controller,$this->action,$this->parameter1,$this->parameter2);
		
	    //Cargamos los top contributors
        $pagination = $snippets->topSnippetsContributors();     
        $this->registry->getObject('template')->getPage()->addTag( 'contributors', array( 'SQL', $pagination->getCache() ) ); 
	    $this->registry->getObject('template')->getPage()->addTag( 'topUserURL', $this->registry->getSetting('avatar_path')); 

	    //Cargamos los top tags
	    require_once( FRAMEWORK_PATH . 'models/tags.inc');
	    $tags = new Tags( $this->registry );
	    $pagination = $tags->topSnippetTags();
	    $this->registry->getObject('template')->getPage()->addTag( 'tags', array( 'SQL', $pagination->getCache() ) ); 
	  }	
     
     //cargamos el total de snippet por categoria
	 require_once( FRAMEWORK_PATH . 'models/category.inc');
	 $category = new Category( $this->registry );
	 $pagination =$category->countSnippetByCategory();
	 $this->registry->getObject('template')->getPage()->addTag( 'langs', array( 'SQL', $pagination->getCache() ) ); 	
	 
  }	
 
  
  	/*
	* Metodo para buscar snippets por categoria
	*
	*
	*/
  private function categorySearch($categoryName,$offset=1){
    
	$offset=($offset<=0)?1:$offset;
    require_once( FRAMEWORK_PATH . 'models/snippets.inc');
    $snippets = new Snippets( $this->registry );
	$pagination = $snippets->listByCategory($categoryName,$offset);
	
    if(!$pagination->checkOffset($offset) )
	    $this->registry->getObject('template')->buildFromTemplates(
	    	$this->registry->getObject('constants')->getHeaderTpl(), 
	    	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_logged_base')).'404/'.$this->registry->getObject('constants')->get404Tpl(), 
	    	$this->registry->getObject('constants')->getFooterTpl()
	    	);
	  else
	  { 
		$this->registry->getObject('template')->buildFromTemplates(
			$this->registry->getObject('constants')->getHeaderTpl(), 
			$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_logged_base')).'snippets/'.$this->registry->getObject('constants')->getListTpl(), 
			$this->registry->getObject('constants')->getFooterTpl()
			);
		//cargamos la info de cada snippet
		$this->registry->getObject('template')->getPage()->addTag( 'snippet', array( 'SQL', $pagination->getCache() ) );
		// cargamos el action 
		$this->registry->getObject('template')->getPage()->addTag( 'controller', $this->action ); 
		// cargamos los tipos de ordenacion y los textos a mostrar
		$this->registry->getObject('template')->getPage()->addTag( 'order_controller1', 'popular' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_text1', 'Rating' );
		$this->registry->getObject('template')->getPage()->addTag( 'order_controller2', 'browse' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_text2', 'Recientes' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_controller3', 'commented' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_text3', 'Mas comentados' );
        // cargamos el texto sobre que ordenacion es la aplicada		
        $this->registry->getObject('template')->getPage()->addTag( 'ordered_by', ' con la categoría '.$categoryName);		
		// cargamos el total de snippets
		$this->registry->getObject('template')->getPage()->addTag( 'snippets_count', $pagination->getTotalRows() );		
		$pagination->showPagination($this->controller,$this->action,$this->parameter1,$this->parameter2);
		
		//Cargamos los top contributors
        $pagination = $snippets->topSnippetsContributors();     
        $this->registry->getObject('template')->getPage()->addTag( 'contributors', array( 'SQL', $pagination->getCache() ) ); 
	    $this->registry->getObject('template')->getPage()->addTag( 'topUserURL', $this->registry->getSetting('avatar_path')); 
	
	    //Cargamos los top tags
	    require_once( FRAMEWORK_PATH . 'models/tags.inc');
	    $tags = new Tags( $this->registry );
	    $pagination = $tags->topSnippetTags();
	    $this->registry->getObject('template')->getPage()->addTag( 'tags', array( 'SQL', $pagination->getCache() ) ); 
	
	  }	

    //cargamos el total de snippet por categoria
	 require_once( FRAMEWORK_PATH . 'models/category.inc');
	 $category = new Category( $this->registry );
	 $pagination =$category->countSnippetByCategory();
	 $this->registry->getObject('template')->getPage()->addTag( 'langs', array( 'SQL', $pagination->getCache() ) ); 		  
	
  }
  
  
   	/*
	* Metodo para buscar snippets por usuario
	*
	*
	*/
  private function usernameSearch($username,$offset=1){
    
	$offset=($offset<=0)?1:$offset;
    require_once( FRAMEWORK_PATH . 'models/snippets.inc');
    $snippets = new Snippets( $this->registry );
	$pagination = $snippets->listByUsername($username,$offset);
	
    if(!$pagination->checkOffset($offset) )
	    $this->registry->getObject('template')->buildFromTemplates(
	    	$this->registry->getObject('constants')->getHeaderTpl(), 
	    	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_logged_base')).'404/'.$this->registry->getObject('constants')->get404Tpl(), 
	    	$this->registry->getObject('constants')->getFooterTpl()
	    	);
	  else
	  { 
		$this->registry->getObject('template')->buildFromTemplates(
			$this->registry->getObject('constants')->getHeaderTpl(), 
			$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_logged_base')).'snippets/'.$this->registry->getObject('constants')->getListTpl(), 
			$this->registry->getObject('constants')->getFooterTpl()
			);
		//cargamos la info de cada snippet
		$this->registry->getObject('template')->getPage()->addTag( 'snippet', array( 'SQL', $pagination->getCache() ) );
		// cargamos el action 
		$this->registry->getObject('template')->getPage()->addTag( 'controller', $this->action ); 
		// cargamos los tipos de ordenacion y los textos a mostrar
		$this->registry->getObject('template')->getPage()->addTag( 'order_controller1', 'popular' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_text1', 'Rating' );
		$this->registry->getObject('template')->getPage()->addTag( 'order_controller2', 'browse' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_text2', 'Recientes' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_controller3', 'commented' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_text3', 'Mas comentados' );
        // cargamos el texto sobre que ordenacion es la aplicada		
        $this->registry->getObject('template')->getPage()->addTag( 'ordered_by', ' creados por '.$username);		
		// cargamos el total de snippets
		$this->registry->getObject('template')->getPage()->addTag( 'snippets_count', $pagination->getTotalRows() );		

		$pagination->showPagination($this->controller,$this->action,$this->parameter1,$this->parameter2);
		
		//Cargamos los top contributors
        $pagination = $snippets->topSnippetsContributors();     
        $this->registry->getObject('template')->getPage()->addTag( 'contributors', array( 'SQL', $pagination->getCache() ) ); 
	    $this->registry->getObject('template')->getPage()->addTag( 'topUserURL', $this->registry->getSetting('avatar_path')); 
	
        //Cargamos los top tags
	    require_once( FRAMEWORK_PATH . 'models/tags.inc');
	    $tags = new Tags( $this->registry );
	    $pagination = $tags->topSnippetTags();
	    $this->registry->getObject('template')->getPage()->addTag( 'tags', array( 'SQL', $pagination->getCache() ) ); 
	
	
	  }	

    //cargamos el total de snippet por categoria
	 require_once( FRAMEWORK_PATH . 'models/category.inc');
	 $category = new Category( $this->registry );
	 $pagination =$category->countSnippetByCategory();
	 $this->registry->getObject('template')->getPage()->addTag( 'langs', array( 'SQL', $pagination->getCache() ) ); 
	
  }
  
  
  	/*
	* Metodo para buscar snippets por tag
	*
	*
	*/
  private function tagSearch($tagName,$offset=1){
    
	$offset=($offset<=0)?1:$offset;
    require_once( FRAMEWORK_PATH . 'models/snippets.inc');
    $snippets = new Snippets( $this->registry );
	$pagination = $snippets->listByTag($this->registry->getObject('db')->sanitizeData($tagName),$offset);
	
    if(!$pagination->checkOffset($offset) )
	    $this->registry->getObject('template')->buildFromTemplates(
	    	$this->registry->getObject('constants')->getHeaderTpl(), 
	    	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_logged_base')).'404/'.$this->registry->getObject('constants')->get404Tpl(), 
	    	$this->registry->getObject('constants')->getFooterTpl()
	    	);
	  else
	  { 
		$this->registry->getObject('template')->buildFromTemplates(
			$this->registry->getObject('constants')->getHeaderTpl(), 
			$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_logged_base')).'snippets/'.$this->registry->getObject('constants')->getListTpl(), 
			$this->registry->getObject('constants')->getFooterTpl()
			);
		//cargamos la info de cada snippet
		$this->registry->getObject('template')->getPage()->addTag( 'snippet', array( 'SQL', $pagination->getCache() ) );
		// cargamos el action 
		$this->registry->getObject('template')->getPage()->addTag( 'controller', $this->action ); 
		// cargamos los tipos de ordenacion y los textos a mostrar
		$this->registry->getObject('template')->getPage()->addTag( 'order_controller1', 'popular' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_text1', 'Rating' );
		$this->registry->getObject('template')->getPage()->addTag( 'order_controller2', 'browse' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_text2', 'Recientes' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_controller3', 'commented' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_text3', 'Mas comentados' );
        // cargamos el texto sobre que ordenacion es la aplicada		
        $this->registry->getObject('template')->getPage()->addTag( 'ordered_by', ' con la etiqueta '.$tagName);		
		// cargamos el total de snippets
		$this->registry->getObject('template')->getPage()->addTag( 'snippets_count', $pagination->getTotalRows() );		
		$pagination->showPagination($this->controller,$this->action,$this->parameter1,$this->parameter2);
		
		//Cargamos los top contributors
        $pagination = $snippets->topSnippetsContributors();     
        $this->registry->getObject('template')->getPage()->addTag( 'contributors', array( 'SQL', $pagination->getCache() ) ); 
	    $this->registry->getObject('template')->getPage()->addTag( 'topUserURL', $this->registry->getSetting('avatar_path')); 
	
        //Cargamos los top tags
	    require_once( FRAMEWORK_PATH . 'models/tags.inc');
	    $tags = new Tags( $this->registry );
	    $pagination = $tags->topSnippetTags();
	    $this->registry->getObject('template')->getPage()->addTag( 'tags', array( 'SQL', $pagination->getCache() ) ); 	
	
	  }	

     //cargamos el total de snippet por categoria
	 require_once( FRAMEWORK_PATH . 'models/category.inc');
	 $category = new Category( $this->registry );
	 $pagination =$category->countSnippetByCategory();
	 $this->registry->getObject('template')->getPage()->addTag( 'langs', array( 'SQL', $pagination->getCache() ) ); 	
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
	$me=$this->registry->getObject('authenticate')->getUser()->getUserID();
	$snippets = new Snippets( $this->registry );
	$snippetData = $snippets->getSnippet( $snippetID );
	// Si no encontramos el snippet
    if( $snippetData==null )
	{
	  //pantalla de error
	  $this->registry->getObject('template')->buildFromTemplates(
	  	$this->registry->getObject('constants')->getHeaderTpl(), 
	  	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_logged_base')).'404/'.$this->registry->getObject('constants')->get404Tpl(), 
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
		$this->registry->getObject('template')->getPage()->addTag( 'fav_msg', "fa-heart" );  
	  }else
	  {
	    $this->registry->getObject('template')->getPage()->addTag( 'action',"fav"); 
		$this->registry->getObject('template')->getPage()->addTag( 'fav_msg', "fa-heart-o" ); 
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

	  // guardamos en el Log
	  require_once FRAMEWORK_PATH . 'models/snippet_log.inc';
      $log = new Snippet_Log($this->registry,$me,$snippetID,'user.snippet.view');
	  $log->save();


    }		
  }
  
  /*
  * Metodo que redirecciona para agregar un nuevo snippet
  *
  **/
  private function addSnippet()
  {
  	require_once( FRAMEWORK_PATH . 'models/category.inc');
    $snippets = new Category( $this->registry );
	$pagination = $snippets->listCategory();
    $this->registry->getObject('template')->buildFromTemplates(
    	$this->registry->getObject('constants')->getHeaderTpl(), 
    	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_logged_base')).'snippets/'.$this->registry->getObject('constants')->getAddTpl(), 
    	$this->registry->getObject('constants')->getFooterTpl());
    $this->registry->getObject('template')->getPage()->addTag( 'category', array( 'SQL', $pagination->getCache() ) ); 
	$this->registry->getObject('template')->getPage()->addTag('error_msg','error-msg');	
	$this->registry->getObject('template')->getPage()->addTag('error_text','');		
	$this->registry->getObject('template')->getPage()->addTag(
		$this->registry->getObject('constants')->getTag('snippet_editor_message'),
		utf8_decode (
	      $this->registry->getSetting(
		    $this->registry->getObject('constants')->getTag('snippet_editor_message'))
		)
	);	
	
  }
  
  /*
  * Metodo que guarda el snippet en BBDD y ademas guarda los tags asociados 
  *   Primero: Comprueba que existan los tags y retorna los ids sino guarda los tags y retorna los id.
  *   Segundo: Guarda el snippet con los id's de los tags creados.
  */
  private function registerSnippet(){
  	
     require_once FRAMEWORK_PATH . 'controllers/snippets/registrationcontroller.inc';
	  $rc = new Registrationcontroller( $this->registry,$this->registry->getObject('authenticate')->getUser()->getUserID()  );
	  //TODO. ver si se redirecciona a browse o a una pagina intermedia que notifique del registro (me inclino mas por esto ultimo)
	  header('Location: browse');  	
  	}
	
	
	/*
	* Metodo Ajax, solo funcionará por Ajax
	* si se llama por otra forma se debe redireccionar al home
	*
	*/
	private function saveFavorite(){	
	
       //TODO comporbar que sea por ajax sino redireccionar a home
	   require_once( FRAMEWORK_PATH . 'models/snippets_favoritos.inc');
	   $me = $this->registry->getObject('authenticate')->getUser()->getUserID();
	   $snippetFav = new Snippets_Favoritos($this->registry,$me,$_SESSION['snippet']['ID']);	   
	   $snippetFav->save();
	   
	   $snippet_owner=$_SESSION['snippet']['ID_User'];
	   // registramos en el log y gamificamos
	   $data['id_snippet']=$_SESSION['snippet']['ID'];
	   $date = new DateTime();
	   // registramos en el log y gamificamos
	   $this->registry->getObject('event')->notify('user.fav.add',$me,$_SERVER['REMOTE_ADDR'],$this->registry->getObject('util')->prepareData($data),$me,$me.'Ha guardado tu favorito',$date->getTimestamp(),3);
		   
	   // Determinamos quien es el dueno, si es diferente al que hace like sumamos
	   if($me!=$snippet_owner){
	    $this->registry->getObject('event')->notify('user.fav.get',$snippet_owner,$_SERVER['REMOTE_ADDR'],$this->registry->getObject('util')->prepareData($data),$me,$this->registry->getObject('db')->sanitizeData($this->registry->getObject('util')->getSnippetNotification('user.fav.get',$snippet_owner,$data['id_snippet'])),$date->getTimestamp(),0);
	   }
	   
	   require_once FRAMEWORK_PATH . 'models/snippet_log.inc';
       $log = new Snippet_Log($this->registry,$me,$_SESSION['snippet']['ID'],'user.fav.add');
	   $log->save();	   	   
	   
	   
	   //TODO poner en constante
	   echo "unfav";
  	   exit();
  	}
	
	/*
	* Metodo Ajax, solo funcionará por Ajax
	* si se llama por otra forma se debe redireccionar al home
	*
	*/
	private function deleteFavorite(){	
       //TODO comporbar que sea por ajax sino redireccionar a home	
	   require_once( FRAMEWORK_PATH . 'models/snippets_favoritos.inc');
	   $me=$this->registry->getObject('authenticate')->getUser()->getUserID();
	   $snippetFav=new Snippets_Favoritos($this->registry,$me,$_SESSION['snippet']['ID']); 
	   $snippetFav->delete();	   
	   //registramos en el log y gamificamos
	   $data['id_snippet']=$_SESSION['snippet']['ID'];
       $date = new DateTime();
	   // registramos en el log y gamificamos
	   $this->registry->getObject('event')->notify('user.fav.del',$me,$_SERVER['REMOTE_ADDR'],$this->registry->getObject('util')->prepareData($data),$me,$me.'Ha borrado tu favorito',$date->getTimestamp(),0);

      require_once FRAMEWORK_PATH . 'models/snippet_log.inc';
      $log = new Snippet_Log($this->registry,$me,$_SESSION['snippet']['ID'],'user.fav.del');
	   $log->save();	   	   
	   
	   //TODO poner en constante
	   echo "fav";
  	   exit();
  	}
	
	/*
	* Metodo Ajax, solo funcionará por Ajax para guardar y mostrar los comentarios
	* si se llama por otra forma se debe redireccionar al home
	* 
	*/
	private function comment(){	
       //TODO comporbar que sea por ajax sino redireccionar a home	
	   require_once( FRAMEWORK_PATH . 'models/comment_snippet.inc');
	   $me=$this->registry->getObject('authenticate')->getUser()->getUserID();
	   $comment=new Comment_Snippet($this->registry);
	   $comment->setComment( htmlspecialchars($this->registry->getObject('db')->sanitizeData($_POST['comment']),ENT_IGNORE));
	   $comment->setIDUser($me);
	   $comment->setIDSnippet($_SESSION['snippet']['ID']);
	   $comment->setAdded(date("Y-m-d H:i:s")); // fecha de ahora	
	   $comment->save();
	   
	   
	   //registramos en el log y gamificamos
	   $data['id_snippet']=$_SESSION['snippet']['ID'];

       $date = new DateTime();
	   $this->registry->getObject('event')->notify('user.comment.add',$me,$_SERVER['REMOTE_ADDR'],$this->registry->getObject('util')->prepareData($data),$me,$me.'Ha Agregado un comentario',$date->getTimestamp(),3); 

	   $snippet_owner=$_SESSION['snippet']['ID_User'];
	   // Determinamos quien es el dueno, si es diferente al que hace like sumamos
	   if($me!=$snippet_owner){
	    $this->registry->getObject('event')->notify('user.comment.get',$snippet_owner,$_SERVER['REMOTE_ADDR'],$this->registry->getObject('util')->prepareData($data),$me,$me.'Ha Agregado un comentario',$date->getTimestamp(),0);
	   }
	   
      require_once FRAMEWORK_PATH . 'models/snippet_log.inc';
      $log = new Snippet_Log($this->registry,$me,$_SESSION['snippet']['ID'],'user.comment.add');
	  $log->save();	   
	   
	   
	   // Obtenemos todos los comentarios para este snippet
	   echo $comment->getCommentsBySnippet($_SESSION['snippet']['ID']);
  	   exit();
  	}	
	
	/*
	* Metodo Ajax, solo funcionará por Ajax para mostrar los comentarios
	* si se llama por otra forma se debe redireccionar al home
	*
	*/
	private function showComments(){
	  
	  //TODO comporbar que sea por ajax sino redireccionar a home	
	   require_once( FRAMEWORK_PATH . 'models/comment_snippet.inc');
	   $me=$this->registry->getObject('authenticate')->getUser()->getUserID();
	   $comment=new Comment_Snippet($this->registry);
	   $comment->setIDUser($me);
	   $comment->setIDSnippet($_SESSION['snippet']['ID']);
	   echo $comment->getCommentsBySnippet($_SESSION['snippet']['ID']);
  	   exit();
	  
	}
	
	
   	/*
	* Metodo Ajax, solo funcionará por Ajax para guardar y mostrar el rating
	* si se llama por otra forma se debe redireccionar al home
	*
	*/
	private function rating(){
	  
	  //TODO comporbar que sea por ajax sino redireccionar a home	
	   require_once( FRAMEWORK_PATH . 'models/rating_snippet.inc');
	   $rating=new Rating_Snippet($this->registry);
	   $me=$this->registry->getObject('authenticate')->getUser()->getUserID();
	   $rating->setIDUser($me);
	   $rating->setIDSnippet($_SESSION['snippet']['ID']);
	   $rating->setVoto($_POST['rating']);
	   $rating->save();
	   
	   //registramos en el log y gamificamos
	   $data['id_snippet'] = $_SESSION['snippet']['ID'];
	   $data['rating'] = $_POST['rating'];
       $snippet_owner = $_SESSION['snippet']['ID_User'];

	   $date = new DateTime();
	   $this->registry->getObject('event')->notify('user.rating.add',$me,$_SERVER['REMOTE_ADDR'],$this->registry->getObject('util')->prepareData($data),$me,$me.' Ha evaluado un snippet',$date->getTimestamp(),3);
       
       // Determinamos quien es el dueno, si es diferente al que hace like sumamos
	   if($me!=$snippet_owner){
	    $this->registry->getObject('event')->notify('user.rating.get',$snippet_owner,$_SERVER['REMOTE_ADDR'],$this->registry->getObject('util')->prepareData($data),$me,$me.'Han evaluado un snippet',$date->getTimestamp(),0);
	   }
       require_once FRAMEWORK_PATH . 'models/snippet_log.inc';
       $log = new Snippet_Log($this->registry,$me,$_SESSION['snippet']['ID'],'user.rating.add');
	   $log->save();
				   
	   //TODO poner en consatante
	   echo "ok";
  	   exit();
	}	
	

	
}
			
?>