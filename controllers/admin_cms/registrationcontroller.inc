<?php

/**
 * Controlador para el registro de Paginas
 */
class Registrationcontroller{
	
	/**
	 * Objeto para el Registro
	 */
	private $registry;
	
	/**
	 * Errores en el registro
	 */
	private $registrationErrors = array();
	
	/**
	 * Array de error label classes - nos permite marcar un campo con un color diferente, para indicar donde estuvo el error
	 */
	private $registrationErrorLabels = array();
	
	/**
	 * Valores que se han enviado para el registro
	 */
	private $submittedValues = array();
	
	/**
	 * Valores "sanitizados" listos para pasarlos a la bd"
	 */
	private $sanitizedValues = array();
	
	
	/*
	* Constructor del controlador
	*/
	public function __construct( Registry $registry, $user , $idPage = -1)
	{
		$this->registry = $registry;
		if( isset( $_POST ) && count( $_POST ) > 0 )
		{
			
		  require_once FRAMEWORK_PATH . 'models/page.inc';
		  require_once FRAMEWORK_PATH . 'models/tags.inc';
		  require_once FRAMEWORK_PATH . 'models/tags_page.inc';
		  // Guardamos o actualizamos el page
		  $pages = new Pages( $this->registry);
		  $pages->setTitle( htmlentities($this->registry->getObject('db')->sanitizeData( $_POST['title'] ),ENT_COMPAT,'UTF-8') );
		  $pages->setBody( $this->registry->getObject('db')->sanitizeData( $_POST['editor'] ) ); 
		  $pages->setParent( $this->registry->getObject('db')->sanitizeData($_POST['parent']));
		  $pages->setPublished($this->registry->getObject('db')->sanitizeData($_POST['publish']));
		  $pages->setLevel($this->registry->getObject('db')->sanitizeData($_POST['level']));
		  $pages->setOrdenation(0);			
		  $pages->setUpdated(date("Y-m-d H:i:s")); // fecha de ahora
		  $pages->setType($this->registry->getObject('db')->sanitizeData($_POST['type']));
		  $pages->setKeywordsSEO( $this->registry->getObject('db')->sanitizeData($_POST['keywords']));
		  $pages->setDescriptionSEO( $this->registry->getObject('db')->sanitizeData($_POST['description']));
		  $pages->setCategory($this->registry->getObject('db')->sanitizeData($_POST['category']));
		  $pages->setId($idPage);

          if($idPage == -1){
          	$pages->setCreated(date("Y-m-d H:i:s")); // fecha de ahora
            $pages->setUrl( $pages->checkAvailability(htmlentities($this->registry->getObject('db')->sanitizeData( $_POST['url']),ENT_COMPAT,'UTF-8')) );
            $pages->setId($pages->save());	
          }else{
          	$pages->setId($idPage);
          	$pages->setUrl( $pages->checkAvailability(htmlentities($this->registry->getObject('db')->sanitizeData( $_POST['url']),ENT_COMPAT,'UTF-8')) );
            $pages->update();
            // y borramos relacion de tags anteriores
            $pages->deleteTags();
          }

		  //Guardamos los Tags
		  // leemos los tags y los separamos por comas
		  $tags=explode(",", $this->registry->getObject('db')->sanitizeData($_POST['keywords']));
          foreach($tags as $clave=>$value)
		  {
		    $myTag = new Tags( $this->registry);
		    $myTag->setTagName(strtolower($value));
		    $idTags[]=$myTag->save();
		  }
					
		  //Guardamos la relacion entre tags y pagina
		  //Por cada Tag guardamos su relacion con el page
		  foreach($idTags as $clave=>$value)
		  {
		    $myTag_page = new Tags_Page( $this->registry);
		    $myTag_page->setIDTag($value);
		    $myTag_page->setIDPage($pages->getId());
		    $idTags_page[]=$myTag_page->save();
		  }

          // registramos en el log y gamificamos
		  $data['page_title']=$pages->getTitle();
	      $this->registry->getObject('event')->notify('user.page.add' , $user,$_SERVER['REMOTE_ADDR'] , $this->registry->getObject('util')->prepareData($data));
		
		}
	}	
	


}

?>