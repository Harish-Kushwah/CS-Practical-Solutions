package sem6.Java.practicals.slip18;

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet(urlPatterns = {"/result"})
public class result extends HttpServlet {
    
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        try (PrintWriter out = response.getWriter()) {
            /* TODO output your page here. You may use following sample code. */
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Servlet result</title>");            
            out.println("</head>");
            out.println("<body>");
            
            out.println("Pno : " + request.getParameter("pno") +"<br>");
            out.println("Name :" + request.getParameter("name")+"<br>");
            out.println("Class :" + request.getParameter("class")+"<br>");
            out.println("Total Marks :" + request.getParameter("total_marks")+"<br>");
           
            int total_marks = Integer.parseInt(request.getParameter("total_marks"));
            
            float percentage = (float)(total_marks*1.0)/3;
            
            out.println("Percentage : " + percentage +"%" +"<br>");
            char grade;
            if(total_marks>90){
                grade='A';
            }
            else if(total_marks>80){
                grade='B';
            }
            else if(total_marks>60){
                grade = 'C';
            }
            else{
                grade = 'D';
            }
            out.println("Grade : " + grade  +"<br>");

            out.println("</body>");
            out.println("</html>");
        }
    }

       @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>

}
