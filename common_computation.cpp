int compute_ncr(int n, int r)            //order of n
{

  int ans=1;
  if(r>n/2)
    r=n-r;
  for(int i=1;i<=r;i++)
   {
      ans*=(n-r+i);
      ans/=i;
   }

  return ans;
}

int HCF(int n1, int n2)
{
	int r;
	while(n2!=0)
	{
		r=n1%n2;
		n1=n2;
		n2=r;
	}
	return n1;
}

// QUICK_SORT //
int partition(int A[], int p, int q)
{
  int x=A[p];
  int i=p;
  for(int j=p+1;j<=q;j++)
  {
    if(A[j]<=x)
    {
      i++;
      int temp=A[i];
      A[i]=A[j];
      A[j]=temp;
    }

  }
  A[p]=A[i];
  A[i]=x;
  return i;
}

void Quick_sort(int A[], int p, int q)
{ int r;
  if(p<q)
  {
    r=partition(A, p, q);
    Quick_sort(A, p, r-1);
    Quick_sort(A, r+1, q);
  }
}

int binary_search2(A stock[], long long int v, long long int n)   //to_search for the place to insert v
{
  int l=0, r=n-1, mid, flag=0;
  while(1)
  {
    // cout<<"l = "<<l<<" r= "<<r<<" v = "<<v<<endl;
    // cout<<stock[r-1].max_sofar<<" "<<v<<" "<<stock[r].max_sofar<<endl;
    if(stock[r-1].t<v && v<=stock[r].t)
      return r;
    mid = (l+r)/2;
    if(v<=stock[mid].t)
      r=mid;
    else
      l=mid;
  }
} 
// QUICK_SORT //

