import java.util.Random;

class Caminhao {

    private int contador;

    public Caminhao () {
        contador = 1;
    }

    public String entrega() {
        return "Transporte via caminhão " + contaTransportes() + " registrado!\n" + 
        "Custo operacional: R$" + String.format("%.2f", calculaCustos()) + "\n";
    }

    public Integer contaTransportes() {
        return contador++;
    }

    public Float calculaCustos() {
        Random rand = new Random();
        float min = 0.0f;
        float max = 50000.0f;
        float numeroAleatorio = rand.nextFloat() * (max - min) + min;
        return numeroAleatorio;
    }


}

public class Main { 
    public static void main(String[] args) {
        Caminhao carreta = new Caminhao();
        
        // Cadastrando vários transportes!
        String resultado = carreta.entrega();
        String resultado1 = carreta.entrega();
        String resultado2 = carreta.entrega();
        String resultado3 = carreta.entrega();
        String resultado4 = carreta.entrega();

        System.out.println(resultado);
        System.out.println(resultado1);
        System.out.println(resultado2);
        System.out.println(resultado3);
        System.out.println(resultado4);

        System.out.println("Perceba que todo o código está centrado em torno da classe 'Caminhao'!");
        System.out.println("Perceba também que não tem como adicionar transporte marinho sem alterar drasticamente o código!");
    }
}