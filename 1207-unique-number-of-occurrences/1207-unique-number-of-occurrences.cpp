class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> freqmap;
        vector<int> freqvect;
        
        // store {number:frequency} in freqmap
        for (int i = 0; i < arr.size(); i++) {
            freqmap[arr[i]]++;
        }
        // store frequencies in vector
        for (auto i: freqmap) {
            freqvect.push_back(i.second);
        }
        // sort vector
        sort(freqvect.begin(), freqvect.end());
        
        // if any value matches with next value, frequencies aren't unique.
        for (int i = 0; i < freqvect.size()-1; i++) {
            if (freqvect[i] == freqvect[i+1]) {
                return false;
            }
        }
        
        return true;
    }
};