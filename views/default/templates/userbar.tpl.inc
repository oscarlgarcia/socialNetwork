<div id="wrap" class="ecpGlobal-bg">
  <div role="navigation" class="navbar navbar-inverse navbar-fixed-top ecpnavbar-bg">
    <div class="container-fluid">
      <!-- Toggle for mobile -->
      <div class="navbar-header">
        <button type="button" data-target="#navbarCollapse" data-toggle="collapse" class="navbar-toggle">
          <span class="sr-only">Toggle navigation</span>
          <span class="icon-bar"></span>
          <span class="icon-bar"></span>
          <span class="icon-bar"></span>
        </button>
        <a href="home" class="navbar-brand"><img src="views/default/images/site/titulo.png"></a>
      </div>
      <!-- nav links -->
      <div id="navbarCollapse" class="collapse navbar-collapse">
        <ul class="nav navbar-nav navbar-right">
          <li class="dropdown">
            <a href="#" data-toggle="dropdown" class="dropdown-toggle">Login <b class="caret"></b></a>
            <ul class="dropdown-menu loginform-custom-padding">
              <li>
                <div class="row">
                  <div class="col-md-12">
                    <form class="form" role="form" method="post" action="authenticate/login" accept-charset="UTF-8" id="formLogin">
                      <div class="form-group input-group ">
  		   	            <span class="input-group-addon"><i class="fa fa-user"></i></span>
                        <input type="text" class="form-control" name="sn_auth_user" id="user" placeholder="Username" required>
                      </div>
                      <div class="form-group input-group">
  			    	    <span class="input-group-addon"><i class="fa fa-lock"></i></span>
                        <label for="password" class="sr-only"></label>
  			    	    <input type="password" class="form-control" name="sn_auth_pass" id="pass" placeholder="Password" required>
						<input type="hidden" id="referer" name="referer" value="{referer}" />
                      </div>
                      <p class="help-block">
                        <a href="authenticate/getpass"><small>He olvidado el password</small></a>
                      </p>
                     <div class="form-group">
                        <button type="submit" class="btn btn-primary btn-block">Sign in</button>
                      </div>
                    </form>
                  </div>
                </div>
              </li>
            </ul>   
          </li>
        </ul> 
      </div>
	 </div> 
  </div>