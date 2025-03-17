class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);

        return res;
    }

    void backtrack(vector<int>& nums, int index) {
        if(index == nums.size()) {
            res.push_back(nums);
            return;
        }

        for(int i = index; i < nums.size(); i++){
            swap(nums[i] , nums[index]);
            backtrack(nums, index + 1);
            swap(nums[i] , nums[index]);
        }
    }

// Initial Call: backtrack({1, 2, 3}, idx = 0)

// Fix 1 at index 0

// Swap nums[0] with nums[0] → {1, 2, 3}
// Recursive call: backtrack({1, 2, 3}, idx = 1)
// Fix 2 at index 1

// Swap nums[1] with nums[1] → {1, 2, 3}
// Recursive call: backtrack({1, 2, 3}, idx = 2)
// Fix 3 at index 2

// Swap nums[2] with nums[2] → {1, 2, 3}
// Base Case: Store {1, 2, 3}
// Backtrack
// Swap nums[1] with nums[2]

// Swap {1, 2, 3} → {1, 3, 2}
// Recursive call: backtrack({1, 3, 2}, idx = 2)
// Fix 2 at index 2

// Swap nums[2] with nums[2] → {1, 3, 2}
// Base Case: Store {1, 3, 2}
// Backtrack
// Swap nums[0] with nums[1]

// Swap {1, 2, 3} → {2, 1, 3}
// Recursive call: backtrack({2, 1, 3}, idx = 1)
// Fix 1 at index 1

// Swap nums[1] with nums[1] → {2, 1, 3}
// Recursive call: backtrack({2, 1, 3}, idx = 2)
// Fix 3 at index 2

// Swap nums[2] with nums[2] → {2, 1, 3}
// Base Case: Store {2, 1, 3}
// Backtrack
// Swap nums[1] with nums[2]

// Swap {2, 1, 3} → {2, 3, 1}
// Recursive call: backtrack({2, 3, 1}, idx = 2)
// Fix 1 at index 2

// Swap nums[2] with nums[2] → {2, 3, 1}
// Base Case: Store {2, 3, 1}
// Backtrack
// Swap nums[0] with nums[2]

// Swap {1, 2, 3} → {3, 2, 1}
// Recursive call: backtrack({3, 2, 1}, idx = 1)
// Fix 2 at index 1

// Swap nums[1] with nums[1] → {3, 2, 1}
// Recursive call: backtrack({3, 2, 1}, idx = 2)
// Fix 1 at index 2

// Swap nums[2] with nums[2] → {3, 2, 1}
// Base Case: Store {3, 2, 1}
// Backtrack
// Swap nums[1] with nums[2]

// Swap {3, 2, 1} → {3, 1, 2}
// Recursive call: backtrack({3, 1, 2}, idx = 2)
// Fix 2 at index 2

// Swap nums[2] with nums[2] → {3, 1, 2}
// Base Case: Store {3, 1, 2}
// Backtrack
// Final Output:
// [[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,2,1], [3,1,2]]

    
};