/*
Day3
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
思路
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		//分组异或
		int x = 0;
		int y = 0;
		int res = 0;
		for (int n : nums) {
			res ^= n;
		}
		//cout << res << endl;
		//找到为1的那一个位
		//如果该位不是1，flag左移
		int flag = 1;
		while (!(res & 1)) {
			flag <<= 1;
			res >>= 1;
		}
		//依据此分组异或
		for (int n : nums) {
			if (n & flag) {
				x ^= n;
			}
			else {
				y ^= n;
			}
		}
		return vector<int>{x, y};
	}
};

int main() {

}
