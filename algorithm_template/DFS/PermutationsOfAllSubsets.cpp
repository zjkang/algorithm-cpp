// https://app.laicode.io/app/problem/643

// All Permutations of Subsets

// Given a string with no duplicate characters, return a list with all permutations of
// the string and all its subsets.
// Examples
// Set = “abc”, all permutations are [“”, “a”, “ab”, “abc”, “ac”, “acb”, “b”, “ba”, “bac”,
// “bc”, “bca”, “c”, “cb”, “cba”, “ca”, “cab”].
// Set = “”, all permutations are [“”].
// Set = null, all permutations are [].

class Solution {
    vector<string> result = {""};
    vector<string> allPermutationsOfSubsets(string set) {
        dfs(set, 0);
        return result;
    }
    // permutation all tree nodes altogether come to the result
    void dfs(string& set, int index) {
        if (index == set.size()) return;
        for (int i = index; i < set.size(); i++) {
            swap(set[index], set[i]);
            result.push_back(set.substr(0, index+1));
            dfs(set, index+1);
            swap(set[index], set[i]);
        }
    }
}
