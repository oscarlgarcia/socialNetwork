<?php

/*
* Clase que contiene las constantes
* autor : Oscar Garcia
*/

class Constants{
	
	private $registry;

  private $tags = array(
   'snippet_editor_message' => 'snippet_editor_message' // mensaje en el editor de snippets
    );

  private $constants = array(
    'site_url'               => 'site_url',
    'site_name'              => 'site_name',
    'code_open'              => 'code_open',
    'code_close'             => 'code_close',
    'code_open_replace'      => 'code_open_replace',
    'code_close_replace'     => 'code_close_replace',
    'pages_logged_base'      => 'logged_pages_base', // Directorio de paginas de usuario
    'pages_admin_base'       => 'admin_pages_base' // directorio base de las paginas de admin
    );

   // Array para los templates
   private $templates = array(
     'header'         => 'header.tpl.inc',  // template de cabecera principal
     'header_simple'  => 'simple_header.tpl.inc', // template cabecera sencilla 
     'dashboard'      => 'dashboard.tpl.inc', // template del dashboard  
     'userbar'        => 'userbar.tpl.inc',  // Barra de usuario por defecto
     'logged_userbar' => 'userbar_loggedin.tpl.inc', // Barra de usuario loggeado
     'main'           => 'main.tpl.inc', // template del main
     'list'           => 'list.tpl.inc', // template para mostrar listas
     'category'       => 'category.tpl.inc', // Template para mostrar las cateogrias
     'add'            => 'add.tpl.inc', // template para agregar
     'view'           => 'view.tpl.inc', // template para ver detalle 
     '404'            => '404.tpl.inc', // template para recurso no disponible
     'invalid'        => 'invalid.tpl.inc', // template para recurso invalido
     'no_results'     => 'no_results.tpl.inc', // template para no hay resultados
     'complete'       => 'complete.tpl.inc', // template el registro de usuarios(estado completo)
     'register'       => 'register.tpl.inc', //template para registro de usuarios(muestra formulario)
     'sent'           => 'sent.tpl.inc', // template para registro de usuarios(correo enviado)
     'reset'          => 'reset.tpl.inc', // template para reset password
     'must_read'      => 'must_read.tpl.inc',//template para contenido "must read" (terms & cond,etc)
     'history'        => 'history.tpl.inc', // template para mostrar historial
     'activate'       => 'activate.tpl.inc',
     'message'        => 'message.tpl.inc',  // Template para mostrar mensaje
     'footer'         => 'footer.tpl.inc',  // template de foooter principal
     'redirect'       => 'redirect.tpl.inc'   // template para mostrar mensaje al redirect
    );

	
  /*
   Constructor
  */
  public function __construct( Registry $registry){
  	$this->registry = $registry;
  }  
  
  public function getConstant($key){
    return $this->constants[$key];
  }

  public function getTag($key){
    return $this->tags[$key];
  }

  // retorna el template header principal
  public function getHeaderTpl(){
    return $this->templates['header'];
  }

  // retorna el template header simple
  public function getBasicHeaderTpl(){
    return $this->templates['header_simple'];
  }

  // retorna el template footer principal
  public function getFooterTpl(){
    return $this->templates['footer'];
  }
	
  // retorna el template dashboard
  public function getDashboardTpl(){
    return $this->templates['dashboard'];
  }

  // retorna el template redirect
  public function getRedirectTpl(){
    return $this->templates['redirect'];
  }

  // retorna el template  userbar
  public function getUserbarTpl(){
    return $this->templates['userbar'];
  }

  // retorna el template  userbar
  public function getLoggedUserbarTpl(){
    return $this->templates['logged_userbar'];
  }

  // retorna el template  main
  public function getMainTpl(){
    return $this->templates['main'];
  } 

  // retorna el template list
  public function getListTpl(){
    return $this->templates['list'];
  } 

  // retorna el template add
  public function getAddTpl(){
    return $this->templates['add'];
  } 

  // retorna el template view
  public function getViewTpl(){
    return $this->templates['view'];
  } 

  // retorna el template 404
  public function get404Tpl(){
    return $this->templates['404'];
  } 

  // retorna el template invalid
  public function getInvalidTpl(){
    return $this->templates['invalid'];
  } 

  // retorna el template no results
  public function getNoResultsTpl(){
    return $this->templates['no_results'];
  } 

  // retorna el template complete
  public function getCompleteTpl(){
    return $this->templates['complete'];
  } 

  // retorna el template register
  public function getRegisterTpl(){
    return $this->templates['register'];
  } 

  // retorna el template sent
  public function getSentTpl(){
    return $this->templates['sent'];
  } 

  // retorna el template reset
  public function getResetTpl(){
    return $this->templates['reset'];
  } 

  // retorna el template must read
  public function getMustReadTpl(){
    return $this->templates['must_read'];
  } 

  // retorna el template message
  public function getMessageTpl(){
    return $this->templates['message'];
  } 

  // retorna el template activate
  public function getActivateTpl(){
    return $this->templates['activate'];
  } 

    // retorna el template message
  public function getHistoryTpl(){
    return $this->templates['history'];
  } 

  public function getCategoryTpl(){
    return $this->templates['category'];
  }

}
?>