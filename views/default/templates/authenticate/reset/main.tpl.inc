<div class="container ecpGlobal-margin">
  <div class="row">
    <div class="col-md-6 col-md-offset-3">
	 <div class="panel panel-default">
	   <div class="panel-heading">
         <h5><i class="glyphicon glyphicon-user"></i> Cambio de Password</h5>
	   </div>
        <div class="panel-body">
	      <div class="alert alert-danger" id="error-msg"></div>
          <form accept-charset="UTF-8" role="form" id="formChangePassword" method="post">
            <fieldset>
		      <label for="password" class="sr-only">Nuevo Password</label>
              <div class="form-group input-group">
		  	<span class="input-group-addon"><i class="glyphicon glyphicon-lock"></i></span>
              <input type="password" class="form-control" name="reset_password" id="reset_password" placeholder="Nuevo Password" required>
              </div>
		  	<label for="password" class="sr-only">Confirmar Password</label>
              <div class="form-group input-group">
		  	<span class="input-group-addon"><i class="glyphicon glyphicon-lock"></i></span>
              <input type="password" class="form-control" name="reset_password_confirm" id="reset_password_confirm" placeholder="Confirmar Password" required>
              </div>
              <button type="submit" class="btn btn-primary btn-block" id="btn_reset">Cambiar Password</button>
              <p class="help-block">
                <a class="text-muted" href="home"><small>Regresar</small></a>
              </p>
            </fieldset>
          </form>
        </div>
      </div>
    </div>
  </div>
</div>
<script type="text/javascript" src="lib/changePassword/changePassword.js"></script>