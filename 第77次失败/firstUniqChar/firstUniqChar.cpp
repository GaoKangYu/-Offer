/*
剑指 Offer 50. 第一个只出现一次的字符
在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。
s 只包含小写字母。

示例:
s = "abaccdeff"
返回 "b"

s = ""
返回 " "
 
限制：
0 <= s 的长度 <= 50000
*/

/*
学到了新内置函数
常规解法，hash set吧
*/

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
	char firstUniqChar(string s) {
		for (auto c : s) {
			if (s.find_first_of(c) == s.find_last_of(c)) {
				return c;
			}
		}
		return ' ';
	}

	string input() {
		char ret[4999];
		gets_s(ret);
		return ret;
	}
};

int main() {
	string input;
	Solution solu;
	input = solu.input();
	cout << "Unique char is : " << solu.firstUniqChar(input) << endl;;
}

