import java.io.IOException;
import java.util.*;
 
public class Main {
 
    public static void main(String[] args) throws IOException {
 
        Scanner tecl = new Scanner(System.in);
        int n = tecl.nextInt();
        tecl.nextLine();

        for (int i=0; i<n; i++){

            String linha = tecl.nextLine();
            String pals[] = linha.split(" ");
            List<String> palavra = Arrays.asList(pals);

            Collections.sort(palavra, new Comp());

            Iterator m = palavra.iterator();

            while (m.hasNext()) {
                System.out.printf("%s", m.next());
                if (m.hasNext()) System.out.printf(" ");   
            }
            System.out.println();
        }
    }
}

class Comp implements Comparator {
    public int compare(Object o1, Object o2) {
        return ((String)o2).length() - ((String)o1).length();
    }
}