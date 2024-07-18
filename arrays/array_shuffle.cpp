class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>v;
        vector<int>v1;
        vector<int>v2;
        for(int i =0 ; i<n ; i++){
            v1.push_back(nums[i]);  //[2,5,1]
        }
        for(int i = n; i<2*n ; i++){
            v2.push_back(nums[i]); //[3,4,7]
        }
        for(int i =0 ;i<n ; i++){
            v.push_back(v1[i]); //[2,3,5,4,1]
            v.push_back(v2[i]);//[2,3,5,4,1,7]
        }
         return v;
    }
};
