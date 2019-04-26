class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string res = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            for(int j = 0; j < res.length(); j++) {
                if (res[j] != strs[i][j]) {
                    if (j == 0) {
                        return "";
                    } else {
                        res.erase(j, res.length());
                    }
                    break;
                }
            }
        }
        return res;
    }
};