class Solution {
public:

/*
Sorting and Priority Queue ( Min-Heap )
TC: O( m*log(m) ) + O( m*log(n) )
SC: O(m)
*/

    int mostBooked(int n, vector<vector<int>>& meetings) {

        vector<int> room_metting_count(n+1, 0); 

        // sort based on the start time, bcoz we give preference to that meeting which starts earlier 
        sort(meetings.begin(),meetings.end());

        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;

        // storing for unused rooms
        priority_queue<int,vector<int>, greater<int>> not_using;

        // initially all the rooms are unused
        for(int i = 1; i<=n; i++){
            pq.push({0,i-1});
        }

        for(int i = 0; i<meetings.size(); i++){


                while (!pq.empty() && pq.top().first <= meetings[i][0]) {
                    int room = pq.top().second;
                    pq.pop();
                    not_using.push(room);
                }

                // if empty room is present then assign the meeting to that empty room with lowest number 
                if(!not_using.empty()){
                        int room = not_using.top();
                        not_using.pop();
                        pq.push({meetings[i][1],room});
                        room_metting_count[room]++;
                }
                else
                {
                // if all the rooms are fulled 
                // take out the room which finishes first which room.top() only
                pair<long long,long long> p = pq.top();

                pq.pop();

                pq.push({p.first+meetings[i][1]-meetings[i][0],p.second});

                room_metting_count[p.second]++;

                }                
        }

        int ans = 0;

        cout << room_metting_count[0] << endl;

        int maxi = *max_element(room_metting_count.begin(),room_metting_count.end());

        for(int i = 0; i<n; i++){

            if(room_metting_count[i]==maxi) return i;

        }

        return 0;
    }
};







