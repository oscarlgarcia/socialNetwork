<?php

/*
* Clase para los correos
* autor : Oscar Garcia
*/

class MailManager{
	
	private $registry;

  /*
   Constructor
  */
  public function __construct( Registry $registry)
  {
  	$this->registry = $registry;
  }  
  
  public function sendRegisterMail($to='',$key) {
  	
  	 if($to!='') {
  	 	$title = 'Bienvenido al Club del Programador';
      $body = "Enhorabuena!!". "\r\n";
      $body.= "Gracias por registrarte en el Club del Programador". "\r\n";
      $body.= " Antes de poder activar tu cuenta debes realizar un último paso para completar el proceso de registro, este paso consiste en visitar la siguiente URL:". "\r\n";
      $body.= $this->registry->getSetting($this->registry->getObject('constants')->getConstant('site_url'))."authenticate/activate/".$key. "\r\n";
      $body.= "Si tienes problemas con la URL, por favor puedes ponerte en contacto con nuestro soporte en soporte@elclubdelprogramador.com ". "\r\n";
      $body.= "Ven entra, aprende y comparte!!"."\r\n";
      $headers  = 'From:Webmaster <webmaster@elclubdelprogramador.com>' . "\r\n";
      $body = wordwrap($body, 70);
      //mail($to,$title,$body,$headers);
	    echo $body ;
  	 }
  	
  }
  
    public function sendForgotPasswordMail($to='',$key) {
  	
  	 if($to!='') {
  	 	$title = '¿No recuerdas tu contraseña?';
      $body = "No te preocupes.". "\r\n";
      $body.= "Hemos recibido una solicitud para cambiar tu contraseña". "\r\n";
      $body.= " Simplemente accediendo al siguiente URL podrás cambiarla:". "\r\n";
      $body.= $this->registry->getSetting($this->registry->getObject('constants')->getConstant('site_url'))."authenticate/reset/".$key. "\r\n";
      $body.= "Este enlace tiene una validez de 60 minutos una vez lo hayas recibido, si no has solicitado esta operación, no es necesario que hagas nada, para cualquier duda por favor ponte en contacto con nuestro soporte en soporte@elclubdelprogramador.com ". "\r\n";
      $body.= "Ven entra, aprende y comparte!!"."\r\n";
      $headers  = 'From:Webmaster <webmaster@elclubdelprogramador.com>' . "\r\n";
      $body = wordwrap($body, 70);
      //mail($to,$title,$body,$headers);
	    echo $body ;
  	 }
  	
  }
  
}
?>