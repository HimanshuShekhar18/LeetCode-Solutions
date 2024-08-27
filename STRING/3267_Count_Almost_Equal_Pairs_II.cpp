class Solution {
public:
/*
String Implementation and Unordered Map and Unordered Set
i) Sort the Elements
ii For each element, find all possible integers we can get by applying the operations.
iii) Store the frequencies of all the integers in a Hashmap.
TC: O(n*log(n))
SC: O(n)
*/
    int countPairs(vector<int>& nums) {

        int maxlength = 0;

        for (int i = 0; i < nums.size(); i++) {
            maxlength = max(maxlength, (int)(to_string(nums[i])).length());
        }

        int count = 0;
        unordered_set<string> st;
        unordered_map<string,int> countmap;

        sort(nums.begin(),nums.end());

        for (int i = 0; i < nums.size(); i++) {
           
            string str = to_string(nums[i]);
            count += countmap[str];

            int len = str.length();

            if (len < maxlength) {
                string strvar = str;
                while (len <= maxlength) {
                    st.insert(strvar);
                    string newstr = strvar;
                    for (int j = 0; j < newstr.length(); j++) {
                        for (int k = j + 1; k < newstr.length(); k++) {
                            swap(newstr[j], newstr[k]);
                            st.insert(newstr);
                            swap(newstr[j], newstr[k]);
                            for (int l = 0; l < newstr.length(); l++) {
                                for (int m = l + 1; m < newstr.length(); m++) {
                                    swap(newstr[j], newstr[k]);
                                    swap(newstr[l], newstr[m]);

                                    st.insert(newstr);

                                    swap(newstr[l], newstr[m]);
                                    swap(newstr[j], newstr[k]);
                                }
                            }
                        }
                    }
                    strvar = '0' + strvar;
                    len++;
                    for (auto x : st) {
                        countmap[x]++;
                    }
                    st.clear();
                }
            } else {
                string strvar = str;
                st.insert(strvar);
                for (int j = 0; j < str.length(); j++) {
                    for (int k = j + 1; k < str.length(); k++) {
                        swap(strvar[j], strvar[k]);
                        st.insert(strvar);
                        swap(strvar[j], strvar[k]);
                        for (int l = 0; l < str.length(); l++) {
                            for (int m = l + 1; m < str.length(); m++) {
                                swap(strvar[j], strvar[k]);
                                swap(strvar[l], strvar[m]);

                                st.insert(strvar);

                                swap(strvar[l], strvar[m]);
                                swap(strvar[j], strvar[k]);
                            }
                        }
                    }
                }
                for (auto x : st) {
                    countmap[x]++;
                }
                st.clear();
            }
        }
        return count;
    }
};

