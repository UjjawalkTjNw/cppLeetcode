/*class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                if(nums[i] + nums[j] == target ){
                    v.push_back(i);
                    v.push_back(j);
                }
            }
        }
        return v;
        
    }
};*/


//Above soln is in O(n^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //create a map
        //check if target - nums[i] exists in map
        //eg: 7 - 3 = 4 exists, 7-4 = 3 exists, 7-5 = 2 
        
        unordered_map<int, int> umap;

        for(int i = 0 ; i < nums.size() ; i++){
            int diff = target - nums[i];
            if(umap.find(diff) != umap.end()){
                return {umap[diff] , i};
            }

            umap[nums[i]] = i;




        }
        return {};

    }

};

