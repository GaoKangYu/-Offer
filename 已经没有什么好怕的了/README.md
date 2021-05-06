# 补足短板

经过一刷发现的不足之处：二叉树、BFS与DFS；动态规划；图形题；递归与回溯

## 需三刷（未短时间想出解答思路）

- 剑指offer66 - [constructArr](https://github.com/GaoKangYu/Sword-For-Offer/blob/main/%E5%B7%B2%E7%BB%8F%E6%B2%A1%E6%9C%89%E4%BB%80%E4%B9%88%E5%A5%BD%E6%80%95%E7%9A%84%E4%BA%86/constructArr.cpp)

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

## 二叉树、BFS、DFS

## 动态规划

## 图形题

## 递归与回溯

