#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using vl = vector<ll>;
using vi = vector<int>;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using vs = vector<string>;
using pdi = pair<double, int>;
using vpp = vector<pll>;
#define ff first
#define ss second

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int randint(int lo, int hi)
{
    uniform_int_distribution<int> dist(lo, hi);
    return dist(rng);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
}
