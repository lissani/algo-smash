#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int len;
	int num;
	cin >> len;

	vector<int> v;

	for (int i=0; i<len; i++){
		cin >> num;
		v.push_back(num);
	}
	
	sort(v.begin(), v.end());

	for (int i=0; i<len; i++){
		cout << v[i] << endl;
	}
}