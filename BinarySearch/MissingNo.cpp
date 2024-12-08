/*
Problem description:
Array given: [3,0,1]
so n = 3 here hence all number in range [0, 3] should be present
Hence , missing no is 2


Array Given: [0,1]
so n = 2 here hence all number in range [0, 2] should be present
Hence, Missing no is 2



*/



#include <iostream>
#include <algorithm>
#include <vector>

int findMissingNumber(std::vector<int>& nums) {
    int n = nums.size();
    std::sort(nums.begin(), nums.end()); // Step 1: Sort the array 
    //TC Of sorting is O(nlogn)

    int left = 0, right = n;

    while (left < right) { // Step 2: Apply binary search : TC is O(logn)
        int mid = left + (right - left) / 2;
        if (nums[mid] > mid) {
            right = mid; // The missing number is in the left half (right ke left mein)
        } else {
            left = mid + 1; // The missing number is in the right half (left ke right mein)
        }
    }

    return left; // `left` will be the missing number
}

int main() {
    std::vector<int> nums = {3, 0, 1}; // Example array
    std::cout << "Missing number: " << findMissingNumber(nums) << std::endl;
    return 0;
}


//TOTAL TC: TC of sorting + TC of BS = O(nlogn) + O(logn) = O(nlogn)