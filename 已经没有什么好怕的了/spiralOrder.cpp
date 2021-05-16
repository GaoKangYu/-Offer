/*
Day2
剑指 Offer 29. 顺时针打印矩阵

输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

 

示例 1：
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]

示例 2：
输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 

限制：
0 <= matrix.length <= 100
0 <= matrix[i].length <= 100
*/

/*
要细心，横向完全打印，纵向不打印两端
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) {
			return {};
		}
		int top = 0;
		int bot = matrix.size() - 1;
		int left = 0;
		int right = matrix[0].size() - 1;
		int n = (bot + 1) * (right + 1);
		vector<int> ret(n);
		int r = 0;
		while (r < n) {
			//从左上打印到右上，包含右上
			for (int i = left; i <= right; ++i) {
				ret[r] = matrix[top][i];
				++r;
				if (r == n) {
					break;
				}
			}
			if (r == n) {
				break;
			}
			//从右上打印到右下，不包括右下
			//m[0][right] --> m[bot][right]
			for (int i = top + 1; i < bot; ++i) {
				ret[r] = matrix[i][right];
				++r;
				if (r == n) {
					break;
				}
			}
			if (r == n) {
				break;
			}
			//从右下打印到左下，不包括左下，列的移动
			//m[bot][right] --> m[bot][left]
			for (int i = right; i >= left; --i) {
				ret[r] = matrix[bot][i];
				++r;
				if (r == n) {
					break;
				}
			}
			if (r == n) {
				break;
			}
			//从左下打印到左上，不包括左上
			for (int i = bot - 1; i > top; --i) {
				ret[r] = matrix[i][left];
				++r;

			}
			if (r == n) {
				break;
			}
			//缩小范围
			++left;
			--right;
			++top;
			--bot;
		}
		return ret;
	}
};

int main() {
	Solution solu;
	vector<vector<int>> input{ {1,2,3,4},{5,6,7,8}, {9,10,11,12}, {13,14,15,16} };
	vector<int> res = solu.spiralOrder(input);
	cout << "[";
	for (auto r : res) {
		cout << r << ", ";
	}
	cout << "]" << endl;
}
