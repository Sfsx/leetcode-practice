class Solution {
public:
    // 尽量不要嵌套 if，将嵌套 if 拉平能够提升速度
    bool isValid(string s) {
        stack<char> s1;
        s1.push('s');
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')' && s1.top() == '(') {
                s1.pop();
            } else if (s[i] == '}' && s1.top() == '{') {
                s1.pop();
            } else if (s[i] == ']' && s1.top() == '[') {
                s1.pop();
            } else {
                s1.push(s[i]);
            }
        }
        return s1.top() == 's';
    }
    bool isValid(string s) {
        stack<char> bs;
        bs.push('s'); // base for stack so that bs.top() doesn't return NULL
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' or s[i] == '{' or s[i] == '[') {
                bs.push(s[i]); // push every valid parenthesis
                continue;
            }
            if((s[i] == ')' and bs.top() == '(') or (s[i] == '}' and bs.top() == '{') or (s[i] == ']' and bs.top() == '[')) {
                bs.pop(); //pop every open parenthesis for matching closed one
            } else {
                bs.push(s[i]); // push non-matching closed parenthesis
            }
        }
        return bs.top() == 's'; // if all parenthesis matched correctly stack will contain only base
    }
};