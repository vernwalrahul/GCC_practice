#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s[2]={"Hi! Rahul here."," Me............"};
	cout<<s[1][1];
	cout<<s[0].substr(4);
	return 0;
}