#include<iostream>

using namespace std;
int qp_x, qp_y, n, i=1, j=1, c_dir=0;

int dir(int x, int y)
{
	x/=i; y/=i;
	if(x==1 && y==0)
		return 1;
	if(x==1 && y==1)
		return 2;
	if(x==0 && y==1)
		return 3;
	if(x==-1 && y==1)
		return 4;
	if(x==-1 && y==0)
		return 5;
	if(x==-1 && y==-1)
		return 6;
	if(x==0 && y==-1)
		return 7;
	return 8;
}

int valid(int x,int y)
{
	if(x>n || y>n || x<1 || y<1)
		return 0;
	return 1;
}

int deduct(int x, int y)
{
    switch(c_dir)
    {
    	case 1:  return (n-x+1);
    	case 2:  return ((n-x<n-y?n-x+1:n-y+1));
    	case 3:  return (n-y+1);
    	case 4:  return (x-1<n-y?x:n-y+1);
    	case 5:  return (x);
    	case 6:  return (x<y?x:y);
    	case 7:  return (y);
    	case 8:  return (n-x<y-1?n-x+1:y);
    }
}
int main(){
	int o_x, o_y; int flag=0;
	cin>>n>>no;

	bool x[n][n]={0};
	cin>>qp_x>>qp_y;

    while(no--)
    {
    	cin>>o_x>>o_y;
    	x[o_x][o_y]=1;
    }

    while(flag<8)
    {
    	int no_invalid=0;
       for(int t_x=-i;t_x<=i;t_x+=i)
       	for(int t_y=-j;t_y<=j;t_y+=j)
       	{	if(valid(pos_x,pos_y))
       		{
       			c_dir=dir(pos_x, pos_y);
       			if(mark[c_dir]!=1)
       				if(x[pos_x][pos_y]==1)
       				{
       					total-=deduct(c_dir);
       					mark[c_dir]=1;
       					flag++;
       				}
       		}
       		else
       			no_invalid++;
       }
       i++; j++;
       if(no_invalid==8)
       	break;
    }

	return 0;
}