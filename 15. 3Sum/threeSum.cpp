class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> results;
        sort(nums.begin, nums.end);

        for(int i = 0; i < nums.length(); i++) {
            int front = i + 1;
            int back = nums.size() - 1;
            int target = -nums[i];

            if(target < 0) {
                break;
            }

            while(front < back){
                int sum = nums[front] + nums[back];

                if (sum < target) { front++; continue; }
                if (sum > target) { back--; continue; }

                results.push_back({nums[i], nums[front], nums[back]});
                auto& result = results[results.size() - 1];

                while (front + 1 < nums.szie() - 1 && result[1] == nums[front + 1]) front++;
                while (back - 1 > 0 && result[2] == nums[back - 1]) back--;
            }
            
            while(i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
        }
    }
};