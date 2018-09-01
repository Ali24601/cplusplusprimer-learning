#include <iostream>
using namespace std;

//全局函数
void fun() {}
void __cdecl func() {}
void __stdcall funs() {}
void __fastcall funf() {}
//void __thiscall funt() {} //__thiscall 只能出现在非静态成员函数声明中

//全局函数
void funl(...) {}
void __cdecl funlc(...) {}
void __stdcall funls(...) {}
void __fastcall funlf(...) {}
//void __thiscall funlt(...) {} //__thiscall 只能出现在非静态成员函数声明中

class A
{
public:
	void fun() {}
	void __cdecl func() {}
	void __stdcall funs() {}
	void __fastcall funf() {}
	void __thiscall funt() {}

	void funl(...) {}
	void __cdecl funlc(...) {}
	void __stdcall funls(...) {}
	void __fastcall funlf(...) {}
	//void __thiscall funlt(...) {}//带有省略号参数的函数中不允许使用 __thiscall

	static void sfun() {}
	static void __cdecl sfunc() {}
	static void __stdcall sfuns() {}
	static void __fastcall sfunf() {}
	//static void __thiscall sfunt() {}//__thiscall 只能出现在非静态成员函数声明中
										//提示有错误，但是编译可以通过，费解
	static void sfunl(...) {}
	static void __cdecl sfunlc(...) {}
	static void __stdcall sfunls(...) {}
	static void __fastcall sfunlf(...) {}
	//static void __thiscall sfunlt(...) {}//带有省略号参数的函数中不允许使用 __thiscall
										 //“...”需要“__cdecl”
};
int main()
{
	cout << "---------全局函数----------" << endl;
	cout << typeid(fun).name() << endl;
	cout << typeid(func).name() << endl;
	cout << typeid(funs).name() << endl;
	cout << typeid(funf).name() << endl;
	//cout << typeid(funt).name() << endl;
	cout << "---------全局不定参函数----------" << endl;
	cout << typeid(funl).name() << endl;
	cout << typeid(funlc).name() << endl;
	cout << typeid(funls).name() << endl;
	cout << typeid(funlf).name() << endl;
	cout << "---------类成员函数----------" << endl;
	cout << typeid(&A::fun).name() << endl;
	cout << typeid(&A::func).name() << endl;
	cout << typeid(&A::funs).name() << endl;
	cout << typeid(&A::funf).name() << endl;
	cout << typeid(&A::funt).name() << endl;
	cout << "---------类不定参成员函数----------" << endl;
	cout << typeid(&A::funl).name() << endl;
	cout << typeid(&A::funlc).name() << endl;
	cout << typeid(&A::funls).name() << endl;
	cout << typeid(&A::funlf).name() << endl;
	//cout << typeid(&A::funlt).name() << endl;
	cout << "---------类静态成员函数----------" << endl;
	cout << typeid(A::sfun).name() << endl;
	cout << typeid(A::sfunc).name() << endl;
	cout << typeid(A::sfuns).name() << endl;
	cout << typeid(A::sfunf).name() << endl;
	//cout << typeid(A::sfunt).name() << endl;
	cout << "---------类静态不定参成员函数----------" << endl;
	cout << typeid(A::sfunl).name() << endl;
	cout << typeid(A::sfunlc).name() << endl;
	cout << typeid(A::sfunls).name() << endl;
	cout << typeid(A::sfunlf).name() << endl;
	//cout << typeid(A::sfunlt).name() << endl;

	cout << typeid(main).name() << endl;
	return 0;
}

//总结
//1.在无显示调用约定时，全局函数、静态成员函数、不定参函数为__cdecl。
//2.在无显示调用约定时，类成员函数（非静态，非不定参）调用约定为__thiscall。
//3.带有省略号参数的函数中不允许使用 __thiscall,可以显示写成其他三种调用方式，
//但最终都是__cdecl。----类不定参成员函数怎么解决this指针问题？？
//4.__thiscall 只能出现在非静态成员函数声明中

//编译选项对默认调用约定的影响
//  __cdecl(/Gd)
//  __fastcall(/Gr)
//  __stdcall(/Gz)
//  __vetorcall(/Gv)
