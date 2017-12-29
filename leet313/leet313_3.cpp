class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int K = primes.size(), res[n], pIdx[n], lastMul[n] ={}, i, curVal, curIdx;

        priority_queue<pair<int, int>> headHeap; // 
        for(res[0]=-1, i=0; i<K;++i)   headHeap.push(make_pair(-primes[i], i)); // first the ugly number value (change to negative to get the minimum one), second is the index of ugly number queues, i.e. candidates[i]

        for(i=1;i<n;++i)
        {
            curVal = headHeap.top().first;
            curIdx = headHeap.top().second;
            headHeap.pop();
            res[i] = curVal; pIdx[i] = curIdx; // pIdx is the index of the maximum prime factor
            while(pIdx[++lastMul[curIdx]]>curIdx); // skip ugly numbers whose maximum factor index is larger than curIdx.
            headHeap.push(make_pair(res[lastMul[curIdx]] * primes[curIdx], curIdx));
        }
        return -res[n-1];
    }
};
