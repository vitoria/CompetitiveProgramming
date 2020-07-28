#include <bits/stdc++.h>
#define MAXN int(1e5)

using namespace std;

int binary_tree[MAXN][2];

void insert(int node, int value) {
  if (value > node) {
    if (binary_tree[node][1] == -1) {
      binary_tree[node][1] = value;
    } else {
      insert(binary_tree[node][1], value);
    }
  } else {
    if (binary_tree[node][0] == -1) {
      binary_tree[node][0] = value;
    } else {
      insert(binary_tree[node][0], value);
    }
  }
}

void bfs(int root) {
  int current;
  bool printed = false;
  queue<int> nextNodes;
  nextNodes.push(root);

  while(!nextNodes.empty()) {
    current = nextNodes.front();
    nextNodes.pop();

    if (binary_tree[current][0] != -1) nextNodes.push(binary_tree[current][0]);
    if (binary_tree[current][1] != -1) nextNodes.push(binary_tree[current][1]);

    cout << (printed ? " " : "") << current;
    printed = true;
  }

  cout << "\n\n";
}

int main() {

  int qty_tests, qty_nodes, value, root;

  scanf("%d", &qty_tests);

  for (int i = 0; i < qty_tests; i++) {
    memset(binary_tree, -1, MAXN*2);
    scanf("%d", &qty_nodes);
    scanf("%d", &root);
    for (int j = 1; j < qty_nodes; j++) {
      scanf("%d", &value);
      insert(root, value);
    }

    cout << "Case " << (i + 1) << ":\n";
    bfs(root);
  }

  return 0;
}