/*************************************************


Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

**************************************************/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
		int area = 0;
		int begin = 0;
		int end = height.size() - 1;
		while (begin < end) {
			if (height[begin] < height[end]) {
				area = height[begin] * (end - begin);
				begin++;
			}
			else {
				area = height[end] * (end - begin);
				end--;
			}
			maxArea = max(maxArea, area);
		}
		return maxArea;
    }
};