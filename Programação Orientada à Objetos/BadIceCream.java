//Jogo cliente-servidor criado para a disciplina de Programação Orientada à objetos, feito em dupla. Parte do cliente.
//Bad Ice Cream - Cliente
//Enzo Campanholo Paschoalini - RA: 221026215
//Thiago Bigotte Gullo - RA: 221026241

import java.awt.*;
import java.awt.event.*;
import javax.imageio.ImageIO;
import javax.swing.*;
import java.io.*;
import java.net.*;

import java.awt.image.BufferedImage;

class BIC extends JFrame {
    static PBIC des = null;
    static Socket socket = null;
    static int pX, qp;
    static int pY;
   
    BIC() {
        super("Bad Ice Cream");
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        if (des != null) {
            add(des);
           
            pack();
            setVisible(true);
            setResizable(false);
            setLocationRelativeTo(null);
        } else {
            System.out.println("Ocorreu um erro ao criar o objeto 'desenho'. Não é possível iniciar BadIceCream.");
        }
    }

    public static class PBIC extends JPanel{
        
        // - declaração das imagens dos sprites dos clientes e dos inimigos
        private BufferedImage clienteUmFrente;
        private BufferedImage clienteUmCostas;
        private BufferedImage clienteUmEsquerda;
        private BufferedImage clienteUmDireita;
        private BufferedImage clienteUmMorto;

        private BufferedImage clienteDoisFrente;
        private BufferedImage clienteDoisCostas;
        private BufferedImage clienteDoisEsquerda;
        private BufferedImage clienteDoisDireita;
        private BufferedImage clienteDoisMorto;

        private BufferedImage inimigoFrente;
        private BufferedImage inimigoCostas;
        private BufferedImage inimigoEsquerda;
        private BufferedImage inimigoDireita;

        private BufferedImage spriteMoeda;
        private BufferedImage imagemFundo;
        // -------------------------------------------------------------------


        Socket socket = null;
        BIC bic;
        public int pX=0 ;
        public int pY=0;
        int maxcoin=0, maxenemy=0;
        int coinX[] = new int[150];
        int coinY[] = new int [150]; 
         int enemyX[] = new int [150];
        int enemyY[] = new int [150];
        int aux=0, i, qp;
        DataOutputStream outputStream ;
        DataInputStream inputStream;
        Rectangle p = new Rectangle(pX , pY, 20, 40);
        int potherX=0, potherY=0;
        //Scanner tecla = new Scanner(inputStream);
        int estadoMovimento1 = 1;
        int estadoMovimento2 = 1;
        int estadoMovimentoInimigo[] = new int[150];
    
        PBIC(Socket socket) throws IOException {
          this.socket = socket;
          
          try{

          // - carregar as imagens usando ImageIO.read()
                clienteUmFrente = ImageIO.read(new File("jogador_azul_frente.png"));
                clienteUmCostas = ImageIO.read(new File("jogador_azul_costas.png"));
                clienteUmEsquerda = ImageIO.read(new File("jogador_azul_esquerda.png"));
                clienteUmDireita = ImageIO.read(new File("jogador_azul_direita.png"));
                clienteUmMorto = ImageIO.read(new File("jogador_azul_morto.png"));

                clienteDoisFrente = ImageIO.read(new File("jogador_vermelho_frente.png"));
                clienteDoisCostas = ImageIO.read(new File("jogador_vermelho_costas.png"));
                clienteDoisEsquerda = ImageIO.read(new File("jogador_vermelho_esquerda.png"));
                clienteDoisDireita = ImageIO.read(new File("jogador_vermelho_direita.png"));
                clienteDoisMorto = ImageIO.read(new File("jogador_vermelho_morto.png"));

                inimigoFrente = ImageIO.read(new File("inimigo_frente.png"));
                inimigoCostas = ImageIO.read(new File("inimigo_costas.png"));
                inimigoEsquerda = ImageIO.read(new File("inimigo_esquerda.png"));
                inimigoDireita = ImageIO.read(new File("inimigo_direita.png"));

                spriteMoeda = ImageIO.read(new File("sprite_token_banana.png"));
                imagemFundo = ImageIO.read(new File("fundo.jpg"));
          
          }catch(IOException e){
            System.out.println(e);
          }
          
          
          setPreferredSize(new Dimension(1000, 600));
          setMinimumSize(new Dimension(1000, 600));
          setMaximumSize(new Dimension(1000, 600));

          System.out.println("Jogador iniciou");
          outputStream = new DataOutputStream(socket.getOutputStream());
          inputStream = new DataInputStream(socket.getInputStream());
          recebeCoord();
          recebeDados();
          
          setFocusable(true);
          setFocusTraversalKeysEnabled(false);
 
         addKeyListener(new KeyAdapter() {
          public void keyPressed(KeyEvent e) {
            int key = e.getKeyCode();
          
              try {
                outputStream.writeInt(key);
                outputStream.flush();
              } catch (IOException e1) {
             
                e1.printStackTrace();
              }
          }
        });
         
    Thread thread = new Thread(){
            public void run(){
             try {
              
           
              do{ 
              recebeCoord();
              recebeDados();
               
             if(aux!=0)
             repaint();
          //   sleep(50);
            }while(true);
            } catch (Exception e) {
              System.out.println(e);
             }
            }
            };
            thread.start();
      
    }
      
        
    
