/*
Day2
剑指 Offer 53 - I. 在排序数组中查找数字 I

统计一个数字在排序数组中出现的次数。

 

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: 2
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: 0
 

限制：
0 <= 数组长度 <= 50000
*/

/*
思路
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution_v1 {
public:
	int search(vector<int>& nums, int target) {
		//直接遍历
		//优化到二分找左区间
		int ret = 0;
		for (auto n : nums) {
			if (n == target) {
				++ret;
			}
		}
		return ret;
	}
};

//利用排序的特点
class Solution {
public:
	int search(vector<int>& nums, int target) {
		//优化到二分找左区间
		if (nums.empty()) {
			return 0;
		}
		int len = nums.size();
		int left = 0;
		int right = len - 1;
		if (nums[left] > target || nums[right] < target) {
			return 0;
		}
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == target) {
				//始终注意目标，不要管其他的，目标是找到左边界
				right = mid;
			}
			else if (nums[mid] > target) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		int ret = 0;
		while (left < len && nums[left] == target) {
			++ret;
			++left;
		}
		return ret;
	}
};

int main() {

}
