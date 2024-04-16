package sem6.Java.practicals.slip19;

import helper.ConnectionProvider;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.*;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author haris
 */
@WebServlet(urlPatterns = {"/validate"})
public class validate extends HttpServlet {
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        try (PrintWriter out = response.getWriter()) {
            /* TODO output your page here. You may use following sample code. */
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Servlet validate</title>");
            out.println("</head>");
            out.println("<body>");

            String username = request.getParameter("username");
            String password = request.getParameter("password");
           
            try {
                Connection conn = ConnectionProvider.getConnection();
                boolean login = false;
                if (conn != null) {
                    String sql = "select * from student where username=? and password=?";

                    PreparedStatement st = conn.prepareStatement(sql);
                    st.setString(1, username);
                    st.setString(2, password);
                    ResultSet set = st.executeQuery();
                    while (set.next()) {
                        login = true;
                    }
                    if(login){
                        out.println("Login Successfull");
                    }
                    else{
                        out.println("Login Failed");
                    }
                }
                else{
                    out.println("Connection failed");
                }

            } catch (Exception exp) {
                out.println(exp);
                exp.printStackTrace();
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

