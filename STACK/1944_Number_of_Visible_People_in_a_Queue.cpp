class Solution {
public:

/*
Monotonic Stack and Next Greater Element
TC: O(n)
SC: O(n)
*/
    vector<int> canSeePersonsCount(vector<int>& heights) {

        int n = heights.size();
        vector<int> ans(n,0);
        vector<int> person(n,0);
        vector<int> nextgreater(n,0);

        stack<int> st;

        st.push(INT_MAX);

        for( int i = n-1; i>=0; i--){

            int curr = heights[i];

            while(st.top()!=INT_MAX && heights[st.top()]<=curr){
                st.pop();
            }

            if(st.top()!=INT_MAX) {
                ans[i]=ans[st.top()]+1;
                nextgreater[i]=st.top();
            }
            st.push(i);
        }

        for(int i = n-2; i>=0; i--){
            if(heights[i]<heights[i+1]) person[i]=1;
            else {
                if(nextgreater[i]==0) person[i]=(ans[i+1])+1;
                else person[i]=(ans[i+1]-ans[nextgreater[i]])+1;
            }
        }

        return person;
        
    }
};
