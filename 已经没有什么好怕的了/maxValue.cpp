/*
Day2
剑指 Offer 47. 礼物的最大价值

在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。
你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。
给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？

示例 1:

输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 12
解释: 路径 1→3→5→2→1 可以拿到最多价值的礼物

提示：
0 < grid.length <= 200
0 < grid[0].length <= 200
*/

/*
思路
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxValue(vector<vector<int>>& grid) {
		//有dfs的思路，但dfs没有选择的思想
		//尝试二维dp
		//每次只能往右或者往下走，那么上一个点是往上或者往左
		//每一个点的值dp[i][j] = max(dp[i - 1][j] + gird[i][j], dp[i][j - 1] + grid[i][j])
		//直接修改grid的值？
		//可以
		int n = grid.size();
		int m = grid[0].size();
		//vector<vector<int>> dp(n, vector<int>(m, 0));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				int left = 0;
				int up = 0;
				if (i > 0) {
					left = grid[i - 1][j];
				}
				if (j > 0) {
					up = grid[i][j - 1];
				}
				grid[i][j] = max(left, up) + grid[i][j];
			}
		}
		return grid[n - 1][m - 1];
	}

};

int main() {
	Solution solu;
	vector<vector<int>> input{ {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	cout << "MaxValue : " << solu.maxValue(input) << endl;
}
