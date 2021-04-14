# 失败换来新的起点
```
所以说选个要睡着的周四晚九点是要干嘛……
```
## 目录
TBD

## 面试题收集
### C++基础
- struct与union的区别？
- 什么是内存对齐，其底层原理是？意义在于？
- const与static的区别？
- 什么是虚函数，什么是虚函数表？
- 进程与线程有什么区别？分别如何通信？
### 岗位相关
- TCP和UDP有什么区别？如何实现可靠的UDP？游戏里是如何使用UDP的？
- 图形学
### 算法
- 快速排序
### 手撕代码
- 链表按位相加
### 聊天
- 最近看了什么书？
### 反问
- 产品的技术栈？
- 这个岗位具体要做什么？

### 一直以来没搞明白的玩意
```
去失败，去面对
```
- 为什么要用指针要用引用，为什么不直接用对象？

**为了节省性能开销，传递对象需要拷贝它本身，传递指针或者引用操作的只是地址，32位机上4byte，64位机上8byte，而对象可能比较庞大，开销不在于构造与析构，在于赋值与传递。**

#### 1、多态、函数重载、重写、重定义
- 多态

多态的条件与影响：

1、调用函数的对象必须是指针或者引用（‘->’而不是‘.’）；

2、调用函数必须是虚函数；

3、虚函数一旦声明，就会建立虚函数表，这个表会直接声明一个较大空间来存（内存对齐）；

4、声明了纯虚函数的类会成为抽象类，不可实例化，一般用于父类，由于目前没有实际经验，还不清楚继承相较于直接新建类的优势；

- 重载（overloading，发生在类内）
 
重载的条件与影响：

1、在同一作用域下，函数名相同但参数列表不同（类型、个数或者顺序）
2、const属性相同；

本质上，是编译器对函数进行了重命名，C不能重载是因为C编译器只会给函数名前面加一个下划线简单命名，而C++（以VS为例）的.map文件中，对于函数名有如下处理：
```
?Add@@YAHHH@Z 
?后面是函数名
@@YA表示参数列表开始
H表示返回值类型
HH表示两个参数的类型
@Z名称结束
```
另外，返回值不能作为决定性因素，是因为有时候并不会使用到函数的返回值，所以编译器无法区分。

- 重写（override，发生在有继承关系的类间）

分为虚函数重写（发生多态）、非虚函数重写（重定义的另一种形式）；

子类重新定义父类中有**相同返回值名称参数的虚函数（重新实现）**，一般而言都是这个目的，重写就是为了虚函数重写，实现多态调用

重写条件：

1、返回类型、函数名、参数列表完全相同；

2、必须发生在不同作用域（基类与子类）；

3、基类中有virtual关键字声明，派生类中可有可无，不能有static
```
注：
所有未加static前缀的全局变量和函数都具有全局可见性，其它的源文件也能访问。如果加了static，就会对其它源文件隐藏。
利用这一特性可以在不同的文件中定义同名函数和同名变量，而不必担心命名冲突。
static可以用作函数和变量的前缀，对于函数来讲，static的作用仅限于隐藏。
static变量有全局生存期，只会被初始化一次，直到整个程序结束。
如果在函数内部被定义，它的作用域仍然只在函数内。
```
- 重定义（不包含虚函数重写）

子类重新定义父类中有相同名称的函数。必须发生在不同作用域中；

函数名相同、返回值可以不同、参数列表不同则会隐藏基类中的同名函数、参数列表相同且基类同名函数不是虚函数则会被隐藏，但可以用作用域分辨符::访问被隐藏的成员。

