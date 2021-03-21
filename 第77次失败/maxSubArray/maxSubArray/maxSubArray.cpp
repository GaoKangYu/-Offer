/*
maxSubArray.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
*/

/*
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
连续子数组，滑动窗口？，但窗口宽度和滑动依据不好确定
滑动窗口不行的时候，很有可能动态规划
n？
dp[j,i]是从下标i到下标j的和,i<j
dp[j,i] = dp[j] - dp[i]
获得了dp数组后，排序最大的减最小的？
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;


class Solution {
public:
	//完整格式版动态规划
	int maxSubArray(vector<int>& nums) {
		vector<int> dp(nums.size());
		dp[0] = nums[0];
		int ret = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			dp[i] = max(dp[i - 1] + nums[i], nums[i]);
			ret = max(dp[i], ret);
		}
		return ret;
	}
};

class Solution_better {
public:
	//改进版
	//动态规划，原地修改数组
	int maxSubArray(vector<int>& nums) {
		int maxnum = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i - 1] > 0) {
				nums[i] += nums[i - 1];
			}
			maxnum = max(maxnum, nums[i]);
		}
		return maxnum;
	}
};

int main()
{
	std::cout << "Hello World!\n";
}

