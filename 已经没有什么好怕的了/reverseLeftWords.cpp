/*
Day2
剑指 Offer 58 - II. 左旋转字符串

字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。
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
思路
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution_v1 {
public:
	string reverseLeftWords(string s, int n) {
		//双指针
		//先用一个临时string存需要翻转到后面的字符
		//然后使用赋值把翻转区后的字符移到前面，最后把翻转区字符填上去
		int k = 0;
		string tmp = "";
		while (k < n) {
			tmp += s[k];
			++k;
		}
		int left = 0;
		int right = n;
		while (right < s.length()) {
			s[left] = s[right];
			++left;
			++right;
		}
		k = 0;
		while (left < s.length()) {
			s[left] = tmp[k];
			++k;
			++left;
		}
		return s;
	}
};


//背下来，反转区间前n，反转区间后n，反转整个区间
//三次翻转的技巧性解法
class Solution {
public:
	string reverseLeftWords(string s, int n) {
		reverse(s.begin(), s.begin() + n);
		reverse(s.begin() + n, s.end());
		reverse(s.begin(), s.end());
		return s;
	}
};

int main() {

}
