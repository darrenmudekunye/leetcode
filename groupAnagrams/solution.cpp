#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 1){
		return {strs};
	}
	std::vector<std::vector<std::string>> output = {};

	std::map<std::string, std::vector<std::string>> hashes;
	
	std::string scat;
	for (string str:strs){
		scat = str;
		std::sort(scat.begin(), scat.end());
		hashes[scat].push_back(str);
     	}

	
	for (auto item:hashes){
		output.push_back(item.second);	
	}
	
	return output;
        
}

int main(){
	
	std::vector<std::string> strs = {"eat","tea","tan","ate","nat","bat"};
	
	std::vector<std::vector<std::string>> x = groupAnagrams(strs);

	for (auto i:x){
		for (std::string y:i){
			std::cout << y << std::endl;
		}
		std::cout << "<<<<" << std::endl;
	}

	return 0;
}
