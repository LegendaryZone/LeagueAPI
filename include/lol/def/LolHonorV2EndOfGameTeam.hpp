#pragma once
#include "../base_def.hpp" 
#include "LolHonorV2EndOfGamePlayer.hpp"
namespace lol {
  struct LolHonorV2EndOfGameTeam { 
    std::string memberStatusString;
    std::string tag;
    bool isBottomTeam;
    std::vector<int32_t> championBans;
    std::string fullId;
    bool isPlayerTeam;
    std::vector<LolHonorV2EndOfGamePlayer> players;
    bool isWinningTeam;
    json stats;
    int32_t teamId;
    std::string name; 
  };
  inline void to_json(json& j, const LolHonorV2EndOfGameTeam& v) {
    j["memberStatusString"] = v.memberStatusString; 
    j["tag"] = v.tag; 
    j["isBottomTeam"] = v.isBottomTeam; 
    j["championBans"] = v.championBans; 
    j["fullId"] = v.fullId; 
    j["isPlayerTeam"] = v.isPlayerTeam; 
    j["players"] = v.players; 
    j["isWinningTeam"] = v.isWinningTeam; 
    j["stats"] = v.stats; 
    j["teamId"] = v.teamId; 
    j["name"] = v.name; 
  }
  inline void from_json(const json& j, LolHonorV2EndOfGameTeam& v) {
    v.memberStatusString = j.at("memberStatusString").get<std::string>(); 
    v.tag = j.at("tag").get<std::string>(); 
    v.isBottomTeam = j.at("isBottomTeam").get<bool>(); 
    v.championBans = j.at("championBans").get<std::vector<int32_t>>(); 
    v.fullId = j.at("fullId").get<std::string>(); 
    v.isPlayerTeam = j.at("isPlayerTeam").get<bool>(); 
    v.players = j.at("players").get<std::vector<LolHonorV2EndOfGamePlayer>>(); 
    v.isWinningTeam = j.at("isWinningTeam").get<bool>(); 
    v.stats = j.at("stats").get<json>(); 
    v.teamId = j.at("teamId").get<int32_t>(); 
    v.name = j.at("name").get<std::string>(); 
  }
}