      public void paintComponent(Graphics g) {
          super.paintComponent(g);
          aux=1;

          g.drawImage(imagemFundo, 0, 0, getWidth(), getHeight(), null);
   
if (estadoMovimento1 == 1) 
    g.drawImage(clienteUmCostas, pX, pY, null);

if (estadoMovimento1 == 2) 
    g.drawImage(clienteUmFrente, pX, pY, null);

if (estadoMovimento1 == 3) 
    g.drawImage(clienteUmEsquerda, pX, pY, null);

if (estadoMovimento1 == 5) 
    g.drawImage(clienteUmMorto, pX, pY, null);

if (estadoMovimento1 == 4) 
    g.drawImage(clienteUmDireita, pX, pY, null);
    

if (estadoMovimento2 == 1) 
    g.drawImage(clienteDoisCostas, potherX, potherY, null);

if (estadoMovimento2 == 3) 
    g.drawImage(clienteDoisEsquerda, potherX, potherY, null);
    
if (estadoMovimento2 == 2) 
    g.drawImage(clienteDoisFrente, potherX, potherY, null);

if (estadoMovimento2 == 5) {
    g.drawImage(clienteDoisMorto, potherX, potherY, null);
}

if (estadoMovimento2 == 4)
    g.drawImage(clienteDoisDireita, potherX, potherY, null);

if ((estadoMovimento1 == 5) && (estadoMovimento2 == 5)) {
  String gameOverText = "GAME OVER";
        Font font = new Font("Arial", Font.BOLD, 150); // Define a fonte, tamanho e estilo
        FontMetrics fontMetrics = g.getFontMetrics(font);
        int textWidth = fontMetrics.stringWidth(gameOverText);
        int textHeight = fontMetrics.getHeight();
        g.setFont(font);
        g.setColor(Color.RED);
        g.drawString(gameOverText, (getWidth() - textWidth) / 2, (getHeight() - textHeight) / 2);
}

        //moeda
          for(int i=0 ; i<maxcoin ; i++){
            g.drawImage(spriteMoeda, coinX[i], coinY[i], null);
          }

          //inimigos
          for(int j=0 ; j<maxenemy ; j++){
            if (estadoMovimentoInimigo[j] == 1)
            g.drawImage(inimigoCostas, enemyX[j], enemyY[j], null);

               if (estadoMovimentoInimigo[j] == 2)
                g.drawImage(inimigoFrente, enemyX[j], enemyY[j], null);

                if (estadoMovimentoInimigo[j] == 3)
                  g.drawImage(inimigoEsquerda, enemyX[j], enemyY[j], null);

                  if (estadoMovimentoInimigo[j] == 4)
                  g.drawImage(inimigoDireita, enemyX[j], enemyY[j], null);        
          }
      
      }
        
      public void recebeCoord() {
        try {
        pX = inputStream.readInt();
        pY = inputStream.readInt();
        estadoMovimento1 = inputStream.readInt();
        potherX = inputStream.readInt();
        potherY = inputStream.readInt();
        estadoMovimento2 = inputStream.readInt();
      } catch (Exception e) {
        e.printStackTrace();
     
      }
      }

      public void recebeDados() {
        try {

              pX = inputStream.readInt();
              pY = inputStream.readInt();
              estadoMovimento1 = inputStream.readInt();
              potherX = inputStream.readInt();
              potherY = inputStream.readInt();
              estadoMovimento2 = inputStream.readInt();
    
              maxcoin =  inputStream.readInt();
              maxenemy = inputStream.readInt();

             
                for(i =0 ; i<maxenemy ; i++){
              enemyX[i] =  inputStream.readInt();
              enemyY[i] =  inputStream.readInt();
              estadoMovimentoInimigo[i] = inputStream.readInt();
                }
                for(i =0 ; i<maxcoin ; i++){
              coinX[i] = inputStream.readInt();
              coinY[i] = inputStream.readInt();
                }
               
    }catch (IOException e) {
                e.printStackTrace();
                System.out.println("Problema no começo");
  
      
    }
    }

  }
    static public void main(String[] args) throws IOException {
         // Conecta ao servidor
        try {
            socket = new Socket("localhost", 80);
            des = new PBIC(socket);
        } catch (UnknownHostException e) {
            e.printStackTrace();
            System.out.println("Não foi possível resolver o host.");
        } catch (IOException e) {
            e.printStackTrace();
        } catch(Exception e){
            e.printStackTrace();
            System.out.println("Ocorreu uma exceção ao criar o objeto 'desenho'.");
        }

        if (socket!=null && des != null) {
            new BIC();
        } else {
            System.out.println("Ocorreu um erro ao criar o socket ou o objeto 'des'. Não é possível executar BadIceCream.");
        }
    }
}
