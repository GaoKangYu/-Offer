/*
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

最简单的方法是大根堆，但是怎么想都会爆栈吧
...
虽然效率低，但是没爆。。。

一直有一个，双指针或者多指针的写法，仔细想想吧

窗口对应的数据结构为 双端队列 ，本题使用 单调队列 即可解决以上问题

新数据结构：单调队列
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		if (nums.empty()) {
			return {};
		}
		vector<int> ret;
		for (int start_index = 0; start_index + k <= nums.size(); ++start_index) {
			int i = start_index;
			int count = k;
			priority_queue<int> sliding_window;
			while (count) {
				sliding_window.push(nums[i]);
				++i;
				--count;
			}
			ret.push_back(sliding_window.top());
		}
		return ret;
	}

	vector<int> maxSlidingWindow_better(vector<int>& nums, int k) {
		vector<int> ans;
		deque<int> deq;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			while (!deq.empty() && nums[i] > nums[deq.back()]) {
				deq.pop_back();
			}
			if (!deq.empty() && deq.front() < i - k + 1) deq.pop_front();
			deq.push_back(i);
			if (i >= k - 1) ans.push_back(nums[deq.front()]);
		}
		return ans;
	}

	vector<int> input_vec() {
		vector<int> ret;
		int val;
		while (scanf_s("%d", &val)){
			ret.push_back(val);
			if (getchar() == '\n'){
				break;
			}
		}
		return ret;
	}

	int input_k() {
		int k;
		scanf_s("%d", &k);
		return k;
	}
};

int main() {
	Solution solu;
	vector<int> vec = solu.input_vec();
	int k = solu.input_k();
	vector<int> res = solu.maxSlidingWindow(vec, k);
	cout << '[' ;
	for (int i = 0; i < res.size(); ++i){
		cout << res[i];
		if (i < res.size() - 1) {
			cout << ',';
		}
	}
	cout << ']' << endl;
}

