#include<cstdio>
#include<map>
#include<cassert>
#include<cstring>
#include<stack>
#include<vector>
using namespace std;

// main idea is build a finite state machine
// have to handle with different cases :(
// program may be large for this problem, but it is just a practice

// seems knowledge learned from Compile Principle influences me too much,
// actually there exits very simple recursive solution

class Solution {
public:

	/* BLANK represent empty string*/
	static const char BLANK = ' ';
	static const int char_size = 128;

	bool isMatch(const char *s, const char *p) {
		/* handle with some special cases*/
		if (strlen(p) == 0)
			return strlen(s) == 0;

		if (strlen(p) > 0 && strlen(s) > 0){
			if ((p[0] == '.' && p[1] != '*') ||(p[0] == s[0] && p[1] != '*'))
				return isMatch(s + 1, p + 1);
		}


		/*** Construct State Transform Table*****/
		int state_num = 2 * strlen(p);

		int TransTbl[state_num][char_size];
		for (int i = 0; i < state_num; i++)
			for (int j = 0; j < char_size; j++)
				TransTbl[i][j] = -1;

		int state = 0;
		char prev = ' ';
		for (int i = 0; p[i] != '\0'; i++) {

			/* handle with normal char */
			if (p[i] != '.' && p[i] != '*') {

				if (i - 2 >= 0 && p[i - 1] == '*' && p[i - 2] == p[i] && ((p[i + 1] != '\0' && p[i + 1] != '*') || p[i + 1] == '\0')) {

					TransTbl[state][p[i]] = state;
					TransTbl[state][BLANK] = state + 1;
					TransTbl[state + 1][p[i]] = state + 2;
					state += 2;
					prev = p[i];
				} else if ( i - 2 >= 0 && p[i - 1] == '*' && p[i - 2] == '.') {
					TransTbl[state][BLANK] = state + 1;
					TransTbl[state + 1][p[i]] = state + 2;
					state += 2;
				} else if (i-2>=0 && p[i-2] == '.' && p[i-1] == '*' && p[i+1] == '*'){
					TransTbl[state][BLANK] = state + 1;
					TransTbl[state+1][p[i]] = state + 2;
					state += 2;
					prev = p[i];
				}

				else {
					TransTbl[state][p[i]] = (state + 1);
					state += 1;
					prev = p[i];
				}

			}
			/*handle with char '.' */
			else if (p[i] == '.') {

				if (strlen(s) >= 3 && p[i - 1] == '*' && p[i - 2] != '.') {
					TransTbl[state][BLANK] = state + 1;

					for (int j = 0; j < char_size; j++)
						TransTbl[state + 1][j] = state + 2;

					TransTbl[state + 1][BLANK] = -1;

					state += 2;
				} else if (strlen(s) >= 3 && p[i - 1] == '*'
						&& p[i - 2] == '.') {
					TransTbl[state][BLANK] = state + 1;

					for (int j = 0; j < char_size; j++)
						TransTbl[state + 1][j] = state + 2;

					TransTbl[state + 1][BLANK] = -1;

					state += 2;
				} else {
					for (int j = 0; j < char_size; j++)
						TransTbl[state][j] = state + 1;

					TransTbl[state][BLANK] = -1;
					TransTbl[state]['.'] = -1;
					TransTbl[state]['*'] = -1;
					state++;
				}
				prev = '.';

			}
			/*handle with char '*' */
			else /*if (p[i] == '*')*/{

				/*  handle with ".*"   */
				if (prev == '.') {
					for (int j = 0; j < char_size; j++)
						TransTbl[state][j] = state;

					TransTbl[state][BLANK] = -1;

					/*  handle with multiple ".*"  */
					while (p[i + 2] != '\0' && p[i + 1] == '.' && p[i + 2] == '*') {
						i += 2;
					}


				} else {
					TransTbl[state][prev] = state;
				}

				/* don't forget forward setting */
				TransTbl[state - 1][BLANK] = state;
			}

		}

		/* last_state is record for validation */
		int last_state = state;

        /*Dump State Transform Table*/
//		for (int i = 0; i < state_num; i++) {
//			for (int j = 'a'; j <= 'c'; j++)
//				if (TransTbl[i][j] != -1)
//					printf("[%d][%c]=%d\n", i, j, TransTbl[i][j]);
//
//			printf("[%d][%c]=%d\n", i, '#', TransTbl[i]['#']);
//
//		}


		/****** Match Processing ******/
		/*** use a stack to implement backtrace , in order to restore state****/

		bool answer = false;
		/* pos_state(pos_index, state) is element of stack*/
		typedef pair<int, int> pos_state;
		/* keep necessary state ( in the case of '*')*/
		stack<pos_state> bt_points;
		state = 0;
		int i;
		int prev_state = 0;
		for (i = 0; s[i] != '\0'; i++) {

			if (TransTbl[state][s[i]] != -1) {
				prev_state = state;
				state = TransTbl[state][s[i]];

				if (TransTbl[prev_state][BLANK] != -1) {
					pos_state ps = make_pair(i, prev_state);
					bt_points.push(ps);
				}

			} else if (TransTbl[state][BLANK] != -1) {
bt_front:
				state = TransTbl[state][BLANK];
				i--;
			}

			else {
				goto bt_back;
			}
		}

		while (TransTbl[state][BLANK] != -1) {
			state = TransTbl[state][BLANK];
		}
		answer = (i == strlen(s) && state == last_state);

bt_back:
		pos_state ps;
		if (!answer && !bt_points.empty()) {
			/* restore the state*/
			ps = bt_points.top();
			i = ps.first;
			state = ps.second;

			bt_points.pop();
			goto bt_front;
		}

		return answer;
	}

};

