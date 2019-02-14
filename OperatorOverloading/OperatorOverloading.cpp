#include <iostream>
#include <vector>
using namespace std;
using std::cout;
class Target
{
public:
	int a = 5;
};

class Base
{ 
public:
	int bbase = 6;
	void Bfun() {}
	Target* operator -> (void)
	{
		cout << "\r\n\tvoid Base::operator->";
		return &s_target;
	}

private:
	static Target s_target;
};
Target Base::s_target;

class Simple
{
private:
	vector<int> vec;
	Base base;
public:
	int ssimp;
	Simple(int val = 0, int len = 0) :vec(len,val)
	{ 
		cout << "\r\n\tSimple::Simple(int val = "<< val <<")"; 
	}
	void operator() (void) 
	{ 
		cout << "\r\n\tvoid Simple::operator()"; 
	}
	int operator[] (int ite) 
	{ 
		cout << "\r\n\tint Simple::operator["<<ite<<"]";
		return vec[ite];
	}
	Base& operator -> (void)
	{
		cout << "\r\n\tvoid Simple::operator->";
		return base;
	}

	template<typename T>
	void operator ->* (T t)
	{
		cout << "\r\n\tvoid Simple::operator->*";
	}

	/*
	void operator . (void)
	{

	}
	*/
	/*
	void operator .* ()
	*/

	//friend int operator sizeof(Simple);
	
};

/*
template<typename T>
int operator sizeof(T)
{
return 1;
}
*/

/*C2473	“operator ?”: 看起来像函数定义，但却没有参数列表
template<typename T>
T operator ?: (bool check, T t1, T t2)
{
	if (check)
		return t1;
	return t2;
}
*/

/*C2833	“operator typeid”不是可识别的运算符或类型
template <typename T>
void operator typeid(T)
{
	return 0;
}
*/

int main()
{
	cout << "Simple s(2,4);";
	Simple s(2,4);

	cout << "s.operator()();";
	s.operator()();
	cout << endl;

	cout << "s()";
	s();
	cout << endl;

	cout << "s.operator[](3);";
	s.operator[](3);
	cout << endl;

	cout << "s[3];";
	s[3];
	cout << endl;

	cout << "s.operator->();";
	s.operator->();
	cout << endl;

	cout << "s.operator->().operator->()->a;";
	s.operator->().operator->()->a;
	cout << endl;

	cout << "s.operator->()->a;";
	s.operator->()->a;
	cout << endl;

	cout << "s->a;\t";
	cout << s->a << endl;

	int Simple::*pb = &Simple::ssimp;
	cout << s.*pb << endl;
	s->*2;
	Simple *ps = &s;
	ps->operator->*(2);


	Base b;
	b->a;
	Base *p = &b;
	//p->a; //Base没有成员a
	p->operator->()->a;
	p->bbase;
	p->Bfun();
	return 0;
}

/*
不可重载的运算符
: :: . .* ?: sizeof typeid

->以及->*在左操作数为指针时不能够重载

间接访问符 ->

假如有class A、B、C
C->返回B
B->返回A*
A有成员int a
则
C c;
c->a;
可以访问A::a;

假如
C->返回B
B->返回A
A没有重载->
则
C c;
c->;
会报错

假如
C->返回B*
B->返回A*
B有成员int b
A有成员int a
则
C c;
c->b;//访问B::b
c->a;//会报错

总结
使用 C c;c->b访问特定成员时
1.->的左操作数为类对象时，首先查找此类有无重载->，没有则goto 4；重载的->返回值为指针 goto 2；重载的->返回值为另一个类的类对象或者引用 goto 1
2.->的左操作数为类指针时，根据右操作数访问对应成员变量或成员函数 goto 3
3.成功
4.失败
*/

