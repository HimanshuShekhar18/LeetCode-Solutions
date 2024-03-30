class Solution {
public:

// <--------------------------------------------MONOTONIC DECREASING DEQUE-------------------------------------------------------->
      
//This is generally known as "Monotonic increasing/decreasing  Queue/Dequeue"
//Approach-1 (Using Deque) Every element is added(pushed) and popped only once,
//So it is O(n) time complexity.
//SC: O(n)

/* Algorithm 
1. When new element comes mums[i], make space for it (windom size con't be greater than k)
2. Now, when nums[i] comes, there is no need to keep small elements in thet window, pop then
3. Nom push i in deque >» for mas(i)
4. If (i>=k-1), then deq.front() is our onsmer for that window
*/

    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        int n = nums.size();
        if(n == 0)
            return {};
        deque<int> deq;

        vector<int> result;
        
        for(int i = 0; i<n; i++) {
            // 1) remove the max elements from front which are out of window size
            while(!deq.empty() && deq.front() <= i-k)
            deq.pop_front();
            
            // 2) we maintain the deque in descending order
            while(!deq.empty() && nums[i] > nums[deq.back()])
            deq.pop_back();
            
            deq.push_back(i);

            if(i >= k-1) // 3) Only when the window size first gets equal or greater than k
            result.push_back(nums[deq.front()]); // 4) front will have the max element (dequeue is maintained in descending order)
        }
        return result;
    }
};
