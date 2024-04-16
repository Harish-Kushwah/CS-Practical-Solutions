package sem6.Java.practicals.slip15;

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet(urlPatterns = {"/Ex2"})
public class Ex2 extends HttpServlet {

    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        try (PrintWriter out = response.getWriter()) {
            /* TODO output your page here. You may use following sample code. */
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Servlet Ex2C</title>");
            out.println("</head>");
            out.println("<body>");

            //Add this code only after creating the servlet             
            Cookie[] c = request.getCookies();
            if (c == null) {
                out.println("Welcome on our webpage");
                Cookie visitCount = new Cookie("VisitCount", "1");
                response.addCookie(visitCount);
            } else {
                if (c[0].getName().equals("VisitCount")) {
                    int count = Integer.parseInt(c[0].getValue()) + 1;
                    Cookie visitCount = new Cookie("VisitCount", Integer.toString(count));
                    response.addCookie(visitCount);
                    out.println("Visit count :" + count);
                }
            }
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
