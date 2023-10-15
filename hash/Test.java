package hash;
import java.util.*;

public class Test {
    public static String swap_cus(String s, int l, int i){
        char[] cc = s.toCharArray();
        char temp = cc[l];
        cc[l] = cc[i];
        cc[i] = temp;
        return new String(cc);
    }

    public static void solve(String str, int l, int r){
        if(l == r)
            System.out.println(str);
        else{
            for(int i=l;i<=r;i++){
                str = swap_cus(str, l,i);
                solve(str,l+1,r);
                str = swap_cus(str, l,i);
            }
        }
    }
    public static void main(String args[]){
        int[] arr = new int[26];

        String inp = "Raj";
        solve(inp,0,inp.length()-1);
        inp = inp.toLowerCase();
        for(int i=0;i<inp.length();i++){
            char ch = inp.charAt(i);
            if (ch >= 'a' && ch <= 'z') {
                arr[ch - 'a']++;
            }
        }

        for(int i=0;i<26;i++){
            char ch = (char) (i + 'a');
            if(arr[i] != 0)
                System.out.println(ch+": "+arr[i]);
        }
    }
}
