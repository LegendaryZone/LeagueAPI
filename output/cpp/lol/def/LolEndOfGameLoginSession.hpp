#pragma once
#include<lol/base_def.hpp> 
#include <lol/def/LolEndOfGameLoginSessionStates.hpp>
namespace lol {
  struct LolEndOfGameLoginSession { 
    LolEndOfGameLoginSessionStates state;
    uint64_t summonerId;
    uint64_t accountId; 
  };
  void to_json(json& j, const LolEndOfGameLoginSession& v) {
  j["state"] = v.state; 
  j["summonerId"] = v.summonerId; 
  j["accountId"] = v.accountId; 
  }
  void from_json(const json& j, LolEndOfGameLoginSession& v) {
  v.state = j.at("state").get<LolEndOfGameLoginSessionStates>(); 
  v.summonerId = j.at("summonerId").get<uint64_t>(); 
  v.accountId = j.at("accountId").get<uint64_t>(); 
  }
}