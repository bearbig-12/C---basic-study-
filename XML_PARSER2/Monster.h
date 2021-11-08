#pragma once

#include <string>
#include <vector>

struct Status
{
	int mLevel{};
	int mHP{};
	int mMP{};
};

struct Item
{
	std::string mName{};
	int mGold{};
};

class Monster
{
private:
	std::string mName{};
	Status mStatus{};
	std::vector<Item> mDropItems{};

public:
	void SetName(const char* name) { mName = name; }
	void SetStatus(const Status& status) { mStatus = status; }
	void AddDropItem(const Item& item) { mDropItems.push_back(item); }

	std::string& GetName() { return mName; }
	Status& GetStatus() { return mStatus; }
	std::vector<Item>& GetItem() { return mDropItems; }
};