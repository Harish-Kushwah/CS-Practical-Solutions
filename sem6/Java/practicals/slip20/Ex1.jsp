
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <form action="s20.jsp" method="post">
            <input type="text" name="num" placeholder="Enter number">
            <button type="submit">submit</button>
        </form>
        
        <% 
           if(request.getParameter("num")!=null)
           {
             StringBuffer num_str  = new StringBuffer(request.getParameter("num"));
             num_str.reverse();
             
             String num_words="";
             for(int i=0; i<num_str.length(); i++){
             
              char num = num_str.charAt(i);
              if(num=='0'){
                  num_words+="Zero";
              }
              else if(num=='1'){
                num_words+=" One";
              }
              else if(num=='2'){
                num_words+=" Two";
              }
              else if(num=='3'){
                num_words+=" Three";
              }
              else if(num=='4'){
                num_words+=" Four";
              }
              else if(num=='5'){
                num_words+=" Five";
              }
              else if(num=='6'){
                num_words+=" Six";
              }
              else if(num=='7'){
                num_words+=" Seven";
              }
              else if(num=='8'){
                num_words+=" Eight";
              }
              else if(num=='9'){
                num_words+=" Nine";
              }
           }
           out.println(num_words);
        }
         
        %>
    </body>
</html>

