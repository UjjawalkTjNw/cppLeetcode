class Solution {
public:
    /* //Recursion
        int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        return fib(n-1) + fib(n-2);
        
    }*/

    
    //Using memoization[dp]
    int fib(int n) {
        int memo[n+1];
        memset(memo , -1, sizeof(memo));
        if(n == 0) return 0;
        if(n == 1) return 1;
        //check if it exists in memo or not
        if(memo[n]!=-1){
            return memo[n];
        }
        memo[n] = fib(n-1) + fib(n-2);
        return memo[n];
        
    }

};