int main() {
	Solution s;
	assert(s.isMatch("aa", "a") == false);
	assert(s.isMatch("aa", "aa") == true);
	assert(s.isMatch("aaa", "aa") == false);
	assert(s.isMatch("aa", "a*") == true);
	assert(s.isMatch("aa", ".*") == true);
	assert(s.isMatch("ab", ".*") == true);
	assert(s.isMatch("aab", "c*a*b") == true);
	assert(s.isMatch("ab", ".*c") == false);
	assert(s.isMatch("abc", ".*c") == true);
	assert(s.isMatch("aaa", "aaaa") == false);
	assert(s.isMatch("aaa", "a.a") == true);
	assert(s.isMatch("aaa", "a*a") == true);
	assert(s.isMatch("aaa", "ab*a") == false);
	assert(s.isMatch("aaa", "ab*a*c*a") == true);
	assert(s.isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*c") == false);
	assert(s.isMatch("a", ".") == true);
	assert(s.isMatch("a", "ab*") == true);
	assert(s.isMatch("a", "ab*a") == false);
	assert(s.isMatch("ab", ".*..") == true);
	assert(s.isMatch("aaa", ".a") == false);
	assert(s.isMatch("bbba", ".*b") == false);
	assert(s.isMatch("a", ".*..a*") == false);
	assert(s.isMatch("a", "a.") == false);
	assert(s.isMatch("ab", ".*..c*") == true);
	assert(s.isMatch("a", ".") == true);
	assert(s.isMatch("abcdede", "ab.*de") == true);
	assert(s.isMatch("baba", "b*.*") == true);
	assert(s.isMatch("bcaccbbacbcbcab", "b*.c*..*.b*b*.*c*") == true);
	assert(s.isMatch("baabbbaccbccacacc", "c*..b*a*a.*a..*c") == true);
	assert(s.isMatch("", "c*c*") == true);
	assert(s.isMatch("bbbaccbbbaababbac", ".b*b*.*...*.*c*.") == true);
	assert(s.isMatch("abbaaaabaabbcba", "a*.*ba.*c*..a*.a*.") == true);


	return 0;
}
