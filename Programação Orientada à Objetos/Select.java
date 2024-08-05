import java.sql.*;

class Select {
    public static void main(String[] args) {
        try {
            Class.forName("org.hsql.jdbcDriver");
            Connection con = DriverManager.getConnection("jdbc:HypersonicSQL:hsql://localhost:8080", "sa", "");
            Statement stmt = con.createStatement();
            
            ResultSet rs = stmt.executeQuery("SELECT * FROM FUNCIONARIOS");
            
            while (rs.next()) {
                int id = rs.getInt("ID");
                String nome = rs.getString("NOME");
                int idade = rs.getInt("IDADE");
                String departamento = rs.getString("DEPARTAMENTO");
                
                System.out.println("ID: " + id);
                System.out.println("Nome: " + nome);
                System.out.println("Idade: " + idade);
                System.out.println("Departamento: " + departamento);
                System.out.println();
            }
            
            stmt.close();
            con.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}