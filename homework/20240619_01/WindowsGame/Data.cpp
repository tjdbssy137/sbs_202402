#include "pch.h"
#include "Data.h"

void BehicleData::FromJson(string json)
{
	Document document;
	document.Parse(json.c_str());

	assert(document.HasParseError() == false); // document의 error가 없어야한다.

	this->Id = document["id"].GetInt64();
	this->Name= document["name"].GetString();
	this->BulletDamage = document["bulletDamage"].GetFloat();
	this->BulletSpeed = document["bulletSpeed"].GetFloat();
	this->AttackTime = document["attackTime"].GetFloat();
	this->ColliderSize = document["colliderSize"].GetInt();
	this->InstallGold = document["installGold"].GetInt();
	this->UpgradeTowerId = document["upgradeTowerId"].GetInt();
	this->UpgradeGold = document["upgradeGold"].GetInt();
	this->RefundGold = document["refundGold"].GetInt();

}
string BehicleData::ToJson()
{
	Document document;
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);

	writer.StartObject();
	writer.Key("id");
	writer.Int64(this->Id);
	writer.Key("name");
	writer.String(this->Name.c_str()); 
	writer.Key("bulletDamage");
	writer.Double(this->BulletDamage);
	writer.Key("attackTime");
	writer.Double(this->AttackTime);
	writer.Key("bulletSpeed");
	writer.Double(this->BulletSpeed);
	writer.Key("colliderSize");
	writer.Int64(this->ColliderSize);
	writer.Key("installGold");
	writer.Int64(this->InstallGold);
	writer.Key("upgradeTowerId");
	writer.Int64(this->UpgradeTowerId);
	writer.Key("upgradeGold");
	writer.Int64(this->UpgradeGold);
	writer.Key("refundGold");
	writer.Int64(this->RefundGold);
	writer.EndObject();

	//document.Accept(writer);

	return string(buffer.GetString());
}


void BoatData::FromJson(string json)
{
	Document document;
	document.Parse(json.c_str());

	assert(document.HasParseError() == false); // document의 error가 없어야한다.

	this->Id = document["id"].GetInt64();
	this->Name = document["name"].GetString();
	this->HP = document["hp"].GetFloat();
	this->MoveSpeed = document["moveSpeed"].GetFloat();
	this->Gold = document["gold"].GetInt();

}
string BoatData::ToJson()
{
	Document document;
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);

	writer.StartObject();
	writer.Key("id");
	writer.Int64(this->Id);
	writer.Key("name");
	writer.String(this->Name.c_str());
	writer.Key("hp");
	writer.Double(this->HP);
	writer.Key("moveSpeed");
	writer.Double(this->MoveSpeed);
	writer.Key("gold");
	writer.Int(this->Gold);
	writer.EndObject();

	return string(buffer.GetString());
}

void WaveData::FromJson(string json)
{
	Document document;
	document.Parse(json.c_str());

	assert(document.HasParseError() == false); // document의 error가 없어야한다.

	this->Id = document["waveID"].GetInt64();
	for (int i = 0; i < document["boatCount"].Size(); i++)
	{
		this->BoatCount.push_back(document["boatCount"][i].GetInt());
	}
}
string WaveData::ToJson()
{
	Document document;
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);

	writer.StartObject();
	writer.Key("waveID");
	writer.Int64(this->Id);
	
	writer.Key("boatCount");
	for (int i = 0; i < BoatCount.size(); i++)
	{
		writer.Int(this->BoatCount[i]);
	}
	
	return string(buffer.GetString());
}