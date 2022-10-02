#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> arr, int n, int m, int mid) {
    int studentCount = 1;
    int pageSum = 0;
    //cout << "checking for mid "<< mid <<endl;
    
    for(int i = 0; i<n; i++) {
        if(pageSum + arr[i] <= mid) {
            pageSum += arr[i];
        }
        else
        {
            studentCount++;
            if(studentCount > m || arr[i] > mid ) {
            return false;
        }
            pageSum = arr[i];
        }
        if(studentCount > m) {
            return false;
        }
        //cout << " for i " << i << " Student "<< studentCount << " pageSum " << pageSum << endl;
    }
    return true;
}

int allocateBooks(vector<int> arr, int n, int m) {
    int s = 0;
    int sum = 0;
    
    for(int i = 0; i<n; i++) {
        sum += arr[i];
    }
    int e = sum;
    int ans = -1;
    int mid = s + (e-s)/2;
    
    while(s<=e)
    {
        if(isPossible(arr,n,m,mid)) {
            //cout<<" Mid returned TRUE" << endl;
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main(){
    vector<int> time = {23,11,13,40};
    cout<<endl<<allocateBooks(time, 4, 2)<<endl;
    return 0;
}

/*
//codestudio: https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbmU4cnAyMUxVWGY5d2Y4bGdfSHRERnMtU0VsUXxBQ3Jtc0ttdHd5YXlEQWtaMExYNWExRGxkajd3U2QtTUtmRFBLX2hjdjZMYXM2RVJYczEyTHpSRFpjdGh6dDZubEVqaDZjUXVIc3FZX25MQXRyUzNyTUNLQmdsOTE2V1pMWkw1UTNmbGdvbnZmaTVwVjdveE5iUQ&q=https%3A%2F%2Fbit.ly%2F3GiCqY0&v=YTTdLgyqOLY


#include <bits/stdc++.h>

bool isPossible(int n, int m, vector<int> time,unsigned long long int mid){
  unsigned long long int days=1;
  unsigned long long int timecount=0;
   for(int i=0;i<m;i++){
       if(time[i]+timecount<=mid){
           timecount+=time[i];
       }
       else{
           days++;
           if(days>n || time[i]>mid){
               return false;
           }
           timecount=time[i];
       }
   }
   return true;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{    
   // Write your code here.
   unsigned long long int start=0;
   unsigned long long int sum=0;
   for(int i=0;i<m;i++){
       sum+=time[i];
   }
   unsigned long long int end=sum;
   unsigned long long int ans=-1;
   unsigned long long int mid=start+(end-start)/2;
   while(start<=end){
       if(isPossible(n,m,time,mid)){
           ans=mid;
           end=mid-1;
       }
       else{
           start=mid+1;
       }
       mid=start+(end-start)/2;
   }
   return ans;
}
*/