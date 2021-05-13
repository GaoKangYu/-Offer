/*
Day2
剑指 Offer 25. 合并两个排序的链表

输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

示例1：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
限制：

0 <= 链表长度 <= 1000
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

class Solution_v1 {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		//直面
		//需要考虑的东西有很多，下一个就做链表相加吧
		//边界条件
		if (!l1) {
			return l2;
		}
		if (!l2) {
			return l1;
		}
		//一般情况，两个链表都有值
		ListNode* ret;
		if (l1->val < l2->val) {
			ret = l1;
			ret->next = mergeTwoLists(l1->next, l2);
		}
		else {
			ret = l2;
			ret->next = mergeTwoLists(l1, l2->next);
		}
		return ret;
	}
};

//递归优化为迭代
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* ret = new ListNode(-1);
		ListNode* head = ret;
		while (l1 != nullptr && l2 != nullptr) {
			if (l1->val < l2->val) {
				head->next = l1;
				l1 = l1->next;
			}
			else {
				head->next = l2;
				l2 = l2->next;
			}
			head = head->next;
		}
		head->next = l1 == nullptr ? l2 : l1;
		return ret->next;
	}
};

int main() {
	//注意链表里别用!node，这个是有歧义的
}
