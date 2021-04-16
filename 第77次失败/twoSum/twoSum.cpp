/*
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
二分查找，超时了

双指针，最优解
要利用好条件，一定是这个递增数组中俩数的和，所以直接加，比较就好
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	vector<int> twoSum_better(vector<int>& nums, int target) {
		//双指针
		int pre = 0;
		int later = nums.size() - 1;
		while (pre < later) {
			int sum = nums[pre] + nums[later];
			if (sum == target) {
				return { nums[pre],nums[later] };
			}
			else if (sum > target) {
				--later;
			}
			else {
				++pre;
			}
		}
		return {};
	}

	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ret;
		for (int i = 0; i < nums.size(); ++i){
			int new_target = target - nums[i];
			if (find_new_target(nums, i, new_target)){
				ret.push_back(nums[i]);
				ret.push_back(new_target);
				return ret;
			}
		}
		return ret;
	}

	//实现从下标start开始的二分查找
	bool find_new_target(vector<int>& nums, int start, int new_target) {
		int n = nums.size() - 1;
		int end = n;
		for (int i = start; i < n; ++i){
			int mid = start + (end - start + 1) / 2;
			if (nums[mid] < new_target){
				start = mid;
			}
			else if (nums[mid] > new_target) {
				end = mid;
			}
			else{
				return true;
			}
		}
		return false;
	}

	vector<int> input_vec() {
		vector<int> input;
		int val;
		while (scanf_s("%d", &val)){
			input.push_back(val);
			if (getchar() == '\n'){
				break;
			}
		}
		fflush(stdin);
		return input;
	}

	int input_val() {
		int val;
		scanf_s("%d", &val);
		fflush(stdin);
		return val;
	}
};

int main() {
	Solution solu;
	vector<int> input = solu.input_vec();
	int target = solu.input_val();
	vector<int> res = solu.twoSum_better(input, target);
	cout << '[' << res[0] << ',' << res[1] << "] \n" << endl;
}
