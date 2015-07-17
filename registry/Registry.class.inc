<?php
/**
* El Club del programador Social Networking
* @author Oscar Garcia
* Registry Class
*/
class Registry {
	
  /**
  * Array de objetos
  */
  private $objects;
 
  /**
  * Array de settings
  */
  private $settings;

  /**
  * Constructor
  **/
  public function __construct() {

  
  }

  /**
  * Crea un nuevo objeto y lo almacena en el registro
  * @param String $object es el nombre del archivo a incluir
  * @param String $key clave par del objeto , el alias
  * @return void
  */

  public function createAndStoreObject( $object, $key )
  {
    require_once( $object . '.class.inc' );
    $this->objects[ $key ] = new $object( $this );
  }

  /**
  * almacena Setting
  * @param String $setting los datos de la configuracion
  * @param String $key la clave del setting
  * @return void
  */
  public function storeSetting( $setting, $key )
  {
    $this->settings[ $key ] = $setting;
  }
  
  /**
  * Retorna el setting desde el almacen de settings
  * @param String $key la clave para buscarlo
  * @return String los datos del setting
  */
  public function getSetting( $key )
  {
    return $this->settings[ $key ];
  }
 
  /**
  * Retorna un objeto del almacen de objetos
  * @param String $key la clave del objeto
  * @return Object
  */
  public function getObject( $key )
  {
    return $this->objects[ $key ];
  }
  
  public function errorPage( $heading, $content )
    {
    	$this->getObject('template')->buildFromTemplates(
        $this->getObject('constants')->getHeaderTpl(), 
        $this->getObject('constants')->getMessageTpl(), 
        $this->getObject('constants')->getFooterTpl()
        );
    	$this->getObject('template')->getPage()->addTag( 'heading', $heading );
    	$this->getObject('template')->getPage()->addTag( 'content', $content );
    }
    
    /**
     * Crear una URL
     * @param array $urlBits partes del  array
     * @param array $queryString 
     * @return String
     */
    public function buildURL( $urlBits, $queryString=array() )
    {
    	return $this->getObject('url')->buildURL( $urlBits, $queryString, false );
    }
    
    /**
     * Redirecciona al usuario a otro lugar y muestra un mensaje en el interim
     * @param String $url la url a direccionar
     * @param String $heading la cabecera del mensaje
     * @param String $message el mensaje en si
     * @return void
     */
    public function redirectUser( $url, $heading, $message )
    {
    	$this->getObject('template')->buildFromTemplates(
        $this->getObject('constants')->getRedirectTpl()
        );
    	$this->getObject('template')->getPage()->addTag( 'heading', $heading );
    	$this->getObject('template')->getPage()->addTag( 'message', $message );
    	$this->getObject('template')->getPage()->addTag( 'url', $url );
    }
}
?>