- 实现/实验代码
```c++
#include <iostream>
#include <vector>
#include <string>

using namespace std;

extern int size_cost = 0;

class Solution {
public:
	Solution() {
		printf("创建了一个Solution类\n");
		size_cost += sizeof(Solution);
	}

	~Solution() {
		printf("析构了一个Solution类\n");
	}
  //混淆重写与重载的定义，最初是想尝试使用纯虚函数，子类重写show_result，
  //但是报错“不允许使用抽象类类型"vector_int_Solution"的对象:纯虚拟函数"Solution:show_result”没有强制替代项”
  //因为使用了纯虚函数，因此父类变成了抽象类，继承了父类的子类，是可以访问父类的函数的，
  //因此，如果需要实例化一个子类，需要实现其父类的全部纯虚函数，否则子类也会变成抽象类
  //困惑在于，为什么virtual void show_name() = 0没有报错，而void show_result() = 0报错？
  //解答如下：声明了纯虚函数的父类，其子类需要实现该纯虚函数，实现，而不是重写，
  //需要同名同参数同返回值并完成具体函数体，否则视为未实现。我把这问题当做了重写。
  //甚至尝试了模板类
	//template<typename T> void show_result(T val) {
	//
	//};
	//所以纯虚函数的使用需谨慎，它应当是通用函数，而不是子类特有
	virtual void show_result() {
		printf("show name.\n");
	};
	//pure virtual
	virtual void show_name() = 0;
	void who_i_am() {
		printf("from sky");
	}
};

class string_Solution : public Solution{
public:
	string_Solution() : Solution() {
		printf("创建了一个string_Solution类\n");
		size_cost += sizeof(string_Solution);
	}

	~string_Solution() {
		printf("析构了一个string_Solution类\n");
	}

	virtual void show_result(string str) {
		printf("Result : ");
		//printf("%s\n", str),这个方法属于C语言，而C是没有string类的，
		//于是无法使用printf直接输出string，改为cout
		//此外，cout其实也不能直接输出string，包含头文件<string>后，
		//实质上是重载了运算符“<<”，使得其支持string，说明本质上，string不是基本类型，c++基于c
		/*
		先来看CString、string和string.h这几个区别：
		CSting:CString是MFC或者ATL中的实现，是MFC里面封装的一个关于字符串处理的功能很强大的类,
		只有支持MFC的工程才可以使用。如在linux上的工程就不能用CString了，只能用标准C++中的string类了。
		在MFC中使用不需要自己加，但在另外的程序中需要加入#include。
		string：string类既是一个标准c++的类库，同时也是STL（Standard Template Library,标准模版库）中的类库，已经纳入C++标准之中。
		它和CString有本质的区别。
		string.h:C语言里面关于字符数组的函数定义的头文件，常用函数有strlen、strcmp、strcpy等等，
		这个头文件跟C++的string类半点关系也没有，所以 并非 <string.h>的“升级版本”，他们是毫无关系的两个头文件。
		综上，cout函数重载的是string类库中的string类型，而不是CString或string.h中的。
		*/
		cout << str << endl;
	}



	virtual void show_name() {
		cout << "Name : String_Solution.\n" << endl;
	}

	string input() {
		//“scanf_s” : 格式字符串“ % s”需要类型“char *”的参数，但可变参数 1 拥有了类型“std::string *”
		//就普遍理性而言，对于输入字符串的情况，使用scanf_s会比较麻烦，一般需要定义char[]并指定长度
		char tmp[255]{'\0'};
		string ret;
		//改成gets_s直接完事
		gets_s(tmp);
		show_result(tmp);
		fflush(stdin);
		return tmp;
	}
};

class vector_int_Solution : public Solution {
public:
	vector_int_Solution() : Solution() {
		printf("创建了一个vector_int_Solution类\n");
		size_cost += sizeof(vector_int_Solution);
	}

	~vector_int_Solution() {
		printf("析构了一个vector_int_Solution类\n");
	}

	virtual void show_result(vector<int> res) {
		printf("Result : [");
		for (int i = 0; i < res.size(); ++i){
			printf("%d", res[i]);
			if (i < res.size() - 1){
				printf(", ");
			}
		}
		printf("]\n");
	}

	virtual void show_name() {
		printf("Name : vector_int_Solution.\n");
	}

	vector<int> input() {
		int tmp;
		vector<int> ret;
		//这为什么也没停止读入？
		//while (scanf_s("%d", &tmp)!=EOF){
		do{
			scanf_s("%d", &tmp);
			ret.push_back(tmp);
		} while (getchar() != '\n');
		fflush(stdin);
		show_result(ret);
		return ret;
	}
};

int main() {
	//Solution solu;
	//目前的问题在于实际场景的应用，我现在是完全不知道使用继承和完全新写一个类的优势在哪里
	Solution* solu;
	//printf("目前占用空间为： %d\n", size_cost);
	string_Solution str_solu;
	solu = &str_solu;
	//printf("目前占用空间为： %d\n", size_cost);
	solu->show_name();
	string input;
	input = str_solu.input();
	//solu->show_result(input);
	vector_int_Solution vec_int_solu;
	solu = &vec_int_solu;
	solu->show_name();
	vector<int> input_vec;
	input_vec = vec_int_solu.input();
```

