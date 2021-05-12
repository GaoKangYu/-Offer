# 失败换来新的起点
```
所以说选个要睡着的周四晚九点是要干嘛……
```
## 目录
TBD

## 面试题收集
### C++基础
- struct与union的区别？
  
  答：
    
    1、struct的大小是所有成员大小之和（包含由于内存对齐所额外占用的空间）；Union的大小是占空间最大的那个成员的大小；

    2、struct可同时分别对各个成员赋值，分别占不同的空间；Union每次赋值都会使得其他成员共享这个空间，都指向这个值。

```c++
/*
0、class和struct有什么区别？
答：实际上没太大的区别，保留struct是为了兼容c语言。区别有：
默认继承权限不同，class继承默认是private继承，而struct默认是public继承
class还可用于定义模板参数，可以把typename换成class，但是关键字struct不能用于定义模板参数
1、struct和union有什么区别？
答：1、struct的大小是所有成员大小之和（包含由于内存对齐所额外占用的空间）；Union的大小是占空间最大的那个成员的大小；
2、struct可同时分别对各个成员赋值，分别占不同的空间；Union每次赋值都会使得其他成员共享这个空间，都指向这个值
*/

#include <iostream>
#include <vector>

using namespace std;

struct testStruct {
	int param_a;//4byte
	bool param_b;//1byte
	char param_c;//1byte
};

union testUnion {
	int param_a;//4byte
	int param_b;//4byte
	int param_c;//4byte
	int param_d;//4byte
};

int main() {
	testStruct tS;
	//struct的大小是所有成员大小之和（包含由于内存对齐所额外占用的空间）
	cout << "tS的大小：" << sizeof(tS) << endl;
	//struct可同时分别对各个成员赋值，分别占不同的空间
	tS.param_a = 1;
	tS.param_b = true;
	tS.param_c = 'c';
	cout << "当前tS的param_a值为：" << tS.param_a << ",param_b值为：" << tS.param_b << ",param_c值为：" << tS.param_c << endl;
	testUnion tU;
	//Union的大小是占空间最大的那个成员的大小
	cout << "tU的大小：" << sizeof(tU) << endl;
	//Union每次赋值都会使得其他成员被重载，其他成员共享这个空间，都指向这个值
	tU.param_a = 1;
	//输出1 1 1 1
	cout << "当前tU的param_a值为：" << tU.param_a << ",param_b值为：" << tU.param_b << ",param_c值为：" << tU.param_c << ",param_d值为：" << tU.param_d << endl;
	tU.param_b = 2;
	//输出2 2 2 2
	cout << "当前tU的param_a值为：" << tU.param_a << ",param_b值为：" << tU.param_b << ",param_c值为：" << tU.param_c << ",param_d值为：" << tU.param_d << endl;
	tU.param_c = 3;
	//输出3 3 3 3
	cout << "当前tU的param_a值为：" << tU.param_a << ",param_b值为：" << tU.param_b << ",param_c值为：" << tU.param_c << ",param_d值为：" << tU.param_d << endl;
	tU.param_d = 4;
	//输出4 4 4 4
	cout << "当前tU的param_a值为：" << tU.param_a << ",param_b值为：" << tU.param_b << ",param_c值为：" << tU.param_c << ",param_d值为：" << tU.param_d << endl;
}
```
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
#### 3、位运算符与逻辑运算符
```C++
/*
剑指 Offer 64. 求1+2+…+n
求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
示例 1：
输入: n = 3
输出: 6
示例 2：
输入: n = 9
输出: 45
 
限制：
1 <= n <= 10000
*/

/*
数学+1，（首项+尾项） * 项数 / 2
但是不让用乘法，wtf
但是还是拓展了思路，八股背多了是这样的，拓展思路啊xd，每天能学到新东西真是太好了
基于法一继续优化
本质上是将  (n+1)*n/2 中题目不允许的操作给替换掉，除法可以用位右移操作>>
得到法二，利用语言自带的特性，sizeof
法二不安全，再次改进
替换乘法，快速乘法
例如，求A*B
A二进制展开，二进制A的第i位1对乘法的贡献为1<<i，所以需要将二进制A中的每一个1拿去贡献，然后将这些值累加起来，又因为不能用for
所以根据题目范围，n 为 [1,10000]，所以 n 二进制展开最多不会超过 14 位，所以写14层循环展开就可以
学到了新知识  &  这个是位运算符，A & 1是A的二进制形式与00000001按位取与，不要总惦记着你的十进制
以及，&&是逻辑运算符，有短路原则，&&前半为0，后半就不算了，因此才出现ans为0,的情况，woc好巧妙，这样的做法还控制了多次循环的情况下，后续循环不再加A
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int sumNums_1(int n) {
		int ret = 1;
		ret = (1 + n) * n / 2;
		return ret;
	}

	int sumNums_2(int n) {
		//一个int占4个byte，因此需要>>3，如果是bool或者char则占1个byte，直接>>1就可以
		//这确实是不安全的行为，因此舍弃该方法，取巧的，算了
		//bool nums[n][n + 1];
		//return sizeof(nums)>>1;
	}

	int sumNums_3(int n) {
		int ans = 0;
		int A = n;
		int B = n + 1;

		(B & 1) && (ans += A);
		B >>= 1;
		A <<= 1;
		cout << "B = "<<B<<endl;
		cout << "A = "<<A<<endl;
		cout << "ans = " << ans << endl;

		(B & 1) && (ans += A);
		B >>= 1;
		A <<= 1;
		cout << "B = " << B << endl;
		cout << "A = " << A << endl;
		cout << "ans = " << ans << endl;

		(B & 1) && (ans += A);
		B >>= 1;
		A <<= 1;

		(B & 1) && (ans += A);
		B >>= 1;
		A <<= 1;

		(B & 1) && (ans += A);
		B >>= 1;
		A <<= 1;

		(B & 1) && (ans += A);
		B >>= 1;
		A <<= 1;

		(B & 1) && (ans += A);
		B >>= 1;
		A <<= 1;

		(B & 1) && (ans += A);
		B >>= 1;
		A <<= 1;

		(B & 1) && (ans += A);
		B >>= 1;
		A <<= 1;

		(B & 1) && (ans += A);
		B >>= 1;
		A <<= 1;

		(B & 1) && (ans += A);
		B >>= 1;
		A <<= 1;

		(B & 1) && (ans += A);
		B >>= 1;
		A <<= 1;

		(B & 1) && (ans += A);
		B >>= 1;
		A <<= 1;

		(B & 1) && (ans += A);
		B >>= 1;
		A <<= 1;

		(B & 1) && (ans += A);
		B >>= 1;
		A <<= 1;

		return ans >> 1;
	}

	int input() {
		int ret;
		scanf_s("%d", &ret);
		return ret;
	}
};

int main() {
	Solution solu;
	int input = solu.input();
	cout << "Result : " << solu.sumNums_3(input);
}
```
- ``&``是位运算符，A & 1是A的二进制形式与00000001按位取与，不要总惦记着你的十进制

