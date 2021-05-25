# 补足短板

经过一刷发现的不足之处：二叉树、BFS与DFS（没有你想象的复杂）；动态规划（需要**选择**时常采用）；图形题；递归与回溯

## 需三刷（未短时间想出解答思路/有比较新奇的特殊解法）

- [剑指offer16 - myPow.cpp](https://github.com/GaoKangYu/Sword-For-Offer/blob/main/%E5%B7%B2%E7%BB%8F%E6%B2%A1%E6%9C%89%E4%BB%80%E4%B9%88%E5%A5%BD%E6%80%95%E7%9A%84%E4%BA%86/myPow.cpp)

快速幂，只有在1的位置上，才有相应的权重，推移权重，积累权重

- [剑指offer65 - add.cpp](https://github.com/GaoKangYu/Sword-For-Offer/blob/main/%E5%B7%B2%E7%BB%8F%E6%B2%A1%E6%9C%89%E4%BB%80%E4%B9%88%E5%A5%BD%E6%80%95%E7%9A%84%E4%BA%86/add.cpp)

位运算，真值表，异或 与，背下来

- [剑指offer56 - singleNumbers.cpp](https://github.com/GaoKangYu/Sword-For-Offer/blob/main/%E5%B7%B2%E7%BB%8F%E6%B2%A1%E6%9C%89%E4%BB%80%E4%B9%88%E5%A5%BD%E6%80%95%E7%9A%84%E4%BA%86/singleNumbers.cpp)

分组异或，根据xy在某一位的异或值不同，将其分在两组，同时也把相同的数分在了同一组

- [692 - topKFrequent.cpp](https://github.com/GaoKangYu/Sword-For-Offer/blob/main/%E5%B7%B2%E7%BB%8F%E6%B2%A1%E6%9C%89%E4%BB%80%E4%B9%88%E5%A5%BD%E6%80%95%E7%9A%84%E4%BA%86/topKFrequent.cpp)

很好的unordered_map和sort模板题

- [剑指offer58 - reverseLeftWords](https://github.com/GaoKangYu/Sword-For-Offer/blob/main/%E5%B7%B2%E7%BB%8F%E6%B2%A1%E6%9C%89%E4%BB%80%E4%B9%88%E5%A5%BD%E6%80%95%E7%9A%84%E4%BA%86/reverseLeftWords.cpp)

三次旋转，旋转前n区间，旋转后n区间，旋转整个区间

- [剑指offer62 - lastRemaining](https://github.com/GaoKangYu/Sword-For-Offer/blob/main/%E5%B7%B2%E7%BB%8F%E6%B2%A1%E6%9C%89%E4%BB%80%E4%B9%88%E5%A5%BD%E6%80%95%E7%9A%84%E4%BA%86/lastRemaining.cpp)

约瑟夫环问题(ans = (ans + m) % i;)

- [剑指offer20 - isNumber](https://github.com/GaoKangYu/Sword-For-Offer/blob/main/%E5%B7%B2%E7%BB%8F%E6%B2%A1%E6%9C%89%E4%BB%80%E4%B9%88%E5%A5%BD%E6%80%95%E7%9A%84%E4%BA%86/isNumber.cpp)

情况虽然比较复杂，但该题解思路非常清晰

- [剑指offer51 - reversePairs](https://github.com/GaoKangYu/Sword-For-Offer/blob/main/%E5%B7%B2%E7%BB%8F%E6%B2%A1%E6%9C%89%E4%BB%80%E4%B9%88%E5%A5%BD%E6%80%95%E7%9A%84%E4%BA%86/reversePairs.cpp)

并归排序模板题
```C++
class Solution {
public:
	int reversePairs(vector<int>& nums) {
		vector<int> tmp(nums.size());
		return mergeSort(0, nums.size() - 1, nums, tmp);
	}
private:
	int mergeSort(int l, int r, vector<int>& nums, vector<int>& tmp) {
		// 终止条件
		if (l >= r) return 0;
		// 递归划分
		int m = (l + r) / 2;
		int res = mergeSort(l, m, nums, tmp) + mergeSort(m + 1, r, nums, tmp);
		// 合并阶段
		int i = l, j = m + 1;
		for (int k = l; k <= r; k++)
			tmp[k] = nums[k];
		for (int k = l; k <= r; k++) {
			if (i == m + 1)
				nums[k] = tmp[j++];
			else if (j == r + 1 || tmp[i] <= tmp[j])
				nums[k] = tmp[i++];
			else {
				nums[k] = tmp[j++];
				res += m - i + 1; // 统计逆序对
			}
		}
		return res;
	}
};
```

- [剑指offer66 - constructArr](https://github.com/GaoKangYu/Sword-For-Offer/blob/main/%E5%B7%B2%E7%BB%8F%E6%B2%A1%E6%9C%89%E4%BB%80%E4%B9%88%E5%A5%BD%E6%80%95%E7%9A%84%E4%BA%86/constructArr.cpp)

思路：两次累乘，从最左乘到i-1，从最右乘到i+1，通过**在自增下标前积累累乘值**实现

```C++
//思路正确，但是效率很低，没有利用到累乘这个条件，每次都需要重复乘，重新赋值tmp
class Solution_v1 {
public:
	vector<int> constructArr(vector<int>& a) {
		int n = a.size();
		vector<int> ret(n, 1);
		//第一遍，求取该位置左边所有数的乘积
		for (int i = 0; i < n; ++i) {
			int tmp = 1;
			int j = 0;
			while (j < i){
				tmp *= a[i];
			}
			ret[i] *= tmp;
		}
		//至此，完成左边所有数的乘积
		//第二遍，求取该位置右边所有数乘积
		for (int i = n - 1; i >= 0; --i) {
			int tmp = 1;
			int j = n - 1;
			while (j > i) {
				tmp *= a[i];
			}
			ret[i] *= tmp;
		}
		return ret;
	}
};


//优化的点在于利用了累乘这个条件，节省了重复乘算中间值的时间
class Solution {
public:
	vector<int> constructArr(vector<int>& a) {
		int n = a.size();
		vector<int> ret(n);
		//第一遍，求取该位置左边所有数的乘积，注意，先乘，再增加下标，始终保持返回数组的ret[i]等于累乘至a[i-1]，
		//这里使用赋值而不是*也可以节省时间
		for (int i = 0, tmp = 1; i < n; tmp *= a[i], ++i) {
			ret[i] = tmp;
		}
		//至此，完成左边所有数的乘积
		//第二遍，求取该位置右边所有数乘积，同样，保持ret[i] = 逆序累乘至a[i+1]，由此组合，可以跳过a[i]且不用除法
		for (int i = n - 1, tmp = 1; i >= 0; tmp *= a[i], --i) {
			ret[i] *= tmp;
		}
		return ret;
	}
```

- [剑指offer13 - movingCount](https://github.com/GaoKangYu/Sword-For-Offer/blob/main/%E5%B7%B2%E7%BB%8F%E6%B2%A1%E6%9C%89%E4%BB%80%E4%B9%88%E5%A5%BD%E6%80%95%E7%9A%84%E4%BA%86/movingCount.cpp)

思路：DFS，模板题
```C++
class Solution {
public:
	int ans = 0;
	int vis[220][220] = { };

	int movingCount(int m, int n, int k) {
		dfs(n, m, k, 0, 0);
		return ans;
	}
	//形参：地图高、宽、限制条件k，起始点x坐标、y坐标
	void dfs(int n, int m, int k, int x, int y) {
		//边界条件1 2 3 ：x坐标超出边界0或m，y坐标超出边界n或0，该点已经走过了
		if (x < 0 || x >= m || y < 0 || y >= n || vis[x][y]) {
			return;
		}
		//边界条件4：计算该点的数位和
		int tmp = 0, x1 = x, y1 = y;
		while (x1) {
			tmp += (x1 % 10);
			x1 /= 10;
		}
		while (y1) {
			tmp += (y1 % 10);
			y1 /= 10;
		}
		//超过K也返回
		if (tmp > k) {
			return;
		}
		//每走一个点计数加一
		ans++;
		//标记此点已经走过
		vis[x][y] = 1;
		//四个方向探索
		dfs(n, m, k, x, y - 1);
		dfs(n, m, k, x, y + 1);
		dfs(n, m, k, x - 1, y);
		dfs(n, m, k, x + 1, y);
		return;
	}
};
```

- [剑指offer39 - majorityElement](https://github.com/GaoKangYu/Sword-For-Offer/blob/main/%E5%B7%B2%E7%BB%8F%E6%B2%A1%E6%9C%89%E4%BB%80%E4%B9%88%E5%A5%BD%E6%80%95%E7%9A%84%E4%BA%86/majorityElement.cpp)、

摩尔投票法
```C++
//摩尔投票法，很巧妙的方法
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		//相同则计数加一，不同则极限一换一
		int x = 0, vote = 0;
		for (auto n : nums) {
			if (vote == 0) {
				x = n;
			}
			vote += (x == n ? 1 : -1);
		}
		return x;
	}
};
```

- [剑指offer17 - printNumbers](https://github.com/GaoKangYu/Sword-For-Offer/blob/main/%E5%B7%B2%E7%BB%8F%E6%B2%A1%E6%9C%89%E4%BB%80%E4%B9%88%E5%A5%BD%E6%80%95%E7%9A%84%E4%BA%86/printNumbers.cpp)

三刷的时候需要考虑大数情况


- [剑指offer04 - findNumberIn2DArray](https://github.com/GaoKangYu/Sword-For-Offer/blob/main/%E5%B7%B2%E7%BB%8F%E6%B2%A1%E6%9C%89%E4%BB%80%E4%B9%88%E5%A5%BD%E6%80%95%E7%9A%84%E4%BA%86/findNumberIn2DArray.cpp)

线性查找：从二维数组的右上角开始查找。如果当前元素等于目标值，则返回 true。如果当前元素大于目标值，则移到左边一列。如果当前元素小于目标值，则移到下边一行。

原理：当前元素大于目标值，说明其下面的值都大于，右边的值都大于，所以只能往左；如果小于，那么其上面和左边都小，因此只能往下。

- [剑指offer04 - minArray](https://github.com/GaoKangYu/Sword-For-Offer/blob/main/%E5%B7%B2%E7%BB%8F%E6%B2%A1%E6%9C%89%E4%BB%80%E4%B9%88%E5%A5%BD%E6%80%95%E7%9A%84%E4%BA%86/minArray.cpp)

把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。

例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。

需要利用旋转数组的性质优化搜索耗时。

在最小值右侧的元素一定小于等于旋转后数组的末尾值，最小值左侧的数字一定大于等于旋转后数组的末尾值。


- [剑指offer64 - sumNums](https://github.com/GaoKangYu/Sword-For-Offer/blob/main/%E5%B7%B2%E7%BB%8F%E6%B2%A1%E6%9C%89%E4%BB%80%E4%B9%88%E5%A5%BD%E6%80%95%E7%9A%84%E4%BA%86/sumNums.cpp)

连续求和即为n(n+1)/2，展开n+1这个因子，其第i个为1的位对积的贡献为2^i-1，累加到n这个因子上即可。

## 二叉树、BFS、DFS

- BFS模板题1 - 层序遍历(借助queue)
- [剑指offer32 - levelOrder](https://github.com/GaoKangYu/Sword-For-Offer/blob/main/%E5%B7%B2%E7%BB%8F%E6%B2%A1%E6%9C%89%E4%BB%80%E4%B9%88%E5%A5%BD%E6%80%95%E7%9A%84%E4%BA%86/levelOrder.cpp)

```C++
class Solution {
public:
	vector<int> levelOrder(TreeNode* root) {
		vector<int> ret;
		queue<TreeNode*> q;
		if (!root) {
			return ret;
		}
		q.push(root);
		while (!q.empty()) {
			TreeNode* cur = q.front();
			ret.push_back(cur->val);
			//其实核心就在于这里，单纯递归很难去除这个重复根节点
			q.pop();
			if (cur->left) {
				q.push(cur->left);
			}
			if (cur->right) {
				q.push(cur->right);
			}
		}
		return ret;
	}
};
```

- 二叉树 递归写法教学
- [剑指offer26 - isSubStructure](https://github.com/GaoKangYu/Sword-For-Offer/blob/main/%E5%B7%B2%E7%BB%8F%E6%B2%A1%E6%9C%89%E4%BB%80%E4%B9%88%E5%A5%BD%E6%80%95%E7%9A%84%E4%BA%86/isSubStructure.cpp)

- DFS模板题
- [剑指offer38 - permutation](https://github.com/GaoKangYu/Sword-For-Offer/blob/main/%E5%B7%B2%E7%BB%8F%E6%B2%A1%E6%9C%89%E4%BB%80%E4%B9%88%E5%A5%BD%E6%80%95%E7%9A%84%E4%BA%86/permutation.cpp)


## 动态规划

## 图形题

## 递归与回溯

- 递归三部曲

  1、整个递归的终止条件

  2、一级递归需要做什么？

  3、应该返回给上一级的返回值是什么？
  
  [例题1 - 剑指offer27 二叉树的镜像](https://github.com/GaoKangYu/Sword-For-Offer/blob/main/%E5%B7%B2%E7%BB%8F%E6%B2%A1%E6%9C%89%E4%BB%80%E4%B9%88%E5%A5%BD%E6%80%95%E7%9A%84%E4%BA%86/mirrorTree.cpp)

```C++
	//递归三部曲
	void mirrorTreeProcess(TreeNode* root) {
		//其一：终止条件是什么？——节点为空
		//因此递归常常需要返回值为void
		if (!root) {
			return;
		}
		if (!root->left && !root->right) {
			return;
		}
		//其二，默认前后处理完全正确，只需要专注于这一层的操作
		//这一层需要进行什么样的操作？——交换左右子树
		TreeNode* tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		//其三，继续递归
		//如果左子树不为空，递归左边
		if (root->right) {
			mirrorTreeProcess(root->right);
		}
		//如果右子树不为空，递归右边
		if (root->left) {
			mirrorTreeProcess(root->left);
		}
	}
```

- [例题2 叶子相似的树]（https://leetcode-cn.com/problems/leaf-similar-trees/）

```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        //叶子元素相等，那么相似
        string s_1;
        dfs(root1, s_1);
        string s_2;
        dfs(root2, s_2);
        return s_1 == s_2;
    }

    void dfs(TreeNode* root, string &s){
        if(!root){
            return; 
        }
	//本题是找叶节点
	//叶节点的定义:没有左右子树的节点
	//根节点：开端，最上层的节点
	//子节点：根节点以外的有左子树或右子树的节点
        if(!root->left && !root->right){
            s += root->val + '0';
        }
        else{
            if(root->left){
                dfs(root->left, s);
            }
            if(root->right){
                dfs(root->right, s);
            }
        }
    }
};
```
