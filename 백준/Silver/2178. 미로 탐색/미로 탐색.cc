#include <iostream>
#include <queue>
#include <utility> // for std::pair
#include <string> // 공백 없는 입력 처리 위해
#include <cstring> // memset 함수로 초기화하기 위해

using namespace std;

int n, m;
int board[101][101]; // 미로 데이터
int dist[101][101]; // 거리(방문 기록), 방문하지 않았으면 -1
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int startX, int startY) {
    queue<pair<int, int>> q;
    // 시작점을 큐에 넣기
    q.push({startX, startY});
    dist[startX][startY] = 1;
    
    // 핵심 동작: 큐에서 꺼내서 탐색 처리
    while(!q.empty()){
        // 큐에서 한칸 꺼내기 - 현재 위치
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        // 근처 가능한 칸 탐색 -> 큐에 삽입
        for (int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx>=0 && ny>=0 && nx<n && ny<m && board[nx][ny] && dist[nx][ny]<0){
                dist[nx][ny] = dist[x][y]+1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    memset(dist, -1, sizeof(dist));

    cin >> n >> m; // N*M 배열

    string l;

    for (int i=0; i<n; i++){
        cin >> l;
        for (int j=0; j<m; j++){
            board[i][j]=l[j]-'0';
        }
    }

    bfs(0,0);

    cout << dist[n-1][m-1];

    return 0;
}