<?php

/**
 * Controlador para el registro de Media
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
		    $idCategoria = "";
			// Guardamos la categoria
			require_once FRAMEWORK_PATH . 'models/category.inc';
			$category = new Category( $this->registry);
			$category->setName( htmlentities($this->registry->getObject('db')->sanitizeData( $_POST['categoryName'] ),ENT_COMPAT,'UTF-8') );
			$category->setDescription( htmlspecialchars($this->registry->getObject('db')->sanitizeData($_POST['categoryDescription']),ENT_IGNORE));
			$category->setImageName( htmlspecialchars($this->registry->getObject('db')->sanitizeData($_POST['image']),ENT_IGNORE)); 		
			$idCategoria = $category->save();		
		
		    // TODO poner el log de administracion
         	//require_once FRAMEWORK_PATH . 'models/admin_log.inc';
         	//$log = new Admin_Log($this->registry,$user,$idSnippet,'user.snippet.add');
			//$log->save();
		}
	}	
	
	
}

?>