class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        unordered_map <char, int> count;
        int maxFreq = 0;
        int left = 0;
        int maxLen = 0;
        
        for(int right = 0; right < answerKey.size(); right++){
            count[answerKey[right]]++;

            // Here we take the element with the max freq so that the number of replacement we
            // will be doing is on the number that occurs less in the window.
            maxFreq = max(maxFreq, count[answerKey[right]]);

            // if window is not valid shrink
            // if there are more elements that occure with less frequency then we cannot 
            // do k operations and convert them to consecutive string
            // Therefore we need to shrink the size of the window and elemenate from the left
            // to maintain the validity of the window
            while((right - left + 1) - maxFreq > k) {
                count[answerKey[left]]--;
                left ++;
            }

            // Once the window is valid get the maxWindow size see till now 
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};