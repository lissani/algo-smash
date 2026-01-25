// push, top, size, empty, pop

# include <iostream>
# include <stack>
# include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> s;

    string cmd;
    int num;

    for (int i=0; i<n; i++){
        cin >> cmd;

        if (cmd=="push"){
            cin >> num;
            s.push(num);
        }
        else if (cmd=="top"){
            if (s.empty()) cout << -1 << endl;
            else cout << s.top() << endl;
        }
        else if (cmd=="size"){
            cout << s.size() << endl;
        }
        else if (cmd=="empty"){
            cout << s.empty() << endl;
        }
        else if (cmd=="pop"){
            if (s.empty()) cout << -1 << endl;
            else {
                cout << s.top() << endl;
                s.pop();
            }
            // cout << s.top() << endl;
            // s.pop();
        }
    }
}