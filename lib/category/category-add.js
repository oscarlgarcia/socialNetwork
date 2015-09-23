/**
 * Plugin para validar las categorias 
 */
$(function() {
  
  $("#btn-addCat").click(function () {
     
    if($.trim($("#categoryName").val()).length == 0 ) {  
      $("#error-msg").html("Falta el titulo de la Categor&iacute;a").fadeIn('slow'); 
      return false;  
    }

    if($.trim($("#categoryDescription").val()).length == 0 ) {  
      $("#error-msg").html("Falta la descripci&oacute;n de la Categor&iacute;a").fadeIn('slow'); 
      return false;  
    }

    if($.trim($("#categoryImage").val()).length == 0 ) {  
      $("#error-msg").html("Falta la Imagen de la Categor&iacute;a").fadeIn('slow'); 
      return false;  
    }


  });

});