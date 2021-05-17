/*
Day2
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
思路
*/

#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_set<int> visit;
		int ret = 0;
		int count = 0;
		int rk = 0;
		for (int i = 0; i < s.length();) {
			if (visit.find(s[i]) == visit.end()) {
				visit.insert(s[i]);
				++count;
				++i;
			}
			else {
				ret = max(ret, count);
				visit.erase(s[rk]);
				--count;
				++rk;
			}
		}
		return max(ret, count);
	}
};

int main() {

}
