#include<bits/stdc++.h> 
#include<iostream>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std; 
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set1;
typedef tree<int,null_type,greater<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set2;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set_s;
typedef tree<pair<int,int>,null_type,less_equal<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set_s2;
typedef long long int ll; 
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pi      2*acos(0.0) 
#define vll     vector<ll> 
#define pq_      priority_queue 
#define pq_min  <int,vector<int>,greater<int>> 
#define vi      vector<int> 
#define vii     vector<pair<int, int>> 
#define pii     pair<int, int> 
#define pb      push_back 
#define sp      ' ' 
#define sz(n)   (int)n.size() 
#define all(n)  n.begin(),n.end() 
#define rall(n) n.rbegin(), n.rend()
#define YES     cout<<"YES\n"; 
#define yes     cout<<"yes\n"; 
#define NO      cout<<"NO\n"; 
#define no      cout<<"no\n"; 
#define bye     return 0; 
const double    eps = 1e-9;
const int       MAX = 1e5; 
const int 		lim = 1e6; 
bool odd(ll num) { return ((num & 1) == 1);}
bool even(ll num) { return ((num & 1) == 0);}
bool isEqual(double a,double b) {return abs(a-b)<eps;}
bool isGreater(double a,double b) {return a>=b+eps;} 
bool isGreaterEqual(double a,double b) {return a>b-eps;}
#define tc int t;cin >> t;while (t--) 
#define mset(n, v) memset(n, v, sizeof(n))
#define chk(n) for(auto it:n)
#define ff(i,n) for(int i = 0; i < n; i++)
#define ff1(i,n) for(int i = 1; i <= n; i++)
#define lcm(a, b) (((a) * (b)) / __gcd(a, b))
int dx[8] = {1,-1, 0, 0, 1, -1, -1, 1}; 
int dy[8] = {0, 0, 1,-1, 1, -1, 1, -1};
int knapsack(int W, int wt[], int val[], int n, int memo[][1000]) 
{
    if (n == 0 || W == 0)
        return 0;
    if (memo[n][W] != -1)
        return memo[n][W];
    if (wt[n - 1] > W) 
        memo[n][W] = knapsack(W, wt, val, n - 1, memo); 
    else 
        memo[n][W] = max(val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1, memo),knapsack(W, wt, val, n - 1, memo));
    return memo[n][W];
}
int main() 
{
    int n,W;
    cin>>n>>W;
    int price[n];
    int wt[n];
    ff(i,n)
        cin>>price[i];
    ff(i,n)
        cin>>wt[i];
    int memo[n+1][1000];
    mset(memo,-1);
    int result = knapsack(W, wt, price, n, memo);
    cout << "Maximum value that can be put in a knapsack of capacity " << W << " is " << result << endl;

    return 0;
}
