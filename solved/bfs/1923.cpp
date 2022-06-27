//
// Created by heechan on 2022/06/27.
//

#include "pch.h"

using namespace std;
int N;
int M;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1}; // 상하좌우 네 방향을 의미

int board[502][502]; // 1이 파란 칸, 0이 빨간 칸에 대응
bool vis[502][502]; // 해당 칸을 방문했는지 여부를 저장

#define X first
#define Y second

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      cin >> board[i][j];

  int mx = 0; // 그림의 최댓값
  int num = 0; // 그림의 수

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j]==0 || vis[i][j])
        continue;

      num++;
      queue<pair<int, int>> Q;
      vis[i][j] = true;
      Q.push({i, j});
      int area = 0;

      while (!Q.empty()) {
        area++;
        auto cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++) {
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];

          if (nx < 0 || ny < 0 || nx >= N || ny >= M)
            continue;
          if (vis[nx][ny] || board[nx][ny]!=1)
            continue;

          vis[nx][ny] = true;
          Q.push({nx, ny});
        }
      }

      mx = max(mx, area);
    }
  }

  cout << num << '\n' << mx;

  return 0;
}
