class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result(2, 0);
		vector<int>::iterator it;
		vector<int> copy(nums);
		if (!is_sorted(nums.begin(), nums.end())) {
			sort(copy.begin(), copy.end());
		}
		int start;
		int end;
		int middle;
		for (int i = 0; i < copy.size(); i++) {
			start = i + 1;
			end = copy.size() - 1;
			middle = (start + end) / 2;
			
			if (copy[i] + copy[start] > target)
				return result;
			else if (copy[i] + copy[end] < target)
				continue;
			else {
				while (start <= end) {
					if (copy[i] + copy[start] == target) {
						int k = 0;
						for (it = nums.begin(); it != nums.end(); it++) {
							if (*it == copy[i]) {
								if (k == 0)
									result[0] = distance(nums.begin(), it);
								else {
									result[1] = distance(nums.begin(), it);
									return result;
								}
								k++;
								continue;
							}
							if (*it == copy[start]) {
								if (k == 0)
									result[0] = distance(nums.begin(), it);
								else {
									result[1] = distance(nums.begin(), it);
									return result;
								}
								k++;
								continue;
							}
						}
					}
					else if (copy[i] + copy[end] == target) {
						int k = 0;
						for (it = nums.begin(); it != nums.end(); it++) {
							if (*it == copy[i]) {
								if (k == 0) {
									result[0] = distance(nums.begin(), it);
								}
								else {
									result[1] = distance(nums.begin(), it);
									return result;
								}
								k++;
								continue;
							}
							if (*it == copy[end]) {
								if (k == 0)
									result[0] = distance(nums.begin(), it);
								else {
									result[1] = distance(nums.begin(), it);
									return result;
								}
								k++;
								continue;
							}
						}
					}
					if ((copy[i] + copy[middle]) == target) {
						int k = 0;
						for (it = nums.begin(); it != nums.end(); it++) {
							if (*it == copy[i]) {
								if (k == 0)
									result[0] = distance(nums.begin(), it);
								else {
									result[1] = distance(nums.begin(), it);
									return result;
								}
								k++;
								continue;
							}
							if (*it == copy[middle]) {
								if (k == 0) 
									result[0] = distance(nums.begin(), it);
								else {
									result[1] = distance(nums.begin(), it);
									return result;
								}
								k++;
								continue;
							}
						}
					}
					else if ((copy[i] + copy[middle]) > target) {
						end = middle - 1;
					}
					else if ((copy[i] + copy[middle]) < target) {
						start = middle + 1;
					}
					else
						break;
					middle = (start + end) / 2;
				}
			}
		}
		return result;
	}
};