#include "pch.h"
#include "DataManager.h"

void DataManager::Init()
{
	// 파일 읽어서 로드하기
	/*ifstream ifs(L"../Resources/Data/MonsterData.json");

	assert(ifs.is_open());

	stringstream buffer;
	buffer << ifs.rdbuf();
	string json = buffer.str();

	Document document;
	document.Parse(json.c_str());

	assert(document.HasParseError() == false);

	assert(document.IsArray());
	GenericArray<false, Value> array = document.GetArray();
	for (SizeType i = 0; i < array.Size(); ++i)
	{
		StringBuffer buffer;
		Writer<StringBuffer> writer(buffer);
		array[i].Accept(writer);

		MonsterData data;
		data.FromJson(buffer.GetString());

		assert(_monsterDatas.contains(data.Id) == false);
		_monsterDatas[data.Id] = data;
	}*/
}

void DataManager::Release()
{
	_monsterDatas.clear();
	_behicleDatas.clear();
	_waveDatas.clear();
	_boatDatas.clear();
}
void DataManager::LoadData(wstring loadData, DataType dataType)
{
	wstring temp = L"../Resources/Data/" + loadData + L".json";
	//wprintf(temp.c_str());
	ifstream ifs(temp);

	assert(ifs.is_open());

	stringstream buffer;
	buffer << ifs.rdbuf();
	string json = buffer.str();

	Document document;
	document.Parse(json.c_str());

	assert(document.HasParseError() == false); // 여기서 오류

	assert(document.IsArray());
	GenericArray<false, Value> array = document.GetArray();

	switch (dataType)
	{
	case DataType::Wave:
	{
		for (SizeType i = 0; i < array.Size(); ++i)
		{
			StringBuffer buffer;
			Writer<StringBuffer> writer(buffer);
			array[i].Accept(writer);

			WaveData data;
			data.FromJson(buffer.GetString());

			assert(_waveDatas.contains(data.Id) == false); // 여기서 오류
			_waveDatas[data.Id] = data;
		}
	}
	break;
	case DataType::Behicle:
	{
		for (SizeType i = 0; i < array.Size(); ++i)
		{
			StringBuffer buffer;
			Writer<StringBuffer> writer(buffer);
			array[i].Accept(writer);

			BehicleData data;
			data.FromJson(buffer.GetString());

			assert(_behicleDatas.contains(data.Id) == false);
			_behicleDatas[data.Id] = data;
		}
	}
	break;
	case DataType::Boat:
	{
		for (SizeType i = 0; i < array.Size(); ++i)
		{
			StringBuffer buffer;
			Writer<StringBuffer> writer(buffer);
			array[i].Accept(writer);

			BoatData data;
			data.FromJson(buffer.GetString());

			assert(_boatDatas.contains(data.Id) == false);
			_boatDatas[data.Id] = data;
		}
	}
	break;
	default:
		break;
	}
}