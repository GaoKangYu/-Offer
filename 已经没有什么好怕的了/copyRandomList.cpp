/*
Day2
剑指 Offer 35. 复杂链表的复制

请实现 copyRandomList 函数，复制一个复杂链表。
在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。

提示：
-10000 <= Node.val <= 10000
Node.random 为空（null）或指向链表中的节点。
节点数目不超过 1000 。
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
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};

class Solution {
public:
	Node* copyRandomList(Node* head) {
		//先原地拷贝，再分离，最后返回
		//首先，原地复制值
		if (!head) {
			return NULL;
		}
		Node* cur = head;
		while (cur) {
			Node* copy_node = new Node(cur->val);
			Node* next = cur->next;
			cur->next = copy_node;
			copy_node->next = next;
			cur = next;
		}
		//至此完成了原地的值的复制
		//开始原地复制random指针
		cur = head;
		while (cur) {
			Node* copy_node = cur->next;
			if (cur->random != NULL) {
				copy_node->random = cur->random->next;
			}
			else {
				copy_node->random = NULL;
			}
			cur = copy_node->next;
		}
		//至此完成了random指针的复制
		//开始分离
		Node* ret = head->next;
		cur = head;
		while (cur->next->next) {
			//恢复原始链表，分离拷贝链表
			Node* copy_node = cur->next;
			Node* origin_node = copy_node->next;
			cur->next = origin_node;
			copy_node->next = origin_node->next;
			cur = origin_node;
		}
		cur->next = NULL;
		return ret;
	}
};

int main() {

}
