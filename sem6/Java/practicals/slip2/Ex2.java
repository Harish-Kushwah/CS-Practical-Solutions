package sem6.Java.practicals.slip2;

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author haris
 */
@WebServlet(urlPatterns = {"/Ex2"})
public class Ex2 extends HttpServlet {

    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        try (PrintWriter out = response.getWriter()) {
          
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Servlet Ex2</title>");            
            out.println("</head>");
            out.println("<body>");
            out.println("<h1>Servlet Ex2 at " + request.getContextPath() + "</h1>");
            // Client information
            out.println("<h2>Client Information:</h2>");
            out.println("<p>IP Address: " + request.getRemoteAddr() + "</p>");
            out.println("<p>User-Agent: " + request.getHeader("User-Agent") + "</p>");

            // Server information
            out.println("<h2>Server Information:</h2>");
            out.println("<p>Server Name: " + request.getServerName() + "</p>");
            out.println("<p>Server Port: " + request.getServerPort() + "</p>");
            out.println("<p>Server OS: " + System.getProperty("os.name") + "</p>");
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
    }

}
