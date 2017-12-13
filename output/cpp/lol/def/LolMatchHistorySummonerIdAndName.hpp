#pragma once
#include<lol/base_def.hpp> 
namespace lol {
  struct LolMatchHistorySummonerIdAndName { 
    std::string displayName; 
  };
  void to_json(json& j, const LolMatchHistorySummonerIdAndName& v) {
  j["displayName"] = v.displayName; 
  }
  void from_json(const json& j, LolMatchHistorySummonerIdAndName& v) {
  v.displayName = j.at("displayName").get<std::string>(); 
  }
}