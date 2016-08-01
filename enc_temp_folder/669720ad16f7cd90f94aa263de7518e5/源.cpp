#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	cin >> s;
	cout << s ;

	while (cin >> s)//windowsÏÂctrl+z·µ»Øfalse
		cout << s << endl;

	while (getline(cin, s))
		cout << s << endl;

	return 0;
}