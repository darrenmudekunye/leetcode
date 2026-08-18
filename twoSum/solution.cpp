#include <vector>
#include <map>
#include <iostream>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
        int diff = 0;
        vector<int> indeces = {};
        map<int, vector<int>> mappings = {};
        for (int i = 0; i < nums.size(); ++i){
            if (mappings.find(nums[i]) == mappings.end()){
                mappings[nums[i]] = {i};
            }else{
                mappings[nums[i]].push_back(i);
            }
        }
	
	for (auto k : mappings){
		std::cout << k.first << endl;
		for (auto j : k.second){cout << j << endl;}
	}

        for (int j = 0; j < nums.size(); j++){
            diff = target - nums[j];
            if (diff == nums[j]){
                if (mappings[nums[j]].size()>1){
                    indeces = {mappings[diff][0], mappings[diff][1]};
                    return indeces;
                }
            }else{
                if (mappings.find(diff)==mappings.end()){
                    continue;
                }else{

                    indeces.push_back(j);
                    vector<int> index = mappings[diff];
                    indeces.push_back(index[0]);
                    return indeces;
                }
            }
        }
        return {0, 0};
}

int main(){
	vector<int> numb = {2,7,11,15,7};
	vector<int> sol = twoSum(numb, 9);
	cout << "[" << sol[0] << ", " << sol[1] << "]";
	return 0;
}

