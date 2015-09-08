$(function() {

  //-------- Validacion de campos para actualizar el tag -----------
  $("#btn-updateTag").click(function () {
    
    if($.trim($("#tag_name").val()).length == 0 ) {  
      $("#error-msg").html("Falta el nombre del Tag").fadeIn('slow'); 
      return false;  
    }
    
    if($.trim($("#tag_name").val()) == $.trim($("#name_hidden").val()) ) {  
      $("#error-msg").html("No actualizaremos... es el mismo nombre").fadeIn('slow'); 
      return false;  
    }    
    
  });

  //-------- Validacion de campos para reasignar el tag ----------
  $("#btn-reasigTag").click(function () {
    
    if($("#id_hidden").val() == $('#tag_select :selected').val() ) {  
      $("#error-msg").html("Estas intentando re-asignar al mismo Tag").fadeIn('slow'); 
      return false;  
    } 

    if( $('#tag_select :selected').val() == -1) {  
      $("#error-msg").html("Debes seleccionar un Tag de destino").fadeIn('slow'); 
      return false;  
    } 
    
  });


});