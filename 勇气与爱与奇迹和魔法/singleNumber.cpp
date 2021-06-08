/*
Day3
剑指 Offer 56 - II. 数组中数字出现的次数 II
在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。

 

示例 1：

输入：nums = [3,4,3,3]
输出：4
示例 2：

输入：nums = [9,1,7,9,7,9,7]
输出：1
 

限制：

1 <= nums.length <= 10000
1 <= nums[i] < 2^31
*/

/*
思路
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		//每个数字都出现了三次，那么32位数字的每一位的值累加，都能被3整除
		//如果不能，说明单独数字那一位为1
		//首先构建一个32长度的数组
		int count[32]{ 0 };
		//统计每一个数字每一位的情况
		for (int n : nums) {
			for (int i = 0; i < 32; ++i) {
				if (n & 1) {
					++count[i];
				}
				n >>= 1;
			}
		}
		//再次遍历count数组，基类单独数字
		int ret = 0;
		//问题在于如何构建这个数字
		for (int i = 31; i >= 0; --i) {
			ret <<= 1;
			if (count[i] % 3) {
				++ret;
			}
		}
		return ret;
	}
};

int main() {

}
