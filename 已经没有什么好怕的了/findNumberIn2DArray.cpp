/*
Day2
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

class Solution {
public:
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		//线性查找，可以，新的方法
		if (matrix.empty() || matrix[0].empty()) {
			return false;
		}
		int rows = matrix.size() - 1;
		int columns = matrix[0].size() - 1;
		//从右上角开始找起
		int row = 0;
		while (columns >= 0 && row <= rows) {
			//相等则找到
			if (matrix[row][columns] == target) {
				return true;
			}
			//比目标小则排除当前值上面的值，因为上面的值都比目标小
			else if (matrix[row][columns] < target) {
				++row;
			}
			//比目标大则排除当前值右边的值，因为右边的值都比目标大
			else {
				--columns;
			}
		}
		return false;
	}
};

int main() {
	Solution solu;
	int target = 4;
	vector<vector<int>> input{ {1,2,3},{4,5,6},{7,8,9} };
	cout << solu.findNumberIn2DArray(input, target) << endl;
}
