#include<iostream>
using namespace std;

string sayDigits(int n, string arr[]){
    if(n==0)
        return "";
    
    return (sayDigits((n/10), arr) +" "+ arr[n%10]);
}

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    string arr[]={"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    string ans = sayDigits(n, arr);
    cout<<endl<<ans<<endl;
    return 0;
}