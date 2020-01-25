/*
 * @lc app=leetcode id=432 lang=java
 *
 * [432] All O`one Data Structure
 *
 * https://leetcode.com/problems/all-oone-data-structure/description/
 *
 * algorithms
 * Hard (31.24%)
 * Likes:    466
 * Dislikes: 61
 * Total Accepted:    25.5K
 * Total Submissions: 81.7K
 * Testcase Example:  '["AllOne","getMaxKey","getMinKey"]\n[[],[],[]]'
 *
 * Implement a data structure supporting the following operations:
 * 
 * 
 * 
 * Inc(Key) - Inserts a new key  with value 1. Or increments an existing key by
 * 1. Key is guaranteed to be a non-empty string.
 * Dec(Key) - If Key's value is 1, remove it from the data structure. Otherwise
 * decrements an existing key by 1. If the key does not exist, this function
 * does nothing. Key is guaranteed to be a non-empty string.
 * GetMaxKey() - Returns one of the keys with maximal value. If no element
 * exists, return an empty string "".
 * GetMinKey() - Returns one of the keys with minimal value. If no element
 * exists, return an empty string "".
 * 
 * 
 * 
 * 
 * Challenge: Perform all these in O(1) time complexity.
 * 
 */

// @lc code=start
class AllOneII { 

    Map<String, Node> kv = new HashMap<>();
    Node head;
    Node tail;
    /** Initialize your data structure here. */
    public AllOneII() {
        head = new Node();
        tail = new Node();
        head.r = tail;
        tail.l = head;
    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    public void inc(String key) {
        if(kv.containsKey(key)){
            Node cur = kv.get(key);
            if(cur.keys.size()==1){
                if(cur.r.cnt==0 || cur.r.cnt > cur.cnt +1 ){
                    cur.cnt = cur.cnt + 1;
                } else {
                    cur.r.keys.add(key);
                    kv.put(key, cur.r);
                    delete(cur);
                }
            } else {
                cur.keys.remove(key);
                if(cur.r.cnt==0 || cur.r.cnt > cur.cnt +1 ){
                    Node node = new Node();
                    node.keys.add(key);
                    node.cnt = cur.cnt + 1;
                    kv.put(key, node);
                    insertAfter(node, cur);           
                } else {
                    cur.r.keys.add(key);
                    kv.put(key, cur.r);
                }
            }
        } else {
            if(head.r.cnt==1){
                head.r.keys.add(key);
                kv.put(key, head.r);
            } else {
                Node node = new Node();
                node.keys.add(key);
                node.cnt = 1;
                kv.put(key, node);
                insertAfter(node, head);
            }
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    public void dec(String key) {
        if(kv.containsKey(key)){
            Node cur = kv.get(key);
            if(cur.keys.size()==1){
                if(cur.cnt==1){
                    delete(cur);
                    kv.remove(key);
                } else if(cur.l.cnt==0 || cur.l.cnt < cur.cnt - 1){
                    cur.cnt -= 1;
                } else {
                    cur.l.keys.add(key);
                    kv.put(key, cur.l);
                    delete(cur);
                }
            } else {
                cur.keys.remove(key);
                if(cur.cnt==1){
                    kv.remove(key);
                } else if(cur.l.cnt==0 || cur.l.cnt < cur.cnt - 1){
                    Node node = new Node();
                    node.cnt = cur.cnt - 1;
                    node.keys.add(key);
                    kv.put(key, node);
                    insertAfter(node, cur.l);
                } else {
                    cur.l.keys.add(key);
                    kv.put(key, cur.l);
                }
            }
        }
    }
    
    /** Returns one of the keys with maximal value. */
    public String getMaxKey() {
        if(tail.l.cnt==0) return "";
        return tail.l.keys.iterator().next();
    }
    
    /** Returns one of the keys with Minimal value. */
    public String getMinKey() {
        if(head.r.cnt==0) return "";
        return head.r.keys.iterator().next();
    }

    private void delete(Node node){
        node.l.r = node.r;
        node.r.l = node.l;
        node.l = null;
        node.r = null;
    }

    private void insertAfter(Node node, Node cur){
        node.r = cur.r;
        cur.r.l = node;
        cur.r = node;
        node.l = cur;
    }
}

class Node{
    Set<String> keys;
    int cnt;
    Node l;
    Node r;
    Node(){
        keys = new HashSet<>();
    }
}

class AllOne {

    /** Initialize your data structure here. */
    class Node
    {
        String key;
        int val;
        Node next;
        Node pre;
        Node(String key)
        {
            this.key = key;
            val = 1;
            pre = null;
            next = null;
        }
    }
    
    HashMap<String, Node> map;
    Node head;
    Node tail;
    public AllOne() {
        map = new HashMap<>();
        head = new Node("");
        tail = new Node("");
        tail.pre = head;
        head.next = tail;
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    public void inc(String key) {
        if (!map.containsKey(key))
        {
            map.put(key, new Node(key));
            addKey(key);
        } else
        {
            map.get(key).val++;
            moveDown(key);
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    public void dec(String key) {
        if (!map.containsKey(key))
        {
            return;
        } else if(map.get(key).val == 1)
        {
            deleteKey(key);
        } else
        {
            map.get(key).val--;
            moveUp(key);
        }
        
    }
    
    /** Returns one of the keys with maximal value. */
    public String getMaxKey() {
        if (tail.pre != head)
        {
            return tail.pre.key;
        } else
        {
            return "";
        }
    }
    
    /** Returns one of the keys with Minimal value. */
    public String getMinKey() {
        if (head.next != tail)
        {
            return head.next.key;
        } else
        {
            return "";
        }
    }
    
    public void addKey(String key)
    {
        map.put(key, new Node(key));
        Node pre = head;
        Node next = head.next;
        Node cur = map.get(key);
        pre.next = cur;
        cur.pre = pre;
        cur.next = next;
        next.pre = cur;
        return;
    }
    
    public void deleteKey(String key)
    {
        Node cur = map.get(key);
        map.remove(key);
        Node pre = cur.pre;
        Node next = cur.next;
        pre.next = next;
        next.pre = pre;
        cur.next = null;
        cur.pre = null;
        return;
    }
    
    public void moveUp(String key)
    {
        Node cur = map.get(key);
        while (cur.pre != head && cur.val < cur.pre.val)
        {
            Node pre = cur.pre;
            exchange(cur, pre);
            cur = pre;
        }
        return;
    }
    
    public void moveDown(String key)
    {
        Node cur = map.get(key);
        while (cur.next != tail && cur.val > cur.next.val)
        {
            Node next = cur.next;
            exchange(next, cur);
            cur = next;
        }
        return;
    }
    
    public void exchange(Node n1, Node n2)
    {
        String tmpKey = n1.key;
        n1.key = n2.key;
        n2.key = tmpKey;
        int tmpVal = n1.val;
        n1.val = n2.val;
        n2.val = tmpVal;
        map.put(n1.key, n1);
        map.put(n2.key, n2);
    }
}
/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * String param_3 = obj.getMaxKey();
 * String param_4 = obj.getMinKey();
 */
// @lc code=end

