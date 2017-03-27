$(function() {


  //-------- Validacion de campos para guardar el controlador -----------
  $("#btn-addController").click(function () {
    
    if($.trim($("#controller_name").val()).length == 0 ) {  
      $("#error-msg").html("Falta el Nombre del Controlador").fadeIn('slow'); 
      return false;  
    }
    
    if($.trim($("#controller_description").val()).length == 0 ) {  
      $("#error-msg").html("Falta la Descripci&oacute;n del controlador").fadeIn('slow'); 
      return false;  
    }
    
    var btn = $(this);
        btn.button('loading');
        setTimeout(function () { 
          btn.button('reset');
            }, 3000);
    
    });


$('#radioBtn a').on('click', function(){
    var sel = $(this).data('title');
    var tog = $(this).data('toggle');
    $('#'+tog).prop('value', sel);
    
    $('a[data-toggle="'+tog+'"]').not('[data-title="'+sel+'"]').removeClass('active').addClass('notActive');
    $('a[data-toggle="'+tog+'"][data-title="'+sel+'"]').removeClass('notActive').addClass('active');
})



});