//Given a string, find and delete as many occurences of consecutive same characters
//E.g: baab -> bb ->Empty String
//If empty string at end, print 'Empty String'
//Using stack, we can solve in O(N)
//Iterate from i=0 to n-1, check str[i] with top of stack. If equal then pop and go to i+1
//Otherwise push it to stack and go to i+1


#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll  long long int
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define f first
#define mp make_pair
#define mod 1000000007
#define s second
#define pb push_back
int main(){

    string S;
    cin >> S;
    vector<char>ans;
    rep(i,S.length()){
        if(ans.size()==0 or S[i]!=ans.back()) ans.pb(S[i]);
        else ans.pop_back();
    }
    if(ans.size()==0) cout<<"Empty String";
    else{
        for(auto x:ans) cout<<x;
    }
}
