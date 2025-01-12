/*Problem desc:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]

Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
*/

//BruteForceapproach:
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for (int i = 0; i < nums1.size(); ++i) {
            int nextGreater = -1;
            bool found = false;
            for (int j = 0; j < nums2.size(); ++j) {
                if (nums2[j] == nums1[i]) {
                    found = true;
                }
                if (found && nums2[j] > nums1[i]) {
                    nextGreater = nums2[j];
                    break;
                }
            }
            ans.push_back(nextGreater);
        }
        return ans;
        
    }
};


//optimal approach:

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreaterMap;
        stack<int> s;

        // Traverse nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; --i) {
            // Maintain elements in decreasing order in the stack
            while (!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }
            // If stack is not empty, the top element is the next greater element
            if (!s.empty()) {
                nextGreaterMap[nums2[i]] = s.top();
            } else {
                nextGreaterMap[nums2[i]] = -1;
            }
            // Push the current element onto the stack
            s.push(nums2[i]);
        }

        // Prepare the result for nums1 based on the nextGreaterMap
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(nextGreaterMap[num]);
        }

        return ans;
    }
};

/*Dry run of optimal approach


### Example
- `nums1 = [4, 1, 2]`
- `nums2 = [1, 3, 4, 2]`

1. **Initialization**:
   - `nextGreaterMap = {}`
   - `stack = []`

2. **Traverse `nums2` from right to left**:

   - **i = 3** (nums2[3] = 2):
     - Stack is empty, so no next greater element.
     - `nextGreaterMap[2] = -1`
     - Push 2 onto the stack: `stack = [2]`

   - **i = 2** (nums2[2] = 4):
     - Stack top (2) is less than 4, pop 2.
     - Stack is empty, so no next greater element.
     - `nextGreaterMap[4] = -1`
     - Push 4 onto the stack: `stack = [4]`

   - **i = 1** (nums2[1] = 3):
     - Stack top (4) is greater than 3.
     - `nextGreaterMap[3] = 4`
     - Push 3 onto the stack: `stack = [4, 3]`

   - **i = 0** (nums2[0] = 1):
     - Stack top (3) is greater than 1.
     - `nextGreaterMap[1] = 3`
     - Push 1 onto the stack: `stack = [4, 3, 1]`

3. **Resulting `nextGreaterMap`**:
   - `nextGreaterMap = {2: -1, 4: -1, 3: 4, 1: 3}`

4. **Prepare the result for `nums1`**:
   - For `nums1[0] = 4`: `nextGreaterMap[4] = -1`
   - For `nums1[1] = 1`: `nextGreaterMap[1] = 3`
   - For `nums1[2] = 2`: `nextGreaterMap[2] = -1`

5. **Final Result**:
   - `ans = [-1, 3, -1]`
*/