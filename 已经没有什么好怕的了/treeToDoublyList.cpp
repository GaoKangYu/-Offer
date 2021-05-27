/*
Day2
剑指 Offer 36. 二叉搜索树与双向链表

输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。
*/

/*
思路
*/

#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
	int val;
	Node* left;
	Node* right;

	Node() {}

	Node(int _val) {
		val = _val;
		left = NULL;
		right = NULL;
	}

	Node(int _val, Node* _left, Node* _right) {
		val = _val;
		left = _left;
		right = _right;
	}
};


class Solution {
public:
	Node* treeToDoublyList(Node* root) {
		//变成一个排序的双向链表，那么需要在中序遍历的过程中完成这个过程
		//左指针指向小值，右指针指向大值
		if (!root) {
			return nullptr;
		}
		dfs(root);
		//头尾节点首位相连，此时的pre节点以及遍历到了尾结点
		head->left = pre;
		pre->right = head;
		return head;
	}

	void dfs(Node* cur) {
		if (!cur) {
			return;
		}
		//左中右
		dfs(cur->left);
		//其实应该把思路变成链表
		//前节点的右指针指向当前节点
		//当前节点的左指针指向前一节点
		//边界情况，如果前一节点为空，当前节点就是头结点
		//pre = cur维持遍历
		if (pre) {
			pre->right = cur;
		}
		else {
			head = cur;
		}
		cur->left = pre;
		pre = cur;
		dfs(cur->right);
	}

private:
	Node* pre;
	Node* head;
};

int main() {
	Solution solu;
	Node* head = new Node(1);
	solu.treeToDoublyList(head);
}
