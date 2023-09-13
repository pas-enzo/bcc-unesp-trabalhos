//Jogo cliente-servidor para a disciplina de Programação Orientada à objetos. Parte do servidor.
//Bad Ice Cream - Servidor
//Enzo Campanholo Paschoalini - RA: 221026215
//Thiago Bigotte Gullo - RA: 221026241

import java.net.*;
import java.awt.Rectangle;
import java.io.*;
import java.util.*;

class ServerBIC {

  ServerBIC(){
    ServerSocket serverSocket = null;
    try {
      serverSocket = new ServerSocket(80);
    } catch (IOException e) {
      System.out.println("Could not listen on port: " + 80 + ", " + e);
      System.exit(1);
    }

   // while (true) {
      try {
        Socket clientSocket1 = serverSocket.accept();
        System.out.println("Accept Funcionou (1)!");
        Socket clientSocket2 = serverSocket.accept();
        System.out.println("Accept Funcionou (2)!");
        new ServerPlayer(clientSocket1, clientSocket2 );

      } catch (IOException e) {
        System.out.println("Accept failed: " + 12345 + ", " + e);
        System.exit(1);
      }
    //}
  }

  
class ServerPlayer{
  
  DataOutputStream os[] = new DataOutputStream[2];
  DataInputStream inputStream;
  Rectangle coin = new Rectangle(0, 0, 0, 0);
  int direcao, cont = 0;
  Rectangle p1 = new Rectangle(0,0, 0, 0);
  Rectangle p2 = new Rectangle(0,0,0,0);
  Random random = new Random();
  int p1X = 80 ,p1Y = 550, p2X = 880, p2Y = 550, i;
  int QP, QP1VIVO=1, QP2VIVO=1 ;
  static int coinX[] = new int[100];
  static int indicecoinX=0;
  static int coinY[] = new int[100];
  static int enemyX[] = new int[100]; 
  static int enemyY[] = new int[100];
  static int auxX;
  static int aux=-1;
  static int auxY;
  static int maxcoin = 7;
  static int maxenemy = 2;
  Socket clientSocket1;
  Socket clientSocket2;

  //variáveis para armazenar o estado de movimento de cada elemento:
  static int p1State = 1; //estado do jogador 1
  static int p2State = 1; //estado do jogador 2
  static int enemyState[] = new int[100];

  class ThreadClient extends Thread {
    Socket cli;
    int nCli;

    ThreadClient(Socket cli, int nCli) {
      this.cli = cli;
      this.nCli = nCli;
      System.out.println("Jogador " + nCli + " entrou");
    }

    public synchronized void run() {
      DataInputStream is;
      try {
        is = new DataInputStream(cli.getInputStream());
        os[nCli] = new DataOutputStream(cli.getOutputStream());
        do {
          int tecla = is.readInt();
          System.out.println("recebeu a tecla " + tecla);
          atualizacoord(tecla , nCli);
        } while (true);
      } catch (IOException e) {
        e.printStackTrace();
      } catch (NoSuchElementException e) {
        System.out.println("Conexacao terminada pelo cliente");
      }
    }
  }


  ServerPlayer(Socket clientSocket1, Socket clientSocket2) {
    
    geraInimigo();
    geraMoeda();
    new ThreadClient(clientSocket1, 0).start();
    new ThreadClient(clientSocket2, 1).start();

  new Thread() {
    public synchronized void run() {
      cont=0;
      while (true) {
        cont++;
        intersectEnemy();
        intersectCoin();
        if(cont>50){
        andainimigo();
        enviaCoordPlayer();
        enviaDados();
        }
        try {
          sleep(33);
        } catch (InterruptedException e) {}

      }
    }
  }.start();
  }
  
void atualizacoord(int tecla , int QP){
    if(QP == 0 && QP1VIVO ==0)return;
    if(QP == 1 && QP2VIVO ==0)return;
    
    if(tecla == 38){
      cima(QP);
    }
    

    if(tecla == 40){
      baixo(QP);
    }
    
    
    if(tecla == 37){
      esquerda(QP);
    }
    

    if(tecla == 39){
      direita(QP);
    }
    

}

    //função de movimento - retorna estados 1(cima) 2(baixo) 3(esquerda) 4(direita) 5(morto)
    public void direita(int QP) {
      if(QP == 0){
         if (p1X<970)
        p1X += 10;
        p1State = 4;
         
    }else{
       if (p2X<970)
      p2X += 10;
      p2State = 4;
       
    }
      } 

  public void esquerda(int QP) {
    if(QP == 0){
       if (p1X>-30)
      p1X -= 10;
      p1State = 3;

  }else{
    if (p2X>-30)
    p2X -= 10;
    p2State = 3;
  
}
      } 

  public void cima(int QP) {
    if(QP == 0){
       if (p1Y>-50)
      p1Y -= 10;
      p1State = 1;
       
  }else{
     if (p2Y>-50)
    p2Y -= 10;
    p2State = 1;
     
  }
      } 

