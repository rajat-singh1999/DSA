#include <bits/stdc++.h> 
using namespace std;

void interLeaveQueue(queue < int > & q) {
    // Write your code here.
    stack<int> s;
    int n = q.size();
    for(int i = 0; i<(n/2) ; i++){
        int temp = q.front();
        q.pop();
        s.push(temp);
    }

    while(!s.empty()){
        int temp = s.top();
        s.pop();
        q.push(temp);
    }

    for(int i = 0; i<(n/2) ; i++){
        int temp = q.front();
        q.pop();
        q.push(temp);
    }

    for(int i = 0; i<(n/2) ; i++){
        int temp = q.front();
        q.pop();
        s.push(temp);
    }

    while(!s.empty()){
        int a = s.top();
        int b = q.front();
        q.pop();
        s.pop();
        q.push(a);
        q.push(b);
    }

}