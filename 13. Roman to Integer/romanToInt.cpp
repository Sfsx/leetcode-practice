class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        int index = 0;
        int prew = 0;
        map<char, int> roman;
        map<char, int>::iterator iter; 
        roman.insert(pair<char, int>('I', 1));
        roman.insert(pair<char, int>('V', 5)); 
        roman.insert(pair<char, int>('X', 10)); 
        roman.insert(pair<char, int>('L', 50)); 
        roman.insert(pair<char, int>('C', 100)); 
        roman.insert(pair<char, int>('D', 500)); 
        roman.insert(pair<char, int>('M', 1000));
        iter = roman.find(s[0]);
        index = iter->second;
        for(int i = 1; i < s.length();i++) {
            prew = index;
            iter = roman.find(s[i]);
            index = iter->second;
            if (prew >= index) {
                res = res + prew;
            } else {
                res = res - prew;
            }
        }
        return res + index;
    }
};