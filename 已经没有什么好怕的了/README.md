# 补足短板

经过一刷发现的不足之处：二叉树、BFS与DFS（没有你想象的复杂）；动态规划（需要**选择**时常采用）；图形题；递归与回溯

## 需三刷（未短时间想出解答思路/有比较新奇的特殊解法）

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

## 二叉树、BFS、DFS

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
