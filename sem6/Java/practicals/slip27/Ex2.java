package sem6.Java.practicals.slip27;

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.*;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;

@WebServlet(urlPatterns = {"/SessionTimeout"})
public class Ex2 extends HttpServlet {

    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        try (PrintWriter out = response.getWriter()) {
            /* TODO output your page here. You may use following sample code. */
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Servlet SessionTimeout</title>");            
            out.println("</head>");
            out.println("<body>");
            
            HttpSession s =  request.getSession();
            out.println("<h3>Max Inactive interval :" + s.getMaxInactiveInterval()+ "</h3>");
            
            out.println("<h3>Set New Inactive time interval (2 hr) </h3>");
            s.setMaxInactiveInterval(2*60*60);  
                  
            out.println("<h3>New Max Inactive interval :" + s.getMaxInactiveInterval() + "<h3>");
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

