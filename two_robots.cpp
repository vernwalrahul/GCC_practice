#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int M, N;
		long long int total_distance=0;
		cin>>M>>N;
		int Ma, Mb;  cin>>Ma>>Mb;
		int R1=Mb, R2=-1;
		total_distance=fabs(Mb-Ma);
		// cout<<"Ma = "<<Ma<<" Mb = "<<Mb<<" total_distance = "<<total_distance<<endl;
		for(int i=1;i<N;i++)
		{
			cin>>Ma>>Mb;
			if(R1==Ma)
			{
				total_distance+=fabs(Ma - R1)+fabs(Mb - Ma);
					R1=Mb;
					continue;
			}
			if(R2==-1){
					total_distance+=fabs(Mb-Ma);
					R2=Mb;
				}
			else{
				if(fabs(R1 - Ma)<=fabs(R2-Ma)){
					total_distance+=fabs(Ma - R1)+fabs(Mb - Ma);
					R1=Mb;
					}
				else	{
					total_distance+=fabs(Mb-Ma)+fabs(Ma-R2);
					R2=Mb;
					}
			}
			// cout<<"Ma = "<<Ma<<" Mb = "<<Mb<<" total_distance = "<<total_distance<<endl;
		}
		cout<<total_distance<<endl;

	}
	return 0;
}