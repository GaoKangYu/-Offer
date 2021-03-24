/*
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
顺序遍历不断缩小上下左右的值即可
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.size() == 0 || matrix[0].size() == 0) {
			return {};
		}
		int top = 0;
		int right = matrix[0].size() - 1;
		int bot = matrix.size() - 1;
		int left = 0;
		vector<int> ret;
		while (top <= bot && left <= right) {
			//当前上，左-->右，注意边界
			//matrix[top][left->right],遍历完整行
			for (int i = left; i <= right; ++i) {
				ret.push_back(matrix[top][i]);
			}
			//当前右，上-->下，注意边界
			//matrix[top-bot][right]，不含matrix[top][right]
			for (int i = top + 1; i <= bot; ++i) {
				ret.push_back(matrix[i][right]);
			}
			//如果剩下的还大于一行
			if (left < right && top < bot) {
				//当前下，右-->左，注意边界
				//matrix[bot][right->left]，不含matrix[bot][right]
				for (int i = right - 1; i >= left; --i) {
					ret.push_back(matrix[bot][i]);
				}
				//当前左，下-->上，注意边界
				//matrix[bot->top][left]，不含matrix[bot][left]和matrix[top][left]
				for (int i = bot - 1; i > top; --i) {
					ret.push_back(matrix[i][left]);
				}
			}
			//上下左右缩小范围
			++top;
			--right;
			++left;
			--bot;
		}
		return ret;
	}
};

int main()
{
	std::cout << "Hello World!\n";
}

