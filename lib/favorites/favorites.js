$(function() {

  //-------------------------------------------------------------------
  /*
  * Funcion de Favoritos
  * El formulario debe llamarse favForm
  * Debe haber un control llamado favAction para "fav/unfav"
  * Debe existir un campo para definir que es AJAX
  * El control para mostrar que esta como favorito debe llamarse fav_star 
  * El boton debe llamarse favBtn
  */
  $("#favBtn").click(function(event) 
  {      
    $(this).button('toggle');
	  $(this).button('loading');    
    var iData=$("#favForm").serialize();
    var controller=$("#favForm").attr('action');
    var action=controller+$("#favAction").val();
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
	  	  else
        {
	  	    $("#favBtn").button('reset');
          alert(msg);
	        if (msg=="unfav") 
          { 
            // le di a guardar
		        $("#fav_star").removeClass("fa-heart-o");
		        $("#fav_star").addClass("fa-heart");    
		      }else 
          {  
            //si le di a borrar
            $("#fav_star").removeClass("fa-heart");
		        $("#fav_star").addClass("fa-heart-o");  
		      }
		      $("#favAction").attr('value',msg);  			  
		    }
	    }
	  });
    return false;
  });		
  //---------------------------------------------------------

  //Inicializamos el boton de favorito
  // El boton debe llamarse fav_Btn
  // y el control que lo muestra fav_star
  if($("#fav_star").hasClass("fa-heart"))
  {
    $("#favBtn").button('toggle');
  }
  //----------------------------------------------------------


});