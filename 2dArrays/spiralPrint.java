import java.util.ArrayList;

public class spiralPrint {

    public static ArrayList<Integer> solve(int[][] m, int r, int c){
        ArrayList<Integer> res = new ArrayList<>();

        int left=0,right=c-1,bottom=r-1, top=0;
        while(res.size() != r*c){
            for(int i=left;i<=right;i++){
                res.add(m[top][i]);
            }
            top++;
            for(int i=top;i<=bottom;i++){
                res.add(m[i][right]);
            }
            right--;
            
            for(int i=right;i>=left;i--){
                res.add(m[bottom][i]);
            }
            bottom--;

            for(int i=bottom;i>=top;i--){
                res.add(m[i][left]);
            }
            left++;
        }
        return res;
    }
    public static void main(String args[]){
        int[][] matrix ={
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15,16},
        };
        int[][] m2 = {
            { 1,  2,  3,  4,  5,  6},
            { 7,  8,  9, 10, 11, 12},
            {13, 14, 15, 16, 17, 18},
            {19, 20, 21, 22, 23, 24},
            {25, 26, 27, 28, 29, 30},
            {31, 32, 33, 34, 35, 36}
        };
        int row=4;
        int col=4;

        ArrayList<Integer> arr = new ArrayList<>();

        arr = solve(matrix,row,col);
        System.out.println(arr);
        arr = solve(m2,6,6);
        System.out.println(arr);
    }
}
