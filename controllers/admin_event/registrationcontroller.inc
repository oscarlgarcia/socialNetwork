<?php

/**
 * Controlador para el registro de Settings
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
		    // Guardamos el Evento
			require_once FRAMEWORK_PATH . 'models/event.inc';
			$event = new Event( $this->registry);
            if (!$event->isSaved($_POST['eventName']))
            {
              $event->setEventName( htmlentities($this->registry->getObject('db')->sanitizeData( $_POST['eventName'] ),ENT_COMPAT,'UTF-8') );
			  $event->setEventDescription( htmlentities($this->registry->getObject('db')->sanitizeData( $_POST['eventDescription'] ),ENT_COMPAT,'UTF-8') );
			  $event->setEventImage( htmlentities($this->registry->getObject('db')->sanitizeData( $_POST['eventImage'] ),ENT_COMPAT,'UTF-8') );
			  $idEvent = $event->save();		
		      // TODO poner el log de administracion
         	  //require_once FRAMEWORK_PATH . 'models/admin_log.inc';
         	  //$log = new Admin_Log($this->registry,$user,$idSnippet,'user.snippet.add');
			  //$log->save();
              header('Location: add'); 
            }else
            {
              $this->registry->getObject('template')->buildFromTemplates(
    	        $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getHeaderTpl(), 
                $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).'event/'.$this->registry->getObject('constants')->getAddTpl(),
     	        $this->registry->getSetting($this->registry->getObject('constants')->getConstant('pages_admin_base') ).$this->registry->getObject('constants')->getFooterTpl()
    	      );
              $this->registry->getObject('template')->getPage()->addTag('error_msg',' ');	
	          $this->registry->getObject('template')->getPage()->addTag('error_text','El Evento ya existe');
	          $this->registry->getObject('template')->getPage()->addTag('eventName',$_POST['eventName']);	
	          $this->registry->getObject('template')->getPage()->addTag('eventDescription',$_POST['eventDescription']);
	          $this->registry->getObject('template')->getPage()->addTag('eventImage',$_POST['eventImage']);
            }
		}
	}	
}

?>