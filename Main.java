import java.io.IOException;
import java.util.*;

public class Main {
 
    public static void main(String[] args) throws IOException {
        Scanner tecl = new Scanner(System.in);
        Map<String, Character> decodifica = new TreeMap<String, Character>();
        
        decodifica.put(".",'a');
        decodifica.put("..",'b');
        decodifica.put("...",'c');
        decodifica.put(". .",'d');
        decodifica.put(".. ..",'e');
        decodifica.put("... ...",'f');
        decodifica.put(". . .",'g');
        decodifica.put(".. .. ..",'h');
        decodifica.put("... ... ...",'i');
        decodifica.put(". . . .",'j');
        decodifica.put(".. .. .. ..",'k');
        decodifica.put("... ... ... ...",'l');
        decodifica.put(". . . . .",'m');
        decodifica.put(".. .. .. .. ..",'n');
        decodifica.put("... ... ... ... ...",'o');
        decodifica.put(". . . . . .",'p');
        decodifica.put(".. .. .. .. .. ..",'q');
        decodifica.put("... ... ... ... ... ...",'r');
        decodifica.put(". . . . . . .",'s');
        decodifica.put(".. .. .. .. .. .. ..",'t');
        decodifica.put("... ... ... ... ... ... ...",'u');
        decodifica.put(". . . . . . . .",'v');
        decodifica.put(".. .. .. .. .. .. .. ..",'w');
        decodifica.put("... ... ... ... ... ... ... ...",'x');
        decodifica.put(". . . . . . . . .",'y');
        decodifica.put(".. .. .. .. .. .. .. .. ..",'z');

        while (tecl.hasNextLine()){
            int n = tecl.nextInt();
            tecl.nextLine();

            for (int i=0; i<n; i++) {
                String linha = tecl.nextLine();

                System.out.println(decodifica.get(linha));
            }
        }
    
    }
 
}