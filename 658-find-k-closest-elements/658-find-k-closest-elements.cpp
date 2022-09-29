class Solution {
public:
    struct Compare {   
        bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
            if(p1.first > p2.first)
                return true;
            if(p1.first < p2.first)
                return false;
            return (p1.second > p2.second);
        }
    };
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> minHeap;
        vector<int> result;
        
        for(int i = 0; i < size(arr); i++)
            minHeap.push({abs(x - arr[i]), arr[i]});
        
        while(k--) result.push_back(minHeap.top().second), minHeap.pop();
        sort(begin(result), end(result));
        
        return result;
    }
};