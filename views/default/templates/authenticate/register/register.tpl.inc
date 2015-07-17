<link rel="stylesheet" type="text/css" href="lib/captcha/captcha.css">
<div class="container ecpGlobal-margin">
  <div class="row">
    <div class="col-md-6 col-md-offset-3">
	  <div class="panel panel-default">
	    <div class="panel-heading">
         <h5><i class="fa fa-user-plus"></i> Registrate <small> es gratis</small></h5>
	    </div>
		<div class="panel-body">
		<!-- START errors -->
		 <div class="alert alert-danger" id="{error_msg}">{error_text}</div>
		<!-- END errors -->
		<form action="authenticate/register" method="post">
		  <div class="form-group input-group">
              <span class="input-group-addon"><i class="fa fa-user"></i></span>
              <input class="form-control" placeholder="Usuario" name="register_user" id="register_user" type="text" required="" autofocus="">
          </div>
		  <div class="form-group input-group">
              <span class="input-group-addon"><i class="fa fa-at"></i></span>
              <input class="form-control" placeholder="Email" name="register_email" tabindex="2" type="email" required="">
          </div>
		  <div class="row">
			<div class="col-xs-12 col-sm-6 col-md-6">
			  <div class="form-group input-group">
			    <span class="input-group-addon"><i class="fa fa-lock"></i></span>
				<input type="password" name="register_password" id="register_password" class="form-control" placeholder="Password" tabindex="3" required="">
			  </div>
			</div>
			<div class="col-xs-12 col-sm-6 col-md-6">
			  <div class="form-group input-group">
			    <span class="input-group-addon"><i class="fa fa-lock"></i></span>
				<input type="password" name="register_password_confirm" id="register_password_confirm" class="form-control" placeholder="Confirmar Password" tabindex="4" required="">
			  </div>
			</div>
		  </div>
        
          <div class="row">
			<div class="col-xs-12 col-sm-6 col-md-6">
			  <div class="form-group input-group">
			  	<a class="captcha_reload" id="captcha_reload">
			  	  <span class="fa fa-refresh icon-48"></span>
			      <img src="{captcha}" class="img-thumbnail" id="captcha_img" />
			    </a>
			  </div>
			</div>
			<div class="col-xs-12 col-sm-4 col-md-4">
			  <div class="form-group input-group">
			    <span class="input-group-addon"><i class="fa fa-child"></i></span>
				<input type="text" name="captcha_code" id="captcha_code" class="form-control" placeholder="Captcha" tabindex="5" required="">
			  </div>
			</div>
		  </div>

		  <div class="row">
		    <div class="col-xs-4 col-sm-3 col-md-3">
			  <div class="checkbox">
                <label>
                  <input type="checkbox" id="iAccept" required="" tabindex="6"> De acuerdo
                </label>
              </div>
			</div>
			<div class="col-xs-8 col-sm-9 col-md-9">
			  Para <strong class="label label-primary">Registrate</strong>, debes leer y aceptar los 
			  <a href="#" data-toggle="modal" data-target="#myModal" tabindex="7">Terminos y Condiciones</a> de nuestro sitio.
			</div>
		  </div>
		  <hr/>
		  <div class="row">
				<div class="col-xs-12 col-md-12"><input type="submit" value="Registrame" name="process_registration" class="btn btn-primary btn-block" tabindex="6"></div>
			</div>
		</form>
		</div>
      </div>
    </div>
  </div>
  
  <!-- Modal HTML -->
  <div id="myModal" class="modal fade">
    <div class="modal-dialog">
      <div class="modal-content">
        <div class="modal-header">
          <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
          <h4 class="modal-title">Terms and Conditions</h4>
        </div>
        <div class="modal-body">
          <h4>1.1. Purpose</h4>
          <p>The mission of LinkedIn is to connect the world’s professionals to enable them to be more productive and successful. 
To achieve our mission, we make services available through our websites, mobile applications, and developer platforms, 
to help you, your connections, and millions of other professionals meet, exchange ideas, learn, make deals, find 
opportunities or employees, work, and make decisions in a network of trusted relationships and groups.</p>
        </div>
        <div class="modal-footer">
          <button type="button" class="btn btn-primary" id="iAgree" data-dismiss="modal">He Le&iacute;do y acepto.</button>
        </div>
      </div>
    </div>
  </div>
  <!-- End modal-->
</div>
<script type="text/javascript" src="lib/register/register_user.js"></script>
<script type="text/javascript" src="lib/captcha/captcha.js"></script>