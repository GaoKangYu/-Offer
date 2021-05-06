/*
Day2
剑指 Offer 42. 连续子数组的最大和

输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。

要求时间复杂度为O(n)。

 

示例1:
输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 
提示：
1 <= arr.length <= 10^5
-100 <= arr[i] <= 100
*/

/*
动态规划
dp[i] = max(nums[i], dp[i-1]+nums[i]);

然后再优化为滚动数组
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution_v1 {
public:
	int maxSubArray(vector<int>& nums) {
		//出错的根本在于状态转移方程错误
		//连续，代表必须加这个数或者这个数单独成为一个子数组
		//dp[i]=max(dp[i-1]+nums[i], nums[i])
		int n = nums.size();
		vector<int> dp(n);
		dp[0] = nums[0];
		int ret = -100;
		ret = max(ret, dp[0]);
		for (int i = 1; i < n; ++i) {
			dp[i] = max(dp[i - 1] + nums[i], nums[i]);
			ret = max(ret, dp[i]);
		}
		return ret;
	}
};

//优化掉dp数组，将空间复杂度降低至O（1）
class Solution_v2 {
public:
	int maxSubArray(vector<int>& nums) {
		//直接使用变量替代
		int pre = 0;
		int ret = -100;
		for (auto n : nums) {
			pre = max(pre + n, n);
			ret = max(ret, pre);
		}
		return ret;
	}

	void acm() {
		int test_nums;
		cin >> test_nums;
		while (test_nums){
			int val;
			vector<int> input;
			while (cin >> val){
				input.push_back(val);
				if (getchar() == '\n') {
					break;
				}
			}
			cout << "Res : " << maxSubArray(input) << endl;
			--test_nums;
		}
	}
};

//仍可以进一步优化，直接修改数组本身
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		//直接使用变量替代
		int ret = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			nums[i] += max(nums[i - 1], 0);
			ret = max(ret, nums[i]);
		}
		return ret;
	}

	void acm() {
		int test_nums;
		cin >> test_nums;
		while (test_nums) {
			int val;
			vector<int> input;
			while (cin >> val) {
				input.push_back(val);
				if (getchar() == '\n') {
					break;
				}
			}
			cout << "Res : " << maxSubArray(input) << endl;
			--test_nums;
		}
	}
};

int main() {
	Solution solu;
	solu.acm();
}
