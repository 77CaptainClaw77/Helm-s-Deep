import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
import java.util.*;
import java.text.DateFormat;
public class svobj extends HttpServlet
{
    public void doGet(HttpServletRequest request,HttpServletResponse response) throws IOException,ServletException {
	response.setContentType("text/html");
	PrintWriter pw=response.getWriter();
	HttpSession sess=request.getSession();
	Date dt=new Date(sess.getLastAccessedTime());
	Date dtc=new Date(sess.getCreationTime());
	DateFormat df=DateFormat.getDateTimeInstance(DateFormat.MEDIUM,DateFormat.MEDIUM);
	pw.println("<html><head><title>Date Format</title></head><body>Now: "+df.format(new Date())+"<br>Access Time:"+df.format(dt)+"<br>Creation Time:"+df.format(dtc)+"</body></html>");
	pw.close();
    }
}
