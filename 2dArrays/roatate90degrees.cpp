#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<vector<int>> matrix){
    int row = matrix.size();
    int col = matrix[0].size();

    for(int j=0;j<col;j++){
        for(int i=row-1;i>=0;i--){
            cout<<" "<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
    for(int row=0; row<3; row++) {
        for(int col=0; col<3; col++) {
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << endl;
    cout << endl;

    rotate(matrix);    
    return 0;
}