import java.sql.*;

class Cria {
    public static void main(String[] args) {
        try {
            Class.forName("org.hsql.jdbcDriver");
            Connection con = DriverManager.getConnection("jdbc:HypersonicSQL:hsql://localhost:8080", "sa", "");
            Statement stmt = con.createStatement();
            
            stmt.executeUpdate("CREATE TABLE FUNCIONARIOS (ID INT, NOME VARCHAR(50), IDADE INT, DEPARTAMENTO VARCHAR(50))");
            
            System.out.println("Nova tabela criada!");
            
            stmt.close();
            con.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}