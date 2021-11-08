#include <iostream>
#include <fstream>
#include <sstream>
#include <rapidjson/document.h>
#include <rapidjson/prettywriter.h>
#include "Monster.h"

using namespace rapidjson;

bool SaveToJSON(const char* filename, std::vector<Monster>& monsters)
{
	StringBuffer sb;
	PrettyWriter<StringBuffer> writer(sb);

	// CODE
	writer.StartObject();		//{
	writer.Key("monsters");			// "monsters" :
	writer.StartArray();			//[


	for (auto& monster : monsters)
	{
		writer.StartObject();
		writer.Key("name");
		writer.String(monster.GetName().c_str());

		// status
		writer.Key("status");
		{

			writer.StartObject();
			Status status = monster.GetStatus();
			writer.Key("level");	writer.Int(status.mLevel);
			writer.Key("hp");		writer.Int(status.mHP);
			writer.Key("mp");		writer.Int(status.mMP);
			writer.EndObject();
		}
		//drops
		writer.Key("items");
		{
			writer.StartArray();
			for (auto item : monster.GetItem())
			{
				writer.StartObject();
				writer.Key("name");		writer.String(item.mName.c_str());
				writer.Key("gold");		writer.Int(item.mGold);
				writer.EndObject();
			}
			writer.EndArray();
		}
		writer.EndObject();
	}



	writer.EndArray();				//]
	writer.EndObject();			//}

	std::ofstream ofs;
	ofs.exceptions(std::ofstream::badbit | std::ofstream::failbit);
	try
	{
		ofs.open(filename);
		ofs << sb.GetString();
		ofs.close();
	}
	catch (std::exception e)
	{
		std::cerr << "���� ���� �߿� ���ܰ� �߻��߽��ϴ�" << std::endl;
		std::cerr << e.what() << std::endl;
		ofs.close();

		return false;
	}
	return true;
}

bool LoadFromJSON(const char* filename, std::vector<Monster>& monsters)
{
	std::ifstream ifs;
	ifs.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	std::stringstream ss;
	try
	{
		ifs.open(filename);
		ss << ifs.rdbuf();
		ifs.close();
	}
	catch (std::exception e)
	{
		std::cerr << "������ �д� ���߿� ���ܰ� �߻��߽��ϴ�" << std::endl;
		std::cerr << e.what() << std::endl;
		ifs.close();
		return false;
	}

	Document doc;
	doc.Parse(ss.str().c_str());

	for (auto& elem : doc["monsters"].GetArray())
	{
		Monster monster;
		monster.SetName(elem["name"].GetString());

		auto status = elem["status"].GetObject();
		monster.SetStatus({
			status["level"].GetInt(),
			status["hp"].GetInt(),
			status["mp"].GetInt()
			});

		for (auto& item : elem["items"].GetArray())
		{
			monster.AddDropItem({
				item["name"].GetString(),
				item["gold"].GetInt()
				});
		}

		monsters.push_back(monster);
	}
	return true;
}


int main()
{
	std::vector<Monster> monsters;

	Monster monster;

	monster.SetName("������");
	monster.SetStatus(Status{ 1,1,1 });
	monster.AddDropItem(Item{ "������ ����",1 });
	monsters.push_back(monster);

	monster.SetName("�����ΰ�");
	monster.SetStatus(Status{ 5,5,5 });
	monster.GetItem().clear();
	monster.AddDropItem(Item{ "����", 2 });
	monster.AddDropItem(Item{ "����", 5 });
	monsters.push_back(monster);

	monster.SetName("�Ǹ�");
	monster.SetStatus(Status{ 10,10,10 });
	monster.GetItem().clear();
	monster.AddDropItem(Item{ "����", 10 });
	monster.AddDropItem(Item{ "����", 5 });
	monsters.push_back(monster);


	SaveToJSON("D:\\Git hub\\SimpleData\\monsters.json", monsters);

	monsters.clear();
	LoadFromJSON("D:\\Git hub\\SimpleData\\monsters.json", monsters);

}