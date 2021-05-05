#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef unsigned long long ull;
typedef long double lld;
#define mod 1000000007
#define PI 3.1415926535897932384626433832795
#define deb(x) cerr << #x <<" "; _print(x); cerr << endl;
#define pb push_back
#define mk make_pair
#define in insert
#define maxHeap priority_queue<int>
#define minHeap priority_queue<int, vi, greater<int>>
#define ps(x, y) fixed << setprecision(y) << x
#define nline "\n"
#define set_bits __builtin_popcountll

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T> void _print(vector <T> v) {cerr << "[ "; for (T el : v) {_print(el); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}

/*---------------------------------------------------------------------------------------------------------------------------*/

void solve(){
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Error.txt","w",stderr);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin>>t;

    for(int i=0;i<t;++i){
        solve();
    }
    return 0;
}