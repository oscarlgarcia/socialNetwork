<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd"> 
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en"> 
<head> 
	<base href="{site_url}" />
	<title>{site_name}</title> 
  <meta http-equiv="content-type" content="text/html; charset=iso-8859-1" /> 
  <meta name="description" content="{site_description}" />
  <meta name="keywords" content="{site_keywords}" /> 
	<link rel="stylesheet" type="text/css" href="views/default/css/font-awesome.min.css" />
	<link rel="stylesheet" type="text/css" href="views/default/css/bootstrap.min.css" />
	<link rel="stylesheet" type="text/css" href="views/default/css/bootstrap-theme.min.css" />
	<link rel="stylesheet" type="text/css" href="views/default/css/site.css" />
	<script type="text/javascript" src="lib/jquery/jquery-2.1.0.min.js" ></script>
</head>  
<body>
<div id="wrap" class="ecpGlobal-bg" nombre="wrapper_pagina">
  <div class="container-fluid" nombre="contenedor_todo">
  <div role="navigation" class="navbar navbar-inverse navbar-fixed-top ecpnavbar-bg">
   <!-- Menubar -->
      <!-- Toggle for mobile -->
      <div class="navbar-header">
        <button type="button" data-target="#navbarCollapse" data-toggle="collapse" class="navbar-toggle">
          <span class="sr-only">Toggle navigation</span>
          <span class="icon-bar"></span>
          <span class="icon-bar"></span>
          <span class="icon-bar"></span>
        </button> 
        <a href="home" class="navbar-brand"><img src="views/default/images/site/titulo-admin.png"></a>
      </div>
    <!-- Nav Links-->
    <div id="navbarCollapse" class="collapse navbar-collapse">
        <ul class="nav navbar-nav navbar-right">
        <li class="dropdown">
            <a href="#" data-toggle="dropdown" class="dropdown-toggle"> <i>Admin</i><b class="caret"></b></a>
         <ul class="dropdown-menu dropdownmenu-custom">
        <li><a href="authenticate/logout"><span class="fa fa-sign-out pull-right" ></span> Cerrar Sesion</a></li>
         </ul>
         </li>
       </ul>
     </div>
     </div> <!-- fin del role -->
    <!-- Menu Admin -->
    <div class="row ecpGlobal-margin" nombre="menu_y_contenido">
      <div class="col-sm-2 col-md-2">
        <div class="panel-group" id="accordion">
          <!-- Funciones historial -->
          <div class="panel panel-primary">
            <div class="panel-heading">
              <h4 class="panel-title">
                <span class="fa fa-gears">&nbsp;</span><a data-toggle="collapse" data-parent="#accordion" href="#collapseSite">Ajustes</a>
              </h4>
            </div>
            <div id="collapseSite" class="panel-collapse collapse">
              <div class="panel-body">
                <table class="table">
                  <tr><td><a href="admin_settings/search">Ajustes Generales</a></td></tr>
                  <tr><td><a href="admin_controllers/search">Controladores</a></td></tr>
                  <tr><td><a href="admin_event/search">Eventos</a></td></tr>
                  <tr><td><a href="admin_gamification/search">Gamificaci&oacute;n</a></td></tr>
                  <tr><td><a href="admin_category/search">Categor&iacute;as</a></td></tr>
                  <tr><td><a href="admin_media/search">Media</a></td></tr>

                </table>
               </div>
             </div>
           </div>
           <!-- fin historial  -->
          <!-- Funciones Comunidad -->
          <div class="panel panel-primary">
            <div class="panel-heading">
              <h4 class="panel-title">
                <span class="fa fa-group">&nbsp;</span><a data-toggle="collapse" data-parent="#accordion" href="#collapseOne">Comunidad</a>
              </h4>
            </div>
            <div id="collapseOne" class="panel-collapse collapse">
              <div class="panel-body">
                <table class="table">
                  <tr><td><a href="admin_users/search">Usuarios</a></td></tr>
                   <tr><td><a href="admin_snippets/search">Snippets</a></td></tr>
                   <tr><td><a href="admin_comments_snippet/search">Comentarios de Snippets</a></td></tr>
                   <tr><td><a href="admin_links/search">Links</a></td></tr>
                   <tr><td><a href="admin_comments_link/search">Comentarios de Links</a></td></tr>
                   <tr><td><a href="admin_tags/search">Tags</a></td></tr>
                 </table>
               </div>
             </div>
           </div>
           <!-- fin comunidad  -->
           <!-- Funciones  -->
           <div class="panel panel-primary">
            <div class="panel-heading">
              <h4 class="panel-title">
                <span class="fa fa-wordpress">&nbsp;</span><a data-toggle="collapse" data-parent="#accordion" href="#collapseCMS">Tutoriales</a>
              </h4>
            </div>
            <div id="collapseCMS" class="panel-collapse collapse">
              <div class="panel-body">
                <table class="table">
                  <tr><td><a href="admin_cms/add">Nueva pagina</a></td></tr>
                  <tr><td><a href="admin_cms/browse">Paginas</a></td></tr>
                 </table>
               </div>
             </div>
           </div>
            <!-- Fin Tutoriales  -->
           <div class="panel panel-primary">
                  <div class="panel-heading">
                        <h4 class="panel-title">
                            <a data-toggle="collapse" data-parent="#accordion" href="#collapseTwo"><span class="fa fa-calendar">&nbsp;</span>Historial</a>
                        </h4>
                    </div>
                    <div id="collapseTwo" class="panel-collapse collapse">
                        <div class="panel-body">
                            <table class="table">
                                <tr>
                                    <td>
                                        <a href="http://www.jquery2dotnet.com">Orders</a> <span class="label label-success">$ 320</span>
                                    </td>
                                </tr>
                                <tr>
                                    <td>
                                        <a href="http://www.jquery2dotnet.com">Invoices</a>
                                    </td>
                                </tr>
                                <tr>
                                    <td>
                                        <a href="http://www.jquery2dotnet.com">Shipments</a>
                                    </td>
                                </tr>
                                <tr>
                                    <td>
                                        <a href="http://www.jquery2dotnet.com">Tex</a>
                                    </td>
                                </tr>
                            </table>
                        </div>
                    </div>
                </div>
                <div class="panel panel-primary">
                    <div class="panel-heading">
                        <h4 class="panel-title">
                            <a data-toggle="collapse" data-parent="#accordion" href="#collapseThree">
                              <span class="fa fa-user">&nbsp;</span>Account</a>
                        </h4>
                    </div>
                    <div id="collapseThree" class="panel-collapse collapse">
                        <div class="panel-body">
                            <table class="table">
                                <tr>
                                    <td>
                                        <a href="http://www.jquery2dotnet.com">Change Password</a>
                                    </td>
                                </tr>
                                <tr>
                                    <td>
                                        <a href="http://www.jquery2dotnet.com">Notifications</a> <span class="label label-info">5</span>
                                    </td>
                                </tr>
                                <tr>
                                    <td>
                                        <a href="http://www.jquery2dotnet.com">Import/Export</a>
                                    </td>
                                </tr>
                                <tr>
                                    <td>
                                        <span class="fa fa-trash text-danger"></span><a href="http://www.jquery2dotnet.com" class="text-danger">
                                            Delete Account</a>
                                    </td>
                                </tr>
                            </table>
                        </div>
                    </div>
                </div>
                <div class="panel panel-primary">
                    <div class="panel-heading">
                        <h4 class="panel-title">
                            <a data-toggle="collapse" data-parent="#accordion" href="#collapseFour">
                              <span class="fa fa-bar-chart">&nbsp;</span>Reports</a>
                        </h4>
                    </div>
                    <div id="collapseFour" class="panel-collapse collapse">
                        <div class="panel-body">
                            <table class="table">
                                <tr>
                                    <td>
                                        <span class="fa fa-usd"></span><a href="http://www.jquery2dotnet.com">Sales</a>
                                    </td>
                                </tr>
                                <tr>
                                    <td>
                                        <span class="fa fa-user"></span><a href="http://www.jquery2dotnet.com">Customers</a>
                                    </td>
                                </tr>
                                <tr>
                                    <td>
                                        <span class="fa fa-tasks"></span><a href="http://www.jquery2dotnet.com">Products</a>
                                    </td>
                                </tr>
                                <tr>
                                    <td>
                                        <span class="fa fa-shopping-cart"></span><a href="http://www.jquery2dotnet.com">Shopping Cart</a>
                                    </td>
                                </tr>
                                
                            </table>
                        </div>
                    </div>
                </div>
            </div>
        </div>
        <div class="col-sm-10 col-md-10" nombre="contenido_principal">