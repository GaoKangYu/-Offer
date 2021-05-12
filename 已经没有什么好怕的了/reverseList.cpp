/*
Day2
剑指 Offer 24. 反转链表

定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

 

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
 

限制：
0 <= 节点个数 <= 5000
*/

/*
思路
*/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode() : val(0), next(NULL){ }
	ListNode(int x) : val(x), next(NULL) { }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		//容易丢失next节点，因此需要三个节点存
		ListNode* cur = head;
		ListNode* pre = nullptr;
		while (cur){
			ListNode* next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return pre;
	}
};

int main() {
	Solution solu;
	ListNode* node_0 = new ListNode(1);
	ListNode* node_1 = new ListNode(2);
	ListNode* node_2 = new ListNode(3);
	ListNode* node_3 = new ListNode(4);
	ListNode* node_4 = new ListNode(5);

	node_0->next = node_1;
	node_1->next = node_2;
	node_2->next = node_3;
	node_3->next = node_4;

	ListNode* res = solu.reverseList(node_0);
	while (res){
		cout << res->val << " ";
		res = res->next;
	}
	cout << endl;
}
