class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        hash_map<char, int> hash;
		hash_map<char, int>::iterator it;
		int first = 1;
		int last = -1;
		if (s.length() == 1)
			return 1;
		int max = 0;
		int c = 0;
		hash[s[0]] = 0;
		while (first < s.length()){
			it = hash.find(s[first]);
			if ( it != hash.end() ) {
				if (it->second > last)
					last = it->second;
				it->second = first;
			}
			else {
				hash[s[first]] = first;	
			}
			first++;
			c = first - last - 1;
			if (max < c) 
				max = c;
		}
		return max;
	}
};