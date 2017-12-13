#pragma once
#include<lol/base_def.hpp> 
namespace lol {
  struct LolChampSelectLegacyChampSelectBannedChampions { 
    std::vector<int32_t> theirTeamBans;
    int32_t numBans;
    std::vector<int32_t> myTeamBans; 
  };
  void to_json(json& j, const LolChampSelectLegacyChampSelectBannedChampions& v) {
  j["theirTeamBans"] = v.theirTeamBans; 
  j["numBans"] = v.numBans; 
  j["myTeamBans"] = v.myTeamBans; 
  }
  void from_json(const json& j, LolChampSelectLegacyChampSelectBannedChampions& v) {
  v.theirTeamBans = j.at("theirTeamBans").get<std::vector<int32_t>>(); 
  v.numBans = j.at("numBans").get<int32_t>(); 
  v.myTeamBans = j.at("myTeamBans").get<std::vector<int32_t>>(); 
  }
}