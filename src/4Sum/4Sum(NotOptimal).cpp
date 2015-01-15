#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<cassert>
#include<algorithm>
#include<string>
#include<ctime>

using namespace std;

class Solution {
public:
  /* A failure trial to transform 4Sum to 2Sum problem.
	   It is not good to generate pairs one by one and then feed the pairs
		 to 2Sum procedures because there will be too many pairs*/

	/* The result of this solution on leetcode is Time Limits Exceeded*/
	vector<vector<int> > fourSum(vector<int> &num, int target) {

		vector<vector<int> > answer;

		if (num.size() < 4)
			return answer;

		vector<int> quad(4);

		vector<pair<int, int> > pairs;

		unordered_set<string> test;

		vector<int> twoSums;

		int size = num.size();

		// generate pairs one by one
		for (int i = 0; i < size; i++) {
			for (int j = i + 1; j < size; j++) {
				pairs.push_back(make_pair(i, j));
				twoSums.push_back(num[i]+num[j]);
			}
		}

		// Get answers of pairs from twoSum procedure
		vector<vector<int> > twoSumAns = twoSum(twoSums, target);

		int a1, b1,a2,b2;

		for (int i = 0; i < twoSumAns.size(); i++) {
			a1 = pairs[twoSumAns[i][0]].first, b1 =
					pairs[twoSumAns[i][0]].second, a2 =
					pairs[twoSumAns[i][1]].first, b2 =
					pairs[twoSumAns[i][1]].second;

			// Examine Index Duplication
			if (a1 != a2 && a1 != b2 && b1 != a2 && b1 != b2) {

				quad[0] = num[a1];
				quad[1] = num[b1];
				quad[2] = num[a2];
				quad[3] = num[b2];
				sort(quad.begin(), quad.end());

				//Examine Quadruplet Duplication
				string str;
				str += quad[0];
				str += quad[1];
				str += quad[2];
				str += quad[3];
				if(test.count(str) == 0){
					answer.push_back(quad);
					test.insert(str);
				}
			}
		}

		return answer;

	}

	vector<vector<int> > twoSum(vector<int> &numbers, int target) {
		vector<vector<int> > answer;
		vector<int> candidate(2, 0);
		// Use multimap instead of map because it could have duplicate element
		unordered_multimap<int, int> m_record;
		typedef unordered_multimap<int, int>::iterator iterator;
		iterator iter ;
		pair<iterator, iterator> range;

		for (int i = 0; i < numbers.size(); i++) {
			m_record.insert(make_pair(numbers[i], i));
		}

		for (int i = 0; i < numbers.size(); i++) {
			 range = m_record.equal_range(target - numbers[i]);

			for (iter = range.first; iter != range.second; iter++) {
				candidate[0] = i;
				candidate[1] = iter->second;
				answer.push_back(candidate);
			}
		}


		return answer;
	}

	void printArrays(vector<vector<int> > arr) {
		for (int i = 0; i < arr.size(); i++) {
			for (int j = 0; j < arr[i].size(); j++)
				cout << arr[i][j] << " ";

			cout << endl;
		}
	}
};

int main() {
	Solution s;
	int a[] = { 91277418, 66271374, 38763793, 4092006, 11415077, 60468277,
			1122637, 72398035, -62267800, 22082642, 60359529, -16540633,
			92671879, -64462734, -55855043, -40899846, 88007957, -57387813,
			-49552230, -96789394, 18318594, -3246760, -44346548, -21370279,
			42493875, 25185969, 83216261, -70078020, -53687927, -76072023,
			-65863359, -61708176, -29175835, 85675811, -80575807, -92211746,
			44755622, -23368379, 23619674, -749263, -40707953, -68966953,
			72694581, -52328726, -78618474, 40958224, -2921736, -55902268,
			-74278762, 63342010, 29076029, 58781716, 56045007, -67966567,
			-79405127, -45778231, -47167435, 1586413, -58822903, -51277270,
			87348634, -86955956, -47418266, 74884315, -36952674, -29067969,
			-98812826, -44893101, -22516153, -34522513, 34091871, -79583480,
			47562301, 6154068, 87601405, -48859327, -2183204, 17736781,
			31189878, -23814871, -35880166, 39204002, 93248899, -42067196,
			-49473145, -75235452, -61923200, 64824322, -88505198, 20903451,
			-80926102, 56089387, -58094433, 37743524, -71480010, -14975982,
			19473982, 47085913, -90793462, -33520678, 70775566, -76347995,
			-16091435, 94700640, 17183454, 85735982, 90399615, -86251609,
			-68167910, -95327478, 90586275, -99524469, 16999817, 27815883,
			-88279865, 53092631, 75125438, 44270568, -23129316, -846252,
			-59608044, 90938699, 80923976, 3534451, 6218186, 41256179, -9165388,
			-11897463, 92423776, -38991231, -6082654, 92275443, 74040861,
			77457712, -80549965, -42515693, 69918944, -95198414, 15677446,
			-52451179, -50111167, -23732840, 39520751, -90474508, -27860023,
			65164540, 26582346, -20183515, 99018741, -2826130, -28461563,
			-24759460, -83828963, -1739800, 71207113, 26434787, 52931083,
			-33111208, 38314304, -29429107, -5567826, -5149750, 9582750,
			85289753, 75490866, -93202942, -85974081, 7365682, -42953023,
			21825824, 68329208, -87994788, 3460985, 18744871, -49724457,
			-12982362, -47800372, 39958829, -95981751, -71017359, -18397211,
			27941418, -34699076, 74174334, 96928957, 44328607, 49293516,
			-39034828, 5945763, -47046163, 10986423, 63478877, 30677010,
			-21202664, -86235407, 3164123, 8956697, -9003909, -18929014,
			-73824245 };

	vector<int> input(a, a + sizeof(a) / sizeof(int));


	clock_t start = clock();
	vector<vector<int> > answer = s.fourSum(input, -236727523);

	cout << answer.size() << endl;

	for (int i = 0; i < answer.size(); i++) {
		for (int j = 0; j < answer[i].size(); j++) {
			cout << answer[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
