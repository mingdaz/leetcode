class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        wordSet = set(wordList)
        if endWord not in wordSet:
            return 0
        beginSet = {beginWord}
        endSet = {endWord}
        charSet = set(string.ascii_lowercase)
        word_len = len(beginWord)
        ladder_len = 2

        while beginSet:
            if len(beginSet) > len(endSet):
                beginSet, endSet = endSet, beginSet
            nextLevelofBeginSet = set()
            for word in beginSet:
                for i in xrange(word_len):
                    word1, word2 = word[:i], word[i+1:]
                    for j in charSet:
                        candidate = word1 + j + word2
                        if candidate in endSet:
                            return ladder_len
                        if candidate in wordSet:
                            wordSet.remove(candidate)
                            nextLevelofBeginSet.add(candidate)
            beginSet = nextLevelofBeginSet
            ladder_len += 1
        return 0