/*
Day3
剑指 Offer 13. 机器人的运动范围

地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。
一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。
例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。
但它不能进入方格 [35, 38]，因为3+5+3+8=19。
请问该机器人能够到达多少个格子？


示例 1：
输入：m = 2, n = 3, k = 1
输出：3

示例 2：
输入：m = 3, n = 1, k = 0
输出：1

提示：
1 <= n,m <= 100
0 <= k <= 20
*/

/*
dfs
加油
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int movingCount(int m, int n, int k) {
		dfs(m, n, k, 0, 0);
		return count;
	}
	//
	void dfs(int m, int n, int k, int x, int y) {
		//边界检测，机器人不能越过方阵边界，重复格子不计算
		if (y < 0 || y >= n || x < 0 || x >= m || visit[x][y])
		{
			return;
		}
		//限制条件，格子位数和小于k
		int sum = 0;
		int tmp_x = x;
		int tmp_y = y;
		while (tmp_x || tmp_y)
		{
			sum += tmp_x % 10 + tmp_y % 10;
			tmp_x /= 10;
			tmp_y /= 10;
		}
		if (sum > k)
		{
			return;
		}
		//能够到达这个格子，计数加一
		++count;
		visit[x][y] = 1;
		//继续向四个方向搜索
		dfs(m, n, k, x + 1, y);
		//dfs(m, n, k, x - 1, y);
		dfs(m, n, k, x, y + 1);
		//dfs(m, n, k, x, y - 1);
		return;
	}

private:
	int count = 0;
	int visit[100][100]{ 0 };
};

int main() {
	
}
