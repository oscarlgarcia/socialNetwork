<?php

/**
 * Controlador para el registro de snippets
 */
class Registrationcontroller{
	
	/**
	 * Objeto para el Registro
	 */
	private $registry;
	
	/**
	 * Errores en el registro
	 */
	private $registrationErrors = array();
	
	/**
	 * Array de error label classes - nos permite marcar un campo con un color diferente, para indicar donde estuvo el error
	 */
	private $registrationErrorLabels = array();
	
	/**
	 * Valores que se han enviado para el registro
	 */
	private $submittedValues = array();
	
	/**
	 * Valores "sanitizados" listos para pasarlos a la bd"
	 */
	private $sanitizedValues = array();
	
	/**
	 * 1 si el usuario se activa de una vez sino se enviará un email
	 */
	private $activeValue = 0;
	
	
	/*
	* Constructor del controlador
	*/
	public function __construct( Registry $registry, $user )
	{
		$this->registry = $registry;
		if( isset( $_POST ) && count( $_POST ) > 0 )
		{
		    $idLinks="";
			$idTags= array();
			$idTags_links= array();
			// Guardamos el Link
			require_once FRAMEWORK_PATH . 'models/links.inc';
			$links = new Links( $this->registry);
			$links->setTitle( htmlentities($this->registry->getObject('db')->sanitizeData( $_POST['title'] ),ENT_COMPAT,'UTF-8') );
			$links->setDescription( htmlentities($this->registry->getObject('db')->sanitizeData( $_POST['description']),ENT_COMPAT,'UTF-8'));
			$links->setURL( $this->registry->getObject('db')->sanitizeData( $_POST['url'] ) ); 
			$links->setIdUser( $this->registry->getObject('db')->sanitizeData($user));
			$links->setRating(0);
			$links->setTotalVotes(0);			
			$links->setAdded(date("Y-m-d H:i:s")); // fecha de ahora	
			$idLinks=$links->save();		
		
			//Guardamos los Tags
			require_once FRAMEWORK_PATH . 'models/tags.inc';
			// leemos los tags y los separamos por comas
			$tags=explode(",", $this->registry->getObject('db')->sanitizeData(htmlentities($_POST['tags'])));
               
			foreach($tags as $clave=>$value)
			{
			  $myTag = new Tags( $this->registry);
			  $myTag->setName(strtolower($value));
			  $idTags[]=$myTag->save();
			}
			
			//Guardamos la relacion entre tags y link
			require_once FRAMEWORK_PATH . 'models/tags_links.inc';
			//Por cada Tag guardamos su relacion con el link
			foreach($idTags as $clave=>$value)
			{
			  $myTag_links = new Tags_Links( $this->registry);
			  $myTag_links->setIDTag($value);
			  $myTag_links->setIDLinks($idLinks);
			  $idTags_links[]=$myTag_links->save();
			}
			
			// registramos en el log y gamificamos
			$data['link_name']=$links->getTitle();
	        $this->registry->getObject('event')->notify('user.link.add',$user,$_SERVER['REMOTE_ADDR'],$this->registry->getObject('util')->prepareData($data));
			
         	require_once FRAMEWORK_PATH . 'models/link_log.inc';
         	$log = new Link_Log($this->registry,$user,$idLinks,'user.link.add');
			$log->save();

			//TODO poner la pagina que debemos mostrar
			//$this->registry->redirectUser( array('profile', 'view', 'edit' ), 'Profile saved', 'The changes to your profile have been saved', false );
		}
	}	
	
	
}

?>