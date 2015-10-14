<?php

/*
* Clase que contiene metodos utilitarios
* autor : Oscar Garcia
*/

class Util{
	
	private $registry;
	
	// Define el algoritmo de encriptacion (22- Blowfish)
	private $cryptAlgo=22;
	// Define el total de rounds necesarios para la generacion de la clave
	private $round="07";

  /*
   Constructor
  */
  public function __construct( Registry $registry)
  {
  	$this->registry = $registry;
  }  
  
  /*
	* Genera el Salt para utilizarse en la encriptacion
	* @return String salt
   */
  public function generateSalt() {
  
    $salt='$2a$'.$this->round.'$'.bin2hex(openssl_random_pseudo_bytes($this->cryptAlgo)).'$';	
    return $salt;
  }
  
  
  /*
	* Genera el password con el Salt y password definido
	* @return String password crypt
   */
  public function cryptPassword($password,$salt){
  	
  	  return crypt($password,$salt);
  	  
  }
  
  /*
  * Genera una Key con MD5
  *
  */
  public function generateKey($word){
  	  return md5($word);
  }
  	
  
  
  /**
  * Guarda valores en Session
  *
  */
  public function storeToSession($key,$value){
    $_SESSION[$key]=$value;
  }
  
  /**
  * borra valores en Session
  *
  */
  public function removeFromSession($key){
    unset($_SESSION[$key]);
  } 
  	
	
  	
  /* Codifica un array para guardarlo como data
  */
  public function prepareData($input){
  	
    if(is_array($input))
      {
        $resultado = array();
        foreach($input as $k => $v)
        {                
          $key = utf8_encode($k);
          $resultado[$key] = $this->prepareData($v);
        }
      }
        else
        {
            $resultado = utf8_encode($input);
        }

        return json_encode($resultado);
  	}


  /*
  * Metodo para construir una frase de notificacion
  */
  public function getSnippetNotification($eventName, $userID, $snippetID){
    
    // cargamos el usuario ( imagen y login )
    // cargamos el evento  ( descripicion e imagen)
    require_once FRAMEWORK_PATH . 'models/event.inc';
    require_once FRAMEWORK_PATH . 'models/user.inc'; 
    $user = new UserModel($this->registry);
    $event = new Event($this->registry);
    $userData = $user->getFastUser($userID);
    $event->getEvent($eventName);

    return "<img src='".$this->registry->getSetting("avatar_path"). $userData['profile_image']."' class='img-rounded' height='32' width='32' /> <b><a href='".$userData['ID']."'>".$userData['login']."</a></b> ".$event->getEventDescription(). " en el <a href='snippets/view/".$snippetID."'>Snippet </a>";

  }




}
?>