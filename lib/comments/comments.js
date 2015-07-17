$(function() {

  //-------------------------------------------------------------------
  /*
  * Funcion de comentarios
  * El formulario debe llamarse commentForm
  * El boton comment-btn
  * El campo comment
  * Debe existir un campo AJAX
  * 
  */
  $("#comment-btn").click(function (event){

    if($.trim($('#comment').val()).length > 0 ) {
      var myBtn=$("#comment-btn");
      myBtn.button('loading');  
      var form=$("#commentForm");
      var iData=form.serializeArray();
      var action=form.attr('action')+"comment";
      
      $("#comment-box").load(action,iData,function( response, status, xhr ) {
        if ( status == "-1" ) {
          window.location.replace("home");
        }else{
	      myBtn.button('reset');
	      $("textarea#comment").val("");
	    }
      });
      return false;
    }
   });

  //-----------------------------------------

  //Para cargar los comentarios
  // incluir un formulario llamado commentForm
  // el action debe llamarse show_comment y debe ser "ajax way"
  // el control que carga los comentarios se llama coment-box
  var form=$("#commentForm");
  var iData=form.serializeArray();
  var action=form.attr('action')+"show_comment";
  $("#comment-box").load(action,iData);
  

  
});