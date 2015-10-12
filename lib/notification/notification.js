$(function() {

  // Cargamos el notificador
  var es = new EventSource("http://localhost/socialNetwork/notification");


  if (!!window.EventSource) {
    var source = new EventSource("http://localhost/socialNetwork/notification");
  } else {
    alert("Your browser does not support Server-sent events! Please upgrade it!");
  }

  // Creamos el listener ( lo que se hara cuando se reciba el evento)
  var listener = function (event) {
    //var div = document.createElement("div");
    //var type = event.type;
    //div.appendChild(document.createTextNode(type + ": " + (type === "message" ? event.data : source.url)));
    //document.body.appendChild(div);
    var n = noty(
    {
      layout: 'bottomRight',
      text: event.data,
      type: 'information',
      maxVisible: 50,
      timeout: 10000
    }
    );

    
  };



  // escuchamos los eventos     
  //source.addEventListener("open", listener);
  source.addEventListener("message", listener);
  //source.addEventListener("error", listener);

});