import com.sun.org.apache.xalan.internal.xsltc.runtime.Node;

/*
 * @lc app=leetcode id=138 lang=java
 *
 * [138] Copy List with Random Pointer
 *
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/
 *
 * algorithms
 * Medium (31.58%)
 * Likes:    2364
 * Dislikes: 561
 * Total Accepted:    330.1K
 * Total Submissions: 1M
 * Testcase Example:  '[[7,null],[13,0],[11,4],[10,2],[1,0]]\r'
 *
 * A linked list is given such that each node contains an additional random
 * pointer which could point to any node in the list or null.
 * 
 * Return a deep copy of the list.
 * 
 * The Linked List is represented in the input/output as a list of n nodes.
 * Each node is represented as a pair of [val, random_index] where:
 * 
 * 
 * val: an integer representing Node.val
 * random_index: the index of the node (range from 0 to n-1) where random
 * pointer points to, or null if it does not point to any node.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [[1,1],[2,1]]
 * Output: [[1,1],[2,1]]
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * 
 * Input: head = [[3,null],[3,0],[3,null]]
 * Output: [[3,null],[3,0],[3,null]]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: head = []
 * Output: []
 * Explanation: Given linked list is empty (null pointer), so return null.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * -10000 <= Node.val <= 10000
 * Node.random is null or pointing to a node in the linked list.
 * Number of Nodes will not exceed 1000.
 * 
 * 
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/
class Solution {
    public Node copyRandomList(Node head) {
        List<Node> list = new ArrayList<>();
        Node dummy = new Node(0);
        Node cur = dummy;
        Node src = head;
        int index = 0;
        while(src!=null){
            Node cpy = new Node(src.val);
            src.val = index++;
            list.add(cpy);
            cur.next = cpy;
            cur = cur.next;
            src = src.next;
        }
        src = head;
        cur = dummy.next;
        while(src!=null){
            if(src.random!=null)
                cur.random = list.get(src.random.val);
            cur = cur.next;
            src = src.next;
        }
        src = head;
        cur = dummy.next;
        while(src!=null){
            src.val = cur.val;
            cur = cur.next;
            src = src.next;
        }
        return dummy.next;
    }
}

// Solution II: recursive "dfs"
class Solution {
    HashMap<Node, Node> map = new HashMap<>();
    public Node copyRandomList(Node head) {
        if(head==null) return null;
        if(map.containsKey(head)) return map.get(head);
        Node cpy = new Node(head.val);
        map.put(head,cpy);
        cpy.next = copyRandomList(head.next);
        cpy.random = copyRandomList(head.random);
        return cpy;
    }
}

// Solution III: iterate order.
class Solution {
    Map<Node, Node> map = new HashMap<>();
    public Node copyRandomList(Node head) {
        if(head==null) return null;
        Node src = head;
        while(src!=null){
            Node cpy = getCloned(src);
            cpy.next = getCloned(src.next);
            cpy.random = getCloned(src.random);
            src = src.next;
        }
        return map.get(head);
    }
    
    private Node getCloned(Node src){
        if(src==null) return null;
        if(!map.containsKey(src)){
            Node cpy = new Node(src.val);
            map.put(src,cpy);
        }
        return map.get(src);
    }
}

public class Solution {
    public Node copyRandomList(Node head) {
  
      if (head == null) {
        return null;
      }
  
      // Creating a new weaved list of original and copied nodes.
      Node ptr = head;
      while (ptr != null) {
  
        // Cloned node
        Node newNode = new Node(ptr.val);
  
        // Inserting the cloned node just next to the original node.
        // If A->B->C is the original linked list,
        // Linked list after weaving cloned nodes would be A->A'->B->B'->C->C'
        newNode.next = ptr.next;
        ptr.next = newNode;
        ptr = newNode.next;
      }
  
      ptr = head;
  
      // Now link the random pointers of the new nodes created.
      // Iterate the newly created list and use the original nodes' random pointers,
      // to assign references to random pointers for cloned nodes.
      while (ptr != null) {
        ptr.next.random = (ptr.random != null) ? ptr.random.next : null;
        ptr = ptr.next.next;
      }
  
      // Unweave the linked list to get back the original linked list and the cloned list.
      // i.e. A->A'->B->B'->C->C' would be broken to A->B->C and A'->B'->C'
      Node ptr_old_list = head; // A->B->C
      Node ptr_new_list = head.next; // A'->B'->C'
      Node head_old = head.next;
      while (ptr_old_list != null) {
        ptr_old_list.next = ptr_old_list.next.next;
        ptr_new_list.next = (ptr_new_list.next != null) ? ptr_new_list.next.next : null;
        ptr_old_list = ptr_old_list.next;
        ptr_new_list = ptr_new_list.next;
      }
      return head_old;
    }
}
// @lc code=end

