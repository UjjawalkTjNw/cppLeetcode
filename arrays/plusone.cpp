
#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    
    // Traverse the digits from the end to the beginning
    for (int i = n - 1; i >= 0; --i) {
        if (digits[i] < 9) {
            digits[i]++;
            return digits;
        }
        digits[i] = 0;
    }
    
    // If we are here, it means all the digits were 9
    digits.insert(digits.begin(), 1);
    return digits;
}

int main() {
    vector<int> digits = {9, 9, 9};
    vector<int> result = plusOne(digits);
    
    cout << "Result: ";
    for (int digit : result) {
        cout << digit << " ";
    }
    cout << endl;
    
    return 0;
}

/*
ex1: [9,9,9]
------------------------
1. for  i =2
    since digit[i] == 9
   digit = [9 , 9 , 0]

2. for i = 1
    since digit[i] == 9
    digit = [9, 0 , 0]

3. for i = 0
    since digit[i] == 9
     digit = [0,0,0]

now for loop ends and we insert one to digits, so it become: [1,0,0,0] 



ex2: [1,2,3,9]
----------------------------
for i = 3
since digit[i] = 9 
digit = [1,2,3,0]

for i = 2
since digit[i] = 3 !=9 
so digit[i]++ 
digit = [1,2,4,0]

*/


