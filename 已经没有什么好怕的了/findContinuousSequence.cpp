/*
Day2
剑指 Offer 57 - II. 和为s的连续正数序列

输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。


示例 1：
输入：target = 9
输出：[[2,3,4],[4,5]]

示例 2：
输入：target = 15
输出：[[1,2,3,4,5],[4,5,6],[7,8]] 

限制：
1 <= target <= 10^5
*/

/*
滑动窗口的O（N）
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution_v1 {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		//滑动窗口
		//从左边加到右边，如果值小于t，继续往右加，如果值大于t，则去掉最左边的值，等于则添加到最终结果里
		vector<vector<int>> ret;
		int sum = 0;
		vector<int> tmp;
		for (int i = 1; i < target;) {
			sum += i;
			if (sum < target) {
				tmp.push_back(i);
				++i;
			}
			else if (sum > target) {
				sum -= tmp[0];
				tmp.erase(tmp.begin());
				sum -= i;
			}
			else {
				tmp.push_back(i);
				ret.push_back(tmp);
				++i;
			}
		}
		return ret;
	}

	void show_vec(vector<int>& vec) {
		if (vec.empty()) {
			return;
		}
		for (auto v : vec) {
			cout << v << " ";
		}
		cout << endl;
	}
};

class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		//滑动窗口改进
		vector<vector<int>> ret;
		//int sum = 0;
		vector<int> tmp;
		for (int i = 1, j = 2; i < j;) {
			int sum = (i + j) * (j - i + 1) / 2;
			if (sum == target) {
				tmp.clear();
				for (int left = i; left <= j; ++left) {
					tmp.emplace_back(left);
				}
				ret.emplace_back(tmp);
				++i;
			}
			else if (sum < target) {
				++j;
			}
			else {
				++i;
			}
		}
		return ret;
	}
};

int main() {
	Solution solu;
	vector<vector<int>> res;
	res = solu.findContinuousSequence(9);
	for (auto i : res) {
		for (int j = 0; j < i.size(); ++j) {
			cout << i[j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
