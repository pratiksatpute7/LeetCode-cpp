class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> taskCount;
        priority_queue<int> maxHeap;

        for(char task : tasks) {
            taskCount[task]++;
        }

        for(auto task : taskCount) {
            maxHeap.push(task.second);
        }

        int time = 0;
        while(!maxHeap.empty()) {
            // if A is sched at 0 then it can be next schedule at time 3
            int cycle = n + 1;
            vector<int> temp;

            while(cycle > 0 && !maxHeap.empty()) {
                int current = maxHeap.top();
                maxHeap.pop();

                if(current - 1 > 0) {
                    temp.push_back(current -  1);
                }
                cycle--;
                time++;
            }

            for(auto freq : temp) {
                maxHeap.push(freq);
            }
            
            // add idle time if cycle not filled i.e queue got empty befor cycle got complete
            if (!maxHeap.empty()) {
                time += cycle;
            }
        }

        return time;
    }
};