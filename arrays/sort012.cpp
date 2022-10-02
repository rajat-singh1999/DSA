#include <bits/stdc++.h>
using namespace std;

void sort012(int *a, int n)
{
    int lo = 0;
    int hi = n - 1;
    int mid = 0;
 
    // Iterate till all the elements
    // are sorted
    while (mid <= hi) {
        switch (a[mid]) {
 
        // If the element is 0
        case 0:
            swap(a[lo++], a[mid++]);
            break;
 
        // If the element is 1 .
        case 1:
            mid++;
            break;
 
        // If the element is 2
        case 2:
            swap(a[mid], a[hi--]);
            break;
        }
    }
     for (int i = 0; i < n; i++)
         cout << a[i] << " ";
}

int main(){
    int arr[] = {2,1,2,2,0,1,1,1,0,2,0,0,0,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort012(arr,n);
    return 0;
}
