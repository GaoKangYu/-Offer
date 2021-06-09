/*
Day3
剑指 Offer 58 - I. 翻转单词顺序

输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。

 

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
思路
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		//从尾到头遍历，找到一个完整单词
		//加入返回值，继续找到下一个完整单词，直到遍历到头部
		string ret = "";
		int len = s.length();
		for (int i = len - 1; i >= 0; --i)
		{
			if (s[i] == ' ') {
				continue;
			}
			//找到了一个单词的尾部
			int word_end_index = i;
			int tmp = i;
			while (i >= 0 && s[tmp] != ' ')
			{
				--i;
				--tmp;
			}
			//找到了一个单词的开头
			int word_start_index = i + 1;
			//单词添加到ret中
			while (word_start_index <= word_end_index)
			{
				ret.push_back(s[word_start_index]);
				++word_start_index;
			}
			//单词用空格分隔
			ret += ' ';
		}
		//去除多余的空格
		ret.pop_back();
		return ret;
	}
};

int main() {
	Solution solu;
	cout << solu.reverseWords("that! do    can I believe I , weeks two in game fun a make will I  ") << endl;
}
