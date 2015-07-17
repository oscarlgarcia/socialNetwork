<div class="container-fluid ecpGlobal-margin">
  <div class="row">
    <div class="col-md-6 col-md-offset-3">
      <h4 style="border-bottom: 1px solid #c5c5c5;"><i class="glyphicon glyphicon-user"></i> Acceso a tu cuenta</h4>
      <div id="form-forget">
	    <div class="alert alert-danger" >{error}</div>
        <form accept-charset="UTF-8" role="form" id="formLogin" method="post" action="authenticate/login" autocomplete="off">
          <fieldset>
            <div class="form-group input-group">
			<span class="input-group-addon"><i class="glyphicon glyphicon-user"></i></span>
            <input type="text" class="form-control" value="{username}" name="sn_auth_user" id="sn_auth_user" placeholder="Usuario" required>
            </div>
			<div class="form-group input-group">
			<span class="input-group-addon"><i class="glyphicon glyphicon-lock"></i></span>
            <input type="password" class="form-control" name="sn_auth_pass" id="sn_auth_pass" placeholder="Password" required>
            </div>
			<input type="hidden" id="referer" name="referer" value="{referer}" />
            <button type="submit" class="btn btn-primary btn-block" id="btn-signin">Sign In</button>
            <p class="help-block">
              <a class="text-muted" href="home"><small>Regresar</small></a>
            </p>
          </fieldset>
        </form>
      </div>
    </div>
  </div>
</div>