/*
剑指 Offer 52. 两个链表的第一个公共节点

输入两个链表，找出它们的第一个公共节点。

示例1：
输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
输出：Reference of the node with value = 8
输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。
从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。

示例2：
输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
输出：Reference of the node with value = 2
输入解释：相交节点的值为 2 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。
在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。

示例3：
输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
输出：null
输入解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
解释：这两个链表不相交，因此返回 null。
 
注意：
如果两个链表没有交点，返回 null.
在返回结果后，两个链表仍须保持原有的结构。
可假定整个链表结构中没有循环。
程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
*/

/*
。。？？？

输入描述过于模糊了吧。。
根本就没输入辅助信息skipA skipB或者intersectVal、、、

我们使用两个指针 node1，node2 分别指向两个链表 headA，headB 的头结点，然后同时分别逐结点遍历，
当 node1 到达链表 headA 的末尾时，重新定位到链表 headB 的头结点；
当 node2 到达链表 headB 的末尾时，重新定位到链表 headA 的头结点。
这样，当它们相遇时，所指向的结点就是第一个公共结点。

神乎其技

*/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode* node1 = headA;
		ListNode* node2 = headB;
		while (node1 != node2){
			node1 = (node1 != NULL ? node1 = node1->next : headB);
			node2 = (node2 != NULL ? node2 = node2->next : headA);
		}
		return node1;
	}

	//感觉经常忽略了 节点 这个概念
	ListNode* build_ListNode() {
		int length;
		printf("Input nodes amount:");
		scanf_s("%d", &length);
		//生成一个结点
		ListNode *head = NULL;
		printf("Input nodes value, ended by 'enter'.\n");
		for (int i = 0; i < length; i++){
			ListNode *p = (ListNode *)malloc(sizeof(ListNode));
			scanf_s("%d", &p->val);
			p->next = NULL;
			ListNode *last = head;
			if (last){
				//如果第一个结点不为空
				while (last->next){
					last = last->next;
				}
				last->next = p;
			}
			else{
				//只有头指针，整个链表中没结点，则把头指针指向新生成的p结点
				head = p;
			}
		}
		print_bulit_list_node(head);
		return head;
	}


	void print_bulit_list_node(ListNode* built_list_node) {
		printf("Input ListNode:");
		printf("[");
		ListNode* cur = built_list_node;
		while (cur) {
			printf("%d", cur->val);
			if (cur->next != nullptr) {
				printf(",");
			}
			cur = cur->next;
		}
		printf("]\n");
	}

};

int main(){
	Solution solu;
	ListNode *headA = solu.build_ListNode();
	ListNode *headB = solu.build_ListNode();
	ListNode *result = solu.getIntersectionNode(headA, headB);
	printf("result is : %d", result->val);
}

