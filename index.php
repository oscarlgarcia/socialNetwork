<?php
session_start();

// Borrar esto cuando pasemos a PROD
error_reporting(E_ALL);
ini_set("display_errors", 1);
// borrar hasta aquí

// ----- definimos el path --------------------------------------------
DEFINE("FRAMEWORK_PATH", dirname( __FILE__ ) ."/" );

//------ incluimos la clase de registro de objetos --------------------
require('registry/Registry.class.inc');
$registry = new Registry(); 

//-------- creamos los objetos de nuestro framework -------------------
$registry->createAndStoreObject( 'Template', 'template' );
$registry->createAndStoreObject( 'Mysqldb', 'db' );
$registry->createAndStoreObject( 'Authentication', 'authenticate' );
$registry->createAndStoreObject( 'Route', 'url' );
$registry->createAndStoreObject( 'MailManager', 'mail' );
$registry->createAndStoreObject( 'Util', 'util' );
$registry->createAndStoreObject( 'EventListener', 'event' );
$registry->createAndStoreObject( 'Constants', 'constants' );
//--------  Obtenemos la URL ---------------------
$registry->getObject('url')->getURLData();

//------------- incluimos la configuracion de la bd -------------------
include(FRAMEWORK_PATH . 'config.inc');

//-------------- creamos la conexion a la bd --------------------------
$registry->getObject('db')->newConnection( $configs['db_host_sn'], $configs['db_user_sn'], $configs['db_pass_sn'], $configs['db_name_sn']);

//--------------  comprobamos si estamos logeados ---------------------
$registry->getObject('authenticate')->checkForAuthentication();

//-------------- Registramos la ruta solicitada -----------------------
require_once( FRAMEWORK_PATH . 'models/logger_page.inc');
$session = "guest";
$resource = "home";
if (isset($_SESSION['sn_auth_session_uid']))
  $session = $_SESSION['sn_auth_session_uid'];

if ( $registry->getObject('url')->getURLPath() != "")
  $resource = $registry->getObject('url')->getURLPath();

$loggerPage = new LoggerPage($registry,$_SERVER["REMOTE_ADDR"],
  $resource,
  date("Y-m-d H:i:s"),
  $session,
  $registry->getObject('util')->prepareData($_SERVER['HTTP_USER_AGENT']),
  session_id());
$loggerPage->save();

//---------------- buscamos los settings en la bd ---------------------
$settingsSQL = "SELECT * FROM settings";
$registry->getObject('db')->executeQuery( $settingsSQL );

//----------------- Los cargamos en el framework ----------------------
while( $setting = $registry->getObject('db')->getRows() )
{
	$registry->storeSetting( $setting['value'], $setting['key'] );
}

//-------------- agregamos los tags de descripcion del site -------
$registry->getObject('template')->getPage()->addTag( 'site_url', $registry->getSetting('site_url') );
$registry->getObject('template')->getPage()->addTag( 'site_name', $registry->getSetting('site_name') );
$registry->getObject('template')->getPage()->addTag( 'site_description', $registry->getSetting('site_description') );
$registry->getObject('template')->getPage()->addTag( 'site_keywords', $registry->getSetting('site_keywords') );
//---------------  buscamos los controladores activos ------------------
$controllers = array();
$controllersSQL = "SELECT * FROM controllers WHERE active=1";
$registry->getObject('db')->executeQuery( $controllersSQL );

//----------------  los cargarmos en un array del framework -------------
while( $controller = $registry->getObject('db')->getRows() )
{
	$controllers[] = $controller['controller'];
}
//--------------- Leemos la URL -----------------------------------------
$controller = $registry->getObject('url')->getURLBit(0);

//----------------  si estamos loggeados --------------------------------
if( $registry->getObject('authenticate')->isLoggedIn() )
{
  //Si es Admin
  if($registry->getObject('authenticate')->getUser()->isAdmin())
  {
    $registry->getObject('template')->buildFromTemplates(
      $registry->getSetting($registry->getObject('constants')->getConstant('pages_admin_base')).$registry->getObject('constants')->getHeaderTpl(),
      $registry->getSetting($registry->getObject('constants')->getConstant('pages_admin_base')).$registry->getObject('constants')->getDashboardTpl(),
      $registry->getSetting($registry->getObject('constants')->getConstant('pages_admin_base')).$registry->getObject('constants')->getFooterTpl()
      );
  }else
  { //Si es usuario normal
    $registry->getObject('template')->buildFromTemplates(
      $registry->getObject('constants')->getHeaderTpl(), 
      $registry->getSetting($registry->getObject('constants')->getConstant('pages_logged_base')).$registry->getObject('constants')->getDashboardTpl(), 
      $registry->getObject('constants')->getFooterTpl()
      );
	  //---------------------- mostramos la barra de usuario logeado ---------
	  $registry->getObject('template')->addTemplateBit(
      'userbar', 
      $registry->getSetting($registry->getObject('constants')->getConstant('pages_logged_base')).$registry->getObject('constants')->getLoggedUserbarTpl()
      );
    $registry->getObject('template')->getPage()->addTag( 'referer', ( isset( $_SERVER['HTTP_REFERER'] ) ? $_SERVER['HTTP_REFERER']  : '' ) );
    $registry->getObject('template')->getPage()->addTag( 'username', $registry->getObject('authenticate')->getUser()->getUserLogin());	
  }	
  
}
else  //-- Si no lo estamos ----/
{
   $registry->getObject('template')->buildFromTemplates(
    $registry->getObject('constants')->getHeaderTpl(),
    $registry->getObject('constants')->getMainTpl(), 
    $registry->getObject('constants')->getFooterTpl()
    );
   //--------------- mostramos la barra de usuario no loggeado -------
   $registry->getObject('template')->addTemplateBit('userbar', $registry->getObject('constants')->getUserbarTpl());
   $registry->getObject('template')->getPage()->addTag('referer','home');
	
   // Si la peticion es por Ajax debemos retornar un mensaje de error
   if (isset($_POST['ajaxRequest'])){
     echo NOT_LOGGED;
	 exit();
   }
	
}


//----------- si el controller que llamamos en la url esta registrado lo redirigimos a ese controlador ------
if( in_array( $controller, $controllers ) )
{
	require_once( FRAMEWORK_PATH . 'controllers/' . $controller . '/controller.inc');
	$controllerInc = $controller.'controller';
	$controller = new $controllerInc( $registry, true );
}
else
{
	 //sino vamos al controler por defecto
	// default controller, or pass control to CMS type system?
}

// -----------------  Generamos la salida -------------------------------
$registry->getObject('template')->parseOutput();
print $registry->getObject('template')->getPage()->getContentToPrint();

?>