  public void baixo(int QP) {
    if(QP == 0){
       if (p1Y<550)
      p1Y += 10;
      p1State = 2;
       
  }else{
     if (p2Y<550)
    p2Y += 10;
    p2State = 2;
     
  }

      } 

void intersectEnemy(){
  p1.setBounds(p1X, p1Y, 40, 40);
  p2.setBounds(p2X, p2Y, 40, 40);
      for(int i =0 ; i< maxenemy ; i++){
     Rectangle enemy = new Rectangle(enemyX[i],enemyY[i], 20 , 40);

     if(enemy.intersects(p1)){
      QP1VIVO = 0;
      p1State = 5;
     }

     if(enemy.intersects(p2)){
      QP2VIVO = 0;
      p2State = 5;
     }

  }
}

void intersectCoin(){
  p1.setBounds(p1X, p1Y, 40, 40);
  p2.setBounds(p2X, p2Y, 40, 40);
  
  int coint0 = 0;
  for(int i =0 ; i< maxcoin ; i++){
          coin.setBounds(coinX[i], coinY[i], 30, 30);

     if(coin.intersects(p1) || coin.intersects(p2)){
      System.out.println("intersectou com a moeda " + i);
      coinY[i] = -1000;
      coinX[i] = -1000;
     }

     
     //verifica se acabou as moedas pra gerar mais
     if(coinX[i] == -1000){
      coint0 ++;
      if(coint0 == maxcoin){
        maxcoin +=3;
        maxenemy ++;
        geraMoeda();
        geraInimigo();
    }
  }
  }
}

void andainimigo(){
    //System.out.println("mudando direcao inimigo");
      for(int i=0 ; i<maxenemy ; i++){
          direcao = random.nextInt(4);
          //direita
          if(direcao == 0){ 
          enemyX[i] +=10;
          enemyState[i] = 4;
          }
          //esquerda
          if(direcao == 1){
            enemyX[i] -=10;
            enemyState[i] = 3;
}         
         //cima
          if(direcao == 2){
            enemyY[i] -=10;
            enemyState[i] = 1;
          }
          //baixo
          if(direcao == 3){
            enemyY[i] +=10;
            enemyState[i] = 2;
          }
          if(enemyX[i] >=800) enemyX[i] -=20;     
          if(enemyX[i] <= 100) enemyX[i] +=20;
          if(enemyY[i] <= 100) enemyY[i] +=20;
          if(enemyY[i] >=400) enemyY[i] -=20;
      }
          
      }
     
public synchronized void enviaCoordPlayer() {
  try {
    
    if (os[0] == null || os[1] == null)
    return; 
  // System.out.println("enviou coord");
   for(int i=0 ; i<2 ; i++){
      if(i == 0){               
        os[0].writeInt(p1X); //player 1
        os[0].writeInt(p1Y);
        os[0].writeInt(p1State);
        os[0].writeInt(p2X); //player 1
        os[0].writeInt(p2Y);
        os[0].writeInt(p2State);

        os[1].writeInt(p2X); //player 2
        os[1].writeInt(p2Y);
        os[1].writeInt(p2State);
        os[1].writeInt(p1X); //player 2
        os[1].writeInt(p1Y);
        os[1].writeInt(p1State);

        os[0].flush();
        os[1].flush();
        }

        if(i == 1){
          os[0].writeInt(p2X); //player 2
          os[0].writeInt(p2Y);
          os[0].writeInt(p2State);
          os[0].writeInt(p1X); //player 2
          os[0].writeInt(p1Y);
          os[0].writeInt(p1State);

          os[1].writeInt(p1X); //player 1
          os[1].writeInt(p1Y);
          os[1].writeInt(p1State);
          os[1].writeInt(p2X); //player 1
          os[1].writeInt(p2Y);
          os[1].writeInt(p2State);

          os[0].flush();
          os[1].flush();
        }
        
      }
      } catch (IOException e) {
       
        e.printStackTrace();
    }
  }

public synchronized void enviaDados() {
      try {    
        if (os[0] == null || os[1] == null)
        return; 
            for(int b = 0 ; b<2 ; b++){

              os[b].writeInt(maxcoin);
              os[b].writeInt(maxenemy);

              for(i =0 ; i<maxenemy ; i++){
              os[b].writeInt(enemyX[i]);//vetor
              os[b].writeInt(enemyY[i]);  //vetor
              os[b].writeInt(enemyState[i]);
              }
              for(i =0 ; i<maxcoin ; i++){
              os[b].writeInt(coinX[i]); //vetor
              os[b].writeInt(coinY[i]); //vetor
              }
              os[b].flush();  
              }
            
                    
            
      } catch (IOException e) {
            e.printStackTrace();
        } 
      
  }
      
static void geraMoeda(){
  for(int i =0 ; i<maxcoin ; i++){
  Random random = new Random();
  auxX = random.nextInt(950);
  auxY = random.nextInt(150, 350);
  coinX[i] = auxX;
  coinY[i] = auxY;
}
System.out.println("Gerou " + maxcoin + " moedas");
}

static void geraInimigo(){
  for(int i =0 ; i<maxenemy ; i++){
Random random = new Random();
auxX = random.nextInt(900);
auxY = random.nextInt(150, 350);
enemyX[i] = auxX;
enemyY[i] = auxY;
System.out.println("coord do inimigo " + i + " " +  auxX + " " +auxY);
}
System.out.println("Gerou " + maxenemy + " inimigos");
}
}

public static void main(String[] args) throws IOException {
  new ServerBIC();
}
}
