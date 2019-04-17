// Input:"aaa" "ab*a*c*a"
// Output:false
// Expected:true
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        return backtracking(s, m, p, n);
    }
    
    bool backtracking(string& s, int i, string& p, int j) {
        if (j == 0 && i == 0) return true;
        if (j == 0 && i != 0) return false;
        if (j != 0 && i == 0) {
            if (p[j - 1] == '*') return backtracking(s, i, p, j - 2);
            return false;
        }
        if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
            return backtracking(s, i - 1, p, j - 1);
        } else if (p[j - 1] == '*') {
            if (backtracking(s, i, p, j - 2)) return true;
            if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                return backtracking(s, i - 1, p, j);
            }
            return false;
        }
        return false;
    }
};