- ``&&``是逻辑运算符，有短路原则，``&&``前半为0，后半就不算了，因此才出现ans为0,的情况，这样的做法还控制了多次循环的情况下，后续循环不再加A

## 知识点总结

**1、为什么要用指针、引用，而不直接使用对象？**
  
  答：为了节省性能开销为了节省性能开销，传递对象需要拷贝它本身，传递指针或者引用操作的只是地址，32位机上4byte，64位机上8byte，而对象可能比较庞大，开销不在于构造与析构，在于赋值与传递。

**2、什么是多态？**

  答：多态的条件与影响：
  
      1、调用函数的对象必须是指针或者引用（‘->’而不是‘.’）；

      2、调用函数必须是虚函数；

      3、虚函数一旦声明，就会建立虚函数表，这个表会直接声明一个较大空间来存（内存对齐）；

      4、声明了纯虚函数的类会成为抽象类，不可实例化，一般用于父类，由于目前没有实际经验，还不清楚继承相较于直接新建类的优势；
      
**3、什么是重载（overloading）？**

  答：
  
  C++中允许出现同名函数，这类现象叫重载。
  
  重载的条件与影响：

	1、在同一作用域下，函数名相同但参数列表不同（类型、个数或者顺序[顺序不同需要类型也不同，因为两个int互换位置对于形参没什么意义]） 
	2、const属性相同；
	本质上，是编译器对函数进行了重命名（名称粉碎），C不能重载是因为C编译器只会给函数名前面加一个下划线简单命名，而C++（以VS为例）的.map文件中，对于函数名有如下处理：
	?Add@@YAHHH@Z 
	?后面是函数名
	@@YA表示参数列表开始
	H表示返回值类型
	HH表示两个参数的类型
	@Z名称结束
	另外，返回值不能作为决定性因素，是因为有时候并不会使用到函数的返回值，所以编译器无法区分。
	

