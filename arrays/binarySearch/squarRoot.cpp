#include<bits/stdc++.h>
using namespace std;

long long int sqrtInteger(int n){
    int s=0,e=n;
    long long int mid = s+((e-s)/2), ans = -1;

    while(s<=e){
        long long int square = mid*mid;
        if(square == n)
            return mid;
        
        if(square<n){
            ans = mid;
            s=mid+1;
        }
        else
            e=mid-1;
        
        mid = s+((e-s)/2);
    }
    return ans;
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
    int tempSol = sqrtInteger(n);
    double ans = precision(n, 4, tempSol);
    cout<<"The square root of "<<n<<" is "<<ans<<"."<<endl;
    return 0;
}