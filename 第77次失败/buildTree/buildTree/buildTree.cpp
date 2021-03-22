/*
剑指 Offer 07. 重建二叉树

3

输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

例如，给出
前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：
	3
   / \
  9  20
	/  \
   15   7
 

限制：0 <= 节点个数 <= 5000
*/

/*
。。。是不熟悉的数据结构

前序是从根节点到子节点
中序：左子树，根节点，右子树
前序：根节点，左子树，右子树

只用一个遍历会产生歧义，那么，如何重建？
不含重复数字，可以尝试一次遍历，同时遍历两个vector，O(n)重建

怎么想都是递归教学
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
/*
前序遍历列表：第一个元素永远是 【根节点(root)】
中序遍历列表：根节点(root)【左边】的所有元素都在根节点的【左分支】，【右边】的所有元素都在根节点的【右分支】
		
算法思路：
通过【前序遍历列表】确定【根节点(root)】
将【中序遍历列表】的节点分割成【左分支节点】和【右分支节点】
递归寻找【左分支节点】中的【根节点(left child)】和 【右分支节点】中的【根节点(right child)】
*/

class Solution {
private:
	unordered_map<int, int> index;

public:
	TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
		if (preorder_left > preorder_right) {
			return nullptr;
		}

		// 前序遍历中的第一个节点就是根节点
		int preorder_root = preorder_left;
		// 在中序遍历中定位根节点
		int inorder_root = index[preorder[preorder_root]];

		// 先把根节点建立出来
		TreeNode* root = new TreeNode(preorder[preorder_root]);
		// 得到左子树中的节点数目
		int size_left_subtree = inorder_root - inorder_left;
		// 递归地构造左子树，并连接到根节点
		// 先序遍历中「从 左边界+1 开始的 size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
		root->left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
		// 递归地构造右子树，并连接到根节点
		// 先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
		root->right = myBuildTree(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);
		return root;
	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int n = preorder.size();
		// 构造哈希映射，帮助我们快速定位根节点
		for (int i = 0; i < n; ++i) {
			index[inorder[i]] = i;
		}
		return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
	}
};

int main()
{
	std::cout << "Hello World!\n";
}