**4、什么是重写（override）？**
  
  答：分为虚函数重写（发生多态）、非虚函数重写（重定义的另一种形式）；一般的目的都是子类重新定义父类中有相同返回值名称参数的虚函数（重新实现），实现多态调用。

  重写条件：

	1、返回类型、函数名、参数列表完全相同；
	2、必须发生在不同作用域（基类与子类）；
	3、基类中有virtual关键字声明，派生类中可有可无，不能有static
**5、static的作用？**
  
  答：作用：
  
	所有未加static前缀的全局变量和函数都具有全局可见性，其它的源文件也能访问。如果加了static，就会对其它源文件隐藏。
	利用这一特性可以在不同的文件中定义同名函数和同名变量，而不必担心命名冲突。
	static可以用作函数和变量的前缀，对于函数来讲，static的作用仅限于隐藏。
	static变量有全局生存期，只会被初始化一次，直到整个程序结束。
	如果在函数内部被定义，它的作用域仍然只在函数内。
**6、什么是重定义？**

  答：子类重新定义父类中有相同名称的函数。必须发生在不同作用域中；函数名相同、返回值可以不同、参数列表不同则会隐藏基类中的同名函数、参数列表相同且基类同名函数不是虚函数则会被隐藏，但可以用作用域分辨符::访问被隐藏的成员。
 
**7、什么是抽象类？**

  答：含有纯虚函数的类为抽象类，抽象类不可以被实例化(`abstract a`)，纯虚函数定义为`virtual void fun() = 0`。值得注意的是，继承了抽象类的子类，如果不**实现全部**的纯虚函数，也会被视为抽象类，此处的**实现**不同于重写，仅仅为完成函数体的定义，不得修改返回值参数等。

**8、cout可以输出string类吗？**

  答：可以，但是需要包含头文件`<string>`，此时实质上是重载了运算符`<<`，说明本质上`string`不是基本类型，C++是基于C的。
  
9、关于输入回车停止读入，**暂且记住吧**。

**10、new一个对象和直接声明对象有什么区别？**

  答：
  
  `ListNode* head = new ListNode()`为`new`一个对象；
  
  1）该方式需要指针接收，在堆上分配空间；
  
  2）如果进行了初始化，则需要显示地回收（`delete`）空间，否则可能出现内存泄露，未经过初始化则不需要`delete`，做了反而可能出错；
  
  3）频繁的`new`、`delete`空间会增加系统开销；
  
  4）`new`产生了一个对象指针，该指针可以在函数之间传递，这个对象指针所指向的堆中的对象实例化是仍然存在的；
  
  5）`new`对象的调用方式是`a->func()`。
  
  `ListNode* cur = head`为直接定义对象；
  
  1）在栈上分配空间；
  
  2）在创建之初就进行了初始化，不需要手动释放空间，使用完直接销毁，理论上不会出现内存泄露；
  
  3）相对效率更高；
  
  4）作用域是局部的，除了方法就没有了；
  
  5）直接定义对象的调用方式是`a.func()`。
  
