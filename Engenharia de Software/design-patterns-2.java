interface ICarro {
    String GetDescricao();
}

class CarroBasico implements ICarro {
    @Override
    public String GetDescricao() {
        return "Carro Básico";
    }
}

abstract class CarroDecorator implements ICarro {
    protected ICarro carroDecorado;

    public CarroDecorator(ICarro carroDecorado) {
        this.carroDecorado = carroDecorado;
    }

    @Override
    public String GetDescricao() {
        return carroDecorado.GetDescricao();
    }    
}

class CarroComNavegacao extends CarroDecorator {
    public CarroComNavegacao(ICarro carroDecorado) {
        super(carroDecorado);
    }

    @Override
    public String GetDescricao() {
        return super.GetDescricao() + ", com Navegação";
    }
}

class CarroComCor extends CarroDecorator {
    private String cor;

    public CarroComCor(ICarro carroDecorado, String cor) {
        super(carroDecorado);
        this.cor = cor;
    }

    @Override
    public String GetDescricao() {
        return super.GetDescricao() + ", Cor " + cor;
    }
}

class CarroComTetoSolar extends CarroDecorator {
    public CarroComTetoSolar(ICarro carroDecorado) {
        super(carroDecorado);
    }

    @Override
    public String GetDescricao() {
        return super.GetDescricao() + ", com Teto Solar";
    }
}

public class Main {
    public static void main(String[] args) {
        teste();
    }

    private static void teste() {
        System.out.println("Testando o Carro usando o padrão Decorator");
        System.out.println("------------------------------------------");

        ICarro carro = new CarroBasico();
        System.out.println(carro.GetDescricao());

        carro = new CarroComNavegacao(carro);
        System.out.println(carro.GetDescricao());

        carro = new CarroComCor(carro, "Azul");
        System.out.println(carro.GetDescricao());

        carro = new CarroComTetoSolar(carro);
        System.out.println(carro.GetDescricao());
    }
}
