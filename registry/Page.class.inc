<?php

/**
*  Clase Gestion del contenido de la pagina
*
* @author Oscar Garcia
* @version 1.0
*/
class Page{

  // titulo
  private $title = '';
  
  // tags del template
  private $tags = array();
  
  // tags las cuales deben procesarse despues de que la pagina
  // se haya parseado.
  // razon: Hay tags en el contenido guardado en base de datos 
  // que deben parsearse.
  private $postParseTags = array();
  
  // trozos de template
  private $bits = array();
  
  // contenido de la pagina
  private $content = "";
  
  private $apd = array();
  
  /**
  * Constructor
  */
  function __construct( Registry $registry )
  {
    $this->registry = $registry;
  }

  /**
  * Obtenemos el titulo de la pagina
  * @return String
  */
  public function getTitle()
  {
    return $this->title;
  }
  
  /**
  * fijamos el titulo de la pagina
  * @param String $title the page title
  * @return void
  */
  public function setTitle( $title )
  {
    $this->title = $title;
  }

  /**
  * Seteamos el contenido
  * @param String $content the page content
  * @return void
  */ 
  public function setContent( $content )
  {
    $this->content = $content;
  }

  /**
  * Agregamos un tag y valor
  * @param String $key la clave para guardar el tag
  * @param String $data el valor que representa
  * @return void
  */
  public function addTag( $key, $data )
  {
    $this->tags[$key] = $data;
  }

  public function removeTag( $key )
  {
    unset( $this->tags[$key] );
  }

  /**
  * Devuelve los tags asociados con la pagina
  * @return void
  */
  public function getTags()
  {
    return $this->tags;
  }

  /**
  * Agregamos tags para post parse
  * @param String $key 
  * @param String $data
  * @return void
  */
  public function addPPTag( $key, $data )
  {
    $this->postParseTags[$key] = $data;
  }

  /**
  * Obtenemos los post parse tags
  * @return array
  */
  public function getPPTags()
  {
    return $this->postParseTags;
  }
  
  /**
  * Añade un trozo de template en la pagina
  * @param String el tag donde la plantilla se añade
  * @param String el nombre del archivo de plantilla
  * @return void
  */
  public function addTemplateBit( $tag, $bit )
  {
    $this->bits[ $tag ] = $bit;
  }

  /**
  * Adds additional parsing data
  * A.P.D is used in parsing loops. We may want to have an extra bit
  * of data depending on on iterations value
  * for example on a form list, we may want a specific item to be "selected"
  * @param String block the condition applies to
  * @param String tag within the block the condition applies to
  * @param String condition : what the tag must equal
  * @param String extratag : if the tag value = condition then we have  an extra tag called extratag
  * @param String data : if the tag value = condition then extra tag is replaced with this value
  */
  public function addAdditionalParsingData($block, $tag, $condition,$extratag, $data)
  {
    $this->apd[$block] = array($tag => array('condition' => $condition,'tag' => $extratag, 'data' => $data));
  }  

  /**
  * Get the template bits to be entered into the page
  * @return array the array of template tags and template file names
  */
  public function getBits()
  {
    return $this->bits;
  }
 
  public function getAdditionalParsingData()
  {
    return $this->apd;
  }

  /**
  * Gets a chunk of page content
  * @param String the tag wrapping the block ( <!-- START tag --> block <!-- END tag --> )
  * @return String the block of content
  */
  public function getBlock( $tag )
  {
    //echo $tag;
    preg_match ('#<!-- START '. $tag . ' -->(.+?)<!-- END '.$tag . ' -->#si', $this->content, $tor);
    $tor = str_replace ('<!-- START '. $tag . ' -->', "", $tor[0]);
    $tor = str_replace ('<!-- END ' . $tag . ' -->', "", $tor);
    return $tor;
  }


  public function getContent()
  {
    return $this->content;
  }

  public function getContentToPrint()
  {
    $this->content = preg_replace ('#{form_(.+?)}#si', '',$this->content);
    $this->content = preg_replace ('#{nbd_(.+?)}#si', '',$this->content);
    return $this->content;
  }

}

?>