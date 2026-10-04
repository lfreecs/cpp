#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using vi = vector<int>;
using pii = pair<int, int>;
#define ff first
#define ss second

vector<pii> h;
vi cn;

bool hay(int cur, int b)
{
    if(!b)return h[cur].ff;
    else return h[cur].ss;
}

int crear()
{
    h.push_back(pii());
    cn.push_back(0);
    return h.size() - 1;
}

int ir(int cur, int bit)// debe retornar el indice al que me moveria
{
    if(!bit)return h[cur].ff;
    else return h[cur].ss;
}
void cam(int cur, int b, int val)
{
    if(!b)h[cur].ff = val;
    else h[cur].ss = val;
}

void ins(int x)// para un movimeinto, puede no existir el nodo, tener valor 0 , o ya tener valor
{
    int cur = 1;
    for(int i = 29 ; i >= 0 ; i--)
    {
        int b = (x >> i) & 1;
        if(!hay(cur, b))
        {
            cam(cur, b, crear());
        }
        cur = ir(cur, b);
        cn[cur]++;
    }
}

void del(int x)
{
    int cur = 1;
    for(int i = 29 ; i >= 0 ; i--)
    {
        int b = (x >> i) & 1;
        cur = ir(cur, b);
        cn[cur]--;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    h.assign(2, {0, 0});
    cn.assign(2, 0);
    ins(0);
    int q;
    cin >> q;
    while(q--)
    {
        char c;
        int x;
        cin >> c >> x;
        if(c == '+')ins(x);
        else if(c == '-')del(x);
        else
        {
            int ans = 0;
            int cur = 1;
            for(int i = 29 ; i >= 0 ; i--)
            {
                int b = (x >> i) & 1;
                if(hay(cur, b ^ 1) && cn[ir(cur, b ^ 1)])
                {
                    cur = ir(cur, b ^ 1);
                    ans += (1 << i);
                }
                else
                {
                    cur = ir(cur, b);
                }
            }
            cout << ans << '\n';
        }
    }
}