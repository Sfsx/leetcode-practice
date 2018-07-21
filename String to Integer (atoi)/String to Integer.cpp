/*************************************************

Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

**************************************************/


class Solution {
public:
    int myAtoi(string str) {
		int64_t result = 0;
		int i = 0;
		int j = 0;
		int k = 0;
		//去除空格
		for (; str[j] == ' '; j++) { }
		i = j;
		//判断符号，并将双符号数据直接return 0
		if (str[i] == '+' || str[i] == '-') {
			i++;
			if (str[i] == '+' || str[i] == '-')
				return 0;
		}
		//string to integers
		for (; i < str.size(); i++, k++) {
			if ('0' <= str[i] && str[i] <= '9') {
				result = result * 10 + (str[i] - '0');
				if (k > 10)
					return str[j] == '-' ? INT32_MIN : INT32_MAX;
			}	
			else
				break;
		}
		//string数位大于10，直接返回
		//string数位等于10，判断是否大于INT32_MIN
		//string数位小于10，返回转换数据	
		result = str[j] == '-' ? -result : result;
		if (result > INT32_MAX)
			INT32_MAX;
		else if (result < INT32_MIN)
			INT32_MIN;
		else
			return result;	
	}
};