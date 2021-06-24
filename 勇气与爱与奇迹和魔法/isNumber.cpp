/*
Day3
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
#include <vector>

using namespace std;

class Solution {
public:
	bool isNumber(string s) {
		//总结一下规律
		//总共有+- eE 数字 . 空格 其他字符
		//其中+-必须只能出现在空格后，前面不能有除了E以外的字符
		//.的后面必须有数字
		//e必须在.的后，e的前面必须有数字
		//必须有一个数字
		//空格只能出现在开头或结尾
		//首先去除开头和结尾的空格
		int len = s.length();
		while (len >= 0 && s[0] == ' ') {
			s.erase(s.begin());
			--len;
		}
		//去除了开头的空格
		while (len > 0 && s[len - 1] == ' ') {
			s.pop_back();
			--len;
		}
		//去除了末尾的空格
		//开始定义判定flag
		bool hasNum = false;
		bool hasE = false;
		bool hasDot = false;
		int DotPos = 0;
		bool hasSymbol = false;
		for (int i = 0; i < len; ++i) {
			if (isdigit(s[i])) {
				hasNum = true;
			}
			//其中+-前面不能有.
			else if (s[i] == '-' || s[i] == '+') {
				if (hasNum || (hasDot && i > DotPos)) {
					return false;
				}
				hasSymbol = true;
			}
			//e的前面必须有数字,e的后面必须有数字
			else if ((s[i] == 'e' || s[i] == 'E')) {
				if (!hasNum || hasE) {
					return false;
				}
				hasE = true;
				hasNum = false;
				hasDot = false;
			}
			//.的前面不能有e，后面不能有-+号
			else if (s[i] == '.') {
				if (hasDot || hasE) {
					return false;
				}
				hasDot = true;
				DotPos = i;
			}
			else {
				return false;
			}
		}
		//必须有一个数字
		return hasNum;
	}
};

int main() {
	string input = "12.3e21";
	Solution solu;
	cout << "res = " << solu.isNumber(input) << endl;

}
