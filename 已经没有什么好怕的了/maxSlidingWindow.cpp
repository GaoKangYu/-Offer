/*
Day2
剑指 Offer 59 - I. 滑动窗口的最大值

给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。

示例:

输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7]
解释:

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 

提示：
你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。
*/

/*
思路
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


//直接模拟，暴力法
class Solution_v1 {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		//大根堆，容量为k，解决获取每个滑动窗口的最大值的问题
		//感觉还好，也不用大根堆，使用常数维护
		int len = nums.size();
		if (nums.empty()) {
			return {};
		}
		int left = 0;
		int right = k;
		vector<int> ret;
		while (right <= len) {
			int max_val = INT_MIN;
			for (int i = left; i < right; ++i) {
				max_val = max(max_val, nums[i]);
			}
			ret.emplace_back(max_val);
			++left;
			++right;
		}
		return ret;
	}
};

//使用双端队列
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		if (nums.empty() || k > nums.size() || k <= 0) {
			return {};
		}
		vector<int> res;
		deque<int> findMax;
		for (int i = 0; i < nums.size(); ++i) {
			// i 每加一次，代表滑动窗口向右移一个单位。
			// i 指向的是每个滑动窗口的尾部元素（从 i = k - 1 开始）。

			if (i >= k && !findMax.empty()) {
				// i >= k 是为了确保 findMax.front() 至少为第一个完整的滑动窗口的最大值索引。
				// 即至少形成了一个完整的滑动窗口。
				res.push_back(nums[findMax.front()]);
			}

			while (!findMax.empty() && nums[i] >= nums[findMax.back()]) {
				// 如果新进来的 nums[i] 大于等于滑动窗口的尾部元素，
				// 说明该尾部元素肯定不会是任何滑动窗口的最大元素。
				findMax.pop_back();
			}

			if (!findMax.empty() && i - findMax.front() >= k) {
				// 虽然 findMax 的头部是最大的元素的索引，但是如果当前滑动窗口已不包括该索引，
				// 那么需要弹出该索引。
				findMax.pop_front();
			}

			findMax.push_back(i);
		}

		res.push_back(nums[findMax.front()]); // 最后一个滑动窗口还没计算就退出了 for 循环，需补上。

		return res;
	}
};

//vec空间优化
class Solution_v3 {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		if (nums.empty()) {
			return {};
		}
		//首先是可以推出返回vec长度的
		int len = nums.size();
		vector<int> ret(len - k + 1);
		//为什么不使用优先队列？因为滑动窗口滑过一个最大值后，因为无法及时弹出前面的值，会影响到后面的最大值选取
		//那么选择双端队列，如果压入值是最大值，则从队左一直弹出，维护队首为最大值
		//否则一直压入
		//抛开初始化处理，每次都是比较新压入值和队首元素的值的大小，如果小，那么当前窗口的最大值还是队首元素，大于等于则弹出所有元素，更新队首元素
		//如果滑动窗口滑过了最大值，也需要把它弹出，这个滑出与否，最大值索引当前下标i - idx >= k，则弹出最大值
		deque<int> dq;
		int j = 0;
		for (int i = 0; i < len; ++i) {
			//确保形成了窗口后再添加元素
			if (i >= k && !dq.empty()) {
				ret[j] = nums[dq.front()];
				++j;
			}
			//队列不为空且新加入的值大于队尾元素，那么说明当前队尾不会成为当前窗口的最大值
			while (!dq.empty() && nums[i] >= nums[dq.back()]) {
				dq.pop_back();
			}
			//队列不为空且当前窗口已经滑过了队首元素
			if (!dq.empty() && i - dq.front() >= k) {
				dq.pop_front();
			}
			dq.push_back(i);
		}
		//添加最后一个元素
		ret[j] = nums[dq.front()];
		return ret;
	}
};

int main() {
	Solution solu;

}
