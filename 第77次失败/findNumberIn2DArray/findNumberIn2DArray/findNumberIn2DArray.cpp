/*
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
关键在于
“每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序”
通常而言，最暴力的解法是全遍历，那么复杂度O(n*m)，根据此条件可优化如下：
缩小搜索范围
找出符合条件的行i和j，符合条件的列k和l
符合条件的搜索行为：
当某行的左值小于等于target且右值大于等于之时，需要搜索，
但是这样存在 不好明确结束条件 的问题
于是，需要率先定位一个区域，四个点：
先按行搜索到matrix[i][0]<=target<=matrix[j][0]，其中如果遍历到bottom还没找到j，直接把bottom当做j
得到i和j，如果直接从i和j开始遍历，就是O(n+m)
进一步地，利用k和l，缩小i与j的范围，如果matrix[i][m-1]<target，当前i++
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0 || matrix[0].size() == 0) {
			return false;
		}
		//先按行搜索到matrix[i][0]<=target<=matrix[j][0]，其中如果遍历到bottom还没找到j，直接把bottom当做j
		//行
		int row = matrix.size();
		//列
		int col = matrix[0].size();
		int start, end = row - 1;
		for (int i = 0; i < row; ++i) {
			if (matrix[i][0] == target) {
				return true;
			}
			else if (matrix[i][0] < target) {
				if (matrix[i][col - 1] == target) {
					return true;
				}
				else if (matrix[i][col - 1] > target) {
					start = i;
					break;
				}
			}
		}
		//找end
		for (int i = start; i < row; ++i) {
			if (matrix[i][0] > target) {
				end = i;
			}
		}
		//从start到end，找目标值
		for (int i = start; i <= end; ++i) {
			for (int j = 0; j < col; ++j) {
				if (matrix[i][j] == target) {
					return true;
				}
			}
		}
		return false;
	}
};

int main(){
	std::cout << "Hello World!\n";
}

