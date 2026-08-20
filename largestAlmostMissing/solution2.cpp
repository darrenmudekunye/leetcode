#include <vector>
#include <set>
#include <map>
using namespace std;

int largestInteger(vector<int>& nums, int k) {
    if (nums.size()<k){
        return -1;
    } 

    vector<int> group = {};
    int largest = -1;
    int start = 0;
    int stop = 0;
    size_t counter = 0;
    set<int> found = {};
    map<int, int> dict = {};

    for (size_t i = 0; i<nums.size(); ++i){
        group.push_back(nums[i]);
        ++counter;
        if (counter==k){
            counter = k-1;
	    start = i;
	    stop = i+k;
            found.insert(group.begin() + start, group.begin() + (stop-1));
            for (int item:found){
                if (dict.find(item)!=dict.end()){
                    dict[item]++;
                }else{
                    dict[item] = 1;
                }
            }
        }
    }
    for (pair<int, int> duo:dict){
        if ((duo.second == 1)&&(duo.first>largest)){
            largest = duo.first;
        }
    }
    return largest;
}
