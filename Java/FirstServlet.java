import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
public class FirstServlet extends HttpServlet{
    public void doGet(HttpServletRequest request,HttpServletResponse response) throws IOException,ServletException{
	response.setContentType("text/html");
	PrintWriter pw=response.getWriter();
	String name=request.getParameter("name");
	String address=request.getParameter("address");
	pw.println("<html><head><title>First Servlet</title></head>");
	pw.println("<body><center><h1>Hello "+name+"</center> <br> @ "+address+"</body></html>");
	pw.close();
    }
}
    
