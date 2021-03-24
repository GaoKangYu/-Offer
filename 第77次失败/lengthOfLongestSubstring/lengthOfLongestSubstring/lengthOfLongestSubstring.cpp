/*
剑指 Offer 48. 最长不含重复字符的子字符串

请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
示例 1:
输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

提示：
s.length <= 40000
*/

/*
哈希+双指针
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int lengthOfLongestSubstring(string s) {
			if (s.length() == 1) {
				return 1;
			}
			//hash set，用于记录计入子序列的字符
			unordered_set<char> append_char;
			int ret = 0;
			int count = 0;
			int rk = 0;
			for (int i = 0; i < s.length();) {
				//当添加的都是新元素的时候，不断扩充子序列长度
				if (append_char.find(s[i]) == append_char.end()) {
					++count;
					append_char.insert(s[i]);
					++i;
				}
				//出现重复元素的时候，更新当前最大值，从头删除set记录直到无重复，同时减小count值
				else {
					ret = max(count, ret);
					append_char.erase(s[rk]);
					--count;
					++rk;
				}
			}
			return max(ret, count);
		}
};

int main()
{
	std::cout << "Hello World!\n";
}

