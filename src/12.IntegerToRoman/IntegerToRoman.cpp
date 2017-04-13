#include<iostream>
#include<string>
#include<map>
#include<cassert>
using namespace std;


class Solution {
public:
	Solution(){
		RomanNumberMap[1000]="M";
		RomanNumberMap[900] = "CM";
		RomanNumberMap[500] = "D";
		RomanNumberMap[400] = "CD";
		RomanNumberMap[100] = "C";
		RomanNumberMap[90] = "XC";
		RomanNumberMap[50] = "L";
		RomanNumberMap[40] = "XL";
		RomanNumberMap[10] = "X";
		RomanNumberMap[9] = "IX";
		RomanNumberMap[5] = "V";
		RomanNumberMap[4] = "IV";
		RomanNumberMap[1] = "I";
	}

    string intToRoman(int num) {
    	string answer;

    	//traverse from large to small
    	map<int, string>::reverse_iterator it = RomanNumberMap.rbegin();

    	for(;it!= RomanNumberMap.rend(); ++it)
    		while (num >= it->first){
    			answer.append(it->second);
    			num -= it->first;
    		}

    	return answer;
    }
private:
    map<int, string> RomanNumberMap;
};

int main(){
	Solution s;
	assert(s.intToRoman(70) == "LXX");
	assert(s.intToRoman(99) == "XCIX");
	return 0;
}
