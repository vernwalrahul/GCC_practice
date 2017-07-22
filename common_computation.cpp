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
