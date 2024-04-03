package sem6.Java.practicals.slip11;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.*;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author haris
 */
@WebServlet(urlPatterns = {"/SearchServlet"})
public class SearchServlet extends HttpServlet {

    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        try (PrintWriter out = response.getWriter()) {
            /* TODO output your page here. You may use following sample code. */
            ArrayList<Customer> list = null;
            try {
                Connection con = ConnectionProvider.getConnection();
                String query = "SELECT * FROM customer where id = ?;";
                PreparedStatement st = con.prepareStatement(query);

                int cust_id = Integer.parseInt(request.getParameter("num"));
                st.setInt(1, cust_id);
                ResultSet set = st.executeQuery();

                list = new ArrayList<>();

                while (set.next()) {
                    int id = set.getInt("id");
                    String name = set.getString("name");
                    list.add(new Customer(id, name));

                }
                 request.setAttribute("list", list);
            getServletConfig().getServletContext().getRequestDispatcher("/search.jsp").forward(request, response); // redirect to jsp page

            } catch (ClassNotFoundException | SQLException ex) {
                out.println(ex);

            }
             catch (NullPointerException exp) {
                request.setAttribute("exp", "No record found");
                out.println(exp);
                        
            }
           

        }
    }

    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /**
     * Handles the HTTP <code>GET</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Handles the HTTP <code>POST</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Returns a short description of the servlet.
     *
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>

}
