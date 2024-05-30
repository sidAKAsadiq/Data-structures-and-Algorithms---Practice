#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Class to represent a state in DFA
class State {
public:
    int id;
    bool isFinal;
    unordered_map<char, int> transitions; // Transition map for each input symbol

    // Constructor
    State(int _id, bool _isFinal) : id(_id), isFinal(_isFinal) {}
};

// Class to represent a DFA
class DFA {
public:
    vector<State> states;
    int initialState;

    // Constructor
    DFA(int _initialState) : initialState(_initialState) {}

    // Add a state to the DFA
    void addState(State state) {
        states.push_back(state);
    }

    // Add a transition from 'fromState' to 'toState' on input symbol 'symbol'
    void addTransition(int fromState, char symbol, int toState) {
        states[fromState].transitions[symbol] = toState;
    }

    // Print the transition table of the DFA
    void printTransitionTable() {
        cout << "Transition Table:\n";
        for (const auto& state : states) {
            cout << "State " << state.id << ":\n";
            for (const auto& [symbol, nextState] : state.transitions) {
                cout << "  Input: " << symbol << " -> Next State: " << nextState << "\n";
            }
            cout << "  Final State: " << (state.isFinal ? "Yes" : "No") << "\n";
        }
    }

    // Implement DFA minimization using table-filling algorithm
    void minimize() {
        vector<vector<bool>> distinguishable(states.size(), vector<bool>(states.size(), false));

        // Mark final and non-final states as distinguishable
        for (int i = 0; i < states.size(); ++i) {
            for (int j = 0; j < states.size(); ++j) {
                if ((states[i].isFinal && !states[j].isFinal) || (!states[i].isFinal && states[j].isFinal)) {
                    distinguishable[i][j] = true;
                }
            }
        }

        bool changed = true;
        while (changed) {
            changed = false;
            for (int i = 0; i < states.size(); ++i) {
                for (int j = 0; j < i; ++j) {
                    if (!distinguishable[i][j]) {
                        for (const auto& [symbol, nextState] : states[i].transitions) {
                            char transitionSymbol = symbol;
                            int nextStateI = nextState;
                            int nextStateJ = states[j].transitions[transitionSymbol];
                            if (distinguishable[nextStateI][nextStateJ] || distinguishable[nextStateJ][nextStateI]) {
                                distinguishable[i][j] = true;
                                changed = true;
                                break;
                            }
                        }
                    }
                }
            }
        }

        // Merge indistinguishable states
        vector<int> representative(states.size());
        for (int i = 0; i < states.size(); ++i) {
            representative[i] = i;
        }

        for (int i = 0; i < states.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (!distinguishable[i][j]) {
                    int repI = findRepresentative(representative, i);
                    int repJ = findRepresentative(representative, j);
                    if (repI != repJ) {
                        representative[max(repI, repJ)] = min(repI, repJ);
                    }
                }
            }
        }

        // Update states with merged states
        vector<State> newStates;
        vector<int> stateMapping(states.size(), -1);
        int newStateCount = 0;
        for (int i = 0; i < states.size(); ++i) {
            int rep = findRepresentative(representative, i);
            if (stateMapping[rep] == -1) {
                stateMapping[rep] = newStateCount++;
                newStates.push_back(states[i]);
            }
        }

        for (auto& state : newStates) {
            for (auto& [symbol, nextState] : state.transitions) {
                nextState = stateMapping[findRepresentative(representative, nextState)];
            }
        }

        states = newStates;
    }

private:
    // Find representative of the equivalence class
    int findRepresentative(const vector<int>& representative, int state) {
        if (state == representative[state]) {
            return state;
        }
        return representative[state] = findRepresentative(representative, representative[state]);
    }
};

int main() {
    cout << "Welcome to DFA minimization program!\n"
            "Consider the following points:\n"
            "1. We have predefined input symbols as 'a' and 'b'\n"
            "2. You are required to enter the number of states, their transitions, and whether they are final or non-final\n"
            "3. A transition table of the given DFA will be printed\n"
            "4. The answer will show you the minimized DFA from the given information in the form of a transition table\n";

    int initialState;
    cout << "Enter initial state: ";
    cin >> initialState;

    DFA dfa(initialState);

    int numStates;
    cout << "Enter the number of states: ";
    cin >> numStates;

    for (int i = 0; i < numStates; ++i) {
        bool isFinal;
        cout << "Is state " << i << " final? (1 for Yes, 0 for No): ";
        cin >> isFinal;
        dfa.addState(State(i, isFinal));
    }

    int numTransitions;
    cout << "Enter the number of transitions: ";
    cin >> numTransitions;

    for (int i = 0; i < numTransitions; ++i) {
        int fromState, toState;
        char symbol;
        cout << "Transition " << i + 1 << " (from state, input symbol, to state): ";
        cin >> fromState >> symbol >> toState;
        dfa.addTransition(fromState, symbol, toState);
    }

    cout << "\nOriginal DFA:\n";
    dfa.printTransitionTable();

    // Minimize the DFA
    dfa.minimize();

    cout << "\nMinimized DFA:\n";
    dfa.printTransitionTable();

    return 0;
}
