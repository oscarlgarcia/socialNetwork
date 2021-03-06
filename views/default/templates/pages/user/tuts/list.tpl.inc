<link rel="stylesheet" href="lib/tutorials/list.css"></link>
<div class="container-fluid ecpGlobal-margin">
  <ul class="breadcrumb">
        <li><a href="home">Home</a></li>
        <li><a href="tuts">Tutoriales</a></li>
        <li><a href="tuts/{category_name}">{category_name}</a></li>
        <li class="active">{category_level}</li>
  </ul>
  <div class="row">
    <div class="col-md-12">
      <h4>Tutoriales Disponibles</h4>
    </div>
  </div>
  <div class="row">
    <div class="col-md-8 col-md-offset-2">
      <div class="list-group">
        <!-- START tuts -->
        <a href="tuts/{tut_url}" class="list-group-item">
          <h4 class="list-group-item-heading"><span class="fa fa-angle-double-right"></span> {tut_title}
          </h4>
          <p class="list-group-item-text">{tut_description}.</p>
        </a>
        <!-- END tuts -->
      </div>
	  </div>
  </div>
</div>