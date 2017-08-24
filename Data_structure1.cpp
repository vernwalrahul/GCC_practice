#include <iostream>
#include <stdint.h>
#include <vector>
#include <algorithm>
using namespace std;

struct A
{
	int a, b, k;
};

bool start(A l, A r)
{
	return l.a<r.a;
}

bool end_(A l, A r)
{
	return l.b<r.b;
}
int main()
{
	unsigned long long int n, m, k, a, b;
	cin>>n>>m;
	vector<A> objects_start(m);
    vector<A> objects_end(m);
	for(int i=0;i<m;i++)
	{
		cin>>objects_start[i].a>>objects_start[i].b>>objects_start[i].k;
        objects_end[i]=objects_start[i];
	}
	
	sort(objects_start.begin(), objects_start.end(), start);
	sort(objects_end.begin(), objects_end.end(), end_);

	
	int64_t curr=objects_start[0].k, max=objects_start[0].k;
	unsigned long long int si=1, ei=0;
	for(int i=objects_start[1].a, j=objects_end[0].b;ei<m;)
	{
		if(si>=m) {
			curr-=objects_end[ei].k; ei++;
		}
        else{
		i=objects_start[si].a;
		j=objects_end[ei].b;
		if(i<=j){
			curr+=objects_start[si].k; si++;
		}
		else{
			curr-=objects_end[ei].k; ei++;
		}
        }
		if(curr>max)
			max=curr;
	}

	cout<<max<<endl;
	return 0;
}