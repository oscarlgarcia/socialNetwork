$(function() {

  $(".tree").find('li').show();

  $("#search").keyup(function(event ) {
    q = $.trim ( $("#search").val() );
    if(q.length > 0){
    	
       $(".tree").find('li').find('a').filter(function(){ 
         if (this.text.toLowerCase().indexOf(q.toLowerCase()) >= 0)
          	return true;
          else
          	return false;
       }).css('background-color','#E4FC5B');

       $(".tree").find('li').find('a').filter(function(){ 
         if (this.text.toLowerCase().indexOf(q.toLowerCase()) < 0)
           return true;
         else
          	return false;
       }).css('background-color','#ffffff');
    }
    else{
      	$(".tree").find('li').show();
    }

     
  });




});