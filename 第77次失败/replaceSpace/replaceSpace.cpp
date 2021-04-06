/*
剑指 Offer 05. 替换空格
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

示例 1：
输入：s = "We are happy."
输出："We%20are%20happy."
 
限制：
0 <= s 的长度 <= 10000
*/

/*
涉及string的扩容

gets_s：需要指定缓冲区大小，从缓冲区第一个字符开始读（有啥读啥），一直读到第一个回车，并且把这个回车清除出缓冲区。

好。
*/

#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
	string replaceSpace(string s) {
		string ret;
		for (auto &c : s){
			if (c == ' ') {
				ret.push_back('%');
				ret.push_back('2');
				ret.push_back('0');
			}
			else{
				ret.push_back(c);
			}
		}
		return ret;
	}

	string string_input() {
		printf("Please input a string, ended by 'Enter'.\n");
		char tmp[9999];
		gets_s(tmp);
		show_result(tmp);
		return tmp;
	}

	void show_result(string result) {
		cout << "Processed result :";
		for (auto c : result){
			cout << c;
		}
		cout << endl;
	}
};

int main() {
	Solution solu;
	string input;
	input = solu.string_input();
	solu.show_result(solu.replaceSpace(input));
}

