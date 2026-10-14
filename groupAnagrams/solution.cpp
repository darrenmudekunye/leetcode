#include <set>
#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 1){
		return {strs};
	}

	std::map<pair<std::set<char>, size_t>, std::vector<std::string>> hashes;

	for (string str:strs){
		std::set<char> scat(str.begin(), str.end());
		size_t len = 0;
		for (char c:str){len+=c;};
		std::pair<std::set<char>, size_t> group = {scat, len}; 
		if (hashes.find(group) != hashes.end()){
			hashes[group].push_back(str);
		} else{
			hashes[group] = {str};
		}
     	}

	std::vector<std::vector<std::string>> output = {};
	
	for (auto item:hashes){
		output.push_back(item.second);	
	}

	return output;
        
}

int main(){
	
	std::vector<std::string> strs = {"eat","tea","tan","ate","nat","bat"};

	//strs = {}
	
	std::vector<std::vector<std::string>> x = groupAnagrams(strs);

	for (auto i:x){
		for (std::string y:i){
			std::cout << y << std::endl;
		}
		std::cout << "<<<<" << std::endl;
	}

	return 0;
}
