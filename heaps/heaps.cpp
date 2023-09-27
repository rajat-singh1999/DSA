#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        size = size+1;
        int index = size;
        arr[index] = val;
        while(index > 1){
            int parent = index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void deletefromheap(){
        if(size == 0){
            cout<<"Nothing to delete...";
            return;
        }
        arr[1] = arr[size];
        size--;
        //take root node to its correct position
        int i=1;
        while(i<size){
            int leftindex = 2*i;
            int rightindex = (2*i)+1;

            if(leftindex<size && arr[i]<arr[leftindex]){
                swap(arr[i],arr[leftindex]);
                i=leftindex;
            }
            else if(rightindex<size && arr[i]<arr[rightindex]){
                swap(arr[i],arr[rightindex]);
                i=rightindex;
            }
            else{
                return;
            }
        }
    }


    void print(){
        for(int i=1;i<=size;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify_for_maxheap(int arr[], int n, int i){
    int largest = i;
    int left = 2*i;
    int right = (2*i)+1;

    if(left<=n && arr[largest]<arr[left]){
        largest = left;
    }
    if(right<=n && arr[largest]<arr[right]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify_for_maxheap(arr,n,largest);
    }
}

void heapify_for_minheap(int arr[], int n, int i){
    int smallest = i;
    int left = (2*i) + 1;
    int right = (2*i) + 2;

    if(left<=n && arr[smallest]>arr[left]){
        smallest = left;
    }
    if(right<=n && arr[smallest]>arr[right]){
        smallest = right;
    }
    if(smallest != i){
        swap(arr[smallest], arr[i]);
        heapify_for_minheap(arr,n,smallest);
    }
}

void heapSort(int arr[],int n){
    int size = n;
    while(size>1){
        swap(arr[size],arr[1]);
        size--;
        heapify_for_maxheap(arr,size,1);
    }
}

int main(){
/*
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deletefromheap();
    h.print();
*/

/*
    int arr[6] = {-1,54,53,55,52,50};
    int n = 5;
    for(int i = n/2; i>0; i--){
        heapify_for_maxheap(arr,n,i);
    }
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    heapSort(arr,n);
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
*/
/*
    for(int i = n/2-1; i>=0; i--){
        heapify_for_minheap(arr,n,i);
    }
    
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
*/
    //maxheap using priority queue
    cout<<endl;
    priority_queue<int> pq;
    pq.push(4);
    pq.push(2);
    pq.push(10);
    pq.push(8);
    cout<<"Element at top: "<<pq.top()<<endl;
    pq.pop();
    cout<<"Element at top: "<<pq.top()<<endl;
    cout<<"Size of pq is "<<pq.size()<<endl;
    if(pq.empty()){
        cout<<"PQ is empty."<<endl;
    }
    else
        cout<<"PQ is not empty."<<endl;

    //minheap using priority queue
    priority_queue<int,vector<int>,greater<int>> minheap;
    minheap.push(4);
    minheap.push(2);
    minheap.push(10);
    minheap.push(8);
    cout<<"Element at top: "<<minheap.top()<<endl;
    minheap.pop();
    cout<<"Element at top: "<<minheap.top()<<endl;
    cout<<"Size of pq is "<<minheap.size()<<endl;
    if(minheap.empty()){
        cout<<"minheap is empty."<<endl;
    }
    else
        cout<<"minheap is not empty."<<endl;
    
    return 0;
}