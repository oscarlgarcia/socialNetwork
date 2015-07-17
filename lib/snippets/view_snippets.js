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
        }
      }
  });

   
  //Inicializamos el charcounter
  $(".counted").charCounter(450,{container: "#counter"});

});