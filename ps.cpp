#include <bits/stdc++.h>
#define int ll
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;
const ll INF = 0x3f3f3f3f;
template <typename... E>
void show(E... e);
#ifdef LOCAL
#include "show.hpp"
#else
#define show \
    if (false) show
#define endl '\n'
#endif
signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
    vvi adj{{3, 2, 4}, {1, 2, 3}};
    show(adj);
    unordered_multimap<int, int> m;
    m.emplace(3, 2);
    m.emplace(3, 2);
    m.emplace(3, 4);
    m.emplace(3, 1);
    show(m);
    show(pair<int, int>{3, 2});
    return 0;
}

/*

*/
