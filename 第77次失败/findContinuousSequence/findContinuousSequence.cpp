/*
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
感觉周四面试会问DFS，这个题目看起来也像DFS
好了，现在感觉不是了
像滑动窗口，因为有 连续 的要求
优化的方向在于如何基于当前窗口进行缩减，而不是直接从一个个遍历，尽可能减少时间复杂度
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		int sum = 0;
		vector<vector<int>> ret;
		vector<int> tmp;
		for (int i = 1; i < target; ++i) {
			sum += i;
			tmp.push_back(i);
			while (sum > target) {
				sum -= tmp[0];
				tmp.erase(tmp.begin());
			}
			if (sum == target) {
				ret.push_back(tmp);
			}
		}
		return ret;
	}

	void print_result(vector<vector<int>> result) {
		printf("[");
		for (int i = 0; i < result.size(); ++i){
			printf("[");
			for (int j = 0; j < result[i].size(); ++j){
				printf("%d", result[i][j]);
				if (j != result[i].size() - 1){
					printf(",");
				}
			}
			printf("]");
			if (i != result.size() - 1) {
				printf(",");
			}
		}
		printf("]\n");
	}

};

int main(){
	Solution solu;
	int val;
	vector<vector<int>> result;
	while (scanf_s("%d", &val) != 0){
		result = solu.findContinuousSequence(val);
		solu.print_result(result);
	}
}

