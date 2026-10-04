#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using vi = vector<int>;
using vl = vector<ll>;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using e = pair<ll, pll>;
#define ff first
#define ss second

struct node{int L = 0,R = 0;ll sum = 0;};
vector<node> st;

int nw()
{
    st.push_back(node());
    return st.size() - 1;
}


void ins(int u, int tl, int tr, int pos, int val)
{
    if(tl == tr){st[u].sum = val;return;}
    int tm = (tl + tr)/2;
    if(pos <= tm)
    {
        if(!st[u].L)st[u].L = nw();
        ins(st[u].L, tl, tm, pos, val);
    }
    else
    {
        if(!st[u].R)st[u].R = nw();
        ins(st[u].R, tm + 1, tr, pos, val);
    }
    st[u].sum = st[st[u].L].sum + st[st[u].R].sum;
}

ll que(int u, int tl, int tr, int l, int r)
{
    if(!u || tl > r || tr < l)return 0;
    if(tl >= l && tr <= r)return st[u].sum;
    int tm = (tl + tr)/2;
    return que(st[u].L, tl, tm, l, r) + que(st[u].R, tm + 1, tr, l, r);
}

void update(int u, int tl, int tr, int pos, int val)
{
    if(tl == tr){st[u].sum = val;return;}
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(nullptr);

    int n, q;
    cin>>n>>q;
    nw();
    nw();
    for(int i = 1 ; i <= n ; i++)
    {
        int x;
        cin>> x;
        ins(1, 1, n, i, x);
    }

    while(q--)
    {
        int l, r;
        int t;
        cin >> t;
        cin>>l>>r;
        if(t==1)
        {
            ins(1, 1, n, l, r);
        }
        else cout << que(1, 1, n, l, r) << '\n';
    }
}