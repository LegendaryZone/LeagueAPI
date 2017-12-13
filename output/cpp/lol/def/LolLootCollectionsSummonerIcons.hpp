#pragma once
#include<lol/base_def.hpp> 
namespace lol {
  struct LolLootCollectionsSummonerIcons { 
    std::vector<int32_t> icons; 
  };
  void to_json(json& j, const LolLootCollectionsSummonerIcons& v) {
  j["icons"] = v.icons; 
  }
  void from_json(const json& j, LolLootCollectionsSummonerIcons& v) {
  v.icons = j.at("icons").get<std::vector<int32_t>>(); 
  }
}