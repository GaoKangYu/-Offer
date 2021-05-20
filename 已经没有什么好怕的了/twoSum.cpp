/*
Day2
剑指 Offer 57. 和为s的两个数字

输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。

示例 1：
输入：nums = [2,7,11,15], target = 9
输出：[2,7] 或者 [7,2]

示例 2：
输入：nums = [10,26,30,31,47,60], target = 40
输出：[10,30] 或者 [30,10]
 

限制：
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^6
*/

/*
思路
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution_v1 {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		//二分
		int n = nums.size();
		for (int i = 0; i < n; ++i) {
			int left = i + 1;
			int right = n - 1;
			int _target = target - nums[i];
			if (semi_find(nums, left, right, _target)) {
				return vector<int>{nums[i], _target};
			}
		}
		return {};
	}

	bool semi_find(vector<int>& nums, int& left, int& right, int& target) {
		int start = left;
		int end = right;
		while (start <= end) {
			int mid = start + (end - start) / 2;
			if (nums[mid] == target) {
				return true;
			}
			else if (nums[mid] > target) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
		return false;
	}
};

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		//双指针
		int n = nums.size();
		int left = 0;
		int right = n - 1;
		while (left < right){
			int sum = nums[left] + nums[right];
			if (sum == target) {
				return vector<int> { nums[left], nums[right] };
			}
			else if(sum < target){
				++left;
			}
			else {
				--right;
			}
		}
		return { };
	}
};

int main() {

}
