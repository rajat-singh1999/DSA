import java.util.Vector;
import java.util.Collections;

public class LongestIncreasingSubsequence {
    public static void main(String args[]){
        
        int[] arr = {-1,1,3,5,6,7,9,11,12};
        // -1 1 2 3 4 6 7 8
        Vector<Integer> v = new Vector<>();
        for(int i:arr){
            v.add(i);
        }

        Collections.sort(v);
        System.out.println(v);
        int c = 0;
        int res = 0;
        for(int i=0;i<v.size()-1;i++){
            if(v.get(i) == v.get(i+1)-1){
                c++;
                if(c>res){
                    res = c;
                }
            }
            else{
                
                c = 0;
            }
        }
        System.out.println(res+1);
    }
}
