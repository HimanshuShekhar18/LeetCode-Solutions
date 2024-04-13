// <-------------------------------------------------------------------------PRE-COMPUTATION-------------------------------------------------------------->

class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();

        vector<int> leftmax(n,0);
        vector<int> rightmax(n,0);

        leftmax[0]=height[0];
        rightmax[n-1]=height[n-1];

        for(int i = 1; i<height.size(); i++){
            leftmax[i]=max(leftmax[i-1],height[i]);
        }
        for(int i = n-2; i>=0; i--){
            rightmax[i]=max(rightmax[i+1],height[i]);
        }

        int ans = 0;

        for(int i = 0; i<n; i++){
                ans+=min(rightmax[i],leftmax[i])-height[i];
        }

        return ans;
    }
};




// <----------------------------------------------------------------TWO POINTERS------------------------------------------------------------------------------->



class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();

        int a = 0; int b = n-1;

        int leftmax = 0;
        int rightmax = 0;

        int ans = 0;

        while(a<=b){

            leftmax = max(height[a],leftmax);
            rightmax = max(height[b],rightmax);

            if(leftmax<rightmax){

                    ans+=leftmax-height[a];
                    a++;

            }
            else {

                ans+=rightmax-height[b];
                b--;

            }
        }

        return ans;
    }
};



// <--------------------------------------------------------------STACK-------------------------------------------------------------------------------------->




class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();

        int right = 0;

        stack<int> st;

        int ans = 0;

        while(right<n){



            while(!st.empty() && height[right]>height[st.top()]){

                int current =  st.top();
                st.pop();
                if(st.empty()) break;
                int left = st.top();
                int mini = min(height[right],height[left]);
                ans+=(mini-height[current])*(right-left-1);

            }

            st.push(right);

            right++;

        }

        return ans;
    }
};




