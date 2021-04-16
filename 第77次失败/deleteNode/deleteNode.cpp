/*
剑指 Offer 18. 删除链表的节点

给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
返回删除后的链表的头节点。

示例 1:
输入: head = [4,5,1,9], val = 5
输出: [4,1,9]
解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.

示例 2:
输入: head = [4,5,1,9], val = 1
输出: [4,5,9]
解释: 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.
 
说明：
题目保证链表中节点的值互不相同
若使用 C 或 C++ 语言，你不需要 free 或 delete 被删除的节点
*/

/*
三种情况
删除头结点
删除中间节点
删除尾结点
因此需要定义一个额外空节点
*/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode() : val(0), next(NULL){}
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteNode(ListNode* head, int val) {
		ListNode *cur = head;
		ListNode* pre = new ListNode;
		//一步步来，先考虑最简单的，删除中间节点，当前前一个节点连接当前后一个节点即可
		while (cur){
			if (head->val == val) {
				head = head->next;
				return head;
			}
			if (cur->val == val) {
				pre->next = cur->next;
				return head;
			}
			pre = cur;
			cur = cur->next;
		}
		return head;
	}
};

int main() {
	//把链表刻进DNA
	Solution solu;
	ListNode* head = new ListNode(4);
	ListNode* node_1 = new ListNode(5);
	head->next = node_1;
	ListNode* node_2 = new ListNode(1);
	node_1->next = node_2;
	ListNode* node_3 = new ListNode(9);
	node_2->next = node_3;
	node_3->next = nullptr;

	ListNode* result = solu.deleteNode(head, 9);
	while (result){
		cout << result->val<<" ";
		result = result->next;
	}

}
