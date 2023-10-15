package hash;
import java.util.*;

public class CharacterFreq {

    public static void solve(String inputString){
        // Create a HashMap to store character counts
        Map<Character, Integer> charCountMap = new HashMap<>();
        
        // Convert the input string to lowercase to make it case-insensitive
        inputString = inputString.toLowerCase();
        
        // Iterate through each character in the string
        for (char c : inputString.toCharArray()) {
            charCountMap.put(c, charCountMap.getOrDefault(c, 0) + 1);
        }
        
        // Print the character counts
        int m = 0;
        char ch=' ';
        for (Map.Entry<Character, Integer> entry : charCountMap.entrySet()) {
            //System.out.println("Character: " + entry.getKey() + ", Count: " + entry.getValue());
            if(entry.getValue()>m){
                m=entry.getValue();
                ch = entry.getKey();
            }
        }
        System.out.println(ch+": "+m);
    }

    public static void main(String args[]){
        String inputString = "hhhagagshdhffkf#$%%%$**&&^uuushsbccbbcmjjee";
        
        solve(inputString);
        Map<Character,Integer> m = new HashMap<>();

        for(char c:inputString.toCharArray()){
            if(Character.isLetterOrDigit(c))
                m.put(c,m.getOrDefault(c,0)+1);
        }
        //System.out.println(m.entrySet());
        for(Map.Entry<Character, Integer> e:m.entrySet()){
            char key = e.getKey();
            int val = e.getValue();
            //System.out.println(key+": "+val);
        }
    }
}
