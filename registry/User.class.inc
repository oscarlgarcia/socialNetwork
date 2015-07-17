<?php

/*
* El Club del programador Social Networking
* Clase para gestionar el Usuario de la aplicacion
* autor : Oscar Garcia
*/

class User{
	
	// Propiedades del Usuario
	private $id;
	private $userLogin;
	private $userPass;
	private $passwordSalt;
	private $twitterName;
	private $userEmail;
	private $userUrl;
	private $userRegistered;
	private $userStatus;
	private $displayName;
	private $experiencePoints;
	private $reputationPoints;
	private $resetKey;
	private $resetExpires;
	private $activationKey;
	private $userLevel;
	
	// Mantiene el registro
	private $registry;
	// Nos determina si el usuario esta correctamente cargado
	private $valid = false;
	
	// enlazar con nueva tabla de status
	// obtener el salt para poder comprobar la validacion

  /*
   Constructor  
  
  */
  public function __construct( Registry $registry, $id=0,$username='', $password='' )
  {
    $this->registry = $registry;
    if( $id==0 && $username != '' && $password != '' ) // Si pasamos user y pass
    {
      $user = $this->registry->getObject('db')->sanitizeData( $username );
      $salt= $this->getSaltByLogin($user);
      $hash = $this->registry->getObject('util')->cryptPassword($password,$salt);
      $sql = "SELECT * FROM users WHERE user_login='{$user}' AND user_pass='{$hash}'"; //todo poner si esta enabled
      $this->registry->getObject('db')->executeQuery( $sql );
      if( $this->registry->getObject('db')->numRows() == 1 )
      {
      	//cargamos el usuario encontrado
        $data = $this->registry->getObject('db')->getRows();
        $this->id = $data['ID'];
        $this->userLogin = $data['user_login'];
        $this->userPass = $data['user_pass'];
        $this->passwordSalt = $data['password_salt'];
        $this->twitterName = $data['twitter_name'];
        $this->userEmail = $data['user_email'];
        $this->userUrl = $data['user_url'];
        $this->userRegistered = $data['user_registered'];
        $this->userStatus = $data['user_status'];
        $this->displayName = $data['display_name'];
        $this->experiencePoints = $data['experience_points'];
        $this->reputationPoints = $data['reputation_points'];
        $this->resetKey = $data['reset_key'];
        $this->resetExpires = $data['reset_expires'];
        $this->activationKey = $data['activation_key'];
        $this->userLevel = $data['user_level'];
        $this->valid = true;
      }
    }
    elseif( $id > 0 ) // Si pasamos id
    {
      $id = intval( $id );
      $sql = "SELECT * FROM users WHERE ID='{$id}'";
      $this->registry->getObject('db')->executeQuery( $sql );
      if( $this->registry->getObject('db')->numRows() == 1 )
      {
        $data = $this->registry->getObject('db')->getRows();
        $this->id = $data['ID'];
        $this->userLogin = $data['user_login'];
        $this->userPass = $data['user_pass'];
        $this->passwordSalt = $data['password_salt'];
        $this->twitterName = $data['twitter_name'];
        $this->userEmail = $data['user_email'];
        $this->userUrl = $data['user_url'];
        $this->userRegistered = $data['user_registered'];
        $this->userStatus = $data['user_status'];
        $this->displayName = $data['display_name'];
        $this->experiencePoints = $data['experience_points'];
        $this->reputationPoints = $data['reputation_points'];
        $this->resetKey = $data['reset_key'];
        $this->resetExpires = $data['reset_expires'];
        $this->activationKey = $data['activation_key'];
        $this->userLevel = $data['user_level'];
        $this->valid = true;
      }
    }
  }
  
  public function getSaltByLogin($login)
  {
    $sql = "SELECT password_salt FROM users WHERE user_login='{$login}'";
    $this->registry->getObject('db')->executeQuery( $sql );
  	 if( $this->registry->getObject('db')->numRows() == 1 )
    {
      $data = $this->registry->getObject('db')->getRows();
      return $data['password_salt'];
    }
  	 return "";
  }
  
  	
  public function getUserID()
	{
		return $this->id;
	}
	
  public function getUserLogin()
	{
		return $this->userLogin;
	}
	
	public function isActive()
	{
		return ( $this->userStatus == 1 ) ? true : false;
	}
	
	
	public function isAdmin()
	{
		return ( $this->userLevel == 10 ) ? true : false;
	}
	
	public function isBanned()
	{
		return ( $this->userStatus == 2 ) ? true : false;
	}
	
	public function isValid()
	{
		return $this->valid;
	}
  	
}

?>