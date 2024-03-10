class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int a = 0; a < nums.size(); a++) {
            for (int j = a + 1; j < nums.size(); j++) {
                if (nums[a] + nums[j] == target) {
                    return {a, j};
                }
            }
        }
       
        return {}; 
    }
};
