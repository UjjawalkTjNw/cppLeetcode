class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n = accounts.size();
        cout << n << '\n';
        int max = 0;
        for(int i = 0 ; i <n ;i++){
            int m = accounts[i].size();
            cout << m << '\n';
            int count = 0 ; //reset count in each iteration
            for(int j = 0 ; j<m ;j++){
                int x = accounts[i][j];
                cout<<  x << '\n';
                count+=x;  
            }
            cout << count << '\n';
            if(count > max){
                max = count;
            }
            
        }
        return max;
    }
};
