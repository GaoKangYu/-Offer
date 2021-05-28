/*
Day2
剑指 Offer 07. 重建二叉树

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
 

限制：
0 <= 节点个数 <= 5000
*/

/*
思路
*/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(){ }
	TreeNode(int x) : val(x), left(NULL), right(NULL){ }
};

class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		//类似的还是递归的思路
		//距离，前序遍历，跟左右，中序遍历，左中右，
		//前序遍历 preorder = [3,9,20,15,7]
		//中序遍历 inorder = [9, 3, 15, 20, 7]
		//从前序遍历可知，3为根节点，从中序遍历可知，在3左侧的是左子树成员，右侧的是右子树成员
		//首先是判断特例，空序列直接返回
		if (preorder.empty()) {
			return NULL;
		}
		TreeNode* ret;
		ret = buildTreeCore(preorder, inorder, 0, preorder.size());
		return ret;
	}

	TreeNode* buildTreeCore(vector<int>& preorder, vector<int>& inorder, int left, int right) {
		if (index == preorder.size() || left == right) {
			return NULL;
		}
		TreeNode* head = NULL;
		for (int i = 0; i < right; ++i) {
			if (preorder[index] == inorder[i]) {
				head = new TreeNode(inorder[i]);
				++index;
				head->left = buildTreeCore(preorder, inorder, left, i);
				head->right = buildTreeCore(preorder, inorder, i + 1, right);
				break;
			}
		}
		return head;
	}
private:
	int index;
};

int main() {

}
