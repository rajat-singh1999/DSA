#include<iostream>
using namespace std;
long long int power(long long int a, long long int b) {
    //base case
    if( b == 0 )
        return 1;

    if(b == 1)
        return a;

    //RECURSIVE CALL
    long long int ans = power(a, b/2);

    //if b is even
    if(b%2 == 0) {
        return ans * ans;
    }
    else {
        //if b is odd
        return a * ans * ans;
    }
}

int main(){
    long long int n, m;
    cout<<"give value of n: ";
    cin>>n;
    cout<<"give value of m: ";
    cin>>m;
    long long int ans = power(n,m);
    cout<<endl<<ans<<endl;
    return 0;
}