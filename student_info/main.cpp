#include <iostream>
#include <set>
#include <vector>
#include <map>
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
        cout << *it;
        if (++it != v.end()) cout << ", ";
    }
    cout << "]\n";
}
int main()
{
    int n;
    cin >> n;
    map<string,vector<string>> data;
    for (int i = 0; i < n; i++){
        vector<string> data_split;
        data_split = input_split<string>();
        vector<string> data_2_to_end;
        for ( unsigned i = 1; i < data_split.size(); i++ ){
            data_2_to_end.push_back(data_split[i]);
        }
        data[data_split[0]] = data_2_to_end;
    }

    vector<string> f;
    f = input_split<string>();
    vector<vector<string>> out;

    for (auto k : data){
        bool is_subset = true;
        for (string c : f){
            if (find(k.second.begin(), k.second.end(), c) == k.second.end()){
                is_subset = false;
                break;
            }
        }

        if (is_subset == true){
            vector<string> temp;
            temp.push_back(k.first);
            for (auto e : k.second){
                temp.push_back(e);
            }
            out.push_back(temp);
        }
    }

    if ( out.size() == 0 ){
        cout << "Not Found" << "\n";
    } else {
        sort(out.begin(), out.end());
        for (auto c1 : out){
            for (auto c2 : c1 ){
                cout << c2 << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
