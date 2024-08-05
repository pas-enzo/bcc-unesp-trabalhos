import java.sql.*;

public class Insere {
    public static void main(String[] args) {
        try {
            Class.forName("org.hsql.jdbcDriver");
            Connection con = DriverManager.getConnection("jdbc:HypersonicSQL:hsql://localhost:8080", "sa", "");
            Statement stmt = con.createStatement();
            
            stmt.executeUpdate("INSERT INTO FUNCIONARIOS VALUES (375150, 'Joao Duo', 24, 'Medico')");
            System.out.println("Linha adicionada com sucesso!");
            
            stmt.executeUpdate("INSERT INTO FUNCIONARIOS VALUES (375151, 'Andre Pier Guidi', 21, 'Motorista')");
            System.out.println("Linha adicionada com sucesso!");
            
            stmt.close();
            con.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}