<?php
 /**
 * Controlador para login/logout/register new user/ reset password/ forgot user & password
 * @version 1.0
 * @author  Oscar Garcia
 */
 
// TODO validar la fortaleza de la contrase�a
// TODO llevar el acceso a bd al modelo		
		
class Authenticatecontroller{
	
	/**
	 * Referencia del objeto registro
	 */
	private $registry;
	
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
		
		if( isset( $urlBits[1] ) )
  		  {
		    if(!isset( $urlBits[2] )) {
  		  	  	$value= 0;
  		  	}
  		  	else {
  		  	  $value= $urlBits[2];	
  		  	}
			  
			  
		    switch( $urlBits[1] )
				{
					case 'activate':
					  $this->validateKey($value);
					  break;
					
					case 'forgot':
					  $this->forgot();
					  break;
					  
					case 'getpass':
					  $this->getPass();
					  break;
					
					case 'reset':
					  $this->resetPassword($value);
					  break;
							
					case 'login':
						$this->login();
						break;
						
					case 'logout':
						$this->logout();
						break;	
					
					case 'register':
						$this->registrationDelegator();
						break;
						
					case 'signup':
					   $this->signup();
					   break;
					 
					case 'terms':
					   $this->terms();
					   break;
				}
				
			}
		
	}
	
 /*
 * Metodo que comprueba la clave de activacion
 *
 **/
  private function validateKey($key){
  	// Si no estamos loggeados
	if($this->registry->getObject('authenticate')->isLoggedIn() == false){
	  //validamos la clave de registro 
	  $activationKey=$this->registry->getObject('db')->sanitizeData($key);
	  $sql = "SELECT * FROM users WHERE activation_key='{$activationKey}' and user_status=0";
	  $this->registry->getObject('db')->executeQuery( $sql );
	  // El Key es valido y el status es 0
	  if( $this->registry->getObject('db')->numRows() == 1 )
	  {
	  	$data = $this->registry->getObject('db')->getRows();
        $sql = "Update users set user_status=1 where activation_key='{$activationKey}'";
        $this->registry->getObject('db')->executeQuery( $sql );
	    //$this->registry->getObject('template')->getPage()->setTitle( 'Registro para ' . $this->registry->getSetting('sitename') . ' completo ');
	    $this->registry->getObject('template')->buildFromTemplates(
	    	$this->registry->getObject('constants')->getHeaderTpl(), 
	    	'authenticate/register/'.$this->registry->getObject('constants')->getCompleteTpl(),
	    	$this->registry->getObject('constants')->getFooterTpl()
	    	);
	    // registramos en el log y gamificamos
	    $this->registry->getObject('event')->notify('user.activate',$data['ID'],$_SERVER['REMOTE_ADDR']);
	  }
	  else {
	  	$this->registry->getObject('template')->buildFromTemplates(
	  		$this->registry->getObject('constants')->getBasicHeaderTpl(), 
	  		'authenticate/register/'.$this->registry->getObject('constants')->getRegisterTpl(),
	  		$this->registry->getObject('constants')->getFooterTpl()
	  		);
		$this->registry->getObject('template')->getPage()->addTag('error_msg','error-msg');	
		$this->registry->getObject('template')->getPage()->addTag('error_text','');	
	  }
   	}	
  }
  
  
 /*
 * Metodo que envia el reset_key
 *
 **/
	private function forgot()
	{
	  // Si no estamos loggeados
	  if($this->registry->getObject('authenticate')->isLoggedIn() == false){
		if( isset( $_POST['sn_email'] ) && $_POST['sn_email'] != '' )
		{
			$e = $this->registry->getObject('db')->sanitizeData( $_POST['sn_email'] );
			$sql = "SELECT * FROM users WHERE user_email='{$e}'";
			$this->registry->getObject('db')->executeQuery( $sql );
			if( $this->registry->getObject('db')->numRows() == 1 )
			{
				$data = $this->registry->getObject('db')->getRows();
				$changes = array();
				$today =  new DateTime('now');
				$password=$data['user_pass'];
				$changes['reset_key'] = $this->registry->getObject('util')->generateKey($password.$today->format('Y-m-d H:i:s'));
				$tomorrow = $today->add(new DateInterval('PT1H'));
				$changes['reset_expires'] = $tomorrow->format('Y-m-d H:i:s');
				// Enviamos el mail de reset
	            $this->registry->getObject('mail')->sendForgotPasswordMail($e,$changes['reset_key']);
                // actualizamos en bd el reset_key	 
                $this->registry->getObject('db')->updateRecords( 'users', $changes, 'ID=' . $data['ID'] );        
	            // registramos en el log y gamificamos
	            $forgotData['email']=$e;
	            $this->registry->getObject('event')->notify('user.password.forgot',$data['ID'],$_SERVER['REMOTE_ADDR'],$this->registry->getObject('util')->prepareData($forgotData));
	        }
			// pantalla de envio de mail
			$this->registry->getObject('template')->buildFromTemplates(
				$this->registry->getObject('constants')->getHeaderTpl(), 
				'authenticate/reset/'.$this->registry->getObject('constants')->getSentTpl(), 
				$this->registry->getObject('constants')->getFooterTpl()
				);
		}
	  }
	}
	
	/*
	* Metodo para redireccionar a la pantalla de password reset
	*
	*/
	function getPass(){
	
	  // Si no estamos loggeados
	  if($this->registry->getObject('authenticate')->isLoggedIn() == false){
	    //  mostramos el formulario
	    $this->registry->getObject('template')->buildFromTemplates(
	    	$this->registry->getObject('constants')->getBasicHeaderTpl(),
	    	'authenticate/reset/'.$this->registry->getObject('constants')->getResetTpl(),
	    	$this->registry->getObject('constants')->getFooterTpl()
	    	);  
	  }
	
	}
	
	/*
	* Metodo para redireccionar a la pantalla de registro
	*
	*/
	function signup(){
	
	  // Si no estamos loggeados
	  if($this->registry->getObject('authenticate')->isLoggedIn() == false){
	    //  mostramos el formulario
	    $this->registry->getObject('template')->buildFromTemplates(
	    	$this->registry->getObject('constants')->getBasicHeaderTpl(),
	    	'authenticate/register/'.$this->registry->getObject('constants')->getRegisterTpl(),
	    	$this->registry->getObject('constants')->getFooterTpl()
	    	);  
		$this->registry->getObject('template')->getPage()->addTag('error_msg','error-msg');	
		$this->registry->getObject('template')->getPage()->addTag('error_text','');
		$this->registry->getObject('template')->getPage()->addTag(
			'captcha',
			'captcha/'.urlencode(microtime())
			);	
	  }
	
	}
	
	
	/*
	* Metodo para redireccionar a la pantalla de registro
	*
	*/
	function terms(){
	
	  // Si no estamos loggeados
	  if($this->registry->getObject('authenticate')->isLoggedIn() == false){
	    //  mostramos el formulario
	    $this->registry->getObject('template')->buildFromTemplates(
	    	'authenticate/register/'.$this->registry->getObject('constants')->getMustReadTpl()
	    	);  
	  }
	
	}
	
	
  /*
  * Metodo que comprueba el reset_key
  *
  **/
	private function resetPassword($key)
	{
	  // Si no estamos loggeados
	  if($this->registry->getObject('authenticate')->isLoggedIn() == false){
	    // lo comprobara
		$resetKey = $this->registry->getObject('db')->sanitizeData($key);
		$ahora = new DateTime('now');
		$now = $ahora->format('Y-m-d H:i:s');
		$sql = "SELECT * FROM users WHERE reset_key='{$key}'";
		$this->registry->getObject('db')->executeQuery( $sql );
		
		if( $this->registry->getObject('db')->numRows() == 1 )
		{
			$data = $this->registry->getObject('db')->getRows();
			if( $data['reset_expires'] < $now )
			{  // reset_expired solo es valido por 60 minutos
				$this->registry->errorPage(' Ha ocurrido un Error', 'El link para cambiar tu password s&oacute;lo es v&aacute;lido por 60 minutos o ya ha sido utilizado.');
			}
			else
			{
				if( isset( $_POST['reset_password'] ) )
				{
					// reset the password
					$changes = array();
					$changes['reset_expires'] = $now;
               $changes['user_pass'] = $this->registry->getObject('util')->cryptPassword($_POST['reset_password'],$data['password_salt']);
					$this->registry->getObject('db')->updateRecords( 'users', $changes, 'ID=' . $data['ID'] );
                    // registramos en el log y gamificamos
                    $this->registry->getObject('event')->notify('user.password.reset',$data['ID'],$_SERVER['REMOTE_ADDR']);
					$this->registry->errorPage(' Cambio de Password', 'El password se ha cambiado.');
				}
				else
				{
					//  mostramos el formulario
					$this->registry->getObject('template')->buildFromTemplates(
						$this->registry->getObject('constants')->getBasicHeaderTpl(),
						'authenticate/reset/'.$this->registry->getObject('constants')->getMainTpl(),
						$this->registry->getObject('constants')->getFooterTpl()
						);
				}
			}
		}
		else
		{
			$this->registry->errorPage(' Ha ocurrido un Error', 'El link para cambiar el password es incorrecto');
		}
	  }
	}	
	
		
	/**
	 * Realiza el inicio de sesion
	 * @return void
	 */
	private function login()
	{
		
		if( $this->registry->getObject('authenticate')->isJustProcessed() )
		{
			if( isset( $_POST['sn_auth_user'] ) && $this->registry->getObject('authenticate')->isLoggedIn() == false )
			{
		      $this->registry->getObject('template')->buildFromTemplates( 
		      	$this->registry->getObject('constants')->getBasicHeaderTpl(),
		      	'authenticate/login/'.$this->registry->getObject('constants')->getMainTpl(), 
		      	$this->registry->getObject('constants')->getFooterTpl()
		      	);
              //si el referer es logout lo limpiamos
	          if($_SERVER['HTTP_REFERER']==$this->registry->getSetting($this->registry->getObject('constants')->getConstant('site_url'))."authenticate/logout"){
                $this->registry->getObject('template')->getPage()->addTag( 'referer','home' );	  
	          }else {				
			    $this->registry->getObject('template')->getPage()->addTag( 'referer', ( isset( $_SERVER['HTTP_REFERER'] ) ? $_SERVER['HTTP_REFERER']  : '' ) );
			  }
			}
			else
			{
				// Si ya estamos logeados hay que redireccionar
				if( $_POST['referer'] == '' )
				{
					 //redireccionamos por nuestra url sino tenemos "referer"
					$referer = $this->registry->getSetting($this->registry->getObject('constants')->getConstant('site_url'));
					// registramos en el log y gamificamos
					$this->registry->getObject('event')->notify('user.login',$_SESSION['sn_auth_session_uid'],$_SERVER['REMOTE_ADDR']);
					$this->registry->redirectUser( $referer, 'Logged in', 'Thanks, you are now logged in, you are now being redirected to the page you were previously on', false);
				}
				else
				{
				  $ref=$_POST['referer'];
				  if($this->registry->getObject('authenticate')->getUser()->isAdmin())
                    $ref="#";
				  
				  if($_SERVER['HTTP_REFERER']==$this->registry->getSetting($this->registry->getObject('constants')->getConstant('site_url'))."authenticate/logout")
                    $ref="#";	 
				  				  
  				  // registramos en el log y gamificamos
	              $this->registry->getObject('event')->notify('user.login',$_SESSION['sn_auth_session_uid'],$_SERVER['REMOTE_ADDR']);
				  // si tenemos "referer" pues lo redireccionamos por ahi
				  $this->registry->redirectUser( $ref, 'Logged in', 'Thanks, you are now logged in, you are now being redirected to the page you were previously on', false);
				}
			}
		}
		else
		{  
			//Si ya estamos logeados no podemos volvernos a logear
			if( $this->registry->getObject('authenticate')->isLoggedIn() == true )
			{
           			
			}
			else
			{  //si no estamos logeados mostramos error
			  $this->registry->getObject('template')->getPage()->addTag( 'error','Debes iniciar tu sesi&oacute;n para continuar');
			  $this->registry->getObject('template')->getPage()->addTag( 'username','');
			  $this->registry->getObject('template')->buildFromTemplates(
			  	$this->registry->getObject('constants')->getBasicHeaderTpl(),
			  	'authenticate/login/'.$this->registry->getObject('constants')->getMainTpl(),
			  	$this->registry->getObject('constants')->getFooterTpl()
			  	);
			  $this->registry->getObject('template')->getPage()->addTag( 'referer', ( isset( $_SERVER['HTTP_REFERER'] ) ? $_SERVER['HTTP_REFERER']  : '' ) );
			}
		}
		
	}

	
	private function logout()
	{
		// registramos en el log y gamificamos
		if(isset($_SESSION['sn_auth_session_uid'])){
		  $this->registry->getObject('event')->notify('user.logout',$_SESSION['sn_auth_session_uid'],$_SERVER['REMOTE_ADDR']);	
		}
		$this->registry->getObject('authenticate')->logout();
		$this->registry->getObject('template')->addTemplateBit(
			'userbar', 
			$this->registry->getObject('constants')->getUserbarTpl()
			);
		$this->registry->getObject('template')->buildFromTemplates(
			$this->registry->getObject('constants')->getHeaderTpl(), 
			$this->registry->getObject('constants')->getMainTpl(), 
			$this->registry->getObject('constants')->getFooterTpl()
			);
	}
	
	/**
	 * Delega el control al controlador para el registro 
	 * @return void
	 */
	private function registrationDelegator()
	{	
		require_once FRAMEWORK_PATH . 'controllers/authenticate/registrationcontroller.inc';
		$rc = new Registrationcontroller( $this->registry );
	}
	
	
	
	
	
	
}
		
		
?>