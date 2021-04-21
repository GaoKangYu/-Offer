/*
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
排序数组，二分
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int search_violence(vector<int>& nums, int target) {
		int ret = 0;
		for (auto n : nums) {
			if (n == target) {
				++ret;
			}
		}
		return ret;
	}

	//问题分析：为什么要进行两次几乎相同的二分查找
	int search(vector<int>& nums, int target) {
		//简洁写法，找target上界和target-1上界
		return search_api(nums, target) - search_api(nums, target - 1);
	}

	int search_api(vector<int>& nums, int target) {
		int len = nums.size();
		int left = 0;
		int right = len - 1;
		while (left <= right){
			int mid = left + (right - left) / 2;
			//小于等于目标值，下界拿过来
			if (nums[mid] <= target) {
				left = mid + 1;
			}
			//否则上界拿过来
			else {
				right = mid - 1;
			}
		}
		return left;
	}

	void acm_test() {
		int test_data_nums;
		cin >> test_data_nums;
		fflush(stdin);
		while (test_data_nums){
			int val;
			vector<int> input;
			while (cin >> val){
				if (getchar() == '\n') {
					break;
				}
				input.push_back(val);
			}
			fflush(stdin);
			int target;
			cin >> target;
			fflush(stdin);
			cout << search(input, target) << endl;
			--test_data_nums;
		}
	}
};

int main() {
	Solution solu;
	solu.acm_test();
}
