#include "pch.h"
#include "Data.h"

void MonsterData::FromJson(string json)
{
	Document document;
	document.Parse(json.c_str());

	assert(document.HasParseError() == false); // document�� error�� ������Ѵ�.

	//if (document.HasMember("hp") && document["hp"].IsFloat()) //errorüũ�� �� �� ������ ��� ������ error��.
	//{
	//	this->Id = document["id"].GetInt64();
	//}
	this->Id = document["id"].GetInt64();
	this->HP = document["hp"].GetFloat();
	this->MoveSpeed = document["moveSpeed"].GetFloat();
	this->Name = document["name"].GetString();
	this->SkillId = document["skillId"].GetInt64();
}
string MonsterData::ToJson()
{
	Document document;
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);

	writer.StartObject();
	writer.Key("id");
	writer.Int64(this->Id);
	writer.Key("hp");
	writer.Double(this->HP);
	writer.Key("moveSpeed");
	writer.Double(this->MoveSpeed);
	writer.Key("name");
	writer.String(this->Name.c_str());
	writer.Key("skillId");
	writer.Int64(this->SkillId);
	writer.EndObject();
	
	//document.Accept(writer);

	return string(buffer.GetString());
}