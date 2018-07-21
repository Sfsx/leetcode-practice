/*************************************************

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);

convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR". 

**************************************************/

string convert(string s, int numRows) {
		string result;
		if (s.size() == 0 || numRows == 1)
			return s;
		int count = s.size() / (numRows * 2 - 2) + 1;
		for (int j = 0; j < numRows; j++) {
			for (int i = 0; i < count; i++) {
				if (j == 0 || j == numRows - 1) {
					if (j + (numRows * 2 - 2)*i<s.size())
						result += s[j + (numRows * 2 - 2)*i];
				}
				else {
					if(j + (numRows * 2 - 2)*i<s.size())
						result += s[j + (numRows * 2 - 2)*i];
					if (-j + (numRows * 2 - 2)*(i + 1)<s.size()) 
						result += s[-j + (numRows * 2 - 2)*(i + 1)];
				}
			} 
				
			
		}
		return result;
	}