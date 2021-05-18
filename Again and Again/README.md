# C++开发岗基础知识整理
## 目录

- [C++基础](https://github.com/GaoKangYu/Sword-For-Offer/tree/main/Again%20and%20Again#c%E5%9F%BA%E7%A1%80)

- [计算机网络](https://github.com/GaoKangYu/Sword-For-Offer/tree/main/Again%20and%20Again#%E8%AE%A1%E7%AE%97%E6%9C%BA%E7%BD%91%E7%BB%9C)

- [算法与数据结构](https://github.com/GaoKangYu/Sword-For-Offer/tree/main/Again%20and%20Again#%E7%AE%97%E6%B3%95%E4%B8%8E%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84)

- [设计模式](https://github.com/GaoKangYu/Sword-For-Offer/tree/main/Again%20and%20Again#%E8%AE%BE%E8%AE%A1%E6%A8%A1%E5%BC%8F)

- [项目相关](https://github.com/GaoKangYu/Sword-For-Offer/blob/main/Again%20and%20Again/README.md#%E9%A1%B9%E7%9B%AE%E7%9B%B8%E5%85%B3)


## C++基础

### 1、什么是多态？

答：多态是指在有继承关系的不同类对象间，调用同一函数，产生了不同行为的现象。该机制通过指针和虚函数实现。

#### 1.1、如何实现多态？

答：

首先，实现多态有两个限制条件：

（1）调用函数的对象必须是指针或者引用。

（2）被调用的函数必须是虚函数，且完成了虚函数的重写。

如果调用函数的对象不是指针或者引用，那么为静态绑定，在编译阶段完成。否则为动态绑定，在运行阶段完成。

如果调用函数不是虚函数，那么都将执行基类的函数。

```C++
#include <iostream>
#include <vector>

using namespace std;

class _base{
public:
	_base() {
		cout << "构造了一个_base类" << endl;
	}

	virtual void show_name() {
		cout << "此为_base类函数" << endl;
	}

	virtual ~_base(){
		cout << "析构了一个_base类" << endl;
	}
private:
	int _m_val;

};

class _child_a : public _base {
public:
	_child_a() {
		_m_ptr = new int(0);
		cout << "构造了一个_child_a类" << endl;
	}

	void show_name() {
		cout << "此为_child_a类函数" << endl;
	}

	~_child_a() {
		cout << "析构了一个_child_a类" << endl;
		delete _m_ptr;
		cout << "释放了_m_ptr" << endl;
	}
private:
	int _m_val;
	int* _m_ptr = nullptr;
};

int main() {
	_base* _b_ptr = new _child_a;
	_b_ptr->show_name();
	delete _b_ptr;
}
```
#### 1.2、只有动态绑定才具有多态性吗？

答：静态绑定也有多态性，函数重载和运算符重载就属于编译时的静态多态性。

#### 1.3、什么是函数重载？

答：函数重载发生在同一作用域内，指一系列函数名相同但参数列表不同（类型、个数或者顺序，当然这个顺序变换不能有歧义）的函数。

#### 1.4、为什么基类的析构函数必须是虚函数？

答：因为会造成内存泄露问题，通过基类指针来管理派生类，如果析构函数不是虚函数，释放该指针时只会析构基类，导致派生类占用的空间没有被释放。

### 2、介绍一下智能指针？

### 3、引用与右值引用有什么区别？

### 4、介绍一下堆和栈（数据结构上的和存储上的）？

#### 4.1、堆的底层都是由二叉树实现的吗？堆排序是用二叉树实现的吗？


## 计算机网络

### TCP和UDP有什么区别？

### 视频通信你会选择用哪一种实现？

## 计算机系统

### 进程与线程


## 算法与数据结构

### 快速排序的复杂度分析？口述其原理。

### 数组和vector的区别，链表和vector的区别。

## 设计模式

## 常见编程题目

### 反转链表

## 项目相关
