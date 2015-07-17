<?php
 /**
 * Controlador para procesar los captcha
 * @version 1.0
 * @author  Oscar Garcia
 */	
class Captchacontroller{
	
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
		require_once( FRAMEWORK_PATH . 'lib/captcha/captcha.class.inc'); 
		$this->registry = $registry;
		$this->captcha();
	}
	
	private function captcha(){
     $captcha = new Captcha($this->registry);
     $captcha->generateCaptcha();
     $captcha->drawImage();
	}
   
   private function check($validator = ''){
   	 if ( isset($_SESSION['_CAPTCHA']) ) {
       $captcha = new Captcha($this->registry,unserialize($_SESSION['_CAPTCHA']['config']));
       echo ($captcha->checkCaptcha($validator))? "a": "b";
     }
   }
	
}

			
?>