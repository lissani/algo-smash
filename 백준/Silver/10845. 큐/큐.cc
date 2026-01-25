#include <iostream>
#include <string>

using namespace std;

class queue {
private:
    int arr[10000]; // 큐의 원소를 저장하는 배열
    int q_size;
    int front_pos;
    int back_pos;
public:
    queue() {
        q_size = 0;
        front_pos = 0;
        back_pos = 0;
    }
    void push(int elem) {
        arr[++back_pos] = elem; // index 1부터 저장
        q_size++;
        if (front_pos == 0) front_pos = 1;
    }
    int pop() {
        if (q_size != 0) {
            int top = arr[front_pos];
            front_pos++;
            q_size--;
            return top;
        }
        return -1;
    }
    int size() {
        return q_size;
    }
    void empty() {
        if(q_size == 0){
            cout << 1 << endl;
        }
        else cout << 0 << endl;
    }
    void front() {
        if (q_size == 0) {
            cout << -1 << endl;
        }
        else cout << arr[front_pos] << endl;
    }
    void back() {
        if (q_size == 0) {
            cout << -1 << endl;
        }
        else cout << arr[back_pos] << endl;
    }
};

int main(void) {
    int N;
    cin >> N;

    string order;
    int num;

    queue q;

    for (int i = 0; i < N; i++) {
        cin >> order;

        if (order == "push") {
            cin >> num;
            q.push(num);
        }
        if (order == "pop") {
            num = q.pop();
            cout << num << endl;
        }
        if (order == "size") {
            num = q.size();
            cout << num << endl;
        }
        if (order == "empty") {
            q.empty();
        }
        if (order == "front") {
            q.front();
        }
        if (order == "back") {
            q.back();
        }
    }
    return 0;
}