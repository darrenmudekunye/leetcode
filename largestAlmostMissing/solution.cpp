#include <map>
#include <vector>
#include <set>
using namespace std;
int largestInteger(vector<int>& nums, int k) {
    if (nums.size()<k){
        return -1;
    } 

    vector<int> group = {};
    int largest = -1;
    size_t counter = 0;
    set<int> found = {};
    map<int, int> dict = {};

    for (size_t i = 0; i<nums.size(); ++i){
        group.push_back(nums[i]);
        ++counter;
        if (counter==k){
            counter = k-1;
            found.insert(group.begin(), group.end());
            for (int item:found){
                if (dict.find(item)!=dict.end()){
                    dict[item]++;
                }else{
                    dict[item] = 1;
                }
            }
            found={};
            group.erase(group.begin());
        }
    }
    for (pair<int, int> duo:dict){
        if ((duo.second == 1)&&(duo.first>largest)){
            largest = duo.first;
        }
    }
    return largest;
}
