#include "GameCore.h"

namespace SceptreEngine
{
	std::string GameCore::CCountry::getCountryNamefromTag(const std::unordered_map<const char*, std::string, CharPtrHash, CharPtrEqual>& map, const char* key)
	{
		auto it = map.find(key);
		return it->second;
	}
}