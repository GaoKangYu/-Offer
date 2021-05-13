/*
Day2
题目描述
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

//两次循环，需统计长度
class Solution_v1 {
public:
	ListNode* getKthFromEnd(ListNode* head, int k) {
		//先统计长度
		int length = 0;
		ListNode* cur = head;
		while (cur) {
			++length;
			cur = cur->next;
		}
		while (length - k) {
			head = head->next;
			--length;
		}
		return head;
	}
};

class Solution {
public:
	//双指针，无需统计长度
	ListNode* getKthFromEnd(ListNode* head, int k) {
		ListNode* slow = head;
		ListNode* fast = head;
		while (k){
			fast = fast->next;
			--k;
		}
		while (fast){
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
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

	ListNode* res = solu.getKthFromEnd(node_0, 3);
	while (res){
		cout << res->val << " ";
		res = res->next;
	}
	cout << endl;
	delete node_0;
	delete node_1;
	delete node_2;
	delete node_3;
	delete node_4;
}
