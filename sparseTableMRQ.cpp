#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define str string
#define pb push_back
#define vc vector
#define ci cin
#define co cout
ll rmq[1000000], a[1000000];

ll build_rmq(ll idx, ll st, ll en)
{
    if (st == en)
        return rmq[idx] = a[st];
    else
    {
        ll mid = (st + en) / 2;
        return rmq[idx] = min(build_rmq(2 * idx, st, mid), build_rmq(2 * idx + 1, mid + 1, en));
    }
}
ll query(ll st, ll en, ll l, ll r, ll idx)
{

    if (l <= st && r >= en)
        return rmq[idx];
    if (l > en || r < st)
    {
        return INT_MAX;
    }
    //2.Partial overlap
    ll mid = (st + en) / 2;
    return min(query(st, mid, l, r, 2 * idx), query(mid + 1, en, l, r, 2 * idx + 1));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    build_rmq(1, 0, n - 1);
    while (m--)
    {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << query(0, n - 1, l, r, 1) << "\n";
    }
}
