#include <iostream>
#include<map>


int main()
{
	std::map<int, std::string> quests;	// key가 int, value가 std::string

	/*quests.insert({ 1, "Tutorial" });
	quests.insert({ 2, "Save villiage" });*/

	std::pair<int, std::string> pair;
	pair.first = 1;
	pair.second = "Tutorial";
	quests.insert(pair);

	std::pair<int, std::string> q2(2, "Save villiage");
	quests.insert(q2);

	for (auto pair : quests)
	{
		std::cout << pair.first << " : " << pair.second << std::endl;
	}

	quests[2] = "Save Town";

	std::map<std::string, std::string> myDictionary;
	myDictionary.insert({ "array", "순차컨테이너" });
	myDictionary.insert({ "map", "보조컨테이너" });
	myDictionary.insert({ "stack", "연관컨테이너" });

	std::cout << myDictionary["array"] << std::endl;
		
}