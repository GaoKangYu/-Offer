/*
Day2
剑指 Offer 46. 把数字翻译成字符串

给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。
一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

示例 1:
输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
 

提示：
0 <= num < 2^31
*/

/*
思路
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int translateNum(int num) {
		//原来是这样，我完全懂了
		string src = to_string(num);//转换成string方便判断是否能两位翻译
		//如果没有组合，按位翻译，那么不管多长，都只有1种翻译方法，所以从str首位开始遍历的当前方法数为1
		int ppre = 0, pre = 0, cur = 1;
		//从str开头开始遍历，维持ppre  pre  cur的滚动序列
		for (int i = 0; i < src.size(); ++i) {
			ppre = pre;
			pre = cur;
			cur = pre;
			//防止无效索引
			if (i == 0) {
				continue;
			}
			//如果可以两两组合，那么dp[i] = dp[i - 1] + dp[i - 2]
			//从0到i-1有dp[i-1]种方法，从0到i-2有dp[i-2]种方法，到了这一步（i-1或者i-2）之后，都只有一种方法到i了
			//因此dp[i] = dp[i - 1] + dp[i - 2]
			if (src[i - 1] == '1' || (src[i - 1] == '2' && src[i] <= '5')) {
				cur = pre + ppre;
			}
		}
		return cur;
	}
};

int main() {

}
