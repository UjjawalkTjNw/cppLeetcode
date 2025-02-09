//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
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
  
    int countPartitions(vector<int>& arr, int d) {
        int sumArray = 0;
        for(int i = 0 ; i < arr.size(); i++){
            sumArray += arr[i];
        }
         // Check if partition is possible with the given difference
        if((sumArray + d) % 2 != 0 || sumArray < d) {
            return 0; // Impossible to partition with given difference.
        }
        
        int S1 = (d + sumArray)/2;
        return countSubsetSum(arr, S1);
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
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
  
    int countPartitions(vector<int>& arr, int d) {
        int sumArray = 0;
        for(int i = 0 ; i < arr.size(); i++){
            sumArray += arr[i];
        }
         // Check if partition is possible with the given difference
        if((sumArray + d) % 2 != 0 || sumArray < d) {
            return 0; // Impossible to partition with given difference.
        }
        
        int S1 = (d + sumArray)/2;
        return countSubsetSum(arr, S1);
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends