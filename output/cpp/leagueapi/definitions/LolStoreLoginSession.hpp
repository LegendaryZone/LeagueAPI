#pragma once
#include <leagueapi/base.hpp>
#include <leagueapi/definitions/LolStoreLoginSessionStates.hpp>

namespace leagueapi {
  struct LolStoreLoginSession { /**/ 
    LolStoreLoginSessionStates state;/**/
    std::string idToken;/**/
    uint64_t summonerId;/**/
    json gasToken;/**/
    uint64_t accountId;/**/
  };
  static void to_json(json& j, const LolStoreLoginSession& v) { 
    j["state"] = v.state;
    j["idToken"] = v.idToken;
    j["summonerId"] = v.summonerId;
    j["gasToken"] = v.gasToken;
    j["accountId"] = v.accountId;
  }
  static void from_json(const json& j, LolStoreLoginSession& v) { 
    v.state = j.at("state").get<LolStoreLoginSessionStates>(); 
    v.idToken = j.at("idToken").get<std::string>(); 
    v.summonerId = j.at("summonerId").get<uint64_t>(); 
    v.gasToken = j.at("gasToken").get<json>(); 
    v.accountId = j.at("accountId").get<uint64_t>(); 
  }
} 