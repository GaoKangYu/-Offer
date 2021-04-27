/*
剑指 Offer 36. 二叉搜索树与双向链表

输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。

为了让您更好地理解问题，以下面的二叉搜索树为例：

我们希望将这个二叉搜索树转化为双向循环链表。链表中的每个节点都有一个前驱和后继指针。

对于双向循环链表，第一个节点的前驱是最后一个节点，最后一个节点的后继是第一个节点。

下图展示了上面的二叉搜索树转化成的链表。“head” 表示指向链表中有最小元素的节点。

特别地，我们希望可以就地完成转换操作。当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继。

还需要返回链表中的第一个节点的指针。
*/

/*
思路
*/

#include <iostream>
#include <vector>

using namespace std;

struct Node{
	int val;
	Node* left;
	Node* right;
	Node() {}
	Node(int x) : val(x), left(NULL), right(NULL) { }
	Node(int x, Node* _left, Node* _right) : val(x), left(_left), right(_right) { }
};

class Solution {
public:
	Node* pre;
	Node* head = new Node();
	Node* treeToDoublyList(Node* root) {
		//二叉搜索树的性质：中序遍历为递增序列，因此，需要在中序遍历的过程中实现指针的转向
		if (!root) {
			return nullptr;
		}
		dfs(root);
		//左指针指向前驱，右指针指向后继
		//head指向头结点，此时的pre为导致递归结束的空节点的前一个，即尾结点，头结点的前驱为尾结点
		head->left = pre;
		//尾结点的右指针指向后继节点，即头结点，尾结点的后继为头结点
		pre->right = head;
		return head;
	}

	void dfs(Node* cur) {
		//递归结束条件，遍历到空节点
		if (!cur) {
			return;
		}
		//中序遍历，左中右
		dfs(cur->left);
		//cur节点的前驱节点不为空，那么把前驱节点的后继节点（右指针）指向当前节点
		if (pre != NULL) {
			pre->right = cur;
		}
		//pre存当前节点的左指针，即前驱节点，如果前驱节点为空则代表为头结点
		else {
			head = cur;
		}
		//当前节点的前驱节点为pre
		cur->left = pre;
		//继续递归，当前节点为新的前驱节点
		pre = cur;
		dfs(cur->right);
	}
};

int main() {
	//4 2 5 1 3
	Node* root = new Node(4);
	Node* _1_left = new Node(2);
	Node* _1_right = new Node(5);
	Node* _2_left_1 = new Node(1);
	Node* _2_right_1 = new Node(3);

	root->left = _1_left;
	root->right = _1_right;
	_1_left->left = _2_left_1;
	_1_left->right = _2_right_1;

	Solution solu;
	//左指针前驱，右指针后继
	Node* res = solu.treeToDoublyList(root);
	int size = 5;
	while (size){
		cout << res->val << " ";
		res = res->right;
		--size;
	}
}
