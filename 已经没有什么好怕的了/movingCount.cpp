/*
Day2
剑指 Offer 13. 机器人的运动范围

地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。
一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。
例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

 
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
DFS与BFS

模板题，背下来
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int ans = 0;
	int vis[220][220] = { };

	int movingCount(int m, int n, int k) {
		dfs(n, m, k, 0, 0);
		return ans;
	}
	//形参：地图高、宽、限制条件k，起始点x坐标、y坐标
	void dfs(int n, int m, int k, int x, int y) {
		//边界条件1 2 3 ：x坐标超出边界0或m，y坐标超出边界n或0，该点已经走过了
		if (x < 0 || x >= m || y < 0 || y >= n || vis[x][y]) {
			return;
		}
		//边界条件4：计算该点的数位和
		int tmp = 0, x1 = x, y1 = y;
		while (x1) {
			tmp += (x1 % 10);
			x1 /= 10;
		}
		while (y1) {
			tmp += (y1 % 10);
			y1 /= 10;
		}
		//超过K也返回
		if (tmp > k) {
			return;
		}
		//每走一个点计数加一
		ans++;
		//标记此点已经走过
		vis[x][y] = 1;
		//四个方向探索
		dfs(n, m, k, x, y - 1);
		dfs(n, m, k, x, y + 1);
		dfs(n, m, k, x - 1, y);
		dfs(n, m, k, x + 1, y);
		return;
	}

	void acm() {
		int test_nums;
		cin >> test_nums;
		while (test_nums){
			int m, n, k;
			cin >> m >> n >> k;
			cout << "Res : " << movingCount(m, n, k) << endl;
			--test_nums;
		}
	}
};

int main() {
	Solution solu;
	solu.acm();
}
