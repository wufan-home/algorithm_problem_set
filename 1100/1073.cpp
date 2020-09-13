class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        int size_1 = arr1.size();
        int size_2 = arr2.size();
        
        int size = max(size_1, size_2);
        vector<int> rv(size, 0);
        for(int i = 1; i <= size; ++i) {
            int index_1 = (i <= size_1 ? size_1 - i : -1);
            int add_1 = (index_1 >= 0 ? arr1[index_1] : 0);
                
            int index_2 = (i <= size_2 ? size_2 - i : -1);
            int add_2 = (index_2 >= 0 ? arr2[index_2] : 0);
            
            rv[size - i] = add_1 + add_2;
        }

        bool overflow = false;
        for(int i = size - 1; i >= 0; --i) {
            if (rv[i] < 2) {
                continue;
            }
            
            if (i == 0) {
                rv[i] -= 2;
                overflow = true;
                continue;
            }
                
            rv[i] -= 2;
            if (rv[i - 1] == 0) {
                rv[i - 1] += 1;
                rv[i - 2] += 1;
            } else {
                rv[i - 1] -= 1;
            }
        }

        if (overflow) {
            rv.insert(rv.begin(), 1);
            rv.insert(rv.begin(), 1);
        } if (rv[0] == 0) {
            while (rv.size() > 1 && rv[0] == 0) {
                rv.erase(rv.begin());
            }
        }
        
        return rv;
    }
};
