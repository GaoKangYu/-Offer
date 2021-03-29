/*
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
#include <stack>

using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
	vector<int> reversePrint(ListNode* head) {
		//最简单的不过把所有val压入stack，然后倒入vector，但这样就是O(n)+O(n)，可以一次遍历吗？
		//算了先看看这样的效率，暂时没有别的想法
		stack<int> tmp;
		while (head){
			tmp.push(head->val);
			head = head->next;
		}
		vector<int> ret;
		while (!tmp.empty()){
			ret.push_back(tmp.top());
			tmp.pop();
		}
		return ret;
	}
	//好麻烦。。
	ListNode* build_list_node() {
		int length;
		printf("Input nodes amount:");
		scanf_s("%d", &length);
		//生成一个结点
		ListNode *head = NULL;
		printf("Input nodes value, ended by 'enter'.\n");
		for (int i = 0; i < length; i++)
		{
			ListNode *p = (ListNode *)malloc(sizeof(ListNode));
			scanf_s("%d", &p->val);
			p->next = NULL;
			ListNode *last = head;
			if (last)
			{
				//如果第一个结点不为空
				while (last->next)
				{
					last = last->next;
				}
				last->next = p;
			}
			else
			{
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
		while (cur){
			printf("%d", cur->val);
			if (cur->next != nullptr){
				printf(",");
			}
			cur = cur->next;
		}
		printf("]\n");
	}

	void output_print(vector<int> output) {
		printf("Output ListNode:");
		printf("[");
		for (int i = 0; i < output.size();++i) {
			printf("%d", output[i]);
			if (i != output.size() - 1){
				printf(",");
			}
		}
		printf("]\n");
	}
};

int main(){
	Solution solu;
	//处理输入输出
	//build ListNode
	ListNode* input;
	input = solu.build_list_node();
	vector<int> output = solu.reversePrint(input);
	solu.output_print(output);
}

