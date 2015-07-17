<?php
 /**
 * Controlador para links new/ browse /
 * @version 1.0
 * @author  Oscar Garcia
 */	
class Linkscontroller{
	
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
					  $this->browse(intval($this->parameter1),'rating');
					  break;
					
					case 'favorites':
					  $this->browse(intval($this->parameter1),'faved');
					  break;
					
                    case 'commented':
					  $this->browse(intval($this->parameter1),'comments');
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
					  $this->addLink();
					  break;
					  
					case 'register':
					  $this->registerLink();
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
	* Metodo para buscar por links ordenados por el mas reciente
	*
	*
	*/
    private function browse($offset=1,$order='rawDate')
    {   
	  require_once( FRAMEWORK_PATH . 'models/links.inc');
      $offset=($offset<=0)?1:$offset;
	  $links = new Links( $this->registry );
	  $pagination = $links->listLinks( $offset,$order );
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
			$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_logged_base')).'links/'.$this->registry->getObject('constants')->getListTpl(), 
			$this->registry->getObject('constants')->getFooterTpl()
			);
	    //cargamos la info de cada link
		$this->registry->getObject('template')->getPage()->addTag( 'link', array( 'SQL', $pagination->getCache() ) );
		
		// cargamos los tipos de ordenacion y los textos a mostrar
		$this->registry->getObject('template')->getPage()->addTag( 'order_controller1', 'popular' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_text1', 'Mas populares' );
		$this->registry->getObject('template')->getPage()->addTag( 'order_controller2', 'favorites' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_text2', 'Favoritos' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_controller3', 'commented' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_text3', 'Mas comentados' );
		$this->registry->getObject('template')->getPage()->addTag( 'order_controller4', 'browse' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_text4', 'Recientes' );
		
		$pagination->showPagination($this->controller,$this->action,$this->parameter1,$this->parameter2);
		
		//Cargamos los top contributors
        $pagination = $links->topContributors();     
        $this->registry->getObject('template')->getPage()->addTag( 'contributors', array( 'SQL', $pagination->getCache() ) ); 
	    $this->registry->getObject('template')->getPage()->addTag( 'topUserURL', $this->registry->getSetting('avatar_path')); 
	    
    	//Cargamos los top tags
    	$pagination = $links->topTags();
	    $this->registry->getObject('template')->getPage()->addTag( 'tags', array( 'SQL', $pagination->getCache() ) ); 
		
	  }		
	
  }	
  
   	/*
	* Metodo para buscar links por usuario
	*
	*
	*/
  private function usernameSearch($username,$offset=1){
    
	$offset=($offset<=0)?1:$offset;
    require_once( FRAMEWORK_PATH . 'models/links.inc');
    $links = new Links( $this->registry );
	$pagination = $links->listByUsername($username,$offset);
	
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
			$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_logged_base')).'links/'.$this->registry->getObject('constants')->getListTpl(), 
			$this->registry->getObject('constants')->getFooterTpl()
			);
		//cargamos la info de cada links
		$this->registry->getObject('template')->getPage()->addTag( 'link', array( 'SQL', $pagination->getCache() ) );
				
		// cargamos los tipos de ordenacion y los textos a mostrar
		$this->registry->getObject('template')->getPage()->addTag( 'order_controller1', 'popular' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_text1', 'Mas populares' );
		$this->registry->getObject('template')->getPage()->addTag( 'order_controller2', 'favorites' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_text2', 'Favoritos' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_controller3', 'commented' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_text3', 'Mas comentados' );
		$this->registry->getObject('template')->getPage()->addTag( 'order_controller4', 'browse' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_text4', 'Recientes' );
		
		$pagination->showPagination($this->controller,$this->action,$this->parameter1,$this->parameter2);
		
		//Cargamos los top contributors
        $pagination = $links->topContributors();     
        $this->registry->getObject('template')->getPage()->addTag( 'contributors', array( 'SQL', $pagination->getCache() ) ); 
	    $this->registry->getObject('template')->getPage()->addTag( 'topUserURL', $this->registry->getSetting('avatar_path')); 
	
        //Cargamos los top tags
    	$pagination = $links->topTags();
	    $this->registry->getObject('template')->getPage()->addTag( 'tags', array( 'SQL', $pagination->getCache() ) ); 
	  }
	
  }
  
  	/*
	* Metodo para buscar links por tag
	*
	*
	*/
  private function tagSearch($tagName,$offset=1){
    
	$offset=($offset<=0)?1:$offset;
    require_once( FRAMEWORK_PATH . 'models/links.inc');
    $links = new Links( $this->registry );
	$pagination = $links->listByTag($this->registry->getObject('db')->sanitizeData($tagName),$offset);
	
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
			$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_logged_base')).'links/'.$this->registry->getObject('constants')->getListTpl(), 
			$this->registry->getObject('constants')->getFooterTpl()
			);
		//cargamos la info de cada links
		$this->registry->getObject('template')->getPage()->addTag( 'link', array( 'SQL', $pagination->getCache() ) );
		
        // cargamos los tipos de ordenacion y los textos a mostrar
		$this->registry->getObject('template')->getPage()->addTag( 'order_controller1', 'popular' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_text1', 'Mas populares' );
		$this->registry->getObject('template')->getPage()->addTag( 'order_controller2', 'favorites' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_text2', 'Favoritos' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_controller3', 'commented' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_text3', 'Mas comentados' );
		$this->registry->getObject('template')->getPage()->addTag( 'order_controller4', 'browse' ); 
		$this->registry->getObject('template')->getPage()->addTag( 'order_text4', 'Recientes' );
		
		$pagination->showPagination($this->controller,$this->action,$this->parameter1,$this->parameter2);
		
		//Cargamos los top contributors
        $pagination = $links->topContributors();     
        $this->registry->getObject('template')->getPage()->addTag( 'contributors', array( 'SQL', $pagination->getCache() ) ); 
	    $this->registry->getObject('template')->getPage()->addTag( 'topUserURL', $this->registry->getSetting('avatar_path')); 
	
        //Cargamos los top tags
    	$pagination = $links->topTags();
	    $this->registry->getObject('template')->getPage()->addTag( 'tags', array( 'SQL', $pagination->getCache() ) ); 
	
	  }	
  }
  
  /*
  * Metodo que redirecciona a la plantilla de ver
  *
  **/
  private function view($linkID)
  {
  	require_once( FRAMEWORK_PATH . 'models/links.inc');
  	require_once( FRAMEWORK_PATH . 'models/tags_links.inc');
	require_once( FRAMEWORK_PATH . 'models/rating_links.inc');
	$link = new Links( $this->registry );
	$data = $link->getLink( $linkID );
	
	// Si no encontramos el link
    if( $data==null )
	{
	  //pantalla de error
	  $this->registry->getObject('template')->buildFromTemplates(
	  	$this->registry->getObject('constants')->getHeaderTpl(), 
	  	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_logged_base')).'404/'.$this->registry->getObject('constants')->get404Tpl(), 
	  	$this->registry->getObject('constants')->getFooterTpl()
	  	);
	}
	else
	{ 
	  //Si lo encontramos 
	  // Definimos la pagina de view 
	  $this->registry->getObject('template')->buildFromTemplates(
	  	$this->registry->getObject('constants')->getHeaderTpl(), 
	  	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_logged_base')).'links/'.$this->registry->getObject('constants')->getViewTpl(), 
	  	$this->registry->getObject('constants')->getFooterTpl()
	  	);
	  // Cargamos los datos
	  $this->registry->getObject('template')->getPage()->addTag('title',$data['title']);
	  $this->registry->getObject('template')->getPage()->addTag('description',$data['description']);
	  $this->registry->getObject('template')->getPage()->addTag('url',$data['url']);
	  $this->registry->getObject('template')->getPage()->addTag('rating',$data['rating']);
	  
	  // Comprobamos si el usuario lo ha guardado como favorito
	  // Si es asi colocamos la action y el icono correspondiente
	  if($link->isFavorited($linkID,$this->registry->getObject('authenticate')->getUser()->getUserID())){
	    $this->registry->getObject('template')->getPage()->addTag( 'action', "unfav" );
		$this->registry->getObject('template')->getPage()->addTag( 'fav_msg', "fa-heart" );  
	  }else
	  {
	    $this->registry->getObject('template')->getPage()->addTag( 'action',"fav"); 
		$this->registry->getObject('template')->getPage()->addTag( 'fav_msg', "fa-heart-o" ); 
	  }
	  
	  
	  // Cargamos los tags
      $tags= new Tags_Links( $this->registry );
      $pagination = $tags->listTagsByLink($linkID);
      if( $pagination->getNumRowsPage() > 0 )
	  {
        $this->registry->getObject('template')->getPage()->addTag( 'tags', array( 'SQL', $pagination->getCache() ) );    	  
      }
	
	  // Validamos el rating
	  // Si puede o no hacer rating
	  $rated= new Rating_Links( $this->registry );
      $this->registry->getObject('template')->getPage()->addTag( 'rating_readonly',$rated->isRatedByUser($linkID,$this->registry->getObject('authenticate')->getUser()->getUserID()) );  
      
	  // cargamos los related
	  $pagination =$tags->getRelatedSnippets($linkID);
      if( $pagination->getNumRowsPage() > 0 )
	  {
        $this->registry->getObject('template')->getPage()->addTag( 'related', array( 'SQL', $pagination->getCache() ) );    	  
      }	
	  
	  //Guardamos la info en session para los metodos AJAX
	  $this->registry->getObject('util')->storeToSession('link',$link->getLink($linkID));
    }		
  }
  
  
  
  /*
  * Metodo que redirecciona para agregar un nuevo link
  *
  **/
  private function addLink()
  {
     $this->registry->getObject('template')->buildFromTemplates(
     	$this->registry->getObject('constants')->getHeaderTpl(),
     	$this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_logged_base')).'links/'.$this->registry->getObject('constants')->getAddTpl(), 
     	$this->registry->getObject('constants')->getFooterTpl()
     	);
	  $this->registry->getObject('template')->getPage()->addTag('error_msg','error-msg');	
	  $this->registry->getObject('template')->getPage()->addTag('error_text','');	
  }
  
  /*
  * Metodo que guarda el link  en BBDD y ademas guarda los tags asociados 
  *   Primero: Comprueba que existan los tags y retorna los ids sino guarda los tags y retorna los id.
  *   Segundo: Guarda el link con los id's de los tags creados.
  */
  private function registerLink(){
     require_once FRAMEWORK_PATH . 'controllers/links/registrationcontroller.inc';
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
	   require_once( FRAMEWORK_PATH . 'models/favorites_links.inc');
	   $me=$this->registry->getObject('authenticate')->getUser()->getUserID();
	   $fav=new Favorites_Links($this->registry,$me,$_SESSION['link']['ID']);	   
	   $fav->save();
	   
	   $link_owner=$_SESSION['link']['ID_User'];
	   // registramos en el log y gamificamos
	   $data['id_links']=$_SESSION['link']['ID'];
	   $this->registry->getObject('event')->notify('user.fav.add',$me,$_SERVER['REMOTE_ADDR'],$this->registry->getObject('util')->prepareData($data));
	   
	   // Determinamos quien es el dueno, si es diferente al que hace like sumamos
	   if($me!=$link_owner){
	    $this->registry->getObject('event')->notify('user.fav.get',$link_owner,$_SERVER['REMOTE_ADDR'],$this->registry->getObject('util')->prepareData($data));
	   }
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
	   require_once( FRAMEWORK_PATH . 'models/favorites_links.inc');
	   $me=$this->registry->getObject('authenticate')->getUser()->getUserID();
	   $fav=new Favorites_Links($this->registry,$me,$_SESSION['link']['ID']); 
	   $fav->delete();	
	   //registramos en el log y gamificamos
	   $data['id_Links']=$_SESSION['link']['ID'];
	   $this->registry->getObject('event')->notify('user.fav.del',$me,$_SERVER['REMOTE_ADDR'],$this->registry->getObject('util')->prepareData($data));
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
	   require_once( FRAMEWORK_PATH . 'models/comments_links.inc');
	   $me=$this->registry->getObject('authenticate')->getUser()->getUserID();
	   $comment=new Comments_Links($this->registry);
	   $comment->setComment( htmlspecialchars($this->registry->getObject('db')->sanitizeData($_POST['comment']),ENT_IGNORE));
	   $comment->setIDUser($me);
	   $comment->setIDLink($_SESSION['link']['ID']);
	   $comment->setAdded(date("Y-m-d H:i:s")); // fecha de ahora	
	   $comment->save();
	   
	   
	   //registramos en el log y gamificamos
	   $data['id_snippet']=$_SESSION['link']['ID'];
	   $this->registry->getObject('event')->notify('user.comment.add',$me,$_SERVER['REMOTE_ADDR'],$this->registry->getObject('util')->prepareData($data)); 
	   $snippet_owner=$_SESSION['link']['ID_User'];
	   // Determinamos quien es el dueno, si es diferente al que hace like sumamos
	   if($me!=$snippet_owner){
	    $this->registry->getObject('event')->notify('user.comment.get',$snippet_owner,$_SERVER['REMOTE_ADDR'],$this->registry->getObject('util')->prepareData($data));
	   }
	   
	   // Obtenemos todos los comentarios para este link
	   echo $comment->getCommentsByLink($_SESSION['link']['ID']);
  	   exit();
  	}	
	
	/*
	* Metodo Ajax, solo funcionará por Ajax para mostrar los comentarios
	* si se llama por otra forma se debe redireccionar al home
	*
	*/
	private function showComments(){
	  
	  //TODO comporbar que sea por ajax sino redireccionar a home	
	   require_once( FRAMEWORK_PATH . 'models/comments_links.inc');
	   $me=$this->registry->getObject('authenticate')->getUser()->getUserID();
	   $comment=new Comments_Links($this->registry);
	   $comment->setIDUser($me);
	   $comment->setIDLink($_SESSION['link']['ID']);
	   echo $comment->getCommentsByLink($_SESSION['link']['ID']);
  	   exit();
	  
	}
	
	
   	/*
	* Metodo Ajax, solo funcionará por Ajax para guardar y mostrar el rating
	* si se llama por otra forma se debe redireccionar al home
	*
	*/
	private function rating(){
	  
	  //TODO comporbar que sea por ajax sino redireccionar a home	
	   require_once( FRAMEWORK_PATH . 'models/rating_links.inc');
	   $rating=new Rating_Links($this->registry);
	   $me=$this->registry->getObject('authenticate')->getUser()->getUserID();
	   $rating->setIDUser($me);
	   $rating->setIDLink($_SESSION['link']['ID']);
	   $rating->setVoto($_POST['rating']);
	   $rating->save();
	   
	   //registramos en el log y gamificamos
	   $data['id_links']=$_SESSION['link']['ID'];
	   $data['rating']=$_POST['rating'];
	   $this->registry->getObject('event')->notify('user.rating.add',$me,$_SERVER['REMOTE_ADDR'],$this->registry->getObject('util')->prepareData($data));
	   //TODO poner en consatante
	   echo "ok";
  	   exit();
	}	
	

	
}
			
?>