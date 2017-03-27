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
		    $idController = "";
			// Guardamos el Controlador
			require_once FRAMEWORK_PATH . 'models/controller.inc';
			$controller = new Controller( $this->registry);
			$controller->setControllerName( htmlentities($this->registry->getObject('db')->sanitizeData( $_POST['controller_name'] ),ENT_COMPAT,'UTF-8') );
			$controller->setDescription( htmlspecialchars($this->registry->getObject('db')->sanitizeData($_POST['controller_description']),ENT_IGNORE));
			$controller->setAuthRequired(htmlspecialchars($this->registry->getObject('db')->sanitizeData($_POST['required']),ENT_IGNORE));
			$controller->setActive(3); // Pendiente de aprobar		
			$controller->setCreated(date("Y-m-d H:i:s")); // fecha de ahora	
			$idController = $controller->save();		
		
		    // TODO poner el log de administracion
         	//require_once FRAMEWORK_PATH . 'models/admin_log.inc';
         	//$log = new Admin_Log($this->registry,$user,$idSnippet,'user.snippet.add');
			//$log->save();
		}
	}	
	
	
}

?>