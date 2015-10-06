$(function() {

  // Cargamos el notificador
  var es = new EventSource("events.php");


  // Creamos el listener ( lo que se hara cuando se reciba el evento)
  var listener = function (event) {
    var div = document.createElement("div");
    var type = event.type;
    div.appendChild(document.createTextNode(type + ": " + (type === "message" ? event.data : es.url)));
    document.body.appendChild(div);
  };



  // escuchamos los eventos     
  //es.addEventListener("open", listener);
  es.addEventListener("message", listener);
  //es.addEventListener("error", listener);

});