/*
Day2
剑指 Offer 12. 矩阵中的路径

给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

例如，在下面的 3×4 的矩阵中包含单词 "ABCCED"（单词中的字母已标出）。
*/

/*
思路
*/

#include <iostream>
#include <vector>

using namespace std;


//dfs+回溯
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[0].size(); ++j) {
				if (dfs(board, word, i, j, 0)) {
					return true;
				}
			}
		}
		return false;
	}

	bool dfs(vector<vector<char>>& board, string& word, int i, int j, int w) {
		//边界条件：搜索到了边界或者值不匹配，返回false
		if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0 || word[w] != board[i][j]) {
			return false;
		}
		//如果已经找到了完整匹配，那么此时凑出了word的长度
		if (w == word.length() - 1) {
			return true;
		}
		//记录回溯点
		char tmp = board[i][j];
		//已经查找过的元素做标注
		board[i][j] = '\0';
		//四个方向查找
		if (dfs(board, word, i + 1, j, w + 1) || dfs(board, word, i - 1, j, w + 1) || dfs(board, word, i, j + 1, w + 1) || dfs(board, word, i, j - 1, w + 1)) {
			return true;
		}
		//如果没有匹配，回到起点
		board[i][j] = tmp;
		return false;
	}
};

int main() {

}
