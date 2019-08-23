#include <bits/stdc++.h>
#define MAX (int)1e5 + 1
using namespace std;
 
bitset<MAX> vis;
vector<int> graph[MAX];
int sz, n, q, ans, num[MAX], parent[MAX], low[MAX];
vector<pair<int, int>> criticalLinks;
 
void dfs(int no){
    vis[no] = true;
    num[no] = low[no] = sz++;
    for(int i = 0; i < graph[no].size(); i++){
        int child = graph[no][i];
        if(!vis[child]){
            parent[child] = no;
            dfs(child);
            if(low[child] > num[no]) {
              criticalLinks.push_back({ min(no, child), max(no, child) });
            }
            low[no] = min(low[no], low[child]);
        }else if(child != parent[no]) low[no] = min(low[no], num[child]);
    }
}
 
void ponte(){
    sz = 0;
    ans = 0;
    vis.reset();
    criticalLinks.clear();
    memset(low, -1, sizeof low);
    memset(num, -1, sizeof num);
    memset(parent, -1, sizeof parent);
    for (int i = 0; i < n; i++) {
      if (!vis[i]) dfs(i);
    }
}

int main() {

  int k;
  char c;
  int x, y, z;

  while (cin >> n) {
    // cin >> n;

    for(int i = 0; i <= n; i++) graph[i].clear();

    for (int i = 0; i < n; i++) {
      cin >> x >> c >> y >> c;
      for (int j = 0; j < y; j++) {
        cin >> z;
        graph[x].push_back(z);
        graph[z].push_back(x);
      }
    }

    ponte();

    // cout << "Case " << v << ":" << endl;
    cout << criticalLinks.size() << " critical links" << endl;

    sort(criticalLinks.begin(), criticalLinks.end());

    for (int g = 0; g < criticalLinks.size(); g++) {
      cout << criticalLinks[g].first << " - " << criticalLinks[g].second << endl;
    }
    cout << endl;
  }

  return 0;
}