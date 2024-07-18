class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>v;
        int n = nums.size();
        for(int i = 0 ; i<2 ; i++){
            for(int j = 0 ; j <n ; j++){
                v.push_back(nums[j]);
               
            }
        }
        return v;

        
    }
};