11、继承的三种方式
|  类型\特点   | 基类属性变化  | 派生类成员权限  |派生类对象权限|
|:----:|:----:|:----:|:----:|
| Public  | 不变，Private成员被隐藏 | 能访问基类Public/Protected，不能访问Private  | 能访问基类Public成员 |
| Private  | 均变为Private，Private成员被隐藏 | 能访问基类Public/Protected，不能访问Private  | 无法访问基类任何成员 | 
| Protected  | 均变为Protected，Private成员被隐藏 | 能访问基类Public/Protected，不能访问Private  | 无法访问基类任何成员 |
```C++
#include <iostream>
#include <vector>

using namespace std;

class test_base{
public:
	int param_a;
	bool param_b;
	//在类内部，能够访问所有函数、成员
	test_base() {
		base_show_private();
		base_show_protected();
	}
	void base_show_public() {
		cout << "基类能在类内部调用自己的public函数" << endl;
	}

private:
	int param_c;
	bool param_d = 3;
	void base_show_private() {
		cout << "基类能在类内部调用自己的private函数" << endl;
	}

protected:
	int param_e = 23;
	bool param_f = false;
	void base_show_protected() {
		cout << "基类能在类内部调用自己的protected函数" << endl;
	}
};

class test_derived_public : public test_base {
public:
	int param_d_a;
	bool param_d_b;
	test_derived_public() {
		//public继承能够访问基类的public、protected参数、函数
		cout << "public继承的派生类能够访问基类的protected参数param_e：" << param_e << endl;
	}
	void show_public() {
		cout << "Derived_public's Public Func." << endl;
	}

private:
	int param_d_c;
	bool param_d_d;
	void show_private() {
		cout << "Derived_public's Private Func." << endl;
	}

protected:
	int param_d_e;
	bool param_d_f;
	void show_protected() {
		cout << "Derived_public's Protected Func." << endl;
	}
};

class test_derived_private : private test_base {
public:
	int param_d_a;
	bool param_d_b;
	test_derived_private() {
		//private继承能够访问基类的public、protected参数、函数
		cout << "private继承的派生类能够访问基类的protected参数param_f：" << param_f << endl;
	}
	void show_public() {
		cout << "Derived_private's Public Func." << endl;
	}

private:
	int param_d_c;
	bool param_d_d;
	void show_private() {
		cout << "Derived_private's Private Func." << endl;
	}

protected:
	int param_d_e;
	bool param_d_f;
	void show_protected() {
		cout << "Derived_private's Protected Func." << endl;
	}
};

class test_derived_protected : protected test_base {
public:
	int param_d_a;
	bool param_d_b;
	test_derived_protected() {
		//protected继承能够访问基类的public、protected参数、函数
		cout << "protected继承的派生类能够访问基类的protected参数param_f：" << param_f << endl;
	}
	void show_public() {
		cout << "Derived_protected's Public Func." << endl;
	}

private:
	int param_d_c;
	bool param_d_d;
	void show_private() {
		cout << "Derived_protected's Private Func." << endl;
	}

protected:
	int param_d_e;
	bool param_d_f;
	void show_protected() {
		cout << "Derived_protected's Protected Func." << endl;
	}
};


int main() {
	//在类外部，能够访问的只有public部分
	cout << "以下为基类访问权限测试:" << endl;
	test_base tb;
	tb.param_a = 1;
	cout << "tb.param_a = " << tb.param_a << endl;
	tb.param_b = true;
	tb.base_show_public();

	cout << endl;
	cout << "以下为public继承访问权限测试:" << endl;
	//public继承可以访问基类的public部分
	test_derived_public td_public;
	//这里我知道为啥，新建子类实际上是从基类开始构造的，因此基类的public参数对子类可见，但修改的不是同一对象
	td_public.param_a = 2;
	cout << "tb.param_a = " << tb.param_a << endl;
	cout << "td_public.param_a = " << td_public.param_a << endl;

	cout << endl;
	cout << "以下为private继承访问权限测试:" << endl;
	//private继承在类外无法访问基类成员
	test_derived_private td_private;
	td_private.param_d_a = 3;
	
	cout << endl;
	cout << "以下为protected继承访问权限测试:" << endl;
	//protect继承在类外无法访问基类成员
	test_derived_protected td_protected;
	td_protected.param_d_a = 1;
	cout << "td_protected.param_d_a = " << td_protected.param_d_a << endl;

}
```
**12、KMP算法**
  
  答：背下来先。
  ```
  实现 strStr() 函数。
  给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。
  如果不存在，则返回  -1 。
  说明：
  对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C 语言的 strstr() 以及 Java 的 indexOf() 定义相符。
  ```
