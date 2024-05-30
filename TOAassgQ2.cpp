#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 100; 

//this is helper func to find indexes
int find_index(int state, vector<vector<int>> partition[2]) {
    for(int i = 0; i < partition[0].size(); i++) {
        for(int j = 0; j < partition[0][i].size(); j++) {
            if(partition[0][i][j] == state) return i;
        }
    }
    return -1; 
}

// first we'll mark final states
void mark_final_states(int num_of_final_states, bool is_final_state[N]) {
    cout<<"Marking final states....\n";
    for(int i = 0; i < num_of_final_states; i++) {
        int final_state;
        cout<<"Mark final state no. "<<i+1<<endl;
        cin >> final_state;
        is_final_state[final_state] = true;
    }
}

// secondly we will create trans table
void create_transition_table(int num_of_states, int num_of_inputs, int transition_table[N][N]) {
    cout<<"\nMaking transition table...\n\n";
    for(int i = 0; i < num_of_states; i++) {
        cout<<"Mark transitions on all inputs of state no. "<<i<<endl;
        for(int j = 0; j < num_of_inputs; j++) {
            cin >> transition_table[i][j];
        }
    }
}

// now we'll make initial divisions that is nonfinal vs final
void make_initial_partition(int num_of_states, bool is_final_state[N], vector<vector<int>> partition[2]) {
    vector<int> classes[2];
    for(int i = 0; i < num_of_states; i++) {
        classes[is_final_state[i]].push_back(i);
    }
    partition[0].push_back(classes[0]);
    partition[0].push_back(classes[1]);
    partition[1] = partition[0];
}

// now we'll work towards the sub divisions until no more groups having opposite transitions are left
void minimizer(vector<vector<int>> partition[2], int transition_table[N][N], int num_of_states, int num_of_inputs, bool is_final_state[N], int num_of_final_states) {
    int iterations = 100;
    while(iterations--) {
        partition[0] = partition[1];
        for(int i = 0; i < partition[1].size(); i++) {
            for(int j = 1; j < partition[1][i].size(); j++) {
                bool placed = false;
                for(int k = 0; k < j; k++) {
                    bool comparison = true;
                    for(int l = 0; l < num_of_inputs; l++) {
                        if(find_index(transition_table[partition[1][i][j]][l], partition) != find_index(transition_table[partition[1][i][k]][l], partition)) {
                            comparison = false;
                            break;
                        }
                    }
                    if(comparison) {
                        placed = true;
                        break;
                    }
                }
                if(placed) continue;
                for(int x = partition[0].size(); x < partition[1].size(); x++) {
                    for(int k = 0; k < partition[1][x].size(); k++) {
                        bool comparison = true;
                        for(int l = 0; l < num_of_inputs; l++) {
                            if(find_index(transition_table[partition[1][i][j]][l], partition) != find_index(transition_table[partition[1][x][k]][l], partition)) {
                                comparison = false;
                                break;
                            }
                        }
                        if(comparison) {
                            partition[1][x].push_back(partition[1][i][j]);
                            partition[1][i].erase(partition[1][i].begin() + j);
                            placed = true;
                            break;
                        }
                    }
                    if(placed) break;
                }
                if(placed) continue;
                vector<int> new_class;
                new_class.push_back(partition[1][i][j]);
                partition[1].push_back(new_class);
                partition[1][i].erase(partition[1][i].begin() + j);
            }
        }
        for(int i = 0; i < partition[0].size(); i++) {
            sort(partition[0][i].begin(), partition[0][i].end());
        }
        sort(partition[0].begin(), partition[0].end());
        for(int i = 0; i < partition[1].size(); i++) {
            sort(partition[1][i].begin(), partition[1][i].end());
        }
        sort(partition[1].begin(), partition[1].end());
        if(partition[0] == partition[1]) break;
    }
}

// finally prints the answer
void print_minimized_dfa(int num_of_inputs, int num_of_states, vector<vector<int>> partition[2], int transition_table[N][N], bool printed[N]) {
    cout << "\nMinimized DFA Transition Table:\n";
    cout << "States\t";
    for(int j = 0; j < num_of_inputs; j++) cout << j << "\t";
    cout << endl << endl;
    for(int i = 0; i < num_of_states; i++) {
        if(printed[i]) continue;
        int ind = find_index(i, partition);
        cout << "[";
        for(int k = 0; k < partition[0][ind].size(); k++) {
            cout << partition[0][ind][k];
            printed[partition[0][ind][k]] = true;
        }
        cout << "]\t";
        for(int j = 0; j < num_of_inputs; j++) {
            ind = find_index(transition_table[i][j], partition);
            cout << "[";
            for(int k = 0; k < partition[0][ind].size(); k++) {
                cout << partition[0][ind][k];
            }
            cout << "]\t";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    cout<<"Welcome to DFA minimization program, Note the following:\n1.You are required to add number of states, input symbols and final states.\n2.Then you are required to create a transition table\n3.Resultant would be the transition table of minimized DFA\nNOTE : The input symbols are starting from 0 - n.\n\n";
    int transition_table[N][N]; 
    bool is_final_state[N]; 
    bool printed[N];
    vector<vector<int>> partition[2]; 

    int num_of_states, num_of_inputs, num_of_final_states;
    cout<<"Enter Number of states , Number of input symbols and Number of final states\n";
    cin >> num_of_states >> num_of_inputs >> num_of_final_states;
    cout<<endl;
    mark_final_states(num_of_final_states, is_final_state);
    create_transition_table(num_of_states, num_of_inputs, transition_table);
    make_initial_partition(num_of_states, is_final_state, partition);
    minimizer(partition, transition_table, num_of_states, num_of_inputs, is_final_state, num_of_final_states);
    print_minimized_dfa(num_of_inputs, num_of_states, partition, transition_table, printed);
    return 0;
}
