/*
剑指 Offer 58 - I. 翻转单词顺序

输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。

示例 1：
输入: "the sky is blue"
输出: "blue is sky the"

示例 2：
输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。

示例 3：
输入: "a good   example"
输出: "example good a"
解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 
说明：
无空格字符构成一个单词。
输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
*/

/*
第一想法是双指针，swap，但是问题一直在与，单词长度不一致的情况下，能不能insert，可以，尝试一下吧

。。没说非要你原地修改啊
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		int len = s.length();
		string res = "";
		if (len == 0) {
			return res;
		}

		int j = len - 1;
		while (j >= 0) {
			if (s[j] == ' ') {
				// 当 s[j] 是空格时，j 不断左移
				j--;
				//当代码执行到continue时，本轮循环终止，进入下一轮循环，具有过滤功能,只看while for等
				//不看if，这里相当于过滤末尾的空格
				continue;
			}

			while (j >= 0 && s[j] != ' ') {
				// 注意 while 里必须用 && 短路求值，且 j >= 0 要放前面
				// 不然如果 j 变成 -1，那么计算 s[j] 会发生溢出错误！
				j--;
			}

			int pos = j; // 用 pos 保存 j 当前的位置
			j++; // j 现在指向的是一个空格，需要右移一位才能指向一个单词的开头
			while (s[j] != ' ' && j < len) {
				// 向 res 中添加单词
				res += s[j];
				j++;
			}
			res += ' ';
			j = pos; // j 回到新添加的单词的最左端再往左一个空格处
		}
		if (res[0] == ' ') {
			return res;
		}
		res.pop_back();
		return res;
	}

	string input() {
		char ret[999];
		gets_s(ret);
		return ret;
	}
};

int main() {
	Solution solu;
	string input = solu.input();
	cout << "Res:" << solu.reverseWords(input);
}
