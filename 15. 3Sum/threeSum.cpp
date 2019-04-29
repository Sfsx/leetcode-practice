class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> solution;
        vector<int> positive;
        vector<int> minus;
        vector<int> zero;
        int result;
        int p = 0;
        int m = 0;
        int z = 0;
        for (int n = 0; n < nums.size(); n++)
        {
            if (nums[n] > 0)
            {
                positive.push_back(nums[n]);
            }
            else if (nums[n] < 0)
            {
                minus.push_back(nums[n]);
            }
            else
            {
                zero.push_back(nums[n]);
            }
        }
        sort(positive.begin(), positive.end());
        sort(minus.begin(), minus.end());
        if (positive.size() == 0 || minus.size() == 0)
            return res;
        for (p = 0; p < positive.size(); p++) {
            if (positive[p] + minus[minus.size() - 1] > 0) break;
            for (m = 0; m < minus.size(); m++) {
                if (minus[m] + positive[p] < 0) break;
                for (z = m + 1; z < minus.size(); z++) {
                    result = positive[p] + minus[m] + minus[z];
                    if (result == 0) {
                        solution.push_back(positive[p]);
                        solution.push_back(minus[m]);
                        solution.push_back(minus[z]);
                        res.push_back(solution);
                        solution.clear()
                    }
                    else if (result < 0) {
                        break;
                    }
                }
            }
        }
        for (p = 0; p < positive.size(); p++) {
            if (positive[p] + minus[minus.size() - 1] > 0) break;
            for (m = 0; m < minus.size(); m++) {
                if (minus[m] + positive[p] < 0) break;
                for (z = m + 1; z < minus.size(); z++) {
                    result = positive[p] + minus[m] + minus[z];
                    if (result == 0) {
                        solution.push_back(positive[p]);
                        solution.push_back(minus[m]);
                        solution.push_back(minus[z]);
                        res.push_back(solution);
                        solution.clear()
                    }
                    else if (result < 0) {
                        break;
                    }
                }
            }
        }
    }
};