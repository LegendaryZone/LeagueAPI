#pragma once
#include <leagueapi/base.hpp>
#include <leagueapi/definitions/LolLobbyLoginSessionStates.hpp>

namespace leagueapi {
  struct LolLobbyLoginSession { /**/ 
    bool connected;/**/
    LolLobbyLoginSessionStates state;/**/
    uint64_t summonerId;/**/
    uint64_t accountId;/**/
    bool isNewPlayer;/**/
    std::string username;/**/
    std::string idToken;/**/
    std::string userAuthToken;/**/
    json gasToken;/**/
    std::string puuid;/**/
  };
  static void to_json(json& j, const LolLobbyLoginSession& v) { 
    j["connected"] = v.connected;
    j["state"] = v.state;
    j["summonerId"] = v.summonerId;
    j["accountId"] = v.accountId;
    j["isNewPlayer"] = v.isNewPlayer;
    j["username"] = v.username;
    j["idToken"] = v.idToken;
    j["userAuthToken"] = v.userAuthToken;
    j["gasToken"] = v.gasToken;
    j["puuid"] = v.puuid;
  }
  static void from_json(const json& j, LolLobbyLoginSession& v) { 
    v.connected = j.at("connected").get<bool>(); 
    v.state = j.at("state").get<LolLobbyLoginSessionStates>(); 
    v.summonerId = j.at("summonerId").get<uint64_t>(); 
    v.accountId = j.at("accountId").get<uint64_t>(); 
    v.isNewPlayer = j.at("isNewPlayer").get<bool>(); 
    v.username = j.at("username").get<std::string>(); 
    v.idToken = j.at("idToken").get<std::string>(); 
    v.userAuthToken = j.at("userAuthToken").get<std::string>(); 
    v.gasToken = j.at("gasToken").get<json>(); 
    v.puuid = j.at("puuid").get<std::string>(); 
  }
} 