```C++
class Solution {
public:
    int strStr(string s, string p) {
        int n = s.size(), m = p.size();
        if(m == 0) return 0;
        //设置哨兵
        s.insert(s.begin(),' ');
        p.insert(p.begin(),' ');
        vector<int> next(m + 1);
        //预处理next数组
        for(int i = 2, j = 0; i <= m; i++){
            while(j and p[i] != p[j + 1]) j = next[j];
            if(p[i] == p[j + 1]) j++;
            next[i] = j;
        }
        //匹配过程
        for(int i = 1, j = 0; i <= n; i++){
            while(j and s[i] != p[j + 1]) j = next[j];
            if(s[i] == p[j + 1]) j++;
            if(j == m) return i - m;
        }
        return -1;
    }
};
```
**13、bool类型**
  
  答：
  
  取值：真（true, 1）/假（false, 0）;
  
  空间大小：1byte;
  
  使用方式:不要写`if(bool_a == false)`,写`if(!bool_a)`。
  
**14、const常量**

  答：
  
  ```C++
  //背景：计算圆的面积，定义PI的值，提高代码可读性。
  //C语言写法
  //用宏定义
  #define PI 3.14
  //但没有指定类型，没有类型检查
  //C++提供了新的关键字const
  //常量：程序生命周期内不变的值，定义的时候必须赋初值
  //C++写法
  const float FPI = 3.14;
  //编译后常量也是有分配内存空间的，所以可以通过指针修改它的值
  float* p = (float*)&FPI;
  //因此，常量无法修改是指在程序编译时期无法修改（编译器会检查），运行的时候可以修改内存，从而改变值，但意义不大...
  //另外，在编译的时候，常量如果是直接赋值，编译器会有一个优化步骤，直接把const这个量替换为它的值，所以通常情况下改了内存也不会生效（自己做个试验吧）
  //如果是运行起来才知道常量的值，那么编译器无法执行这一优化过程，会从地址去找常量的值，所以这种情况下是可以修改的
  ```
  
  关键字`const`用于修饰变量，将变量变为常量；

**15、const指针**

  答：
  
  例如：
  ```C++
  //v1 code
  char* p = "test";
  p[0] = 'a';
  //此时编译可以通过，但运行时报错，这样是不安全的
  
  //v2 code
  const char* p = "test";
  p[0] = 'a';
  //此时直接编译不通过，因为const告诉了编译器这个常量字符数组是不能修改的
  ```
  `const T*`或者`T const*`表示不能修改该指针指向的内容，但是指针本身的值是可以修改的；
  
  另外，`T* const`表示该指针是一个常量，指针本身的值不能改变，但是指针指向内容可以改变；
  
  `const T* const`表示指针本身以及指针指向内容都不能改变。
  
  `const_cast`：可用于去掉`const`属性，比强行转换可读性高。
  ```C++
  const int n = 5;
  //实现一个指向n的指针
  //int* p = &n;编译不通过，类型不匹配
  //int* p = (int*)&n;使用强制转换可实现
  //或者
  int *p = const_cast<int*>(&n);
  ```
  
**16、默认参数**
   
   答：
   ```c++
   //v1 code
   int testFun(int n1, int n2, int n3, int n4, int n5, int n6){
   	return 0;
   }
   
   int main(){
   	testFun(1, 2, 3);
	return 0;
   }
   
   //v2 code
   //使用宏，将后三个值给定一个默认值，但是因为没有类型检查，默认值也不方便再改变，所以不安全
   #define TESTFUN(m,n,k) TestFun(m,n,k,1,2,3)
   int testFun(int n1, int n2, int n3, int n4, int n5, int n6){
   	return 0;
   }
   
   int main(){
   	TESTFUN(1,2,3);
	return 0;
   }
   
   //v3 code
   int testFun(int n1, int n2, int n3, int n4 = 4, int n5 = 5, int n6 = 6){
   	return 0;
   }
   
   int main(){
   	testFun(1,2,3);
	testFun(1,2,3,44);
	return 0;
   }
   ```
   
   函数默认参数可以写在声明处（比如自定义的头文件）**或者** 定义处，只能出现在一个地方，一般写在声明处。
   
   当一个参数有默认值时，其右边的所有参数都应该有默认值。
   
