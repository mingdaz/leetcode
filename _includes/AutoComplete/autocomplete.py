from heapq import heappush, heappop


class Trie:
	def __init__(self):
		self.root = {}
		self.end = -1

	def add(self, word: str, val: int):
		curNode = self.root
		for c in word:
			if c not in curNode:
				curNode[c] = {}
			curNode = curNode[c]
		curNode[self.end] = val

	def startwith(self, prefix: str):
		curNode = self.root
		for c in prefix:
			if c not in curNode:
				curNode[c] = {}
			curNode = curNode[c]		
		heap = []
		self.dfs(curNode, prefix, heap)
		suggest_list = []
		while heap:
			score, word = heappop(heap)
			suggest_list.append("%s %d"%(word,score)) 
		return suggest_list


	def dfs(self,node: dict, prefix: str, heap):
		for idx in node:
			if idx==self.end:
				heappush(heap, (node[idx],prefix))
			else:
				self.dfs(node[idx],prefix+idx,heap)


def main(dictpath,filepath):
	t = Trie()
	with open(dictpath,'r') as f:
		for line in f:
			word,score = line.strip().split(" ", 1)
			t.add(word,int(score))
	with open(filepath,'r') as f:
		for line in f:
			prefix = line.strip()
			print(t.startwith(prefix))


if __name__ == '__main__':
	dictpath = "./dict.txt"
	filepath = "./test.txt"
	main(dictpath,filepath)