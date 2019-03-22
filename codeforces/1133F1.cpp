#include <bits/stdc++.h>
#define MAX 200100
#define ll long long

using namespace std;

ll v, a, x, y;
vector<ll> graph[MAX];
ll index_with_max_degree = 0;
bool visited[MAX];
vector<pair<ll, ll>> ans;

void bfs() {
    queue<ll> to_process;
    to_process.push(index_with_max_degree);
    ll current_vertice;
    pair<ll, ll> bla;
    visited[index_with_max_degree] = true;
    while (!to_process.empty()) {
        current_vertice = to_process.front();
        to_process.pop();
        for (ll i = 0; i < graph[current_vertice].size(); i++) {
            if (!visited[graph[current_vertice][i]]) {
                to_process.push(graph[current_vertice][i]);
                bla.first = current_vertice;
                bla.second = graph[current_vertice][i];
                ans.push_back(bla);
            }
            visited[graph[current_vertice][i]] = true;
        }
    }
}

int main() {

    cin >> v >> a;

    for (ll i = 0; i < a; i++) {
        cin >> x >> y;
        x -= 1; y-=1;
        graph[x].push_back(y);
        graph[y].push_back(x);
        if (graph[x].size() > graph[index_with_max_degree].size()) index_with_max_degree = x;
        if (graph[y].size() > graph[index_with_max_degree].size()) index_with_max_degree = y;
    }

    bfs();

    for (ll i = 0; i < ans.size(); i++) {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
    }

    return 0;
}