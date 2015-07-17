$(function() {

  var elements = $(".code_replace");
  for(var i = 0; i < elements.length; i++){
    var editor = CodeMirror.fromTextArea(elements[i], {
      lineNumbers: true,
      styleActiveLine: true,
      matchBrackets: true,
	    theme: 'solarized dark',
	    readOnly: true,
    });
  }  


});