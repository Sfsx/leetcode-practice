class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> results;
        sort(nums.begin(), nums.end());
        for (int i = 0, n = nums.size(); i < n - 3; i++) {
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            if (nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) continue;

            for (int j = nums.size() - 1; i < j && j - 2 > 0; j--) {
                int partsum = nums[i] + nums[j];
                int front = i + 1;
                int back = j - 1;
                if (partsum + nums[j - 1] + nums[j - 2] < target) break;
                if (partsum + nums[i + 2] + nums[i + 1] > target) continue;

                while(front < back){
                    int sum = nums[front] + nums[back] + partsum;

                    if (sum < target) { front++; continue; }
                    if (sum > target) { back--; continue; }

                    results.push_back({nums[i], nums[front], nums[back], nums[j]});

                    while (front + 1 < nums.size() && nums[front] == nums[front + 1]) front++;
                    while (back - 1 >= 0 && nums[back] == nums[back - 1]) back--;

                    front++;
                }
                while(j - 1 > i && nums[j - 1] == nums[j]) j--;
            }
            while(i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
        }
        return results;
    }
};