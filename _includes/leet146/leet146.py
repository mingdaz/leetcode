from collections import OrderedDict

class LRUCache:

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.dict = OrderedDict()
        self.cap = capacity

        
    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key in self.dict:
            self.dict.move_to_end(key)
        return self.dict.get(key,-1)
        
        

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: void
        """
        self.dict[key] = value
        self.dict.move_to_end(key)
        if len(self.dict) > self.cap:
            self.dict.popitem(last=False)


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)