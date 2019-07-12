class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string cur = "";
        sub(n, cur, result, 0, 0);
        return result;
    }

    void sub(int n, string cur, vector<string>& result, int open, int close) {
        if (cur.length() == n * 2) {
            result.push_back(cur);
            return;
        }

        if (open < n) {
            sub(n, cur + "(", result, open+1, close);
        }

        if (close < open) {
            sub(n, cur + ")", result, open, close+1);
        }
    }
};