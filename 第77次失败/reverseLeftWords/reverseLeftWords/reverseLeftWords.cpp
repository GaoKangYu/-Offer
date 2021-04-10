/*
剑指 Offer 58 - II. 左旋转字符串

字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
请定义一个函数实现字符串左旋转操作的功能。
比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

 
示例 1：
输入: s = "abcdefg", k = 2
输出: "cdefgab"

示例 2：
输入: s = "lrloseumgh", k = 6
输出: "umghlrlose"
 
限制：
1 <= k < s.length <= 10000
*/

/*
双指针+额外存储空间n
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string reverseLeftWords(string s, int n) {
		int pre = 0, later = n;
		string tmp;
		int i = 0;
		while (n) {
			tmp += s[i];
			++i;
			--n;
		}
		for (; later < s.size(); ++pre, ++later) {
			s[pre] = s[later];
		}
		i = 0;
		while (pre < s.size()) {
			s[pre] = tmp[i];
			++pre;
			++i;
		}
		return s;
	}

	//字符串翻转、回文等，可以考虑直接把字符串倍增成为两个同样的字符串拼接的长字符串，然后旋转
	/*
	abcdef
	abcdefabcdef
	abc  defabc  def  旋转三个字符
	abcde  fabcde  f  旋转五个字符
	*/
	//学到了新知识，`substr`
	string reverseLeftWords_better(string s, int n) {
		int len = s.size();
		s += s;
		return s.substr(n, len);
	}

	string input_str() {
		char ret[9999];
		printf("Please input a string, ended by 'enter'.\n");
		gets_s(ret);
		fflush(stdin);
		show_res(ret);
		return ret;
	}

	int input_int() {
		int ret;
		printf("Please input a number, ended by 'enter'.\n");
		scanf_s("%d", &ret);
		fflush(stdin);
		return ret;
	}

	void show_res(string str) {
		cout <<"Result : "<< str << endl;
	}
};

int main() {
	Solution solu;
	string input = solu.input_str();
	int n = solu.input_int();
	solu.show_res(solu.reverseLeftWords(input, n));
}

