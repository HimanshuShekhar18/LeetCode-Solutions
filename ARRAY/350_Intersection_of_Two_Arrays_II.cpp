class Solution {
public:

/*
Naive Approach: Unordered Map and insert()
TC: O(M+N)
SC: O(M+N)
*/

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int,int> mp2;

        for(int i = 0; i<nums2.size(); i++){
            mp2[nums2[i]]++;
        }

        unordered_map<int,int> mp;

        for(int i = 0; i<nums1.size(); i++){
            mp[nums1[i]]++;
        }

        vector<int> ans;

        for(auto it: mp){
            int value = it.first;
            int count = it.second;

            if(mp2.count(value)){
                int common = min(count,mp2[value]);
                ans.insert(ans.end(),common,value);
            }
        }
        return ans;
    }
};


// <---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------->


/*

Follow-up Question I:
What if the given array is already sorted? How would you optimize your algorithm?
Ans: Two Pointers Algorithm 
TC: O(n)
SC: O(1)

*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        // imagine arrays are already sorted then don't count in Time Complexity
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0;

        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int> ans;
        while (i < n1 && j < n2) {
            if (nums2[j] > nums1[i]) {

                i++;
            } else if (nums2[j] < nums1[i]) {

                j++;
            } else {

                ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }

        return ans;
    }
};



// <--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------->


class Solution {
public:

/*

What if nums1's size is small compared to nums2's size? Which algorithm is better?

Ans: unordered_map storing frequency of elements of nums1 array only

TC: O(n)
SC: O(n)

*/
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int,int> mp;

        for(int i = 0; i<nums1.size(); i++){
            mp[nums1[i]]++;
        }

        vector<int> ans;

        for(int i = 0; i<nums2.size(); i++){
            
            if(mp.count(nums2[i])){

                ans.push_back(nums2[i]);
                mp[nums2[i]]--;
                if(mp[nums2[i]]==0) mp.erase(nums2[i]);
            }
        }
        return ans;
    }
};



