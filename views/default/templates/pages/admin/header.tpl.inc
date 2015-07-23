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
<div id="wrap" class="ecpGlobal-bg">
  <div class="container-fluid">
    <div class="row">
      <div class="col-sm-2 col-md-2">
        <img src="views/default/images/site/logo_1.png" style="padding-top:2px;" alt="Thumbnail Image">
      </div>
      <div class="pull-right">
        <a href="authenticate/logout"><span class="glyphicon glyphicon-log-out"></span> Cerrar Sesion</a>
      </div>
    </div>
    <div class="row">
      <div class="col-sm-2 col-md-2">
        <div class="panel-group" id="accordion">
          <div class="panel panel-primary">
            <div class="panel-heading">
              <h4 class="panel-title">
                <span class="fa fa-group">&nbsp;</span><a data-toggle="collapse" data-parent="#accordion" href="#collapseOne">Comunidad</a>
              </h4>
            </div>
            <div id="collapseOne" class="panel-collapse collapse">
              <div class="panel-body">
                <table class="table">
                  <tr>
                    <td>
                      <a href="admin_users/browse">Usuarios</a>
                    </td>
                   </tr>
                   <tr>
                     <td>
                       <a href="admin_snippets/search">Snippets</a>
                     </td>
                   </tr>
                   <tr>
                     <td>
                       <a href="admin_links/browse">Links</a>
                     </td>
                   </tr>
                    <tr>
                    <td>
                      <a href="admin_comments/browse">Comentarios</a>
                    </td>
                   </tr>
                 </table>
               </div>
             </div>
           </div>
           <!--   -->
           <div class="panel panel-primary">
            <div class="panel-heading">
              <h4 class="panel-title">
                <span class="fa fa-wordpress">&nbsp;</span><a data-toggle="collapse" data-parent="#accordion" href="#collapseCMS">Tutoriales</a>
              </h4>
            </div>
            <div id="collapseCMS" class="panel-collapse collapse">
              <div class="panel-body">
                <table class="table">
                  <tr>
                    <td>
                      <a href="admin_cms/add">Nueva pagina</a>
                    </td>
                   </tr>
                  <tr>
                    <td>
                      <a href="admin_cms/browse">Paginas</a>
                    </td>
                   </tr>
                 </table>
               </div>
             </div>
           </div>
           <div class="panel panel-primary">
                  <div class="panel-heading">
                        <h4 class="panel-title">
                            <a data-toggle="collapse" data-parent="#accordion" href="#collapseTwo"><span class="glyphicon glyphicon-calendar"></span> Historial</a>
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
                            <a data-toggle="collapse" data-parent="#accordion" href="#collapseThree"><span class="glyphicon glyphicon-user">
                            </span>Account</a>
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
                                        <span class="glyphicon glyphicon-trash text-danger"></span><a href="http://www.jquery2dotnet.com" class="text-danger">
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
                            <a data-toggle="collapse" data-parent="#accordion" href="#collapseFour"><span class="glyphicon glyphicon-file">
                            </span>Reports</a>
                        </h4>
                    </div>
                    <div id="collapseFour" class="panel-collapse collapse">
                        <div class="panel-body">
                            <table class="table">
                                <tr>
                                    <td>
                                        <span class="glyphicon glyphicon-usd"></span><a href="http://www.jquery2dotnet.com">Sales</a>
                                    </td>
                                </tr>
                                <tr>
                                    <td>
                                        <span class="glyphicon glyphicon-user"></span><a href="http://www.jquery2dotnet.com">Customers</a>
                                    </td>
                                </tr>
                                <tr>
                                    <td>
                                        <span class="glyphicon glyphicon-tasks"></span><a href="http://www.jquery2dotnet.com">Products</a>
                                    </td>
                                </tr>
                                <tr>
                                    <td>
                                        <span class="glyphicon glyphicon-shopping-cart"></span><a href="http://www.jquery2dotnet.com">Shopping Cart</a>
                                    </td>
                                </tr>
                                
                            </table>
                        </div>
                    </div>
                </div>
            </div>
        </div>
        <div class="col-sm-10 col-md-10">