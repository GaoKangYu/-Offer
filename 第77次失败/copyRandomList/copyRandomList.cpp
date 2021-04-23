/*
剑指 Offer 35. 复杂链表的复制

请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，
还有一个 random 指针指向链表中的任意节点或者 null。

输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
*/

/*
思路
*/

#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int val;
	Node* next;
	Node* random;
	int random_idx;
	Node(int x) : val(x), next(NULL), random(NULL), random_idx(-1) { }
};

class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (!head) {
			return { };
		}
		//虽然不知道他要我干嘛。。
		//没关系的，没关系的，会做的努力做，不会做的看懂题解思路了做，最不济，背，今天好好休息吧
		//遍历第一遍，实现拷贝每一个节点，将拷贝节点放在原节点右边
		Node* raw_node = head;
		//等等，先粗，再细，不要被这个细节耽误了时间，先实现大体思路
		//实现每个原始节点右边是拷贝节点，链表翻倍
		while (raw_node) {
			//每次新建一个拷贝节点，节点值为当前原始节点
			Node* cur_copy_node = new Node(raw_node->val);
			//拷贝节点的下一节点为当前节点的原始下一节点
			cur_copy_node->next = raw_node->next;
			//当前原始节点的下一个节点指向拷贝节点
			raw_node->next = cur_copy_node;
			//继续遍历，原始节点指向拷贝节点身后的那一个节点
			raw_node = cur_copy_node->next;
		}
		//至此，实现倍增，以上步骤进行了输出验证，没有问题
		//实现随机指针的赋值，为什么不能在上一步中同时实现？因为会指向原始链表，而不是拷贝链表
		//同样地，再遍历一次
		//复用raw_node，打回初值
		raw_node = head;
		while (raw_node) {
			//拷贝节点的random指针指向当前节点的random指针指向节点的下一个节点（拷贝节点）
			//注意，如果原始节点的random指针为null，是不存在“下一个节点”的，需要单独判断
			if (raw_node->random) {
				raw_node->next->random = raw_node->random->next;
				raw_node->next->random_idx = raw_node->random_idx;
			}
			//移动到下一个原始节点，继续遍历
			raw_node = raw_node->next->next;
		}
		//至此，完成了拷贝节点所有值的赋值
		//最后一步，拆分链表，完成拷贝节点的提取
		//需要保证原链表是不变的，不然就失去拷贝的意义了
		//raw_node负责恢复原链表
		raw_node = head;
		//需要获取拷贝节点的头结点，用作返回的指针
		Node* copy_node_head = raw_node->next;
		//copy_node负责拆分拷贝节点
		Node* copy_node = copy_node_head;
		//遍历一次，将当前拷贝节点的next指针指向下一个拷贝节点
		//从第一个节点开始
		while (raw_node) {
			if (copy_node->next == nullptr) {
				raw_node->next = nullptr;
				break;
			}
			//第一个节点为原节点，需要将next指向拷贝节点的下一个节点
			raw_node->next = copy_node->next;
			//先不考虑拷贝节点的操作，恢复原链表
			raw_node = raw_node->next;
			copy_node->next = raw_node->next;
			copy_node = copy_node->next;
		}
		return copy_node_head;
	}

	void show_res(Node* res) {
		cout << "[";
		while (res){
			cout << "[";
			cout << res->val << "," << res->random_idx << "]";
			if (res->next) {
				cout << ", ";
			}
			res = res->next;
		}
		cout << "]" << endl;
	}
};

int main() {
	//输入：输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
	//突然觉得，链表这种题目，挺适合我的，只要细心，能一次过，所以，努力啊
	Node* node_0 = new Node(7);
	Node* node_1 = new Node(13);
	Node* node_2 = new Node(11);
	Node* node_3 = new Node(10);
	Node* node_4 = new Node(1);

	node_0->next = node_1;
	node_0->random = NULL;
	node_0->random_idx = -1;

	node_1->next = node_2;
	node_1->random = node_0;
	node_1->random_idx = 0;

	node_2->next = node_3;
	node_2->random = node_4;
	node_2->random_idx = 4;

	node_3->next = node_4;
	node_3->random = node_2;
	node_3->random_idx = 2;

	node_4->next = NULL;
	node_4->random = node_0;
	node_4->random_idx = 0;

	Solution solu;
	Node* res = solu.copyRandomList(node_0);
	solu.show_res(res);
}
