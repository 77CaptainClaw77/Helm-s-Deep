import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.*;
import java.sql.*;
class LoginPage implements ActionListener {
    static JFrame jf;
    JTextField ufield = new JTextField(25);
        JPasswordField pwfield = new JPasswordField(25);
    LoginPage() {
        jf=new JFrame("LOGIN");
        jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        jf.setLayout(new GridLayout(3, 1));
        JLabel uname = new JLabel("Username");
        JLabel password = new JLabel("Password");
        JButton submit = new JButton("Submit");
        JButton exit = new JButton("Exit");
        submit.addActionListener(this);
        exit.addActionListener(this);
        jf.add(uname);
        jf.add(ufield);
        jf.add(password);
        jf.add(pwfield);
        jf.add(submit);
        jf.add(exit);
        jf.pack();
        jf.setVisible(true);
    }

    public void actionPerformed(ActionEvent ae) {
        if(ae.getActionCommand()=="Submit"){
            String uname=ufield.getText();
            String password=pwfield.getText();
            try{
               // Class.forName("com.mysql.jdbc.Driver");
                Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/student","root","");
               /* Statement stmt=con.createStatement();
                ResultSet rs=stmt.executeQuery("SELECT * FROM user_details WHERE username=\''"+uname+"\' AND password=\'"+password+"\'");
                if(rs.next()){
                    JOptionPane.showMessageDialog(jf, "SUCCESS", "success", JOptionPane.INFORMATION_MESSAGE);
                }
                else{
                    JOptionPane.showMessageDialog(jf, "Invalid Credentials Entered!", "invalid", JOptionPane.ERROR_MESSAGE);
                }*/
                con.close();
            }
            catch(Exception e){
                System.out.println(e);
                e.printStackTrace();
            }
        }
        else{
            jf.dispose();
            System.exit(0);
        }
    }
}
class ExecLogin{
    public static void main(String[] args) {
        new LoginPage();
    }
}
