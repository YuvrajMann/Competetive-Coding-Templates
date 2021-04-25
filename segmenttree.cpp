#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
vector<int> tree(2 * 1000);
int A[7] = {1, 11, 3, 5, 4, 9, 10};
//sum range queries
void build(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = A[start];
    }
    else
    {
        int mid = (start + end) / 2;
        build(2 * node + 1, start, mid);
        build(2 * node + 2, mid + 1, end);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
}
void update(int node, int start, int end, int idx, int val)
{
    if (start == end)
    {
        // Leaf node
        A[idx] += val;
        tree[node] += val;
    }
    else
    {
        int mid = (start + end) / 2;
        if (start <= idx and idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(2 * node + 1, start, mid, idx, val);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(2 * node + 2, mid + 1, end, idx, val);
        }
        // Internal node will have the sum of both of its children
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
}
int query(int node, int start, int end, int l, int r)
{
    if (r < start or end < l)
    {
        // range represented by a node is completely outside the given range
        return 0;
    }
    if (l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    int p1 = query(2 * node + 1, start, mid, l, r);
    int p2 = query(2 * node + 2, mid + 1, end, l, r);
    return (p1 + p2);
}
int main()
{
    build(0, 0, 6);
    cout << endl;
    cout << query(0, 0, 6, 1, 3) << endl;
    //add certain value
    update(0, 0, 6, 2, 11);
    cout << query(0, 0, 6, 1, 3) << endl;
    return 0;
}