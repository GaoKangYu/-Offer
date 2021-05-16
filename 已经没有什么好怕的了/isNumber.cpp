/*
Day2
剑指 Offer 20. 表示数值的字符串

请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。

数值（按顺序）可以分成以下几个部分：

若干空格
一个 小数 或者 整数
（可选）一个 'e' 或 'E' ，后面跟着一个 整数
若干空格
小数（按顺序）可以分成以下几个部分：

（可选）一个符号字符（'+' 或 '-'）
下述格式之一：
至少一位数字，后面跟着一个点 '.'
至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
一个点 '.' ，后面跟着至少一位数字
整数（按顺序）可以分成以下几个部分：

（可选）一个符号字符（'+' 或 '-'）
至少一位数字
部分数值列举如下：

["+100", "5e2", "-123", "3.1416", "-1E-16", "0123"]
部分非数值列举如下：

["12e", "1a3.14", "1.2.3", "+-5", "12e+5.4"]

示例 1：
输入：s = "0"
输出：true

示例 2：
输入：s = "e"
输出：false

示例 3：
输入：s = "."
输出：false

示例 4：
输入：s = "    .1  "
输出：true 

提示：
1 <= s.length <= 20
s 仅含英文字母（大写和小写），数字（0-9），加号 '+' ，减号 '-' ，空格 ' ' 或者点 '.' 。
*/

/*
思路
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	bool isNumber(string s) {
		//用这几个题目进入状态也不错，冷静
		//冷静
		//按顺序解析
		if (s.empty() || s.length() == 0) {
			return false;
		}
		bool has_num = false;
		bool has_dot = false;
		bool has_e = false;
		//首先过滤首尾的空格
		s.erase(0, s.find_first_not_of(" "));
		s.erase(s.find_last_not_of(" ") + 1);
		int n = s.length();
		for (int j = 0; j < n; ++j) {
			//是数字不需要前置条件
			if (isdigit(s[j])) {
				has_num = true;
			}
			//.只能出现一次，不能在e后面
			else if (s[j] == '.' && !has_dot && !has_e) {
				has_dot = true;
			}
			//e只能出现一次，必须在数字后面
			else if ((s[j] == 'e' || s[j] == 'E') && !has_e && has_num) {
				has_e = true;
				//e的后面也必须有数字，因此出现e以后需要把has_num置false
				has_num = false;
			}
			//-+只能出现在首位或者紧跟在e的后面
			else if ((s[j] == '-' || s[j] == '+') && (j == 0 || s[j - 1] == 'e' || s[j - 1] == 'E')) {
				continue;
			}
			//其他字符直接返回false
			else {
				return false;
			}
		}
		//必须有数字才能true，所以直接返回has_num
		return has_num;
	}
};

int main() {

}
