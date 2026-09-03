// Only beats 5%, very inefficient. 
// I assume the cause is the nested loop
#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
        size_t index = 0;
 	int current_num;
	int next_num;
	while (true) {
		current_num = nums[index];
		next_num = nums[index+1];
		while (current_num == next_num){
			nums.erase(nums.begin() + (index + 1));
	                index+1 < nums.size() ? next_num = nums[index+1] : next_num = -101;
			cout<< current_num << "  " << next_num << endl; 
		}
		if (index + 2 >= nums.size()){break;}else{index++;};

        }

	return nums.size();
}



int main(){
	vector<int> k = {1,1};
	std::cout << removeDuplicates(k) << endl;
	k = {1,1,2};
	cout << removeDuplicates(k);
	return 0;
}
