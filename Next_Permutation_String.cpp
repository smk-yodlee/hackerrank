//Next permutation of a string is done here using the predefined function in stl
//Otherwise, from end of string find the first character s[i] that is greater than character at some index j, s[j]
//i.e. s[j]<s[i] for j<i
//Swap them and save idx j as prefix
//Sort all char from prefix+1 to end of string
//Then result = substr(0,prefix) + sort_substr(prefix+1,end)


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

 string s;

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        cin >> s;
        if (next_permutation(s.begin(), s.end())) printf("%s\n", s.c_str());
        else printf("no answer\n");
    }
    return 0;
}
