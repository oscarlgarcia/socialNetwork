<?php

/**
 * Controlador para el registro de usuarios
 */
class Registrationcontroller{
	
	/**
	 * Objeto para el Registro
	 */
	private $registry;
	
	/**
	 * Campos para el registro estandard
	 */
	private $fields = array( 'user' => 'Usuario', 'password' => 'Contraseña', 'password_confirm' => 'Confirmacion de Contraseña', 'email' => 'Correo Electronico');
	
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
	 * 4 si el usuario se activa de una vez sino se enviarÃ¡ un email
	 */
	private $activeValue = 3;
	
	
	/*
	* Constructor del controlador
	*/
	public function __construct( Registry $registry )
	{
		$this->registry = $registry;
		// si se ha presionado el boton de submit
		if( isset( $_POST['process_registration'] ) )
		{
			if( $this->checkRegistration() == true )
			{
				$userId = $this->processRegistration();
				if( $this->activeValue == 4 )
				{
					$this->registry->getObject('authenticate')->forceLogin( $this->submittedValues['register_user'], md5( $this->submittedValues['register_password'] ) );
				}
				$this->uiRegistrationProcessed();
			}
			else
			{
				$this->uiRegister( true );
			}
			
		}
		else
		{
			$this->uiRegister( false );
		}
	}
	
	/**
	 * Process the users registration, and create the user and users profiles
	 * @return int
	 */
	private function processRegistration()
	{
		// insert
		$this->registry->getObject('db')->insertRecords( 'users', $this->sanitizedValues );
		// get ID
		$uid = $this->registry->getObject('db')->lastInsertID();
		// return the ID for the frameworks reference - autologin?
		return $uid;
	}
	
	
	// Comprobamos si los campos estan definidos
	
	private function checkRegistration()
	{
		require_once( FRAMEWORK_PATH . 'lib/captcha/captcha.class.inc'); 
		$allClear = true;
		// blank fields
		foreach( $this->fields as $field => $name )
		{
			if( ! isset( $_POST[ 'register_' . $field ] ) || $_POST[ 'register_' . $field ] == '' )
			{
				$allClear = false;
				$this->registrationErrors[] = 'Debes suministrar tu ' . $name;
				$this->registrationErrorLabels['register_' . $field . '_label'] = 'error';
			}
		}
		

		// captcha

		if ( isset($_SESSION['_CAPTCHA']) ) {
          $captcha = new Captcha($this->registry,unserialize($_SESSION['_CAPTCHA']['config']));
           if (!$captcha->checkCaptcha($_POST['captcha_code'])){
            $allClear = false;
			$this->registrationErrors[] = 'La frase es incorrecta';
			$this->registrationErrorLabels['register_user_label'] = 'error';
           }
        }

		// username length
		if( strlen( $_POST['register_user'] ) < 6 )
		{
			$allClear = false;
			$this->registrationErrors[] = 'Tu nombre de usuario es muy corto, debe contener al menos 6 caracteres';
			$this->registrationErrorLabels['register_user_label'] = 'error';
		}
		
		
		// passwords match
		if( $_POST[ 'register_password' ]!= $_POST[ 'register_password_confirm' ] )
		{
			$allClear = false;
			$this->registrationErrors[] = 'Las contraseñas deben coincidir';
			$this->registrationErrorLabels['register_password_label'] = 'error';
			$this->registrationErrorLabels['register_password_confirm_label'] = 'error';
		}

		// password length
		if( strlen( $_POST['register_password'] ) < 6 )
		{
			$allClear = false;
			$this->registrationErrors[] = 'Tu contraseña es muy corta, debe contener al menos 6 caracteres';
			$this->registrationErrorLabels['register_password_label'] = 'error';
			$this->registrationErrorLabels['register_password_confirm_label'] = 'error';
		}
		
		
		// email headers
		if( strpos( ( urldecode( $_POST[ 'register_email' ] ) ), "\r" ) === true || strpos( ( urldecode( $_POST[ 'register_email' ] ) ), "\n" ) === true )
		{
			$allClear = false;
			$this->registrationErrors[] = 'Tu correo electronico no es valido';
			$this->registrationErrorLabels['register_email_label'] = 'error';
		}
		
		// email valido
		if( ! preg_match( "^[_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9-]+)*(\.[a-z]{2,4})^", $_POST[ 'register_email' ] ) )
		{
			$allClear = false;
			$this->registrationErrors[] = 'Tu correo electronico no es valido';
			$this->registrationErrorLabels['register_email_label'] = 'error';

		}
		
		// sanitizamos
		$u = $this->registry->getObject('db')->sanitizeData( $_POST['register_user'] );
		$e = $this->registry->getObject('db')->sanitizeData( $_POST['register_email'] );
		
		$sql = "SELECT * FROM users WHERE user_login='{$u}' OR user_email='{$e}'";
		$this->registry->getObject('db')->executeQuery( $sql );
		
		// comprobamos si ambos existen en la base de datos
		if( $this->registry->getObject('db')->numRows() == 2 )
		{
			$allClear = false;
			// both	
			$this->registrationErrors[] = 'Tanto el usuario como el correo electronico ya estan en uso.';
			$this->registrationErrorLabels['register_user_label'] = 'error';
			$this->registrationErrorLabels['register_email_label'] = 'error';
		}
		elseif( $this->registry->getObject('db')->numRows() == 1 )
		{
			// en un unico registro existe ambos o uno de los 2 pero no sabemos cual
			$u = $this->registry->getObject('db')->sanitizeData( $_POST['register_user'] );
			$e = $this->registry->getObject('db')->sanitizeData( $_POST['register_email'] );
			$data = $this->registry->getObject('db')->getRows();
			  // si son los 2
			if( $data['user_login'] == $u && $data['user_email'] == $e )
			{
				$allClear = false;
				$this->registrationErrors[] = 'Tanto el usuario como el correo electronico ya estan en uso.';
				$this->registrationErrorLabels['register_user_label'] = 'error';
				$this->registrationErrorLabels['register_email_label'] = 'error';
			} 
			elseif( $data['user_login'] == $u )
			{ 
			   // si es el ususario
				$allClear = false;	
				$this->registrationErrors[] = 'Este usuario ya estan en uso.';
				$this->registrationErrorLabels['register_user_label'] = 'error';
			}
			else
			{
				// si es el correo
				$allClear = false;
				$this->registrationErrors[] = 'Este correo electronico ya estan en uso.';
				$this->registrationErrorLabels['register_email_label'] = 'error';
			}
		}
		
		if( $allClear == true )
		{
			$this->sanitizedValues['user_login'] = $u;
			$this->sanitizedValues['user_email'] = $e;
			$this->sanitizedValues['password_salt'] = $this->registry->getObject('util')->generateSalt();
			$this->sanitizedValues['user_pass'] = $this->registry->getObject('util')->cryptPassword($_POST['register_password'],$this->sanitizedValues['password_salt']);

			$this->sanitizedValues['user_status'] = $this->activeValue;
			$this->sanitizedValues['display_name'] = $u;
			$this->sanitizedValues['user_registered'] = date("Y-m-d H:i:s");
			$this->sanitizedValues['activation_key'] =$this->registry->getObject('util')->generateKey($this->sanitizedValues['user_login'].$this->sanitizedValues['user_email']);
            // Enviamos el mail de confirmacion
	        $this->registry->getObject('mail')->sendRegisterMail($this->sanitizedValues['user_email'],$this->sanitizedValues['activation_key']);
	  
	        $this->submittedValues['register_user'] = $_POST['register_user'];
			$this->submittedValues['register_password'] = $_POST['register_password'];
			return true;
		}
		else
		{
			$this->submittedValues['register_user'] = $_POST['register_user'];
			$this->submittedValues['register_email'] = $_POST['register_email'];
			$this->submittedValues['register_password'] = $_POST['register_password'] ;
			$this->submittedValues['register_password_confirm'] = $_POST['register_password_confirm'];
   		    return false;
		}
		
		
		
	}
	
