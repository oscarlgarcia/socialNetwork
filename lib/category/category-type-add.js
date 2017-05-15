/**
 * Plugin para validar los tipos de categorias 
 */
$(function() {
  
  $("#btn-addCat").click(function () {
     
    if($.trim($("#categoryName").val()).length == 0 ) {  
      $("#error-msg").html("Falta el titulo de la Categor&iacute;a").fadeIn('slow'); 
      return false;  
    }


  });

});