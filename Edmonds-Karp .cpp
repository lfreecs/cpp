#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using vi = vector<int>;
using vl = vector<ll>;
using pil = pair<int, ll>;
ll const inf = 1e18;
struct edge
{
    ll to, cap;
};

int n, m;

vector<edge> edges;
vector<vi> al;
vi par;

void add(int u, int v, ll c)// añade la arista u -> v de capacidad c
{
    al[u].push_back(edges.size());//arista original
    edges.push_back({v, c});
    al[v].push_back(edges.size());//arista inversa
    edges.push_back({u, 0});
}

ll bfs(int s, int t)
{
    par.assign(n, -1);// -1 porque los nodos parten en 0
    par[s] = -2;// -2 para diferenciar de los demas nodos
    queue<pil> q;
    q.push({s, inf});

    while(!q.empty())
    {
        auto [u, flow] = q.front();q.pop();
        for(int id : al[u])
        {
            auto[v, capa] = edges[id];
            if(par[v] == -1 && capa > 0)
            {
                par[v] = id;
                ll mnflow = min(flow, capa);
                if(v == t)return mnflow;
                q.push({v, mnflow});
            }
        }
    }
    return 0;
}

ll edmond(int s, int t)
{
    ll totalflow = 0;
    while(true)
    {
        ll pushed = bfs(s, t);
        if(!pushed)break;//tamos listos
        totalflow += pushed;
        int cur = t;
        while(cur != s)
        {
            int id = par[cur];
            edges[id].cap -= pushed;
            edges[id ^ 1].cap += pushed;
            cur = edges[id ^ 1].to;
        }
    }
    return totalflow;
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(nullptr);
    cin >> n >> m;
    al.assign(n, vi());
    for(int i = 0 ; i < m ; i++)
    {
        int a, b;
        ll c;
        cin >> a>> b>>c;
        a--, b--;
        add(a, b, c);
    }

    cout << edmond(0, n-1)<<'\n';
    
    for(int u = 0 ; u < n ;u++)
    {
        if(par[u] != -1)
        {
            for(int id : al[u])
            {
                int v = edges[id].to;
                if(id % 2 == 0 && par[v]==-1)
                {
                    cout << u + 1 << ' ' << v + 1 << '\n';
                }
            }
        }
    }
}