/*************************************************

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.

Example:

Input: "cbbd"

Output: "bb"

**************************************************/

class Solution {
public:
	string longestPalindrome(string s) {
		string result;
		string stack = s;
		string buf;
		result += s[0];
		if (s.size() <= 2)
			return s;
		int max = 1;
		int len = 0;
		for (int i = 0; i < s.size(); i++) {
			while ( i + (len + 1) < stack.size() && i - len >= 0 && stack[i - len] == s[i + (len + 1)]) {
				len++;
			}
			buf = stack.substr(i - (len - 1), 2 * len);
			len = 0;
			//
			while ( i - len >=0 && (i + (len + 2)) <= stack.size() && stack[i - len] == s[i + (len + 2)]) {
				len++;
			}
			if (len > 0 && (2 * len + 1) > buf.size())
				buf = stack.substr(i - (len - 1), (2 * len)+1);
			len = 0;
				
			if (buf.size() > max) {
				result = buf;
				max = buf.size();
			}
			if (max / 2 >= stack.size() - i - 1)
				break;
		}
		return result;
	}
};