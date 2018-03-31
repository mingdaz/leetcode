class Solution {
public:
  vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
    unordered_map<int, stack<int>> value_indices;
    for (int i = 0; i < B.size(); ++i) {
      value_indices[B[i]].push(i);
    }

    vector<int> result(A.size(), 0);
    for (int i = 0; i < A.size(); ++i) {
      auto &indices = value_indices[A[i]];
      result[i] = indices.top();
      indices.pop();
    }

    return result;
  }
};