$(function() {

 $(".deleteButton a").bind( "click", function() 
 {
   $("#delete_link").attr("href",$(this).data("deleteurl")); 
 });

});