#include<iostream>
#include<vector>
using namespace std;

struct A{
	int a,b,c;
};
int main()
{
	vector<A> p(2);
	vector<int> I;
	I.push_back(1);
	cout<<I[2]<<endl;
	cout<<p[1].a<<p[1].b<<p[1].c<<endl;
	return 0;
}