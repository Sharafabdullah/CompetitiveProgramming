#include <bits/stdc++.h>
using namespace std;
 
// Return the letter (from L, I, T) that is not equal to a or b (assumes a != b).
char missingChar(char a, char b) {
    if ((a=='L' && b=='I') || (a=='I' && b=='L')) return 'T';
    if ((a=='L' && b=='T') || (a=='T' && b=='L')) return 'I';
    if ((a=='I' && b=='T') || (a=='T' && b=='I')) return 'L';
    return '?'; // should not happen
}
 
// Count letters in the string s.
void countLetters(const string &s, int &cntL, int &cntI, int &cntT) {
    cntL = cntI = cntT = 0;
    for (char c : s) {
        if(c=='L') cntL++;
        else if(c=='I') cntI++;
        else if(c=='T') cntT++;
    }
}
 
// Check if string s is balanced.
bool isBalanced(const string &s) {
    if(s.size() % 3 != 0) return false;
    int cntL, cntI, cntT;
    countLetters(s, cntL, cntI, cntT);
    int target = s.size()/3;
    return (cntL==target && cntI==target && cntT==target);
}
 
// Try to simulate exactly candidate_m operations (insertions) to reach a balanced string.
// The operations are recorded in 'ops' (each is the 1-indexed position at which we insert).
// Return true if successful.
bool simulateCandidate(const string &original, int candidate_m, vector<int> &ops) {
    string s = original;
    int initL, initI, initT;
    countLetters(s, initL, initI, initT);
    int n = s.size();
    int finalLength = n + candidate_m;
    if(finalLength % 3 != 0) return false;
    int target = finalLength / 3;
    if(initL > target || initI > target || initT > target) return false;
    // Determine how many of each letter we must add.
    int reqL = target - initL, reqI = target - initI, reqT = target - initT;
 
    ops.clear();
    // We must perform exactly candidate_m operations.
    for (int op = 0; op < candidate_m; op++){
        // In each step, look for an allowed adjacent pair whose forced letter is still needed.
        int bestPos = -1, bestNeed = -1;
        char bestForced = ' ';
        for (int i = 0; i < (int)s.size()-1; i++){
            if(s[i] == s[i+1]) continue; // must be different
            char forced = missingChar(s[i], s[i+1]);
            int need = 0;
            if(forced == 'L') need = reqL;
            else if(forced == 'I') need = reqI;
            else if(forced == 'T') need = reqT;
            if(need > 0 && need > bestNeed){
                bestNeed = need;
                bestPos = i;
                bestForced = forced;
            }
        }
        if(bestPos == -1){
            // No allowed operation yields a needed letter.
            return false;
        }
        // Record the operation.
        // Note: positions are given in the current string (1-indexed).
        ops.push_back(bestPos + 1);
        // Insert the forced letter between s[bestPos] and s[bestPos+1].
        s.insert(s.begin() + bestPos + 1, bestForced);
        // Update the required count.
        if(bestForced=='L') reqL--;
        else if(bestForced=='I') reqI--;
        else if(bestForced=='T') reqT--;
    }
    return isBalanced(s);
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
 
        // If n==1 then no operation is possible.
        if(n == 1){
            cout << -1 << "\n";
            continue;
        }
 
        // Check if there is at least one allowed adjacent pair.
        bool validPairExists = false;
        for (int i = 0; i < n-1; i++){
            if(s[i] != s[i+1]){
                validPairExists = true;
                break;
            }
        }
        if(!validPairExists){
            cout << -1 << "\n";
            continue;
        }
 
        int cntL, cntI, cntT;
        countLetters(s, cntL, cntI, cntT);
 
        // Try candidate m values: m such that (n+m) is divisible by 3 and
        // (n+m)/3 >= max(cntL,cntI,cntT) and m <= 2*n.
        int bestCandidate = -1;
        vector<int> bestOps;
        for (int m = 0; m <= 2*n; m++){
            if((n + m) % 3 != 0) continue;
            int target = (n + m) / 3;
            if(cntL > target || cntI > target || cntT > target) continue;
            vector<int> ops;
            if(simulateCandidate(s, m, ops)){
                bestCandidate = m;
                bestOps = ops;
                break;
            }
        }
 
        if(bestCandidate == -1){
            cout << -1 << "\n";
        } else {
            cout << bestCandidate << "\n";
            for (int op : bestOps)
                cout << op << "\n";
        }
    }
 
    return 0;
}
