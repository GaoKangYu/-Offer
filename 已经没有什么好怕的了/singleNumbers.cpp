/*
Day2
剑指 Offer 56 - I. 数组中数字出现的次数

一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

示例 1：
输入：nums = [4,1,4,6]
输出：[1,6] 或 [6,1]

示例 2：
输入：nums = [1,2,10,4,1,4,3,3]
输出：[2,10] 或 [10,2] 

限制：
2 <= nums.length <= 10000
*/

/*
分组异或
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		//分组异或，求只出现了1次的x和y
		//把所有的数字异或，得到的值为x^y，那么按位开始计算
		//该位为0代表这两个数在那一位的值是相同的，该位为1代表这两个数在那一位是不同的
		//但这样也分不开，因为有多种情况
		int x = 0, y = 0, xynor = 0, divide = 1;
		for (int num : nums) {
			xynor ^= num;
		}

		//分组目的：相同的数分在同一边，不同的数分在两边
		//原理：如果x和y的某一位不同，那么其异或值在该位为1，于是可以找到任一个那个位
		//通过x、y异或之结果不同而将xy分在两边，同时，两个相同的数在该位的异或值也是一样的，由此可以把相同的数放在同一边
		//神乎其技
		while (xynor & divide == 0){
			divide <<= 1;
		}
		for (int num : nums) {
			if (num & divide == 0) {
				x ^= num;
			}
			else {
				y ^= num;
			}
		}
		return vector<int>{ x, y };
	}
};

int main() {

}
