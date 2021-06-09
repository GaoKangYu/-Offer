/*
Day3
题目描述
*/

/*
b bn
bn e
b e
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	string reverseLeftWords(string s, int n) {
		reverse(s.begin(), s.begin() + n);
		reverse(s.begin() + n, s.end());
		reverse(s.begin(), s.end());
		return s;
	}
};


class Solution_v1 {
public:
	string reverseLeftWords(string s, int n) {
		string ret;
		int i = n;
		for (; i < s.size(); ++i) {
			ret += s[i];
		}
		i = 0;
		for (; i < n; ++i) {
			ret += s[i];
		}
		return ret;
	}
};

int main() {

}
