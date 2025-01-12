//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();
        //int t[n][target+1];
        vector<vector<bool>> t(n + 1, vector<bool>(target + 1, false));
        //Base condn
        for(int i = 0 ; i < n ; i++){
            t[i][0] = true;
        }
        for(int j = 1 ; j < target ; j ++){
            t[0][j] = false;
        }
        
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ;j <=target ; j++){
                if(arr[i-1] <=j){
                    t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j] ;
                    
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][target];
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends