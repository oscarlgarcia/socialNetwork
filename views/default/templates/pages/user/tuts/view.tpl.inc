<link rel="stylesheet" href="lib/codemirror/codemirror.css"/>
<link rel="stylesheet" href="lib/tutorials/view_tutorial.css"/>
<link rel="stylesheet" href="lib/codemirror/theme/solarized.css">
<script src="lib/codemirror/codemirror.js"></script>
<script src="lib/codemirror/mode/javascript/javascript.js"></script>
<script src="lib/codemirror/addon/selection/active-line.js"></script>
<div class="container-fluid ecpGlobal-margin">
  <ul class="breadcrumb">
        <li><a href="home">Home</a></li>
        <li><a href="tuts/">Tutoriales</a></li>
        <li><a href="tuts/{category_name}">{category_name}</a></li>
        <li><a href="tuts/{category_name}/{level_name}">{level_name}</a></li>
  </ul>
  <!-- Page panel -->
  <div class="row">
    <div class="col-md-12">
      <div class="panel panel-primary">
  	    <div class="panel-heading">
  	      <h4>{title}</h4>  
  	    </div>
        <div class="panel-body">
          <div class="row-fluid">
  		      <p>{body}</p>
  	      </div>
  	    </div> 
      </div>
    </div>
  </div>
  <!-- End Page panel --> 
  <!-- related Panel -->
  <div class="row">
    <div class="col-md-12">
    <label>Otros tutoriales que pueden interesarte</label>
    <div class="panel panel-default">
        <div class="panel-body">
    <!-- START related -->
    <div class="col-md-2">
        <div class="panel panel-default grey">
      <div class="panel-body">
        <div class="text-center">
          <a href="tuts/{related_url}" alt="{full_title}">
            <img class="img-rounded"  alt="{full_title} "width="80" height="80" src="{related_image}">
            <h5>{related_title}</h5>
        </a>
            </div>
        </div>
      </div>  
    </div>
    <!-- END related -->
    </div>
    </div>
    </div>
  </div>
  <!-- end related Panel -->
</div>
<script type="text/javascript"  src="lib/tutorials/view_tutorial.js"></script>