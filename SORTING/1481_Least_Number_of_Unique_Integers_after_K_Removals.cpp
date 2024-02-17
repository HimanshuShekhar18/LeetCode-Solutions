class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {

        map<int,int> mp;

        vector<int> ans;

        for(int i = 0; i<arr.size(); i++){
            mp[arr[i]]++;
        }
        
        for(auto it: mp){
            ans.push_back(it.second);
        }

        sort(ans.begin(),ans.end());
        reverse(ans.begin(),ans.end());

        int n = ans.size();

        

        while(k>0){
            int res = ans.back();
             if(k-res>=0) {
                ans.pop_back();
             }
             k=k-res;
        }

        return ans.size();
    }
};



// <-----------------------------------------------------------COUNT SORT--------------------------------------------------------------------------------->


class Solution {
public:

/*
Count Sort
TC: O(n)
SC: O(n)
*/
    void countsort(vector<int> &arr, int n ){
      int k = arr[0];

      // finding the maximum element
      for(int i=0; i<n;i++){
            k=max(arr[i],k);
      }

      // error: a variable-sized object may not be initialized
      vector<int> count(k+1,0);
      // dynamic array can be allocated: int* count  = new int[k];

      // finding the count of each element
      for(int i = 0;i<n; i++){
            count[arr[i]]++;            
      }

      // finding the position of each element
      for(int i = 1;i<=k; i++){
            count[i]+=count[i-1];            
      }


      // storing the element of original array in sorted fashion
      vector<int> output(n);
      for(int i = n-1; i>=0; i--){
            output[--count[arr[i]]]=arr[i];
      }

      // passing the output array to original array
      for(int i=0; i<n;i++){
            arr[i]=output[i];
      }

}

    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {

        unordered_map<int,int> mp;

        vector<int> ans;

        for(int i = 0; i<arr.size(); i++){
            mp[arr[i]]++;
        }
        
        for(auto it: mp){
            ans.push_back(it.second);
        }

        int n = ans.size();
        countsort(ans,n);

        reverse(ans.begin(),ans.end());        

        while(k>0){
            int res = ans.back();
             if(k-res>=0) {
                ans.pop_back();
             }
             k=k-res;
        }

        return ans.size();
    }
};