**17、什么是内联函数？**
  
  答：
  
  声明方式：`inline`，直接把函数体粘贴在调用处，节省找进出口的开销，是对编译器的**建议**，debug模式为了方便调试，编译器不会采用此建议。
  
  用内联说明这个函数会多次使用，因此一般用在头文件里，如果该函数被多个cpp文件调用，会报错重复定义，必须加`inline`，此时就没有调用过程了。
  
  ```
  int getMax(int a, int b){
  	return a > b ? a : b;
  }
  
  int main(){
  	int n1 = getMax(1,2);
	int n2 = getMax(2,3);
	int n3 = getMax(2,4);
	//需要调用三次函数，但是进出函数的开销可能比这个函数本身功能的开销还大
	//（为了简单的喝口水，上下6楼就位买水喝，就很亏，如果买很多东西顺便买水，就还好）
	//也可以用宏实现这个功能，相当于直接把函数体放在了调用处,不会产生调用开销，
	//但仍然是不安全，没有类型检查，不支持很多运算操作等
  }
  
  //v2 code
  inline int getMax(int a, int b){
  	return a > b ? a : b;
  }
  
  int main(){
  //直接把函数体放在调用处
  	int n1 = getMax(1,2);
	int n2 = getMax(2,3);
	int n3 = getMax(2,4);
  }
  ```
**18、什么是引用？**
  
  答：
  
  引用是变量的别名，占4个字节的空间，记录关联空间的地址，本质上是指针，是一个常量指针。
  
  常量指针：`const int* p`或者`int const* p`，本质是指针，指向常量。这个指针的值是可以改变的。但是指针指向的地址的内容是无法改变的（这个指针指向了字符常量区中的一个地址）。
  
  指针常量：`int* const p =  number`，本质是常量，是指针类型，这个指针的值是无法被改变的（这个指针指向了一个固定的地址）但是这个地址的内容是可以改的。
  
