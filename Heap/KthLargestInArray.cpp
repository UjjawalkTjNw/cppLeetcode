class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /* way 1:
        //Sorting works but it takes O(nlogn)
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return  nums[n-k];
        */
        
        
        //way2: max heap
        /*priority_queue<int>pq(nums.begin(), nums.end());
        int ans = 0;
        while(k--){
            //k = 3 2 1 0 
            ans = pq.top(); 
            pq.pop();
        }
        return ans;
        */

        //way3: min heap

        priority_queue<int, vector<int>, greater<int>>pq;
        for(auto x: nums){
            pq.push(x);
            if(pq.size() > k){ //This will maintain min heap of size 2
                pq.pop(); //
            }

        }
        //at the end we will have final two elements with top being ans
        return pq.top();







         //Using set it will fail in cases like array looking like [1]
        /*set<int>s;
        int result;
        int n = nums.size();
        for(int i = 0 ; i< n-1 ; i++){
            s.insert(nums[i]);

        }

        auto it = s.end();
        advance(it, -2); // Move iterator to the second-to-last element
        result = *it;
        return result;
        */
    }
};