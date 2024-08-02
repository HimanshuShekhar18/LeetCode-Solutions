class Solution {
public:
    vector<vector<long long>> seg;
    static int n;

    vector<long long> create(long long a) {

        vector<long long> temp;
        temp.push_back(a);
        return temp;
    }

    vector<long long> combine(vector<long long>& a, vector<long long>& b) {

        int a_ka_size = a.size();
        int b_ka_size = b.size();

        int i = 0, j = 0;
        vector<long long> c;
        while (i < a_ka_size && j < b_ka_size) {
            if (a[i] <= b[j]) {
                c.push_back(a[i]);
                i++;
            } else {
                c.push_back(b[j]);
                j++;
            }
        }

        while (i < a_ka_size) {
            c.push_back(a[i]);
            i++;
        }

        while (j < b_ka_size) {
            c.push_back(b[j]);
            j++;
        }

        return c;
    }

    void build(vector<int>& rating, int id = 1, int l = 0, int r = n) {
        if (r - l == 1) {
            seg[id] = create(rating[l]);
            return;
        }

        int mid = (r + l) / 2;
        build(rating, 2 * id, l, mid);
        build(rating, 2 * id + 1, mid, r);
        seg[id] = combine(seg[2 * id], seg[2 * id + 1]);
    }

    int query(int x, int y, int k, int id = 1, int l = 0, int r = n) {
        if (l >= y ||  x>=r)
            return 0;
        if (l >= x && r <= y) {
            return seg[id].size() -
                   (upper_bound(seg[id].begin(), seg[id].end(), k) -
                    seg[id].begin());
        }

        int mid = (r + l) / 2;
        long long left = query(x, y, k,2 * id,  l, mid);
        long long right = query(x, y, k,2 * id + 1,  mid, r);

        return (left + right);
    }

    

    int numTeams(vector<int>& rating) {

        int ans = 0;
        n = rating.size();
        seg.resize(4 * n + 1);

        build(rating);

        for (int i = 1; i < n-1; i++) {

            int greaterright = query(i+1,n,rating[i]);
            int smallerright = n-(i+1)-greaterright;
            int greaterleft = query(0,i,rating[i]);
            int smallerleft = (i)-greaterleft;

            ans+=greaterright*smallerleft+smallerright*greaterleft;
        }

        return ans;
    }
};

int Solution :: n = 0;