```C++
//v1 code，函数fun中的形参n是拷贝的，不是mian中的同一个n
void fun(int n){
  n = 8;
  return;
}

int main(){
  int n = 5;
  fun(n);
  cout << n << endl;
  return 0;
}

//v2 code，使用指针，但不安全，需要检查地址
void fun(int* pN){
if(pN != nullptr){
   n = 8; 
}
 return;
}

int main(){
  int n = 5;
  fun(&n);
  cout << n << endl;
  return 0;
}

//v3 code，使用引用
void fun(int &n){
 n = 8;
 return;
}

int main(){
  int n = 5;
  //或者
  //int& refN = n; //左值引用，变量的别名，此时函数形参仍是指针int* pN
  fun(n);
  cout << n << endl;
  return 0;
}
```

  注意事项：
  
  1、引用在定义时必须初始化，不能用常量为引用赋值。
  
  2、只有常量引用可以使用常量来初始化，例如：`const int& crefN = 12; `。
  
  3、引用关系一旦建立无法修改。
  
  引用的使用：
  
  1、作为函数参数（形参使用引用）。
  
  2、作为函数的返回值。
  
  ```C++
  //可以在函数外部改变函数内部的值，不安全行为
  int& fooRtnRef(){
  	int k = 3;
	return k;
  }
  ```
  
  二级引用不存在，可以使用指针的引用替代二级指针。
  
  **19、作用域**
    
  答：
  
  ```C++
  #include <iostream>
  
  int n = 6;
  int main(){
    int n = 5;
    //局部作用域的n会隐藏全局的n
    {
    	int n = 7;
	printf("%d", n);
	//n = 7
    }
    //n = 5
  }
  ```
  
  1、全局作用域 名字空间作用域（namespace）
  
  2、局部作用域 块作用域
  
  3、类域（class）
  
  数据隐藏：
  
  1、在不同的作用域可以定义多个同名变量
  
  2、内部变量会隐藏外部变量（从内往外找）
  
  名字空间`namespace`：
  
  1、是一种作用域的划分，通常用于区分项目中的模块或组件
  
  2、关键字`namespace`可以分开使用（可以放在不同文件内）
  
  3、名字空间可以嵌套
  
  4、名字空间可以取别名
  
  ```C++
  namespace testName{
  	int test_val_1 = 4;
  }
  
  namespace testNewName{
  	int test_val_1 = 3;
  }
  
  int test_val_1 = 1;
  
  int main(){
    testName::test_val_1 = 6;
    cout << testName::test_val_1 <<endl;
    testNewName::test_val_1 = 7;
    cout << testNewName::test_val_1 <<endl;
    //::test_val_1表示全局作用域
  }
  ```
  
  名字空间的引用：
  
  1、（推荐）直接使用`名字空间::内容`
  
  2、声明名字空间`using namespace testName`，从这句话以后，使用`testName`下的命名空间，此时不加`::`默认表示`testName`下，加了则特指
  
  3、声明只使用名字空间的部分变量或函数`using testName::n`，此时没有声明的都是全局作用域下的变量
  
  名字空间的原理：
  
  **20、类与面向对象**
  
  答：
  
  封装：把数据和操作数据的方法放在一起组成一体，是面向对象思想独有的、
        c语言的struct不能添加函数，但可通过函数指针绑定外部函数，再传入结构体数据成员的指针，实现封装。
  继承
  多态
  
  访问权限：在当前类域之外的访问规则，类访问权限检查在编译时期进行。
  
  public：类域里和类域外均可访问（struct默认是public）
  
  private：只有类域里可以访问（class默认是private）
  
  protected：保护权限（继承中使用）
  
  类中，数据成员一般私有（private），前缀默认`m_`，成员函数部分公有
  
  同一个类的成员函数地址是一样的，表示同一个类的所有对象的成员函数是共用的：数据是独立的，成员函数是公有的。
  
  `this`指针：成员函数调用时会传递this指针，通过寄存器exc传递，这种传递方式称为`thiscall`。
  
  **21、构造函数**
  
  答：
  
  构造函数：
  
  1）用于对象的初始化
  
  2）写法：函数名为类名，不写返回值
  
  3）允许函数重载
  
  4）如果类中没有构造函数，编译器会提供一个默认的（无参构造函数，可能会被优化[缺省]）
  
  拷贝构造函数：
  
  1）作用：本质上是一种构造函数，在`A a;  A b = a;`这种用一个对象创建另一个对象时调用，此时不会执行默认的构造函数。
  
  2）缺省的拷贝构造的作用：完全的把对象1拷贝给对象2，memcpy。
  
  3）何时需要重写拷贝构造函数：当对象的成员函数存在一种需要分配的资源时，为了避免析构时重复释放，需要重写拷贝构造函数或禁用。
  ```C++
  //自行补完的写法
  A(A& obj){
    //todo
  }
  //禁用拷贝构造函数方法：
  A(A& obj) = default;
  A(A& obj) = delete;
  ```
  
  **22、构析函数**
  
  答：
  
  析构函数：
  
  1.作用：完成资源的释放。

  2.写法：类名前加上~，无返回值、参数，不可重载，不需要手动调用。
  
  **23、浅拷贝与深拷贝**
  
  答：
  
  浅拷贝：两个内容相同的不同对象指向同一地址。
  
  深拷贝：两个内容相同的不同对象指向不同地址。
  
  拷贝构造产生的对象是浅拷贝，因此在析构释放内存的时候可能出错（已经释放的内存再次释放）。
  
  ```C++
  //浅拷贝写法
  A(A& obj){
    this->obj.m_val = obj.m_val;
  }
  //深拷贝写法：
  A(A& obj){
    //todo
    m_val = (char*)malloc(255);
    if(m_val == nullptr){
      return;
    }
    memcpy(this->obj.m_val, obj.m_val, strlen(255));
  }
  ```
  
  **24、new与delete
  
  答：
  
  栈上的对象：局部对象
  
  全局对象
  
  堆对象:
  
  运算符：
  
  1.`new`：分配空间，调用构造函数。
  
  2.`delete`：调用析构函数，释放空间。
  
  ps:对于基本数据类型而言，new与delete仅仅分配内存。
  
  3.相对的，`malloc`和`free`是c语言中用的，不会调用构造和析构函数。
  
  4.（申请堆上对象时，不推荐）混用组合：对于对象而言，如果用`new`构造了对象，但使用`free`释放，会导致没有调用析构函数，类似的，使用`malloc`和`delete`则没有掉构造函数。
  
  5.类似的`new[]`与`delete[]`（特别是申请对象数组时）也要配套使用。
  ```C++
  //通过new新建会调用构造函数
  //通过malloc不会
  A* a = new A;
  if(a != nullptr){
      delete a;
  }
  ```
  
  `malloc`在堆上分配字节，`free`释放该空间
  
  
  
  
  
  **25、友元函数**
