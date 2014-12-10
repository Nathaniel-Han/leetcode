/* main idea : utilization of two pointers */
/* always move a step for the lower index because it is the determinant of maxArea*/
class Solution {
public:
	
	int maxArea(vector<int> &height) {
		int i = 0, j = height.size() - 1;

		int maxArea = 0, minHeight;

		while (i < j) {
			minHeight = height[i] < height[j] ? height[i] : height[j];
			if (maxArea < (j - i) * minHeight)
				maxArea = (j - i) * minHeight;

			if (height[i] < height[j]) {
					i++;
			} else {
				j--;
			}
		}

		return maxArea;
	}
};

int main() {

	return 0;
}
