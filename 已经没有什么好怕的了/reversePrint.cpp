/*
Day2
剑指 Offer 06. 从尾到头打印链表

输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

 

示例 1：

输入：head = [1,3,2]
输出：[2,3,1]
 

限制：
0 <= 链表长度 <= 10000
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
	ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
	vector<int> reversePrint(ListNode* head) {
		//两个想法，统计链表长度反向插入
		//顺序插入然后反向数组
		//都需要遍历两次
		ListNode* cur = head;
		int n = 0;
		while (cur) {
			++n;
			cur = cur->next;
		}
		vector<int> ret(n);
		for (int i = n - 1; i >= 0; --i) {
			ret[i] = head->val;
			head = head->next;
		}
		return ret;
	}
};

int main() {
	ListNode* head = new ListNode(1);
	ListNode* node1 = new ListNode(2);
	ListNode* node2 = new ListNode(3);
	ListNode* node3 = new ListNode(4);

	head->next = node1;
	node1->next = node2;
	node2->next = node3;

	Solution solu;
	vector<int> res = solu.reversePrint(head);
	cout << "[";
	for (auto r : res) {
		cout << r << " ";
	}
	cout << "]" << endl;
}
