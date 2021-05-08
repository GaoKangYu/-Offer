/*
Day2
剑指 Offer 50. 第一个只出现一次的字符

在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。

示例:
s = "abaccdeff"
返回 "b"

s = ""
返回 " "
 

限制：
0 <= s 的长度 <= 50000
*/

/*
思路
*/

#include <iostream>
#include <set>
#include <string>

using namespace std;

class Solution{
public:
	char firstUniqChar(string s) {
		//首先想到的是哈希表
		//O(n) + O(n)
		//但是因为字母数字只有26个，所以相当于O(1)
		//可以使用下标数组
		int count[26]{ 0 };
		for (auto chr : s) {
			++count[chr - 'a'];
		}
		for (auto chr : s) {
			if (count[chr - 'a'] == 1) {
				return chr;
			}
		}
		return ' ';
	}

	void acm() {
		string s;
		getline(cin, s);
		cout << "Input string : " << s << endl;
		cout << "Result : " << firstUniqChar(s) << endl;
	}
};


int main() {
	Solution solu;
	solu.acm();
}
