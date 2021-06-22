/*
Day3
剑指 Offer 04. 二维数组中的查找

在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

示例:

现有矩阵 matrix 如下：

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。
给定 target = 20，返回 false。

限制：
0 <= n <= 1000
0 <= m <= 1000
*/

/*
思路
*/

#include <iostream>
#include <vector>

using namespace std;

/*
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
  target == 16
*/

class Solution {
public:
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		//右上角往其他方向找
		int right = matrix[0].size() - 1;
		int up = 0;
		while (right >= 0 && up < matrix.size())
		{
			if (target > matrix[up][right]) {
				++up;
			}
			else if (target < matrix[up][right]) {
				--right;
			}
			else
			{
				return true;
			}
		}
		return false;
	}
};

int main() {
	Solution solu;
	vector<vector<int> > input{ 
		{1,   4,  7, 11, 15},	
	{2,   5,  8, 12, 19},
	{3,   6,  9, 16, 22 },							
	{10, 13, 14, 17, 24},
	{18, 21, 23, 26, 30 }
};
	int target = 22;
	cout << solu.findNumberIn2DArray(input, target) << endl;
}
