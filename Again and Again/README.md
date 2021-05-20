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

答：因为会造成内存泄露问题，当通过基类指针来管理派生类，如果析构函数不是虚函数，释放该指针时只会析构基类，导致派生类占用的空间没有被释放。

### 2、介绍一下智能指针？

答：智能指针主要用于管理在堆上分配的内存，它将普通的指针封装为一个栈对象。当栈对象的生存周期结束后，会在析构函数中释放掉申请的内存，从而防止内存泄漏。

shared_ptr：采用引用计数的方法，多个智能指针可以指向相同对象，记录当前内存资源被多少个智能指针引用。该引用计数的内存在堆上分配。当新增一个时引用计数加1，当过期时引用计数减一。只有引用计数为0时，智能指针才会自动释放引用的内存资源。

unique_ptr：实现独占式拥有或严格拥有概念，只对一块资源负责，保证同一时间内只有一个智能指针可以指向该对象。对于避免资源泄露(例如“以new创建对象后因为发生异常而忘记调用delete”)特别有用。没有拷贝构造函数，只有移动构造函数。

weak_ptr：用来解决shared_ptr相互引用时的死锁问题,如果说两个shared_ptr相互引用,那么这两个指针的引用计数永远不可能下降为0,资源永远不会释放。它是一种弱引用，不会增加引用计数，使得引用形不成环，最后就可以正常的释放内部的对象，不会造成内存泄漏。

#### 2.1、什么是拷贝构造？什么移动构造？

答：拷贝构造是指使用对象来初始化同类的另一个对象，它会分配一片空间并把传入对象的值复制过来，属于深拷贝。如果没有自行定义拷贝构造函数，编译器会自己生成，但是如果类是含有指针变量、有动态分配内存的情况，不可缺省（经过测试，验证了这一结论，编译通过运行错误，报错`Invalid address specified to RtlValidateHeap`）。
```C++
#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

class TestClass {
public:
	TestClass() {
		cout << "构造了一个TestClass类" << endl;
		_m_val = 0;
		int_ptr = new int(10);
		//int_ptr = &_m_val;
	}

	TestClass(int x) {
		cout << "构造了一个TestClass类" << endl;
		_m_val = x;
		int_ptr = new int(x);
		//错误，_m_val何时释放是未知的，这样的操作本身也不安全
		//int_ptr = &_m_val;
	}

	TestClass(const TestClass& obj) {
		cout << "构造了一个TestClass类" << endl;
		_m_val = obj._m_val;
		int_ptr = new int;
		*int_ptr = *obj.int_ptr;
	}

	~TestClass(){
		cout << "析构了一个TestClass类" << endl;
		assert(int_ptr != nullptr);
			delete this->int_ptr;
			cout << "释放了int_ptr指针" << endl;
	}
private:
	int _m_val;
	int* int_ptr;
};

int main() {
	TestClass a(10);
	TestClass b = a;
}
```


移动构造：同样为使用对象来初始化同类另一个对象，但是没有重新分配空间，而是将构造对象的指针指向了要拷贝对象的空间，并将拷贝对象的指针指空。对于程序执行过程中产生的临时对象，往往只用于传递数据（没有其它的用处），并且会很快会被销毁。因此在使用临时对象初始化新对象时，我们可以使用移动构造将其包含的指针成员指向的内存资源直接移给新对象所有，无需再新拷贝一份，这能提高初始化的执行效率。

#### 2.2、什么是浅拷贝？什么是深拷贝？

答：浅拷贝：只复制指向某一块内存的指针，拷贝出来的指针和原指针指向同一块内存，没有分配新空间。

深拷贝：先分配空间，再拷贝值，拷贝出来的指针和原指针指向两块不同的内存。

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
