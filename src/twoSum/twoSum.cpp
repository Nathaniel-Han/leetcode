#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> answer;
        map<int, int> m_record;
        map<int, int>::iterator it;

        for(int i=0;i<numbers.size();i++){
        	m_record[numbers[i]] = i;
        }

        for(int i=0;i<numbers.size();i++){
        	it = m_record.find(target - numbers[i]);
        	if(it != m_record.end() && it->second != i ){
        		answer.push_back(i+1);
        		answer.push_back(it->second+1);
        		return answer;
        	}

        }
    }
};

int main(){
	vector<int> numbers;
	numbers.push_back(3);
	numbers.push_back(2);
	numbers.push_back(4);
	int target = 6;

	Solution s;

	vector<int> answers = s.twoSum(numbers, target);

	cout << "index1 = "<< answers[0]<<endl;
	cout << "index2 = "<< answers[1]<<endl;

	return 0;
}
