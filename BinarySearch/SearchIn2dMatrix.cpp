class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int n = matrix.size(); //row count
        int m = matrix[0].size(); // column count

        int low = 0;
        int high = n -1 ;
        int row = -1;


        while (low <= high){
            int mid  = (low + high)/2;
            //middle row first element is target
            if(target == matrix[mid][0]){
                return true;
            }
            if(target > matrix[mid][0]){
                row = mid;
                low = mid + 1;

            }
            else{
                high = mid - 1;
            }

           
        }
        if(row == -1) // signifies no such row with target is found
        {
            return false;
        }
        return searchMatrix(matrix[row].begin(), matrix[row].end(), target);  //doubt here
       
    }
};