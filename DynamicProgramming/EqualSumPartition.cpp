class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();
        
        vector<vector<bool>> t(n + 1, vector<bool>(target + 1, false));
        //Base condn
        for(int i = 0 ; i < n ; i++){
            t[i][0] = true;
        }
        for(int j = 1 ; j < target ; j ++){
            t[0][j] = false;
        }
        
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ;j <=target ; j++){
                if(arr[i-1] <=j){
                    t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j] ;
                    
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][target];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0 ; i <n ; i++){
            sum += nums[i];
        }
        if(sum%2 != 0){ //There is no one we can have equal sum subsets
            return false;
        }
        //control here means sum is even
        //Half the sum and check if there exists subset in nums satisfying sum/2
        //It become subset sum now
        return isSubsetSum(nums, sum/2);

        

        
    }
};