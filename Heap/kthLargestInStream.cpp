//concept is same as kth largest in array using min heap

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>>pq;
    int globalK;
    KthLargest(int k, vector<int>& nums) {
        globalK  = k;
        for(auto x:nums){
            if(pq.size() < k){
               pq.push(x);
            }
            else if(pq.size() == k && x >= pq.top()){
                pq.push(x);
            }
            if(pq.size() > k){
                pq.pop();
            }
        }
        }
        
    
    
    int add(int val) {
        if(pq.size() < globalK){
            pq.push(val);
        }
        else if(pq.size() == globalK && val >= pq.top()){
            pq.push(val);
        }
        if(pq.size() > globalK){
            pq.pop();
        }

        return pq.top();
        

        
    }
};
