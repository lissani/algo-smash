// push, top, size, empty, pop

# include <iostream>
# include <queue>
# include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    queue<int> q;

    string cmd;
    int num;

    for (int i=0; i<n; i++){
        cin >> cmd;

        if (cmd=="push"){
            cin >> num;
            q.push(num);
        }
        else if (cmd=="front"){
            if (q.empty()) cout << -1 << endl;
            else cout << q.front() << endl;
        }
	else if (cmd=="back"){
            if (q.empty()) cout << -1 << endl;
            else cout << q.back() << endl;
        }
        else if (cmd=="size"){
            cout << q.size() << endl;
        }
        else if (cmd=="empty"){
            cout << q.empty() << endl;
        }
        else if (cmd=="pop"){
            if (q.empty()) cout << -1 << endl;
            else {
                cout << q.front() << endl;
                q.pop();
            }
            // cout << s.top() << endl;
            // s.pop();
        }
    }
}