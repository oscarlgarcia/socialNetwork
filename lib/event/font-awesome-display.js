/**
* Plugin para visualizar los iconos de FontAwesome o Glyphicon
*/
$(function() {

  $("#icon_button_search").click(function () {
    $("#iconViewer").removeClass();
    $("#iconViewer").addClass($("#iconValue").val());
  });

  $("#iconViewer").click(function(){
    $("#eventImage").val($( this ).attr('class'));
    $("#mediaModal").modal('toggle');
  });

});