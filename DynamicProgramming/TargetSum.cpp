/*  Problem Statement
Given an array of integers A[] of length N and an integer target.
You want to build an expression out of A by adding one of the symbols '+' and '-' before each integer in A and then concatenate all the integers.

For example, if arr = {2, 1}, you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that can be built, which evaluates to target and return your answer with modulo 109+7.


Example 1:

Input:
N = 5
A[] = {1, 1, 1, 1, 1}
target = 3
Output:
5
Explanation:
There are 5 ways to assign symbols to 
make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

Example 2:

Input:
N = 1
A[] = {1}
target = 1
Output:
1

*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
  
    int countSubsetSum(vector<int>& arr, int k){
        //Base condn [initialization]
        int n = arr.size();
        vector<vector<int>> t(n+1, vector<int>(k+1, 0));
        
//Mistake mad by me was in initialisation of matrix
        for(int j = 0; j<=k ; j++){
            t[0][j] = 0;
        }
        
        
        for(int i = 0 ; i <=n ; i++){
            t[i][0] = 1;
        }
        
        
        
        //fill remaining grids starting from 1,1
        for(int i = 1 ; i<=n ; i++){
            for(int j = 0 ; j<=k ; j++){ //this will handle when sum is zero
                if(arr[i-1] <=j){
                    t[i][j] = (t[i-1][j-arr[i-1]] + t[i-1][j]) % 1000000007  ;// This will handle large arrays 
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][k];
    }
    long long findTargetSumWays(int n, vector<int>& A, int target) {
        
        // take an exmple of array 1 1 2 3 where required sum is 1
        // +1 -1 -2 +3 , -1 + 1 -2 +3 , 1+1+2-3  therefore three ways
        //take for eg: +1 -1 -2 +3  ==== (3+1) - (1+2) = 1
        //so this problem is count of subset sum with given difference
        
        int sumArray = 0;
        for(int i = 0 ; i <n; i++){
            sumArray += A[i];
        }
         // Check if partition is possible with the given difference
        if((sumArray + target) < 0 || (sumArray + target) % 2 != 0 || sumArray < target) {     // sumArray + target <0 will handle if this goes negative because S1 calculation relies on that
            return 0; // Impossible to partition with given difference.
        }
        
        int S1 = (target + sumArray)/2;
        return countSubsetSum(A, S1);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin >> N;
        vector<int> arr(N);

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout << ob.findTargetSumWays(N, arr, target);
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends