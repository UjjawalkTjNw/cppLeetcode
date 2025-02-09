//Now code works for all cases 


int findWays(vector<int>& arr, int k)
{
	//problem is same as subset sum ; only we  have to return count of subsets that has sum
        //if false; no such subset return 0
        //if true; has such subsets return count

        //Base condn
        int n = arr.size();
        vector<vector<int>> t(n + 1, vector<int>(k + 1, 0));
  
        for(int j =1 ; j <=k ; j++){
            t[0][j] = 0;
        }


        for(int i = 0 ; i <=n ; i++){
            t[i][0] = 1 ;
        }
        
        //after initialization fill other grids
        for(int i = 1; i <=n ; i++){
            for(int j = 0 ; j<=k ; j++){   // started with zero, because consider a case with sum =0 then in that case how it is possible to start from 1 becaus we will only be having 1 column
                if(arr[i-1] <=j){  //when element is less than target include
                    t[i][j] = (t[i-1][j-arr[i-1]] + t[i-1][j]) % 1000000007; //inlude + not include
                    //because each subset we make has options if it gives sum equal to target or not
                    //1000000007 is a widely used prime number in competitive programming and algorithm contests., so we take modulo with this, this prevents failure in case of large arrays
                    // if we donot take modulo with this then in large array cases the code fails
                }
                else{  //when element id more than target; eg: element is 12 and target is 10
                //exclude it
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][k];
        
    
}

//solved in takeUforward, coding ninjas
