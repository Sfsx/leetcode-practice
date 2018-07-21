/*************************************************

Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

**************************************************/

class Solution {
public:
    bool isPalindrome(int x) {
		string a = std::to_string(x);
		int begin = 0;
		int end = a.size() - 1;
		while (begin < end) {
			if (a[begin] == a[end]) {
				begin++;
				end--;
			}
			else
				return false;
		}
		return true;
	}
};