$(function() {
    
  //-------------------------------------------------------------
  /*
  *  Funcion de validar formulario agregar link
  *  El boton debe llamarse btn-addLink
  *  
  */
  $("#btn-addLink").click(function () {
	 
    if($.trim($("#title").val()).length == 0 ) {  
      $("#error-msg").html("Falta el titulo del Link").fadeIn('slow'); 
      return false;  
    }
	
	if($.trim($("#description").val()).length == 0 ) {  
      $("#error-msg").html("Falta la descripcion del Link").fadeIn('slow'); 
      return false;  
    }
	
	if($.trim($("#url").val()).length == 0 ) {  
      $("#error-msg").html("Falta el URL del Link").fadeIn('slow'); 
      return false;  
    }
    
    var regexpurl=/^(ht|f)tps?:\/\/\w+([\.\-\w]+)?\.([a-z]{2,6})?([\.\-\w\/_]+)$/i;
   	if(!$.trim($("#url").val()).match(regexpurl) ) {  
      $("#error-msg").html("La URL es invalida").fadeIn('slow'); 
      return false;  
    }
    
    
	
	if($.trim($('#tags').val()).length == 0 ) {  
       
        $("#error-msg").html("Nos falta los Tags").fadeIn('slow'); 
        return false;  
    }
	
	var btn = $(this);
        btn.button('loading');
        setTimeout(function () { 
          btn.button('reset');
            }, 3000);
	
  });
  
  //------------------------------------------
  //incializamos los tags
  $('#tags').tagsInput({
    width:'auto',
    defaultText:'+tag',
    maxChars : 10,
    height:'34px'
  });
	
  //Setup the charcounter 
  $(".counted_description").charCounter(550,{container: "#counter_description"});
	
	
});