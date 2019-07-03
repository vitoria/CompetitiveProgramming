#include <bits/stdc++.h>
#define MAX 100

using namespace std;

char puzzle[MAX][MAX];
int visited[MAX][MAX];
bool ans;
int n, m;

void dfs(int x, int y, int px, int py){
	visited[x][y] = true;
	
	if (x+1 < n && (x+1 != px || y != py) && puzzle[x+1][y] == puzzle[x][y]) {
		if (visited[x+1][y]) ans = true;
		else dfs(x+1, y, x, y);
	}
	
	if (x-1 >= 0 && (x-1 != px || y != py) && puzzle[x-1][y] == puzzle[x][y]) {
		if (visited[x-1][y]) ans = true;
		else dfs(x-1, y, x, y);
	}
	
	if (y+1 < m && (x != px || y+1 != py) && puzzle[x][y+1] == puzzle[x][y]) {
		if (visited[x][y+1]) ans=true;
		else dfs(x,y+1,x,y);
	}
	
	if (y-1 >= 0 && (x != px || y-1 != py) && puzzle[x][y-1] == puzzle[x][y]) {
		if (visited[x][y-1]) ans = true;
		else {
      dfs(x, y-1, x, y);
    }
	}
	
}

int main(){

	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> puzzle[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) {
				dfs(i, j, -1, -1);
			}
		}
	}
	
	cout << (ans ? "Yes\n" : "No\n");
	
	
  return 0;
}