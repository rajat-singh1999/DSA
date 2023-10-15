import java.util.ArrayList;

public class BoundaryPrint {
    public static void main(String args[]){
        int[][] matrix ={
                        {1, 2, 3, 4},
                        {5, 6, 7, 8},
                        {9, 10, 11, 12},
                        {13, 14, 15,16},
                    };
        int row=4;
        int col=4;
        System.out.println(matrix[1][3]); 
        ArrayList<Integer> arr = new ArrayList<>();
        int s=0;
        int e = col;
        for(int i=s;i<e;i++){
            arr.add(matrix[0][i]);
        }
        s++;
        e = row;
        for(int i=s;i<e;i++){
            arr.add(matrix[i][col-1]);
        }
        s = col-2;
        e = 0;
        for(int i=s;i>=e;i--){
            arr.add(matrix[row-1][i]);
        }
        s = row-2;
        e = 1;
        for(int i=s;i>=e;i--){
            arr.add(matrix[i][0]);
        }

        System.out.println(arr);
    }
}
