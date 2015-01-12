#include<iostream>
#include<map>
#include<string>
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

    int romanToInt(string s) {
    	int answer = 0;
    	int index = 0;
    	map<int, string>::reverse_iterator it = RomanNumberMap.rbegin();

    	for(;it != RomanNumberMap.rend(); ++it){
    		while(s.substr(index, it->second.length())==it->second){
    			answer += it->first;
    			index += it->second.length();
    		}
    	}

    	return answer;


    }
private:
    map<int, string> RomanNumberMap;
};

int main(){
	Solution s;
	assert(s.romanToInt("XCIX") == 99);
	assert(s.romanToInt("DCXXI") == 621);
	return 0;
}
