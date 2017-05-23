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