- ACM模式下，遇到回车完成输入，int、string、vector<int>分别的实现。
- 基于前序中序后序遍历完成二叉树的建立与可视化
- 链表的实现与典型题

#### 2、二叉树
- 二叉树的种类
- 二叉树的存储方式
- 二叉树遍历
- 二叉树构造
- 实例
```c++
#include <iostream>
using namespace std;

int main(){

}
```

## 知识点总结

**1、为什么要用指针、引用，而不直接使用对象？**
  
  答：为了节省性能开销为了节省性能开销，传递对象需要拷贝它本身，传递指针或者引用操作的只是地址，32位机上4byte，64位机上8byte，而对象可能比较庞大，开销不在于构造与析构，在于赋值与传递。

2、什么是多态？

  答：多态的条件与影响：
  
      1、调用函数的对象必须是指针或者引用（‘->’而不是‘.’）；

      2、调用函数必须是虚函数；

      3、虚函数一旦声明，就会建立虚函数表，这个表会直接声明一个较大空间来存（内存对齐）；

      4、声明了纯虚函数的类会成为抽象类，不可实例化，一般用于父类，由于目前没有实际经验，还不清楚继承相较于直接新建类的优势；
      
3、什么是重载（overloading）？

  答：重载的条件与影响：

	1、在同一作用域下，函数名相同但参数列表不同（类型、个数或者顺序） 
	2、const属性相同；
	本质上，是编译器对函数进行了重命名，C不能重载是因为C编译器只会给函数名前面加一个下划线简单命名，而C++（以VS为例）的.map文件中，对于函数名有如下处理：
	?Add@@YAHHH@Z 
	?后面是函数名
	@@YA表示参数列表开始
	H表示返回值类型
	HH表示两个参数的类型
	@Z名称结束
	另外，返回值不能作为决定性因素，是因为有时候并不会使用到函数的返回值，所以编译器无法区分。

4、什么是重写（override）？
  
  答：分为虚函数重写（发生多态）、非虚函数重写（重定义的另一种形式）；一般的目的都是子类重新定义父类中有相同返回值名称参数的虚函数（重新实现），实现多态调用。

  重写条件：

	1、返回类型、函数名、参数列表完全相同；
	2、必须发生在不同作用域（基类与子类）；
	3、基类中有virtual关键字声明，派生类中可有可无，不能有static
5、static的作用？
  
  答：作用：
  
	所有未加static前缀的全局变量和函数都具有全局可见性，其它的源文件也能访问。如果加了static，就会对其它源文件隐藏。
	利用这一特性可以在不同的文件中定义同名函数和同名变量，而不必担心命名冲突。
	static可以用作函数和变量的前缀，对于函数来讲，static的作用仅限于隐藏。
	static变量有全局生存期，只会被初始化一次，直到整个程序结束。
	如果在函数内部被定义，它的作用域仍然只在函数内。
6、什么是重定义？

  答：子类重新定义父类中有相同名称的函数。必须发生在不同作用域中；函数名相同、返回值可以不同、参数列表不同则会隐藏基类中的同名函数、参数列表相同且基类同名函数不是虚函数则会被隐藏，但可以用作用域分辨符::访问被隐藏的成员。
 
7、什么是抽象类？

  答：含有纯虚函数的类为抽象类，抽象类不可以被实例化(`abstract a`)，纯虚函数定义为`virtual void fun() = 0`。值得注意的是，继承了抽象类的子类，如果不**实现全部**的纯虚函数，也会被视为抽象类，此处的**实现**不同于重写，仅仅为完成函数体的定义，不得修改返回值参数等。

8、cout可以输出string类吗？

  答：可以，但是需要包含头文件`<string>`，此时实质上是重载了运算符`<<`，说明本质上`string`不是基本类型，C++是基于C的。
  
9、关于输入回车停止读入，**暂且记住吧**。
