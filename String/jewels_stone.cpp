class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;
        int n = jewels.size();
        int m = stones.size();
        char x;
        for(int i = 0 ; i < n ; i++){
            x = jewels[i];
            cout << x;
            for(int j = 0 ; j < m ; j++){
                if(stones[j] == x){
                    count = count+1;
                }

            }
            
        }
        return count;
    }
};