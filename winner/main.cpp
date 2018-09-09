#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

template <class T>
vector<T> input_split() {
    cin >> ws;
    string line;
    getline(cin, line);
    stringstream ss(line);
    T buf;
    vector<T> tokens;
    while (ss >> buf)
        tokens.push_back(buf);
    return tokens;
}

template <class T>
void print(vector<T> v) {
    cout << "[";
    for (auto it=v.begin(); it!=v.end();) {
        cout << "'" <<*it << "'";
        if (++it != v.end()) cout << ", ";
    }
    cout << "]\n";
}

int main()
{
    int n;
    cin >> n;
    vector<string> winner;
    vector<string> loser;
    for (int i = 0; i < n; i++){
        vector<string> result;
        result = input_split<string>();
        if ( find(winner.begin(), winner.end(), result[0]) == winner.end() ){
            winner.push_back(result[0]);
        }
        if (find(loser.begin(), loser.end(), result[1]) == loser.end()){
            loser.push_back(result[1]);
        }
    }
    vector<string> out;

    for (string c : winner){
        if ( find(loser.begin(), loser.end(), c) == loser.end() ){
            out.push_back(c);
        }
    }
    sort(out.begin(), out.end());
    print(out);
    return 0;
}
