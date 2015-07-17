<?php

/*
* Clase encargada del Routing del framework
* Autor: Oscar Garcia
*/
class Route{
	
	private $urlBits = array();
	private $urlPath;
	
	/*
  * Constructor
  **/	
  public function __construct( Registry $registry )
  {
    $this->registry = $registry;
  }
	
  /**
  * fijamos el path URL
  * @param String url path
  */
  public function setURLPath($path)
  {
    $this->urlPath = $path;
  }

  /**
  * Retorna datos de la URL actual
  * @return void
  */
  public function getURLData()
  {
  	 // si viene de la forma ?page=xxx
  	 // obtenemos la pagina
    $urldata = ( isset( $_GET['page'] ) ) ? $_GET['page'] : '' ;
    $this->urlPath = $urldata;
    // si no viene el param page
    if( $urldata == '' )
    {
      $this->urlBits[] = '';
      $this->urlPath = '';
    }
    else
    { 
      // si viene page 
      $data = explode( '/', $urldata );
      while ( !empty( $data ) && strlen( reset( $data ) ) === 0 )
      {
        array_shift( $data );
      }
      while ( !empty( $data ) && strlen( end( $data ) ) === 0)
      {
        array_pop($data);
      }
      $this->urlBits = $this->array_trim( $data );
    }
  }

  
  public function getURLBits()
  {
    return $this->urlBits;
  }


  public function getURLBit( $whichBit )
  {
    return ( isset( $this->urlBits[ $whichBit ] ) ) ?  $this->urlBits[ $whichBit ] : 0 ;
  }

  public function getURLPath()
  {
    return $this->urlPath;
  }
  
  private function array_trim( $array ) 
	{
	    while ( ! empty( $array ) && strlen( reset( $array ) ) === 0) 
	    {
	        array_shift( $array );
	    }
	    
	    while ( !empty( $array ) && strlen( end( $array ) ) === 0) 
	    {
	        array_pop( $array );
	    }
	    
	    return $array;
	}

  public function buildURL( $bits, $qs, $admin )
  {
    $admin = ( $admin == 1 ) ? $this->registry->getSetting('admin_folder') . '/' : '';
    $the_rest = '';
    foreach( $bits as $bit )
    {
      $the_rest .= $bit . '/';
    }
    $the_rest = ( $qs != '' ) ? $the_rest . '?&' .$qs : $the_rest;
    return $this->registry->getSetting($this->registry->getObject('constants')->getConstant('site_url')) . $admin . $the_rest;
  }
}

?>