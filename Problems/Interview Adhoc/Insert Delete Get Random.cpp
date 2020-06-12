/*
Source code by Yash Kapoor

Codeforces      yk112
Leetcode        yk112
Codechef        yashkapoor112

Problem Statement - 

Problem Link - https://leetcode.com/problems/insert-delete-getrandom-o1/

*/

class RandomizedSet {
public:
    unordered_map<int, int> memo;
    vector<int> arr;
    RandomizedSet() {   
    }
    //O(1)
    bool insert(int val) {
        if(memo.find(val)!=memo.end())  return false;
        memo[val] = arr.size();
        arr.push_back(val);
        return true;
    }
    //O(1)
    bool remove(int val) {
        if(memo.find(val) == memo.end())
            return false;
        int idx = memo[val];
        memo[arr[arr.size()-1]] = idx;
        swap(arr[idx], arr[arr.size()-1]);
        arr.pop_back();
        memo.erase(val);
        return true;
    }
    //O(1)
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};
