class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        int lenght = digits.size();
        if(lenght == 0) return res;
        vector<string> nums = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string cur = "";
        queue<string> q;
        q.push("");
        while(!q.empty()) {
          cur = q.front();
          q.pop();
          if(cur.size() < lenght) {
            // 巧妙的运用 字符数字 与 '0' 的差值作为向量nums的下标， 以及 c++ 11 的 auto 对向量的的 string 进行循环
            for( auto c : nums[digits[cur.size()]  - '0']) {
              // 隐式类型转换 将 char c 转换为 string 类型
              q.push(cur + c);
            }
          } else {
            res.push_back(cur);
          }
        }
        return res;
    }
};