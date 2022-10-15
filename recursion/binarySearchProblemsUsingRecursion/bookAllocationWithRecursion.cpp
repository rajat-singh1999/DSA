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

int allocateBooks(vector<int>& arr, int s, int e, int m, int ans){
    int mid=s+((e-s)/2);
    if(s>e)
        return ans;
    if(isPossible(arr, arr.size(), m, mid)){
        ans=mid;
        e=mid-1;
    }
    else
        s=mid+1;
    return allocateBooks(arr, s, e, m, ans);
}

int main(){
    vector<int> time = {23,11,13,40};
    int n=time.size();
    int sum=0;
    for(int i = 0; i<n; i++) {
        sum += time[i];
    }
    cout<<endl<<allocateBooks(time, 0, sum, 2, -1)<<endl;
    return 0;
}

/*
//codestudio: https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbmU4cnAyMUxVWGY5d2Y4bGdfSHRERnMtU0VsUXxBQ3Jtc0ttdHd5YXlEQWtaMExYNWExRGxkajd3U2QtTUtmRFBLX2hjdjZMYXM2RVJYczEyTHpSRFpjdGh6dDZubEVqaDZjUXVIc3FZX25MQXRyUzNyTUNLQmdsOTE2V1pMWkw1UTNmbGdvbnZmaTVwVjdveE5iUQ&q=https%3A%2F%2Fbit.ly%2F3GiCqY0&v=YTTdLgyqOLY

*/