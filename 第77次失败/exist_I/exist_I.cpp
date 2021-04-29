/*
剑指 Offer 12. 矩阵中的路径

给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
*/

/*
思路
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (word.empty()) return false;
		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[0].size(); ++j)
			{
				// 使用回溯法解题
				if (dfs(board, word, i, j, 0)) return true;
			}
		}
		return false;
	}
	bool dfs(vector<vector<char>>& board, string& word, int i, int j, int w)
	{
		// 如果索引越界，或者值不匹配，返回false
		if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[w]) return false;
		if (w == word.length() - 1) return true;
		char temp = board[i][j];
		board[i][j] = '\0'; // 将当前元素标记为'\0'，即一个不可能出现在word里的元素，表明当前元素不可再参与比较
		if (dfs(board, word, i - 1, j, w + 1)
			|| dfs(board, word, i + 1, j, w + 1)
			|| dfs(board, word, i, j - 1, w + 1)
			|| dfs(board, word, i, j + 1, w + 1))
		{
			// 当前元素的上下左右，如果有匹配到的，返回true
			return true;
		}
		board[i][j] = temp; // 将当前元素恢复回其本身值
		return false;
	}
};


int main() {
	std::cout << "Hello World!\n";
}
