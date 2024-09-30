class Solution {
public:
    

    int uniqueNo =1;
    
    int removeDuplicates(vector<int>& nums) {
        //handle case when nums is empty
        if(nums.empty()){
            return 0 ;
        }
        
        for(int i = 0 ; i < nums.size() ; i++){
            cout <<"UniqueNo:" <<  uniqueNo << endl;
            int a = nums[i];
            cout <<"A: "<< a << endl;
            int b = nums[i+1];
            cout << "B: " << b << endl;

            if(a == b){
                continue;
            }
            uniqueNo+=1;
        }
        return uniqueNo;
        
    }
};
//why not accepting k