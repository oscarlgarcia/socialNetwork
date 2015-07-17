$(function() {

  //---------------------------------------------------------------------------
  /*
  *
  *  Funcion para rating
  *  El formulario debe llamarse ratingForm
  *  El control debe llamarse rating
  *  Debe existir un campo AJAX
  */
  $("#rating").on("rating.change", function(event, value, caption) {
	$("#rating").rating("refresh", {disabled: true, showClear: false});
    var form=$("#ratingForm");
	var iData=form.serializeArray();
	var action=form.attr('action');
	$.ajax(
	   {
		  type: "POST",
		  url:  action,
		  data: iData,
		  success: function(msg)
		  {  
		    //TODO comprobar cuando es error
		  	if(msg == "-1")
		  	 window.location.replace("home");             			
		  }
		});
    return false;
  });
  //----------------------------------------------------------------------------
  
  // Inicializamos el star rating
  // El control debe llamarse rating
  $("#rating").rating();


});
