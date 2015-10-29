/**
 * Plugin para validar las reglas de gamificacion 
 */
$(function() {
  
  $("#btn-addRule").click(function () {

  if($("#eventName").val() == -1 ) {  
      $("#error-msg").html("Falta el evento que dispara la regla").fadeIn('slow'); 
      return false;  
    }

    if($.trim($("#image").val()).length == 0 ) {  
      $("#error-msg").html("Falta el Badge de la regla").fadeIn('slow'); 
      return false;  
    }

    if($.trim($("#threshold").val()).length == 0 ) {  
      $("#error-msg").html("Falta el Umbral").fadeIn('slow'); 
      return false;  
    }

    if($.trim($("#xp").val()).length == 0 ) {  
      $("#error-msg").html("Falta los Puntos de experiencia").fadeIn('slow'); 
      return false;  
    }
    
    if($.trim($("#rp").val()).length == 0 ) {  
      $("#error-msg").html("Falta los Puntos de Reputacion").fadeIn('slow'); 
      return false;  
    }
    
    if($.trim($("#lp").val()).length == 0 ) {  
      $("#error-msg").html("Falta los Puntos de nivel").fadeIn('slow'); 
      return false;  
    }

  });

});