	private function uiRegistrationProcessed()
	{
		$this->registry->getObject('template')->getPage()->setTitle( 
			'Registro para ' . $this->registry->getObject('constants')->getConstant('site_name') . ' completo ');
		$this->registry->getObject('template')->buildFromTemplates(
			$this->registry->getObject('constants')->getBasicHeaderTpl(), 
			'authenticate/register/'.$this->registry->getObject('constants')->getActivateTpl(), 
			$this->registry->getObject('constants')->getFooterTpl()
			);
		
	}
	
	private function uiRegister( $error )
	{
		$this->registry->getObject('template')->buildFromTemplates(
			$this->registry->getObject('constants')->getBasicHeaderTpl(),
			'authenticate/register/'.$this->registry->getObject('constants')->getRegisterTpl(),
			$this->registry->getObject('constants')->getFooterTpl()
			);  
		if ($error)
		  $this->registry->getObject('template')->getPage()->setTitle( 'Registro para true'  );
		else
		  $this->registry->getObject('template')->getPage()->setTitle( 'Registro para false'  );
		  
		// blank out the field tags
		$fields = array_keys( $this->fields );
		foreach( $fields as $field )
		{
			$this->registry->getObject('template')->getPage()->addTag( 'register_' . $field . '_label', '' );
			$this->registry->getObject('template')->getPage()->addTag( 'register_' . $field, '' );
		}
		if( $error == false )
		{
			$this->registry->getObject('template')->getPage()->addTag( 'error', '' );
			$this->registry->getObject('template')->getPage()->addTag('error_msg','error-msg');
		}
		else
		{
			$errorsData = array();
			$errors =  $this->registrationErrors;
			foreach( $errors as $error )
			{
				$errorsData[] = array( 'error_text' => $error );
				break;
			}
			$errorsCache = $this->registry->getObject('db')->cacheData( $errorsData );
			$this->registry->getObject('template')->getPage()->addTag('error_msg','simple-msg');
			$this->registry->getObject('template')->getPage()->addTag( 'errors', array( 'DATA', $errorsCache ) );
			$this->registry->getObject('template')->getPage()->addTag(
			'captcha',
			'captcha/'.urlencode(microtime())
			);

			$toFill = array_merge( $this->submittedValues,$this->registrationErrorLabels );
			foreach( $toFill as $tag => $value )
			{
				$this->registry->getObject('template')->getPage()->addTag( $tag, $value );
			}
		}
	}
	
	
}



?>