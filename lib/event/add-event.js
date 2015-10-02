$(function() {

  //-------- Validacion de campos para agregar el Evento -----------
  $("#btn-addEvent").click(function () {
    
    if($.trim($("#eventName").val()).length == 0 ) {  
      $("#error-msg").html("Falta el nombre del Evento").fadeIn('slow'); 
      return false;  
    }

    if($.trim($("#eventDescription").val()).length == 0 ) {  
      $("#error-msg").html("Falta la descripci&oacute;n del Evento").fadeIn('slow'); 
      return false;  
    }  

    if($.trim($("#eventImage").val()).length == 0 ) {  
      $("#error-msg").html("Falta el Icono del Evento").fadeIn('slow'); 
      return false;  
    } 
    
  });

});