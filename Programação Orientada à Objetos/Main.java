import java.io.IOException;
import java.util.*;

public class Main {
 
    public static void main(String[] args) throws IOException {
        Scanner tecl = new Scanner(System.in);
        TreeSet<String> treeSet = new TreeSet<>();

        int n = tecl.nextInt();
        tecl.nextLine();

        for (int i=0; i<n; i++) {
            String linha = tecl.nextLine();

            treeSet.add(linha);
        }

        int dif = 151 - treeSet.size();

        System.out.println("Falta(m) " + dif + " pomekon(s).");
    }
 
}