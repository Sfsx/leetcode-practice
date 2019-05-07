class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sum = INT_MAX / 2;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 1; i++) {
            int begin = i + 1;
            int end = nums.size() - 1;

            while(begin < end) {
                int curSum = nums[i] + nums[begin] + nums[end];
                
                if(curSum > target) { 
                    end--;
                    if (abs(curSum - target) < abs(sum - target)) { sum = curSum; }
                    continue;
                }
                if(curSum < target) {
                    begin++;
                    if (abs(curSum - target) < abs(sum - target)) { sum = curSum; }
                    continue;
                }
                
                sum = target;
                break;
            }
            if (sum == target) { break; }
        }
        return sum;
    }
};