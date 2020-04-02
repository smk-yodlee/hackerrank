//Given a string S, we can make it highest value palindromic in O(N) by using 2 pointers left=0 and right=len-1
//Change str[left] or str[right] to greater value and left++ and right-- and k--
//If at any point k is -ve, then it is not possible to make it palindromic in k changes, so print -1

//Now to make it the highest palindrome number, if we have more k available, then repeat process updating both left and right to 9
//k changes by 2 each time
//If k=1 at the end of this and len is odd, then we can also change middle element to 9

#include <bits/stdc++.h>
#include<assert.h>

using namespace std;

char ans[100005] = {'\0'};
bool mark[100005];

void solution() {

   memset(mark,0,sizeof(mark));
   int n, len, l, r, k;
   string str;

   cin>>n>>k;
   cin>>str;
   len = str.size();

   assert(n>0 && n<=100000);
   assert(k>=0 && k<=100000);
   assert(len>0 && len<=100000);

   //Making palindrome
   l=0; r=len-1;
   while(l<=r)
   {
	   assert(str[l]>='0' && str[l]<='9');
	   assert(str[r]>='0' && str[r]<='9');

	   if(l==r)
	   {
		   ans[l] = str[l];
		   break;
	   }
	   if(str[l] == str[r])
	   {
		   ans[l] = str[l];
		   ans[r] = str[r];
	   }
	   else
	   {
		   if(str[l]>= str[r])
		   {
			   mark[r] = 1;
			   k--;
			   ans[l] = ans[r] = str[l];
		   }
		   else
		   {
			   mark[l] = 1;
			   k--;
			   ans[l] = ans[r] = str[r];
		   }
	   }
	   l++;
	   r--;
   }

   if(k<0)
   {
	   printf("-1\n");
	   return;
   }

   //Maximizing number
   l=0; r=len-1;
   while(l<=r)
   {
	   if(l==r)
	   {
		   if(ans[l]<'9' && k>=1)
			ans[l] = '9';
		   break;
	   }
	   if(ans[l]<'9')
	   {
		   if(mark[l] == 0 && mark[r] == 0 && k>=2) //not touch before
		   {
			   k-=2;
			   ans[l] = ans[r] = '9';
		   }
		   else if((mark[l]==1 || mark[r]==1) && k>=1)
		   {
			   k-=1;
			   ans[l] = ans[r] = '9';
		   }
	   }
	   l++;
	   r--;
   }
   ans[len] = '\0';
   printf("%s\n", ans);
}

int main () {

		solution();
	return 0;
}
