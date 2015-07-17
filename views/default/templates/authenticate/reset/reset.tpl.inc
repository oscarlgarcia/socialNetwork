<div class="container-fluid ecpGlobal-margin">
  <div class="row">
    <div class="col-md-6 col-md-offset-3">
	  <div class="panel panel-default">
	  <div class="panel-heading">
        <h5><i class="glyphicon glyphicon-user"></i> ¿Olvidaste tu Password?</h5>
	  </div>
      <div class="panel-body">
        <form accept-charset="UTF-8" role="form" id="formReset" method="post" action="authenticate/forgot">
          <fieldset>
            <span class="help-block">Enviaremos a tu correo electrónico las instrucciones de como obtener tu nuevo password.</span>
            <div class="form-group input-group">
              <span class="input-group-addon">@</span>
              <input class="form-control" placeholder="Email" name="sn_email" id="email" type="email" required="" autofocus="">
            </div>
            <button type="submit" class="btn btn-primary btn-block" id="btn-olvidado">Recuperar Password</button>
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