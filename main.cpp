
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
std::string recursebuild(std::string input, std::string builder = "");
int main()
{

	auto output = recursebuild("bbbcccaaaa");
	std::cout << output << std::endl;
	output = recursebuild("bb");
	std::cout << output << std::endl;
	
}

std::string sortIntoPriority(std::string const& inputstring) {
	if (inputstring.size() < 2) {
		return inputstring;
	}
	
	std::map<std::string, int> countset;

	for (auto it = inputstring.begin(); it < inputstring.end(); ++it) {

		if (countset.find(std::string(1, *it)) == countset.end()) {
			countset.insert({ std::string(1,*it),1 });
		}
		else {
			countset[std::string(1, *it)] += 1;
		}

	}

	std::vector<std::pair<std::string, int>> pairs;

	for (auto itr = countset.begin(); itr != countset.end(); ++itr) {
		pairs.push_back(*itr);
	}
	std::sort(pairs.begin(), pairs.end(), [=](std::pair<std::string, int>& a, std::pair<std::string, int>& b) {
		return a.second > b.second;
		});

	std::string input = "";
	for (auto it = pairs.begin(); it != pairs.end(); ++it) {
		for (int i = 0; i < (*it).second; ++i) {
			input += (*it).first;
		}
	}

	return input;
}




std::string recursebuild(std::string input,std::string builder) {
	input = sortIntoPriority(input);
	if (input.size() <2) {
		return (input + builder);
	}
	auto first = input[0];
	
	for (int i = 1; i < input.size(); ++i) {
		if (input[i] != first) {
			std::string b(input.substr(i, 1) + input.substr(0, 1));
			input.erase(i, 1);
			input.erase(0, 1);
			return recursebuild(input,b+builder);
		}
	}
	return "None";
}




