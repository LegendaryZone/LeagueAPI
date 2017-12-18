#pragma once
#include "../base_def.hpp" 
#include "LolSummonerLoginSessionStates.hpp"
namespace lol {
  struct LolSummonerLoginSession { 
    bool connected;
    LolSummonerLoginSessionStates state;
    uint64_t accountId;
    std::string puuid;
    uint64_t summonerId; 
  };
  inline void to_json(json& j, const LolSummonerLoginSession& v) {
    j["connected"] = v.connected; 
    j["state"] = v.state; 
    j["accountId"] = v.accountId; 
    j["puuid"] = v.puuid; 
    j["summonerId"] = v.summonerId; 
  }
  inline void from_json(const json& j, LolSummonerLoginSession& v) {
    v.connected = j.at("connected").get<bool>(); 
    v.state = j.at("state").get<LolSummonerLoginSessionStates>(); 
    v.accountId = j.at("accountId").get<uint64_t>(); 
    v.puuid = j.at("puuid").get<std::string>(); 
    v.summonerId = j.at("summonerId").get<uint64_t>(); 
  }
}