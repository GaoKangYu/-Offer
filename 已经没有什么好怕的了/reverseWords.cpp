/*
Day2
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
		//wtf，是交换整个单词，而不是字符
		string ret = "";
		//其实拷贝是有必要的，直接修改s，s就不可用了
		//如果是要直接修改s，形参应该会写成引用吧
		int n = s.length();
		for (int i = n - 1; i >= 0; --i) {
			//过滤空格
			if (s[i] == ' ') {
				continue;
			}
			//找到一个单词的结尾
			int end = i;
			int tmp = end;
			while (i >= 0 && s[tmp] != ' ') {
				--i;
				--tmp;
			}
			//找到一个单词的结尾
			int start = i + 1;
			//往ret中添加单词
			while (start <= end) {
				//cout << ret << "|";
				ret += s[start];
				++start;
			}
			ret += ' ';
		}
		ret.pop_back();
		return ret;
	}
};

int main() {
	Solution solu;
	string res = solu.reverseWords("dshasbh cdanj asdjnjas    djsand sadnkjsad as djnasd  ");
	cout << "Res : " << res << endl;
}
