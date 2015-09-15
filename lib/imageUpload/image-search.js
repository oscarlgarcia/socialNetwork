 /**
 * Plugin para buscar imagenes  
 */
$(function() {

  // Formulario para buscar imagenes
  // se debe llamar imageSearchForm
  // boton image_button_search
  $("#image_button_search").click(function(){
    var form=$("#imageSearchForm");
    var iData=form.serializeArray();
    $("#image_box").load(form.attr('action'),iData);
    return false;
  });



});