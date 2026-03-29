#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

using namespace std;

int main() {

    vector<int> arr = {1, 2, 1, 3, 2, 1};

    unordered_map<int, int> mp;

    for (int i = 0; i < arr.size(); i++) {
        mp[arr[i]]++;
    }

    for (auto it : mp) {
        cout << it.first << " -> " << it.second << endl;
    }

    return 0;
}
