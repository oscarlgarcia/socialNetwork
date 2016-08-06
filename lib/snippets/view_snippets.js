$(function() {


  // Inicializamos el editor
  var editor = CodeMirror.fromTextArea(document.getElementById("code"), {
    lineNumbers: true,
    styleActiveLine: true,
    matchBrackets: true,
	  theme: 'solarized dark',
	  readOnly: true,
	  extraKeys: {
        "F11": function(cm) {
          cm.setOption("fullScreen", !cm.getOption("fullScreen"));
        },
        "Esc": function(cm) {
          if (cm.getOption("fullScreen")) cm.setOption("fullScreen", false);
          $(".ecpnavbar-bg").css('z-index',"1050");
        }
      }
  });

   
  //Inicializamos el charcounter
  $(".counted").charCounter(450,{container: "#counter"});

   $("#btn-fullscreen").click(function () {
    editor.setOption("fullScreen",true); 
    $("#code").css('z-index',"3000"); 
    $(".ecpnavbar-bg").css('z-index',"1029");  
   });

});