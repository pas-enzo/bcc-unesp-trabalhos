#include<bits/stdc++.h>
using namespace std;

int main()
{
  
  int t,n,i,c,j; 
  
  cin >> t;

  while (t--)
  {
      cin>>n;

      int x[n];

      for(i=0;i<n;i++) 
        cin >> x[i];

      for(i=0;i<n;i++)
      {
        c=1; 
        j=i;

        while(x[j]!=i+1) 
        { 
            c++; j=x[j]-1; 
        }

        cout << c <<" ";
      }

      cout << endl;
      
  }

}
