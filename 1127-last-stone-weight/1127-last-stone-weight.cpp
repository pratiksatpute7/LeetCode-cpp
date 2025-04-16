class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        for(int stone : stones){
            maxHeap.push(stone);
        }

        while(maxHeap.size() >= 2) {
            int max = maxHeap.top();
            maxHeap.pop();
            int nextMax = maxHeap.top();
            maxHeap.pop();

            if(max == nextMax) {
                continue;
            } else {
                max -= nextMax;
                maxHeap.push(max);
            }
        }

        if(!maxHeap.empty()) {
            return maxHeap.top();
        } else {
            return 0;
        }
    }
};