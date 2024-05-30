#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 100 ; 

int idx(int x , vector<vector<int>> pi[2]) {
    for(int i = 0; i < pi[0].size(); i++) {
        for(int j = 0; j < pi[0][i].size(); j++) {
            if(pi[0][i][j] == x) return i;
        }
    }
    return -1; 
}

void markFinalStates(int nfs ,bool fs[N]) {
    for(int i = 0; i < nfs; i++) {
        int finalState;
        cin >> finalState;
        fs[finalState] = true;
    }
}

void initializeTransitionTable(int n , int m , int t[N][N]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> t[i][j];
        }
    }
}

void initializeEquivalenceClasses( int n , bool fs[N] , vector<vector<int>> pi[2]) {
    vector<int> v[2];
    for(int i = 0; i < n; i++) {
        v[fs[i]].push_back(i);
    }
    pi[0].push_back(v[0]);
    pi[0].push_back(v[1]);
    pi[1] = pi[0];
}

void decomposeEquivalenceClasses(vector<vector<int>> pi[2] ,int t[N][N] , int n , int m , bool fs[N] , int nfs) {
    int iterations = 100;
    while(iterations--) {
        pi[0] = pi[1];
        for(int i = 0; i < pi[1].size(); i++) {
            for(int j = 1; j < pi[1][i].size(); j++) {
                bool placed = false;
                for(int k = 0; k < j; k++) {
                    bool comparision = true;
                    for(int l = 0; l < m; l++) {
                        if(idx(t[pi[1][i][j]][l] , pi) != idx(t[pi[1][i][k]][l] , pi )) {
                            comparision = false;
                            break;
                        }
                    }
                    if(comparision) {
                        placed = true;
                        break;
                    }
                }
                if(placed) continue;
                for(int x = pi[0].size(); x < pi[1].size(); x++) {
                    for(int k = 0; k < pi[1][x].size(); k++) {
                        bool comparision = true;
                        for(int l = 0; l < m; l++) {
                            if(idx(t[pi[1][i][j]][l] , pi) != idx(t[pi[1][x][k]][l] , pi )) {
                                comparision = false;
                                break;
                            }
                        }
                        if(comparision) {
                            pi[1][x].push_back(pi[1][i][j]);
                            pi[1][i].erase(pi[1][i].begin() + j);
                            placed = true;
                            break;
                        }
                    }
                    if(placed) break;
                }
                if(placed) continue;
                vector<int> vv;
                vv.push_back(pi[1][i][j]);
                pi[1].push_back(vv);
                pi[1][i].erase(pi[1][i].begin() + j);
            }
        }
        for(int i = 0; i < pi[0].size(); i++) {
            sort(pi[0][i].begin(), pi[0][i].end());
        }
        sort(pi[0].begin(), pi[0].end());
        for(int i = 0; i < pi[1].size(); i++) {
            sort(pi[1][i].begin(), pi[1][i].end());
        }
        sort(pi[1].begin(), pi[1].end());
        if(pi[0] == pi[1]) break;
    }
}

void printMin(int m , int n , vector<vector<int>> pi[2] ,int t[N][N] , bool printed[N]) {
    cout << "\nMinimised DFA Table:\n";
    cout << "---------------------\n";
    cout << "Q\t";
    for(int j = 0; j < m; j++) cout << j << "\t";
    cout << endl << endl;
    for(int i = 0; i < n; i++) {
        if(printed[i]) continue;
        int ind = idx(i , pi);
        cout << "[";
        for(int k = 0; k < pi[0][ind].size(); k++) {
            cout << pi[0][ind][k];
            printed[pi[0][ind][k]] = true;
        }
        cout << "]\t";
        for(int j = 0; j < m; j++) {
            ind = idx(t[i][j] , pi);
            cout << "[";
            for(int k = 0; k < pi[0][ind].size(); k++) {
                cout << pi[0][ind][k];
            }
            cout << "]\t";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {

int t[N][N]; 
bool fs[N]; 
bool printed[N];
vector<vector<int>> pi[2]; 

int n, m, nfs;
    cin >> n >> m >> nfs;
    markFinalStates(nfs , fs);
    initializeTransitionTable(n , m , t);
    initializeEquivalenceClasses(n , fs , pi);
    decomposeEquivalenceClasses(pi , t , n , m , fs , nfs);
    printMin(m , n , pi , t , printed);
    return 0;
}