/*
Day2
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
		//统计每个32位数字每位的值的和，因为有这个单独数字的存在
		//破坏了这个每位和能被3整除的现象
		//首先建立数组存每位和
		int count[32]{ 0 };
		//统计每个数字每位的情况
		for (auto n : nums) {
			for (int i = 0; i < 32; ++i) {
				if (n & 1) {
					++count[i];
				}
				//1往右移，除以2
				n >>= 1;
			}
		}
		//至此，count数组统计完毕，随后倒序构建单独数字
		int ret = 0;
		for (int i = 31; i >= 0; --i) {
			ret <<= 1;
			if (count[i] % 3 != 0) {
				//cout << count[i];
				ret += 1;
			}
		}
		return ret;
	}
};

int main() {
	Solution solu;
	vector<int> test_vec{ 12,12,21,12,21,21,4 };
	cout << "Res : " << solu.singleNumber(test_vec) << endl;
}
