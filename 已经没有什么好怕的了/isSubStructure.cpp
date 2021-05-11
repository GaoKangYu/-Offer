/*
Day2

剑指 Offer 26. 树的子结构

输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)

B是A的子结构， 即 A中有出现和B相同的结构和节点值。

例如:
给定的树 A:

     3
    / \
   4   5
  / \
 1   2
给定的树 B：

   4 
  /
 1
返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。

示例 1：

输入：A = [1,2,3], B = [3,1]
输出：false
示例 2：

输入：A = [3,4,5,1,2], B = [4,1]
输出：true
*/

/*
思路
*/

#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	bool isSubStructure(TreeNode* A, TreeNode* B) {
		//如果其中有空树，直接返回false
		if (!A || !B) {
			return false;
		}
		bool res;
		//如果匹配到了一个值，则进入匹配函数
		if (A->val == B->val) {
			res = doesAHaveB(A, B);
		}
		//如果不匹配，往左找匹配的值
		if (!res) {
			res = isSubStructure(A->left, B);
		}

		//如果不匹配，往右找匹配的值
		if (!res) {
			res = isSubStructure(A->right, B);
		}
		return res;
	}

	bool doesAHaveB(TreeNode* A, TreeNode* B) {
		//如果B已经遍历完了
		if (!B) {
			return true;
		}
		//如果A已经遍历完了但B还有多的，不匹配
		if (!A && B) {
			return false;
		}
		//如果值不等，不匹配
		if (A->val != B->val) {
			return false;
		}
		//否则继续匹配左右
		return doesAHaveB(A->left, B->left) && doesAHaveB(A->right, B->right);
	}
};

int main() {

}
