// Created by Arseniy Arsentyew <programpro.ars@gmail.com>
// Sharing with the MIT license

// class DisjointSet:
//     information - (value, (parent, rank))
//
//     makeSet(i) - creates set with value (i)
//     getInfo(i) - returns information about (i)
//     setRank(ind, val) - set (ind)th rank to val
//     setParent(ind, val) - set (ind)th parent to val
//     find(i) - finds set (i)
//     unionSets(i, j) - concatenate set (i) with set (j)
//     print() - prints disjoint set

#include <bits\stdc++.h>

using namespace std;

// Disjoint set realisation
class DisjointSet {
    public: 
        vector<pair<int, pair<int, int>>> information;

        void makeSet(int i) {
            information.push_back(make_pair(i, make_pair(i, 0)));
        }

        pair<int, pair<int, int>> getInfo(int ind) {
            for (int i = 0; i < information.size(); i++) {
                if (information[i].first == ind) {
                    return information[i];
                }
            }
            return make_pair(0, make_pair(0, 0));
        }

        void setRank(int ind, int val) {
            for (int i = 0; i < information.size(); i++) {
                if (information[i].first == ind) {
                    information[i].second.second = val;
                }
            }
        }

        void setParent(int ind, int val) {
            for (int i = 0; i < information.size(); i++) {
                if (information[i].first == ind) {
                    information[i].second.first = val;
                }
            }
        }

        int find(int i) {
            while (i != getInfo(i).second.first) {
                i = getInfo(i).second.first;
            }
            return i;
        }

        void unionSets(int i, int j) {
            int i_id = find(i);
            int j_id = find(j);
            if (i_id == j_id) {
                return;
            }
            if (getInfo(i_id).second.second > getInfo(j_id).second.second) {
                setParent(j_id, i_id);
            }
            else {
                setParent(i_id, j_id);
                if (getInfo(i_id).second.second == getInfo(j_id).second.second) {
                    setRank(j_id, getInfo(j_id).second.second + 1);
                }
            }
        }

        void print() {
            for (int i = 0; i < information.size(); i++) {
                cout << information[i].first << ' ';
                cout << information[i].second.first << ' ';
                cout << information[i].second.second << '\n';
            }
        }
};

// Example CLI
int main() {
    DisjointSet disjointSet;
    string input;
    cout << "Disjoint set has been created\n";
    cout << "-: ";
    while(cin >> input) {
        if (input == "makeSet") {
            int key;
            cin >> key;
            disjointSet.makeSet(key);
            disjointSet.print();
        }
        else if (input == "find") {
            int val;
            cin >> val;
            cout << disjointSet.find(val) << '\n';
        }
        else if (input == "unionSets") {
            int s1, s2;
            cin >> s1 >> s2;
            disjointSet.unionSets(s1, s2);
            disjointSet.print();
        }  
        else {
            break;
        }
        cout << "-: ";
    }
    return 0;
}   