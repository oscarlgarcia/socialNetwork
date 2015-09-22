$(function() {


  //--------------- preguntamos por el editor del CMS -------
  if (typeof(CKEDITOR) !== "undefined")
  {
    // Iniciamos el editor para el CMS
    CKEDITOR.replace('editor'); 
  }  


  //------ Enlazamos el evento click para cada pagina
  $(".tree li a" ).bind( "click", function() 
  {
    $(".tree li a" ).removeClass("label label-info");
    $("#parent").val($( this ).data("parent") );
    $( this ).addClass("label label-info");
  });


  //-------- Validacion de campos para guardar la Page -----------
  $("#btn-addPage").click(function () {
    
    if($.trim($("#title").val()).length == 0 ) {  
      $("#error-msg").html("Falta el titulo de la P&aacute;gina").fadeIn('slow'); 
      return false;  
    }
    
    if($.trim($("#url").val()).length == 0 ) {  
      $("#error-msg").html("Falta el URL de la P&aacute;gina").fadeIn('slow'); 
      return false;  
    }
    
    if($("#category").val() == -1 ) {  
       
        $("#error-msg").html("Debes Seleccionar una Categor&iacute;a").fadeIn('slow'); 
        return false;  
    }

    if($("#type").val() == -1 ) {  
       
        $("#error-msg").html("Debes Seleccionar un Tipo de P&aacute;gina").fadeIn('slow'); 
        return false;  
    }

    if($("#level").val() == -1 ) {  
       
        $("#error-msg").html("Debes Seleccionar un el nivel de Dificultad").fadeIn('slow');
        return false;  
    }
    
    if($.trim(CKEDITOR.instances.editor.getData()).length == 0 ) {     
        $("#error-msg").html("Falta el contenido de la Pagina").fadeIn('slow'); 
        return false;  
    }
    
    if($.trim($('#parent').val()).length == 0 ) {  
       
        $("#error-msg").html("Debes seleccionar de quien pertenece").fadeIn('slow'); 
        return false;  
    }    
    
    var btn = $(this);
        btn.button('loading');
        setTimeout(function () { 
          btn.button('reset');
            }, 3000);
    
    });


  //--------------------------------------------
  // Inicializamos los keywords SEO
  $('#keywords').tagsInput({
    width:'auto',
    defaultText:'+tag',
    maxChars : 10,
    height:'34px'
  });


  // ------------ Gestionamos el preview -----
  $('#preview-btn').click(function() {
    form = $('#add_page_form');
    form.attr('target',"_blank");
    form.attr('action','admin_cms/preview');
    form.submit();
  });


});