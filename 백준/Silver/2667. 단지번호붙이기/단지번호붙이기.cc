#include <iostream>
#include <algorithm>
#include <vector>
#include <string> // 공백 없는 입력 처리 위해

using namespace std;

int n;
int board[101][101]; // 미로 데이터
int visited[101][101]; // 거리(방문 기록), 방문하지 않았으면 -1
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int cnt;
vector<int> result;

void dfs(int x, int y) {
    visited[x][y] = 1;
    cnt ++;

    for (int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx>=0 && ny>=0 && nx<n && ny<n && board[nx][ny] && visited[nx][ny]==0){
            dfs(nx,ny);
        }
    }
}

int main() {


    cin >> n; 

    string l;

    for (int i=0; i<n; i++){
        cin >> l;
        for (int j=0; j<n; j++){
            board[i][j]=l[j]-'0';
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if(board[i][j] == 1 && !visited[i][j]) {
                // 새로운 단지 발견
                cnt = 0; // 단지 내 집 개수 초기화
                dfs(i, j); // dfs가 끝나고 돌아오면 한 단지 탐색 완료
                result.push_back(cnt);
            }
        }
    }

    sort(result.begin(), result.end());
    
    cout << result.size() << endl;

    for (int i=0; i<result.size(); i++){
        cout << result[i] << endl;
    }

    return 0;
}