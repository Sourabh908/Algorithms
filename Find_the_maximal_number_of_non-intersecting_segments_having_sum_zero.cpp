/*----------------------^^
                          Sourabh Rana
                                      ^^--------------------------*/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> indexed_set;



#define nl                   '\n'
#define ll                   long long
#define pb                   push_back
#define pob                  pop_back
#define all(x)               (x).begin(),(x).end()
#define rev(n)               reverse(n.begin(), n.end())
#define gcd(a,b)             __gcd(a,b)
#define F                    first
#define S                    second
#define get_max(a)           *max_element(a.begin(), a.end())
#define get_min(a)           *min_element(a.begin(), a.end())
#define UNIQUE(x)            sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()
#define get_sum(a)           accumulate(a.begin(), a.end(), 0LL)
#define tc                       \
                             ll int T=1;   \
                             cin >> T; \
                             while (T--)


typedef pair<int, int>       pi;
typedef pair<ll, ll>         pl;

typedef vector<int>          vi;
typedef vector<ll>           vl;
typedef vector<pi>           vpi;
typedef vector<pl>           vpl;

#define rep(i,k,n)           for (int i = k; i < n; i++)
#define per(i,n,k)          for (int i = n; i >= k; i--)

/*****************************************************************************/

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

/*****************************************************************************/
bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if(max(a.F,a.S)==max(b.F,b.S))return min(a.F,a.S)<min(b.F,b.S);
    return max(a.F,a.S)<max(b.F,b.S);
}

int lcm(int a , int b) {
    return ((a * b) / gcd(a, b));
}

bool isprime(ll int num) {
    if (num <= 1) return false;
    if (num <= 3)  return true;

    ll range = sqrt(num);
    if (num % 2 == 0 || num % 3 == 0)
        return false;


    for (ll i = 5; i <= range; i += 6)
        if (num % i == 0 || num % (i + 2) == 0)
            return false;

    return true;
}

bool isPalindrome(string &str)
{
    int l = 0;
    int h = str.length() - 1;

    while (h > l)
    {
        if (str[l++] != str[h--])return false;

    }
    return true;
}

/*****************************************************************************/


/*****************************************************************************/

const int MOD = 1e9 + 7;




/*_________________  RECURSION MEANS : TRUST YOUR FUNCTION  _________________*/

/* IBH -> Induction - Base condition - Hypothesis */
/*   Choice + Decision --> Recursion  */   // Taking Decision Make input smaller
/*Choice Diagram or Input-Output Method*/







/*****************************************************************************/
/*
                    LAMBDA Function syntex
[](int x,int y){
    return x>y;
}
*/
// const int N = 1e5 + 10;
// vector<int> g[N];
// vector<bool> vis(N, false);

// void dfs(int vertex) {
//     // Take Action on Vertex after entering the vertex

//     vis[vertex] = true;
//     for (auto child : &g[vertex]) {
//         // Take Action on child before entering the child node

//         if (vis[child])continue;
//         dfs(child);

//         // Take Action on child after exiting child node
//     }

//     // Take Action on vertex before exiting the vertex
// }

bool binary_search(vector<int> &nums,int x){
         int k=0;
         int n=nums.size();
         for(int b=n/2;b>=1;b/=2){
               while(k+b<n  && nums[k+b]<=x)k+=b;
         }
         if(nums[k]==x)return true;
         return false;
}
// lower_bound(all(v),x)-v.begin();
// upper_bound(all(v),x)-v.begin();

// indexed_set s;
// (n+p-1)/p 
/*
  D. Kousuke's Assignment
time limit per test2 seconds
memory limit per test256 megabytes
After a trip with Sakurako, Kousuke was very scared because he forgot about his programming assignment. In this assignment, the teacher gave him an array a
 of n
 integers and asked him to calculate the number of non-overlapping segments of the array a
, such that each segment is considered beautiful.

A segment [l,r]
 is considered beautiful if al+al+1+⋯+ar−1+ar=0
.

For a fixed array a
, your task is to compute the maximum number of non-overlapping beautiful segments.

Input
The first line of input contains the number t
 (1≤t≤104
) — the number of test cases. Each test case consists of 2
 lines.

The first line contains one integer n
 (1≤n≤105
) — the length of the array.
The second line contains n
 integers ai
 (−105≤ai≤105
) — the elements of the array a
.
It is guaranteed that the sum of n
 across all test cases does not exceed 3⋅105
.

Output
For each test case, output a single integer: the maximum number of non-overlapping beautiful segments.

Example
InputCopy
3
5
2 1 -3 2 1
7
12 -4 4 43 -3 -5 8
6
0 -4 0 3 0 1
OutputCopy
1
2
3
  */

void answer() {
    
int n;
cin>>n;
vector<int> v(n+1);for(int i=1;i<=n;++i)cin>>v[i];
map<int,int> m;
vector<int> prf(n+1,0);
vector<int> lst(n+1);
m[0]=0;
for(int i=1;i<=n;++i){
      prf[i]=prf[i-1]+v[i];
      if(m.find(prf[i])==m.end()){
        lst[i]=-1;
      }
      else{
        lst[i]=m[prf[i]];
      }
      m[prf[i]]=i;
}
vector<int> dp(n+1,0);
for(int i=1;i<=n;++i){
     dp[i]=max(dp[i],dp[i-1]);
     if(lst[i]!=-1){
        dp[i]=max(dp[i],dp[lst[i]]+1);
     }
}
cout<<get_max(dp)<<nl;
  
}

int main() {
    optimize();
    tc{
        answer();
    }


}
