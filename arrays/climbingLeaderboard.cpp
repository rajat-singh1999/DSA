/*
7
100 100 50 40 40 20 10 //ranked array
4
5 25 50 120 //player scores array

6
4
2
1


6
100 90 90 80 75 60
5
50 65 77 90 102

6
5
4
2
1
*/


/*
vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player){
    vector<int> ans;

    ranked.erase( unique( ranked.begin(), ranked.end() ), ranked.end() );

    int n = player.size();
    for(int i = 0; i < n; i++){
        int temp = player[i];
        
        while(temp >= ranked.back() && !ranked.empty()){
            ranked.pop_back();
        } 
        ans.push_back(ranked.size()+1);
    }
    return ans;
}
*/