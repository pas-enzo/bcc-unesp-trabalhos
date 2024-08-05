import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class Janela extends JFrame {
  JButton bt1;
  JLabel lb1;
  JComboBox<String> cb1;

  Janela() {
    super("Swing");
    setLayout(new FlowLayout( ));
    add(bt1 = new JButton("Botao 1"));
    add(lb1 = new JLabel("Label 1"));
    add(cb1 = new JComboBox<String>());
    add(new JTextField(20));
    cb1.addItem(new String("Item 1"));
    cb1.addItem("Item 2");
    cb1.addItem(new String("Item 3"));
    cb1.addItem("Item 4");
    cb1.addItem(new String("Item 5")); 
    cb1.addItem(new String("Item 6"));
    cb1.addItem(new String("Item 7"));
    cb1.addItem(new String("Item 8"));
    cb1.addItem(new String("Item 9"));
    cb1.addItem("Item 0");

    bt1.addActionListener(new EscutadorDoBotao(getContentPane()));

    setDefaultCloseOperation(EXIT_ON_CLOSE);

    pack();
    setSize(getWidth(), getWidth());
    
    setVisible(true);
  }
}

class EscutadorDoBotao implements ActionListener {
  JPanel pane;

  EscutadorDoBotao(Container f) {
    pane = (JPanel)f;
  }

  public void actionPerformed(ActionEvent e) {
    
    //Mostra uma mensagem erro
    JOptionPane.showMessageDialog(pane, "Mensagem", "Titulo",
                    JOptionPane.ERROR_MESSAGE);

    //Mostra uma mensagem informacao
    JOptionPane.showInternalMessageDialog(pane, "Mensagem", "Titulo",
                    JOptionPane.INFORMATION_MESSAGE);

    //Opcao
    int Opc=JOptionPane.showConfirmDialog(null, "Mensagem", "Titulo",
                    JOptionPane.YES_NO_OPTION);
    System.out.println(Opc);

    //Opcao
    Opc=JOptionPane.showInternalConfirmDialog(pane, "O que voce acha?", "Titulo",
                    JOptionPane.YES_NO_CANCEL_OPTION, JOptionPane.INFORMATION_MESSAGE);
    System.out.println(Opc);

    //Opcao
    Object[] options = { "Aceita", "Cancela" };
    Opc=JOptionPane.showOptionDialog(null, "Click Aceita to continue", "Titulo",
                    JOptionPane.DEFAULT_OPTION, JOptionPane.WARNING_MESSAGE, null, //null=sem icone
                    options, options[0]);
    System.out.println(Opc);

    //Le uma string
    String inputValue = JOptionPane.showInputDialog("Please input a value");
    System.out.println(inputValue);

    //Escolha entre varias opcoes
    Object[] possibleValues = { "Um", "Dois", "Tres" };
    Object selectedValue = JOptionPane.showInputDialog(null, "Escolha um", "Titulo",
                    JOptionPane.INFORMATION_MESSAGE, null,  //null=sem icone
                    possibleValues, possibleValues[1]);
    System.out.println(selectedValue);
  }
}

class Swing {
  static public void main(String[] args) {
    try {
    //~ UIManager.setLookAndFeel("javax.swing.plaf.synth.SynthLookAndFeel");
    //~ UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
    //~ UIManager.setLookAndFeel("com.sun.java.swing.plaf.motif.MotifLookAndFeel");
    UIManager.setLookAndFeel("javax.swing.plaf.metal.MetalLookAndFeel");
    } catch (Exception e) {}
    Janela f = new Janela();
  }
}