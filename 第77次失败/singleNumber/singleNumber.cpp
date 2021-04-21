/*
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
按位异或，但是是  其他数字都出现了三次  因此无法直接使用这样的方式

排序后双指针，待会计算一下这个复杂度O(N*LogN)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int singleNumber_violence(vector<int>& nums) {
		int n = nums.size();
		//首先排序
		quick_sort(0, n - 1, nums);
		//双指针
		//参考样例： 3 3 3 4 5 5 5 
		int slow = 0;
		int fast = 2;
		while (fast < n){
			if (nums[slow] != nums[fast]) {
				return nums[slow];
			}
			slow += 3;
			fast += 3;
		}
		return nums[slow];
	}

	//这次可以一次成功吗？
	void quick_sort(int left, int right, vector<int> &nums) {
		if (left >= right) {
			return;
		}
		int i = left;
		int j = right;
		int base = nums[left];
		while (i < j){
			//从右往左，找到比base小的
			while (i < j && nums[j] >= base) {
				--j;
			}
			//从左往右找，找到比base大的
			while (i < j && nums[i] <= base){
				++i;
			}
			swap(nums[i], nums[j]);
		}
		//基准值归位
		swap(nums[i], nums[left]);
		quick_sort(left, i - 1, nums);
		quick_sort(i + 1, right, nums);
	}

	int singleNumber(vector<int>& nums) {
		//整体思路：如果某个数字出现三次，那么这个三个数字的和肯定能被3整除
		//则其对应二进制位的每一位的和也能被3整除
		//统计数组中每个数字的二进制位中每一位的和，判断该位能否被3整除
		//如果可以，则只出现了一次的那个数字该位为0，否则为1
		//因此，先统计每一位的情况，建一个32位的数组来存每一位的1的个数
		vector<int> bits(32, 0);
		//好像快明白了
		//对于数组中的每一个数字，都要求取其每一位的一的个数
		for (auto num : nums) {
			//32位数字，每一位都要操作，正好使用数组下标
			for (int i = 0; i < 32; i++) {
				//判断该位是不是1，与运算即可，是1就加1，不是就加0
				bits[i] += num & 1;
				//num右移，除2
				num >>= 1;
			}
		}
		//至此，bits数组中已经统计好了nums数组中，所有数字每一位的1的和
		//只要该位能整除3，说明目标值在该位的值为0
		int res = 0;
		//从最高位开始算
		for (int i = 31; i >= 0; i--) {
			//左移，乘2
			res <<= 1;
			//因为每一位要么能整除3，要么因为目标数，多了一个1，所以能整除3得到值为0，不能则为1
			res += bits[i] % 3;
		}
		//妙
		return res;
	}

	void acm_input() {
		int test_data_nums;
		cin >> test_data_nums;
		while (test_data_nums){
			vector<int> input;
			int val;
			while (cin >> val){
				input.push_back(val);
				if (getchar() == '\n'){
					break;
				}
			}
			cout << singleNumber(input) << endl;
			--test_data_nums;
		}
	}
};

int main() {
	Solution solu;
	solu.acm_input();
}
