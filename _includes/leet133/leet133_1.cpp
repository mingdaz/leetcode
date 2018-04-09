/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {

public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<int,UndirectedGraphNode *> M;
        return clone(M,node);
    }
    UndirectedGraphNode *clone(unordered_map<int,UndirectedGraphNode *>& M,UndirectedGraphNode *node) {
        if(!node) return NULL;
        if(M.find(node->label) != M.end())
            return M[node->label];
        UndirectedGraphNode* temp = new UndirectedGraphNode(node->label);
        M[node->label] = temp;
        for(UndirectedGraphNode* n:node->neighbors){
            temp->neighbors.push_back(clone(M,n));
        }
        return temp;
    }
};
