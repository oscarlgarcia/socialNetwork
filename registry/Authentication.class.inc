<?php
 
 /**
 * Authentication
 * 
 *
 * @version 1.0
 * @author  Oscar Garcia
 */
class Authentication {
	
	/**
	 * El objeto User
	*/
	private $user;
	
	/**
	 * variable Boolean que indica si el usuario esta loggeado
	 */
	private $loggedIn = false;
	
	/**
	 * Indica si el login se ha procesado o no
	 */
	private $justProcessed = false;
	
	/**
	 * Constructor
	 */
  public function __construct( Registry $registry ) 
  {
	   $this->registry = $registry;
  }
	
  /**
  * Metodo que comprueba si se ha autenticado
  */
  public function checkForAuthentication()
  {
  	 // Limpiamos el tag de error ( si lo hubiere)
    $this->registry->getObject('template')->getPage()->addTag('error', '');
	    // si hay definido en sesion el uid del usuario y no es 0
    	if( isset( $_SESSION['sn_auth_session_uid'] ) && intval( $_SESSION['sn_auth_session_uid'] ) > 0 )
    	{
    		// autenticamos
    		$this->sessionAuthenticate( intval( $_SESSION['sn_auth_session_uid'] ) );
    		
    		// si autenticamos correctamente
    		if( $this->loggedIn == true )
	    	{
	    		// Limpiamos el tag de error
	    		$this->registry->getObject('template')->getPage()->addTag('error', '');
	    	}
	    	else
	    	{
	    		// sino enviamos mensaje de error
	    		$this->registry->getObject('template')->getPage()->addTag('error', 'Error: Your username or password was not correct, please try again33');	
	    	}
    	} // si no tenemos uid, autenticamos por user y password
    	elseif( isset(  $_POST['sn_auth_user'] ) &&  $_POST['sn_auth_user'] != '' && isset( $_POST['sn_auth_pass'] ) && $_POST['sn_auth_pass'] != '')
    	{ //autenticamos por metodo post con user y pass
    		$this->postAuthenticate( $_POST['sn_auth_user'] , $_POST['sn_auth_pass'] );
      // si autenticamos correctamente
    		if( $this->loggedIn == true )
	    	{ // limpiamos tag de error
	    		$this->registry->getObject('template')->getPage()->addTag('error', '');
	    	}
	    	else
	    	{
	    		// sino enviamos mensaje de error
	    		$this->registry->getObject('template')->getPage()->addTag('error', 'El Usuario o Password no son correctos, por favor intentalo de nuevo');	
   			    $this->registry->getObject('template')->getPage()->addTag('username', $_POST['sn_auth_user']);	
	    	}
    	}
    	elseif( isset( $_POST['login']) )
    	{
    		$this->registry->getObject('template')->getPage()->addTag('error', 'Error: Your must enter a username and a password11');	
    	}

    }	
	
 
  
  /*POST authentication
  * Si el usuario intenta loggearse enviando el formulario
  * se llama este metodo
  * se utiliza el user object para buscar en la base datos
  */
  private function postAuthenticate( $u, $p )
  {
    $this->justProcessed = true;
    require_once(FRAMEWORK_PATH.'registry/User.class.inc');
    $this->user = new User( $this->registry, 0, $u, $p );
    if( $this->user->isValid() )
    {
      if( $this->user->isActive() == false )
      {
        $this->loggedIn = false;
        $this->loginFailureReason = 'inactive';
      }
      elseif( $this->user->isBanned() == true )
      {
        $this->loggedIn = false;
        $this->loginFailureReason = 'banned';
      }
      else
      {
        $this->loggedIn = true;
        $_SESSION['sn_auth_session_uid'] = $this->user->getUserID();
      }
    }
    else
    {
      $this->loggedIn = false;
      $this->loginFailureReason = 'invalidcredentials';
    }
  }
  
  
  /** SESSION autentication
  * Este metodo intentara autenticar si el usuario
  * no ha enviado el formulario de autenticacion
  * pero tiene definida algunos datos en sesion
  */  
  private function sessionAuthenticate( $uid )
  {
  	 //incluimos la clase User
    require_once(FRAMEWORK_PATH.'registry/User.class.inc');
    // Limpiamos el uid
    $this->user = new User( $this->registry, intval( $_SESSION['sn_auth_session_uid'] ), '', '' );
    // si el usuario es valido    
    if( $this->user->isValid() )
    {
      if( $this->user->isActive() == false )
      {
        $this->loggedIn = false;
        $this->loginFailureReason = 'inactive';
      }
      elseif( $this->user->isBanned() == true )
      {
        $this->loggedIn = false;
        $this->loginFailureReason = 'banned';
      }
      else
      {
        $this->loggedIn = true;
      }
    }
    else
    {
      $this->loggedIn = false;
      $this->loginFailureReason = 'nouser';
    }
    if( $this->loggedIn == false )
    {
      $this->logout();
    }
  }
  
  
  function logout() 
	{
		//unset($_SESSION['sn_auth_session_uid'] );
		session_unset ();
		$this->loggedIn = false;
		$this->user = null;
	}
  
  public function forceLogin( $username, $password )
	{
		$this->postAuthenticate( $username, $password );
	}
    
  public function isLoggedIn()
  {
    return $this->loggedIn;
  }
    
  public function isJustProcessed()
  {
  	return $this->justProcessed;
  }
    
    public function getUser()
    {
    	return $this->user;
    }  
  
  
  
  
  
}  
  
?>