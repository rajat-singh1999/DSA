#include<iostream>
using namespace std;

int squareRoot(int n, int s, int e){
    int mid=s+((e-s)/2);

    if(s>e)
        return 0;
    else if(mid*mid==n)
        return mid;
    else if(mid*mid<n)
        s=mid+1;
    else
        e=mid-1;
    return squareRoot(n, s, e);
}

double precision(int n, int preci, int tempSol){
    double ans=tempSol, factor = 1;

    for(int i = 0; i<preci;i++){
        factor = factor/10;
        for(double j=ans;j*j<n;j=j+factor)
            ans=j;
    }
    
    return ans;
}

int main(){
    int n = 377;
    int tempSol = squareRoot(n, 0, n-1);
    double ans = precision(n, 4, tempSol);
    cout<<"The square root of "<<n<<" is "<<ans<<"."<<endl;
    return 0;
}