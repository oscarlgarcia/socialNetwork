<div class="container-fluid ecpGlobal-margin">
  <ul class="breadcrumb">
        <li><a href="home">Home</a></li>
        <li class="active">Links</li>
  </ul>
  <div class="row ecpGlobal-margin-bottom" >
    <div class="col-md-8">
      <div class="alert alert-info">
        <p>Tienes enlaces interesantes que deseas que conozcamos?. Comp&aacute;rtelos con la comunidad  de forma f&aacute;cil.</p>
      </div>	
    </div>
    <div class="col-md-4">	  
      <a class="btn btn-primary btn-lg" href="links/add" ><span class="fa fa-link"></span> Agrega un Link</a>
    </div>
  </div>
  <div class="row">
    <div class="col-md-10">
      <div class="panel panel-primary">
        <div class="panel-heading">
          <span class="fa fa-list"></span> Links
	      <div class="btn-group pull-right">
		    <button type="button" class="btn btn-primary btn-xs">Ordenar por:</button>
            <button type="button" class="btn btn-primary btn-xs dropdown-toggle" data-toggle="dropdown"><span class="caret"></span></button>
	        <ul class="dropdown-menu slidedown">
              <li><a href="links/{order_controller1}">{order_text1}</a></li>
			  <li><a href="links/{order_controller2}">{order_text2}</a></li>
			  <li><a href="links/{order_controller3}">{order_text3}</a></li>
			  <li><a href="links/{order_controller4}">{order_text4}</a></li>
            </ul>
          </div>
        </div>
        <div class="panel-body">
          <!-- START link -->
          <div class="row">
            <div class="col-md-12 snippet">
              <div class="row">
                <div class="col-md-12">
                  <h4><strong><a href="{url}" target="_blank" rel="nofollow" >{title}</a></strong></h4>
                </div>
              </div>
              <div class="row">
                <div class="col-md-12 snippet-header-line">
                  Por: <a href="links/user/{author}"><img src="{topUserURL}{profile_image}" class="img-rounded" width="24" height="24"></a> | 
                  <span class="fa fa-calendar">
                  </span> {fecha} | <span class="fa fa-star"></span> {rating} | <span class="fa fa-heart"></span> {faved} | 
				  <span class="fa fa-comment"></span> {comments} | <span class="fa fa-tags"></span>Tags : {all_tags}
                </div>
              </div>
              <div class="row snippet-content">
                <div class="col-md-12">
                  <p>{description}</p>
				  <p><a class="btn btn-xs btn-info" href="links/view/{ID}">Ver Detalles</a></p>
                </div>
              </div>
            </div>
          </div>
          <!-- END link -->
          <!-- pagination -->
          <div class="col-md-9">
            <ul class="pagination">
                {page_items}
            </ul>
          </div>                             		
          <!-- end pagination -->
        </div>
      </div>
    </div>
	<div class="col-md-2">
	<div class="panel panel-primary">
        <div class="panel-heading">
		  <span class="fa fa-user"></span> Top Contributors
	    </div>
		<div class="panel-body">
		<ul class="widget">
		<!-- START contributors -->
		  <li>
		    <a href="links/user/{user_login}"><img src="{topUserURL}{profile_image}" class="img-rounded"  width="36" height="36" alt="{total}"></a>
		  </li>
		<!-- END contributors -->
		</ul>
	    </div>
    </div>
	<div class="panel panel-primary">
		<div class="panel-body">
		Publicidad
	    </div>
    </div>
	<div class="panel panel-primary">
        <div class="panel-heading">
		<span class="fa fa-tags"></span> Tags populares
	    </div>
		<div class="panel-body">
		<ul class="widget">
		<!-- START tags -->
		<li>
		  <a href="links/tag/{name}" class="label label-default">{name}</a>
		</li>
		<!-- END tags -->
		</ul>
	    </div>
    </div>
	</div>
  </div>
</div>