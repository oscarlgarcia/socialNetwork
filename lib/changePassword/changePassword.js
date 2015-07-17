$(function() {
  //-------------------------------------------------------------
  /*
  *  Funcion de validar formulario en cambio de password
  *  
  */
  $("#btn_reset").click(function () {
    	
	if($.trim($("#reset_password").val()).length == 0 || $.trim($("#reset_password").val()).length < 6 ) {  
       
        $("#error-msg").html("El Password no es lo suficientemente largo").fadeIn('slow'); 
        return false;  
    }
    
    if($.trim($("#reset_password").val()) != $.trim($("#reset_password_confirm").val()) ) {   
        $("#error-msg").html("Los Passwords no coinciden").fadeIn('slow'); 
        return false;  
    }
  });


});