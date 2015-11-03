<?php

/**
 * Controlador para el registro de reglas
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
		    $idRule = "";
			// Guardamos la regla
			require_once FRAMEWORK_PATH . 'models/gamification_rules.inc';
			$rule = new Gamification_Rules( $this->registry);
			$rule->setEventName( htmlentities($this->registry->getObject('db')->sanitizeData( $_POST['eventName'] ),ENT_COMPAT,'UTF-8') );
			$rule->setIDBadge( htmlspecialchars($this->registry->getObject('db')->sanitizeData($_POST['image']),ENT_IGNORE));
			$rule->setThreshold( htmlspecialchars($this->registry->getObject('db')->sanitizeData($_POST['threshold']),ENT_IGNORE)); 
            $rule->setExperiencePoints( htmlspecialchars($this->registry->getObject('db')->sanitizeData($_POST['xp']),ENT_IGNORE)); 
            $rule->setReputationPoints( htmlspecialchars($this->registry->getObject('db')->sanitizeData($_POST['rp']),ENT_IGNORE)); 
            $rule->setLevel_points( htmlspecialchars($this->registry->getObject('db')->sanitizeData($_POST['lp']),ENT_IGNORE)); 
            $rule->setTitle(htmlspecialchars($this->registry->getObject('db')->sanitizeData($_POST['title']),ENT_IGNORE));
            $rule->setDescription(htmlspecialchars($this->registry->getObject('db')->sanitizeData($_POST['description']),ENT_IGNORE));
			$idRule = $rule->save();		
		
		    // TODO poner el log de administracion
         	//require_once FRAMEWORK_PATH . 'models/admin_log.inc';
         	//$log = new Admin_Log($this->registry,$user,$idSnippet,'user.snippet.add');
			//$log->save();
		}
	}	
	
	
}

?>