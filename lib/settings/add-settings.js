$(function() {

  //-------- Validacion de campos para agregar el tag -----------
  $("#btn-addSetting").click(function () {
    
    if($.trim($("#setting_key").val()).length == 0 ) {  
      $("#error-msg").html("Falta el nombre del Setting").fadeIn('slow'); 
      return false;  
    }

    if($.trim($("#setting_value").val()).length == 0 ) {  
      $("#error-msg").html("Falta el valor del Setting").fadeIn('slow'); 
      return false;  
    }  
    
  });

});