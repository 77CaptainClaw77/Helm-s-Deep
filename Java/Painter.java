import javax.swing.*;
import java.awt.*;
class PainterPage
{
    JFrame p;
    PainterPage()
    {
        p=new JFrame();
        p.setSize(1280,720);
        p.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JPanel paintCanvas=new JPanel(){
            protected void paintComponent(Graphics g)
            {
                this.paintComponent(g);
                int h=getHeight();
                int w=getWidth();
                for(int i=0;i<100;i++)
                {
                    g.drawLine(i,i+1,i+2,i+3);
                }
            }
        };
        paintCanvas.setBorder(BorderFactory.createLineBorder(Color.cyan, 2, true ));
        p.add(paintCanvas);
        p.setVisible(true);
    }
}
class ExecPaint
{
    public static void main(String[] args) {
       new PainterPage();
    }
}