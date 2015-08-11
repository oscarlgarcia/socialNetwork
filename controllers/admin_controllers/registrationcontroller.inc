<?php

/**
 * Controlador para el registro de Controladores
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
		    $idSnippet="";
			$idTags= array();
			$idTags_snippet= array();
			// Guardamos el Snippet
			require_once FRAMEWORK_PATH . 'models/snippets.inc';
			$snippet = new Snippets( $this->registry);
			$snippet->setTitle( htmlentities($this->registry->getObject('db')->sanitizeData( $_POST['title'] ),ENT_COMPAT,'UTF-8') );
			$snippet->setDescription( htmlentities($this->registry->getObject('db')->sanitizeData( $_POST['description']),ENT_COMPAT,'UTF-8'));
			$snippet->setCode( $this->registry->getObject('db')->sanitizeData( $_POST['code'] ) );
			$snippet->setCategory( $this->registry->getObject('db')->sanitizeData( $_POST['category'] ) );
			$snippet->setIdUser( $this->registry->getObject('db')->sanitizeData($user));
			$snippet->setRating(0);
			$snippet->setTotalVotes(0);	
			$snippet->setOperationalStatus(3); // Pendiente de aprobar		
			$snippet->setAdded(date("Y-m-d H:i:s")); // fecha de ahora	
			$idSnippet=$snippet->save();		
		
			//Guardamos los Tags
			require_once FRAMEWORK_PATH . 'models/tags.inc';
			// leemos los tags y los separamos por comas
			$tags=explode(",", htmlentities($this->registry->getObject('db')->sanitizeData($_POST['tags'])));
          	
			foreach($tags as $clave=>$value)
			{
			  $myTag = new Tags( $this->registry);
			  $myTag->setName(strtolower($value));
			  $idTags[]=$myTag->save();
			}
			
			//Guardamos la relacion entre tags y snippet
			require_once FRAMEWORK_PATH . 'models/tags_snippet.inc';
			//Por cada Tag guardamos su relacion con el snippet
			
			foreach($idTags as $clave=>$value)
			{
			  $myTag_snippet = new Tags_Snippet( $this->registry);
			  $myTag_snippet->setIDTag($value);
			  $myTag_snippet->setIDSnippet($idSnippet);
			  $idTags_snippet[]=$myTag_snippet->save();
			}
			
			// registramos en el log y gamificamos
			$data['snippet_name']=$snippet->getTitle();
	        $this->registry->getObject('event')->notify('user.snippet.add',$user,$_SERVER['REMOTE_ADDR'],$this->registry->getObject('util')->prepareData($data));
			
         	require_once FRAMEWORK_PATH . 'models/snippet_log.inc';
         	$log = new Snippet_Log($this->registry,$user,$idSnippet,'user.snippet.add');
			$log->save();
			
			//TODO poner la pagina que debemos mostrar
			//$this->registry->redirectUser( array('profile', 'view', 'edit' ), 'Profile saved', 'The changes to your profile have been saved', false );
		}
	}	
	
	
}

?>