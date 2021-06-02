/*
Day3
剑指 Offer 36. 二叉搜索树与双向链表

输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。
要求不能创建任何新的节点，只能调整树中节点指针的指向。
*/

/*
着眼双向链表
*/

#include <iostream>
#include <vector>

using namespace std;

struct Node{
	int val;
	Node* left;
	Node* right;

	Node(){ }
	Node(int _val) : val(_val), left(NULL), right(NULL){ }
	Node(int _val, Node* _left, Node* _right) : val(_val), left(_left), right(_right){ }
};

class Solution {
public:
	Node* treeToDoublyList(Node* root) {
		if (!root) {
			return NULL;
		}
		treeToDoublyListCore(root);
		//首尾相连
		head->left = pre;
		pre->right = head;
		return head;
	}

	void treeToDoublyListCore(Node* cur) {
		if (!cur) {
			return;
		}
		//中序遍历
		//实际的逻辑是，当前节点的左指针指向前一节点，前一节点的右指针指向当前节点
		treeToDoublyListCore(cur->left);
		if (pre != NULL) {
			pre->right = cur;
			cur->left = pre;
		}
		//如果找到了头结点，直接赋值给头结点
		else {
			head = cur;
		}
		pre = cur;
		treeToDoublyListCore(cur->right);
	}

	void showResult(Node* input) {

	}

private:
	Node* pre = new Node();
	Node* head = new Node();
};

int main() {
	Node* head = new Node(4);
	Node* _1_left = new Node(2);
	Node* _1_right = new Node(5);
	Node* _2_left = new Node(1);
	Node* _2_right = new Node(3);

	head->left = _1_left;
	head->right = _1_right;
	_1_left->left = _2_left;
	_1_left->right = _2_right;

	Solution solu;
	solu.treeToDoublyList(input);
	head = head->right;
	while (true) {
		cout << head->val << " ";
		head = head->right;
	}
	cout << endl;
}
