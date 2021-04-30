/*
剑指 Offer 19. 正则表达式匹配

请实现一个函数用来匹配包含'. '和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。
在本题中，匹配是指字符串的所有字符匹配整个模式。
例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"和"ab*a"均不匹配。

示例 1:
输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。

示例 2:
输入:
s = "aa"
p = "a*"
输出: true
解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。

示例 3:
输入:
s = "ab"
p = ".*"
输出: true
解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。

示例 4:
输入:
s = "aab"
p = "c*a*b"
输出: true
解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。

示例 5:
输入:
s = "mississippi"
p = "mis*is*p*."
输出: false
s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母以及字符 . 和 *，无连续的 '*'。
*/

/*
做过，有限状态机
理清思路
全部if else尝试一下
*/

#include <iostream>
#include <vector>

using namespace std;

//总结下来
/*
两类特殊字符 * 和 .
.：可替代任意字符
*:重复其前面那个字符若干次（包括0次）
*.:无组合技
.*：组合技，任意多个万能字符
*/

class Solution {
public:
	bool isMatch(string s, string p) {
		int s_len = s.length();
		int p_len = p.length();
		//边界情况，如果s和p都是空的
		if (s_len == 0 && p_len == 0) {
			return true;
		}
		//如果p不是空
		else if (s_len == 0 && p_len != 0) {
			//遍历p，
			for (int i = 0; i < p_len; ++i) {
				//如果当前字符为字母
				if (p[i] >= 'a' && p[i] <= 'z') {
					//下一个值不为*，false
					if (i < p_len - 1 && p[i + 1] != '*') {
						return false;
					}
					//如果当前字符为字母且没有下一个字符了
					else if(i == p_len - 1){
						return false;
					}
				}
				//如果当前字符是.
				else if (p[i] == '.') {
					//且下一个值不为*，false
					if (i < p_len - 1 && p[i + 1] != '*') {
						return false;
					}
					//如果没有下一个字符了
					else if (i == p_len - 1) {
						return false;
					}
				}
				//若*是首位，能够替代空字符吗，这里选择能
				//当前位为*且后面还有值，那么false
				else if (p[i] == '*' && i < p_len - 1) {
					return false;
				}
			}
			return true;
		}
		//两个字符串逐字符比较s[i]和p[j]的值
		for (int i = 0, j = 0; i < s_len; ++i, ++j) {
			//加一个边界条件，如果s没遍历完的时候p遍历完了，直接返回不匹配
			if (j >= p_len) {
				return false;
			}
		//这样思想的前提是，前面的都是非特殊符号的字符且都匹配了，这样的思路，情况或许会好分一些，每一个位上只有3种情况，字母，.或*
			//忽略相同的值，遇到不同的值时：
			if (s[i] != p[j]) {
				//第一种情况：p[j]是字母且p[j+1]不是*
				if (p[j] >= 'a' && p[j] <= 'z' && j < p_len - 1 && p[j + 1] != '*') {
					return false;
				}
				//第二种情况，该字符为*，这种情况下需要前一个字符p[j - 1]等于当前的s[i]
				else if (p[j] == '*') {
					if (j < 1 || p[j - 1] != s[i]) {
						return false;
					}
				}
				//第三种情况，该字符为.，这种情况下因为存在组合技，会比较麻烦
				//先考虑最简单的
				else if (p[j] == '.') {
					//最简单的情况，下一个不是*
					if (j < p_len - 1 && p[j + 1] != '*') {
						//这一位匹配成功，继续遍历到下一位
						continue;
					}
					//下一个是*
					else if (j < p_len - 1 && p[j + 1] == '*') {
						//.*的组合是可以替代任何字符，表示有若干个万能符.
						//实际上就是无敌了，除非*后面还有值
						//字符串需要匹配，那么算上特殊符号处理，最终字符串长度肯定相等，那么可以尝试得出使用组合技的次数
						//为(. *) 2 + (s_len - i) - (p_len - j)
						while (i < s_len - 1 && s[i] == s[i + 1]){
							++i;
						}
						//至此，该组合技使用完毕
						//有两种可能导致技能失效
						//第一，s后面的值都相等，把s遍历完了，但p后面还有值
						if (s[i] == s[i + 1] && i == s_len - 2 && j != p_len - 1) {
							return false;
						}
						//第二，s没有遍历完，s后面还有值，这个时候借用for循环中的++i可以将i指向新值，将j指向新值即可，如果此时j后面没值了，不匹配
						else if (s[i] != s[i + 1] && j == p_len - 2) {
							return false;
						}
						//否则，再继续遍历
						//for循环中有一次++，所以只需要额外++一次
						++j;
					}
				}
			}
		}
		//如果都通过了，就匹配
		return true;
	}
};

class Solution_better {
public:
	bool isMatch(string s, string p) {
		int m = s.size() + 1, n = p.size() + 1;
		vector<vector<bool>> dp(m, vector<bool>(n, false));
		dp[0][0] = true;
		// 初始化首行
		for (int j = 2; j < n; j += 2)
			dp[0][j] = dp[0][j - 2] && p[j - 1] == '*';
		// 状态转移
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (p[j - 1] == '*') {
					if (dp[i][j - 2]) dp[i][j] = true;                              // 1.
					else if (dp[i - 1][j] && s[i - 1] == p[j - 2]) dp[i][j] = true; // 2.
					else if (dp[i - 1][j] && p[j - 2] == '.') dp[i][j] = true;      // 3.
				}
				else {
					if (dp[i - 1][j - 1] && s[i - 1] == p[j - 1]) dp[i][j] = true;  // 1.
					else if (dp[i - 1][j - 1] && p[j - 1] == '.') dp[i][j] = true;  // 2.
				}
			}
		}
		return dp[m - 1][n - 1];
	}
};

int main() {
	std::cout << "Hello World!\n";
}
