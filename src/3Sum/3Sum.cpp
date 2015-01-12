#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	// The time complexity is O(N^2)
	// it first turns out that the challenge is how to eliminate duplications with <set>
	// the trick I utilize is shown in the two while clauses in the for loop.
	vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > answer;
		vector<int> triple_vec;

		//sorting is a necessary procedure in this method
		sort(num.begin(), num.end());

		int size = num.size();
		int twoSum;


		for (int i = 0; i < size; i++) {
			for (int j = i + 1; j < size; j++) {

				twoSum = num[i] + num[j];

				// binary search is applied to search for the third element
				if (std::binary_search(num.begin() + j + 1, num.end(), -twoSum)) {

						triple_vec.push_back(num[i]);
						triple_vec.push_back(num[j]);
						triple_vec.push_back(-twoSum);
						answer.push_back(triple_vec);
						triple_vec.clear();
				}
				// trick to eliminate duplications
				while (num[j] == num[j+1])
					j++;
			}
			// trick to eliminate duplications
			while (num[i] == num[i+1])
				i++;
		}

		return answer;

	}
};

int main() {
	Solution s;
	int a[] = { -1, 0, 1, 2, -1, -4 ,-1};
	vector<int> input(a, a + sizeof(a) / sizeof(int));

	vector<vector<int> > answer = s.threeSum(input);

	cout << answer.size() << endl;

	for(int i=0;i<answer.size();i++){
		for(int j=0;j<answer[i].size();j++){
			cout << answer[i][j] << " ";
		}
		cout << endl;
	}


	return 0;
}
