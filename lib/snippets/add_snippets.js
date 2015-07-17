$(function() {

  //-------------------------------------------------------------
  /*
  *  Validamos formulario agregar snippet
  *  
  */
  //-------------------------------------------------------------
  $("#btn-addsnippet").click(function () {
	 
	if($.trim($("#title").val()).length == 0 ) {  
      $("#error-msg").html("Falta el titulo del Snippet").fadeIn('slow'); 
      return false;  
    }
	
	if($.trim($("#description").val()).length == 0 ) {  
      $("#error-msg").html("Falta la descripcion del Snippet").fadeIn('slow'); 
      return false;  
    }
	
    if($("#category").val() == -1 ) {  
       
        $("#error-msg").html("Debes Seleccionar un lenguaje").fadeIn('slow'); 
        return false;  
    }
	
	if($.trim(editor.getValue()).length == 0 ) {  
       
        $("#error-msg").html("Nos falta tu Snippet").fadeIn('slow'); 
        return false;  
    }
	
	if($.trim($('#tags').val()).length == 0 ) {  
       
        $("#error-msg").html("Nos falta los Tags").fadeIn('slow'); 
        return false;  
    }
	
	var btn = $(this);
        btn.button('loading');
        setTimeout(function () { 
          btn.button('reset');
            }, 3000);
	
  });
  //----------------------------------------------------------------------------------
  // Inicializamos los tags de Snippets
  $('#tags').tagsInput({
	  width:'auto',
	  defaultText:'+tag',
	  maxChars : 10,
	  height:'34px'
	});
	
  //Inicializamos el charcounter 
  $(".counted_description").charCounter(550,{container: "#counter_description"});

  // Inicializamos el Editor de codigo
  var editor = CodeMirror.fromTextArea(document.getElementById("code"), {
    lineNumbers: true,
    styleActiveLine: true,
    matchBrackets: true,
	theme: 'solarized dark',
	extraKeys: {
        "F11": function(cm) {
          cm.setOption("fullScreen", !cm.getOption("fullScreen"));
        },
        "Esc": function(cm) {
          if (cm.getOption("fullScreen")) cm.setOption("fullScreen", false);
        }
      }
  });
  //----------------------------------
});