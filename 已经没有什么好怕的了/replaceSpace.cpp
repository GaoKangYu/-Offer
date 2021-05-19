/*
Day2
剑指 Offer 05. 替换空格

请实现一个函数，把字符串 s 中的每个空格替换成"%20"。


示例 1：
输入：s = "We are happy."
输出："We%20are%20happy."
 

限制：
0 <= s 的长度 <= 10000
*/

/*
思路
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	string replaceSpace_v1(string s) {
		//能够很直观的想到需要额外申请空间的解法
		string ret = "";
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == ' ') {
				ret += "%20";
			}
			else {
				ret += s[i];
			}
		}
		return ret;
	}

	string replaceSpace(string s) {
		//能够很直观的想到需要额外申请空间的解法
		string ret;
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == ' ') {
				ret.push_back('%');
				ret.push_back('2');
				ret.push_back('0');
			}
			else {
				ret.push_back(s[i]);
			}
		}
		return ret;
	}
};

int main() {

}
