import javax.swing.*;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

import static java.awt.Color.*;

import java.awt.*;
import java.awt.event.*;

class AlphaBetaView implements ActionListener {
    JFrame abv;
    JLabel jb;
    JPanel jp;

    AlphaBetaView() {
        abv = new JFrame();
        abv.setSize(1200, 768);
        jb = new JLabel();
        abv.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        jp = new JPanel();
        JButton alpha = new JButton("Alpha");
        JButton beta = new JButton("Beta");
        alpha.setText("Alpha");
        beta.setText("beta");
        jb.setText("Press Any Button");
        alpha.addActionListener(this);
        beta.addActionListener(this);
        jp.add(alpha);
        jp.add(beta);
        jp.add(jb);
        abv.add(jp);
        abv.setVisible(true);

    }

    public void actionPerformed(ActionEvent ae) {
        String txt = ae.getActionCommand();
        jb.setText(txt + " was pressed!");
        if (txt == "Alpha")
            jp.setBackground(blue);
        else
            jp.setBackground(red);
       //System.out.println(ae.getSource());
    }
}
class ExecAlphaBeta
{
    public static void main(String[] args) {
    SwingUtilities.invokeLater(new Runnable()
    {
        public void run()
        {
            new AlphaBetaView();
        }
    });        
       
    }
}