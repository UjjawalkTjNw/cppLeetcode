

/*
eg:
Given the array: [1, 3, 2, 6, 3, 5, 6, 3, 4, 6]

The sub-arrays that begin with 3 and end with 6 are:

[3, 2, 6]

[3, 5, 6]

[3, 2, 6, 3, 5, 6] (overlapping)

[3, 4, 6] (from the second occurrence of 3)

[3, 2, 6, 3, 4, 6] (overlapping)

[3, 5, 6, 3, 4, 6] (overlapping)

*/



#include <iostream>
#include <vector>
using namespace std;

int countSubarrays(vector<int>& nums) {
    int count = 0;

    // Iterate through the array to find the starting point (3)
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 3) {
            // For each start point (3), find an endpoint (6)
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] == 6) {
                    count++;
                }
            }
        }
    }
    
    return count;
}

int main() {
    vector<int> nums = {1, 3, 2, 6, 3, 5, 6, 3, 4, 6};
    int result = countSubarrays(nums);
    cout << "Number of sub-arrays that begin with 3 and end with 6: " << result << endl;
    return 0;
}
