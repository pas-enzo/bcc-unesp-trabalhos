/*Exercicios da lista ExeciciosPOO.pdf*/

//Enzo Campanholo Paschoalini - RA: 221026215

//Exercicio 1 ---------------------------------------------------------------------------------------------------------------
/*1. Uma Classe em Java é um tipo de dado definido pelo programador composto de estados, características  e comportamentos
que permite o armazenamento de propriedades e métodos dentro dela. Basicamente, as classes são moldes nas quais são baseadas
as instâncias de objetos, e defini-la envolve especificar seus atributos e seus métodos. Pode ser considerada semelhante ao
tipo de dado “struct” da linguagem C, uma vez que o usuário define quais atributos estão contidas dentro dela, mas difere
desta estrutura uma vez que as classes podem armazenar também as funções dentro delas, enquanto as structs podem apenas
armazenar dados. Sua definicao occorre da seguinte maneira:*/

class nomeClasse {
    
    //atributos
    int atributoInteiro;
    float atributoFlutuante;

    //metodos
    void setInteiro (int _inteiro) {
        atributoInteiro = _inteiro;
    }

    void setFlutuante (float _flutuante) {
        atributoFlutuante = _flutuante;
    }
}
//---------------------------------------------------------------------------------------------------------------------------

//Exercicio 2 ---------------------------------------------------------------------------------------------------------------
/*A Instância em Java é um novo objeto, de nome dado pelo programador, que é criado a partir de uma classe, utilizando o
operador “new”. A instanciação de uma classe se resume no ato de criar um novo objeto a partir desta mesma classe. Vale 
ressaltar que uma classe não pode ser utilizada se não for criada uma instância de tal classe. Sua implementacao ocorre da se-
guinte maneira:*/

class exemploInstancia {

    nomeClasse x = new nomeClasse(); //novo objeto com nome "x" instancia a classe nomeClasse, e passa a existir na memoria
}
//---------------------------------------------------------------------------------------------------------------------------

//Exercicio 3 ---------------------------------------------------------------------------------------------------------------
/*Dizer que um método está sobrecarregado, na linguagem de programação Java, diz respeito ao conceito de polimorfismo, que 
nada mais é do que criar variações de um mesmo método. Basicamente, se resume na criação de dois ou mais métodos de mesmo nome 
em uma mesma classe. Isso permite que seja utilizado o mesmo nome em mais de um método contanto que seus argumentos sejam 
diferentes para que haja algum tipo de separação.*/
//---------------------------------------------------------------------------------------------------------------------------

//Exercicio 4 ---------------------------------------------------------------------------------------------------------------
/*O “override”, ou sobreposição de métodos, na programação orientada a objetos, também é um recurso do polimorfismo que 
permite que uma subclasse reescreva um método que originalmente pertencia a sua superclasse. Deste modo, a implementação da 
subclasse se sobrepõe à implementação da superclasse. */
//---------------------------------------------------------------------------------------------------------------------------

//Exercicio 5 ---------------------------------------------------------------------------------------------------------------
/*5. O modificador “FINAL”, quando utilizado antes de um atributo, a torna uma constante e faz com que ela só possa ser 
inicializada uma única vez, ou diretamente na declaração da classe ou no método construtor. Já quando ela é utilizada antes de
 um método, este modificador garante que este não será sobrescrito, ou seja, o método declarado como final terá o seu protótipo
  mantido, e, quando chamado por um objeto da classe, seu código será executado. Nenhuma classe herdeira é capaz de sobrescrever
   um método definido como final. */
//---------------------------------------------------------------------------------------------------------------------------

//Exercicio 6 ---------------------------------------------------------------------------------------------------------------
class Pessoa {
    private String nome;
    private String endereco;
    private String telefone;

    //retorna o valor de cada atributo privado
    public String retornaNome() {
        return nome;
    }

    public String retornaEnd() {
        return endereco;
    }

    public String retornaTele() {
        return telefone;
    }

    //atribui o valor para cada string
    void setNome (String _nome) {
        this.nome = _nome;
    }

    void setEnd (String _end) {
        this.endereco = _end;
    }

    void setTele (String _tele) {
        this.telefone = _tele;
    }

    //imprime os valores na tela
    void imprime() {
        System.out.println("Nome: " + nome);
        System.out.println("Endereco: " + endereco);
        System.out.println("Telefone: " + telefone);
    }
}
//---------------------------------------------------------------------------------------------------------------------------

//Exercicio 7 ---------------------------------------------------------------------------------------------------------------
class Aluno extends Pessoa {
    private String ra;

    //retorna o valor de ra
    public String retornaRa() {
        return ra;
    }

    //atribui valor para ra
    void setRa(String _ra) {
        this.ra = _ra;
    }

    //sobreposicao de metodos
    void imprime() {
        super.imprime();
        System.out.println("RA: " + ra);
    }
}
//---------------------------------------------------------------------------------------------------------------------------

//Exercicio 8 ---------------------------------------------------------------------------------------------------------------
class Mostra extends MostraDados {
    //metodos sobrecarregados 
    void mostra(int _valor) {
        System.out.println("Valor: " + _valor);
    }

    void mostra(float _x) {
        System.out.println("X: " + _x);
    }
}
//---------------------------------------------------------------------------------------------------------------------------

//Exercicio 9 ---------------------------------------------------------------------------------------------------------------
//a classe MostraDados foi alterada para uma interface abstrata
abstract interface MostraDados {
    abstract void mostra(int l);
    abstract void mostra(float f);
}

//ao inves de usar a sintaxe extends, a interface implica que deve ser utilizado a palavra implements
class Mostra implements MostraDados {
    //metodos sobrecarregados 
    void mostra(int _valor) {
        System.out.println("Valor: " + _valor);
    }

    void mostra(float _x) {
        System.out.println("X: " + _x);
    }
}

class ProgPrincipal {
    static int valor = 123;
    static float x = 4.56;
    
    static void mostraValores(MostraDados db) {
        db.mostra(x);
        db.mostra(valor);
    }

    public static void main(String []s) {
        Mostra mostra = new Mostra();
        mostraValores(mostra);
    }
}
//---------------------------------------------------------------------------------------------------------------------------

//Exercicio 10 --------------------------------------------------------------------------------------------------------------
/*10. Podem existir duas funções mostra() na mesma classe por causa do sobrecarregamento de métodos, um conceito do 
polimorfismo, que dita que é possível criar dois ou mais métodos de mesmo nome em uma classe. A linguagem as diferencia pelos 
seus argumentos, que obrigatoriamente devem ser diferentes para que essa técnica funcione. */
//---------------------------------------------------------------------------------------------------------------------------
