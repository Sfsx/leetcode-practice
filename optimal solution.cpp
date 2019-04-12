class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		int m = nums2.size();
		if (n > m) 
			return findMedianSortedArrays(nums2, nums1);
		
		int k = (m + n - 1) / 2;
		int l = 0,r = min(k,n);
		while(l < r) {
			mid1 = (l + r) / 2;
			mid2 = k - mid1;
			if (nums1[mid1] < nums2[mid2])
				l = mid1 + 1;
			else
				r = mid1;
		}
		
		//nums1[l - 1], nums1[l], nums2[k - l], nums2[k - l + 1]
		int a = max(l - 1 > 0 ? nums1[l - 1] : INT_MIN, k - l > 0 ? nums2[k - l] : INT_MIN);
		if ((n + m) & 1 == 1)
			return (double)a;
		
		int b = min(l < n ? nums1[l] : INT_MAX, k - l + 1 < m ? nums2[k - l + 1] : INT_MAX);
		return (a + b) / 2.0;
	}

	int myAtoi(string str) {
		long result = 0;
		int indicator = 1;
		int i = 0;
		i = str.find_first_not_of(' ');
		if (str[i] == '-' || str[i] == '+')
			indicator = str[i++] == '-' ? -1 : 1;
		while('0' < str[i] && str[i] < '9') {
			result = result * 10 + (str[i++] - '0');
			if (result * indicator >= INT_MAX) return INT_MAX;
			if (result * indicator <= INT_MIN) return INT_MIN;
		}
		return result * indicator;
	}

	int reverse(int x) {
		long result = 0;
		while(x) {
			result = result * 10 + x % 10;
			x /= 10;
		}
		return (result > INT_MAX || result < INT_MIN) ? 0 : result;
	}


    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        return backtracking(s, m, p, n);
    }
    
    bool backtracking(string& s, int i, string& p, int j) {
        if (i == 0 && j == 0) return true;
        if (i != 0 && j == 0) return false;
        if (i == 0 && j != 0) {
            //in this case only p == "c*c*c*" this pattern can match null string
            if (p[j-1] == '*') {
                return backtracking(s, i, p, j-2);
            }
            return false;
        }
        //now both i and j are not null
        if (s[i-1] == p[j-1] || p[j-1] == '.') {
            return backtracking(s, i - 1, p, j - 1);
        } else if (p[j-1] == '*') {
            //two cases: determines on whether p[j-2] == s[i-1]
            //first p[j-2]* matches zero characters of p
            if (backtracking(s, i, p, j - 2)) return true;
            //second consider whether p[j-2] == s[i-1], if true, then s[i-1] is matched, move to backtracking(i - 1, j)
            if (p[j-2] == s[i-1] || p[j-2] == '.') {
                return backtracking(s, i - 1, p, j);
            }
            return false;
        }
        return false;
    }
};