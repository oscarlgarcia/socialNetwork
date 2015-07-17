<?php

/**
 * Clase ImageUpload 
 * Gestiona la subida de imagenes al CMS 
 */
class ImageUpload {

    private $registry;

    private $validExtension = array("jpg", "jpeg", "svg", "png", "gif", "tif");
	
	/**
	 * Constructor
	 * @param Object registry
	 * @return void
	 */
  function __construct( Registry $registry) 
  {
    $this->registry = $registry;
  }
    

  function listImages($directory = "static/resources/images/"){
    
    $result = array(); 
    $files = array_diff(scandir($directory), array('..', '.'));
    $r="";
    foreach($files as $clave => $valor) 
    {
      $r.="<div class='col-md-3'><div class='panel panel-default'>
        <div class='panel-body'><img width='80' height='80' style='border:1px;' class='img-thumbnail' src='".$directory.$valor."' /></div></div></div>";
    }
    return $r;

  }



}