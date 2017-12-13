#pragma once
#include<lol/base_def.hpp> 
#include <lol/def/LolMatchmakingQueueCustomGameSpectatorPolicy.hpp>
namespace lol {
  struct LolMatchmakingLobbyStatus { 
    LolMatchmakingQueueCustomGameSpectatorPolicy customSpectatorPolicy;
    bool isCustom;
    bool isSpectator;
    bool allowedPlayAgain;
    std::optional<std::string> lobbyId;
    bool isLeader;
    int32_t queueId;
    std::vector<uint64_t> memberSummonerIds; 
  };
  void to_json(json& j, const LolMatchmakingLobbyStatus& v) {
  j["customSpectatorPolicy"] = v.customSpectatorPolicy; 
  j["isCustom"] = v.isCustom; 
  j["isSpectator"] = v.isSpectator; 
  j["allowedPlayAgain"] = v.allowedPlayAgain; 
  j["lobbyId"] = v.lobbyId; 
  j["isLeader"] = v.isLeader; 
  j["queueId"] = v.queueId; 
  j["memberSummonerIds"] = v.memberSummonerIds; 
  }
  void from_json(const json& j, LolMatchmakingLobbyStatus& v) {
  v.customSpectatorPolicy = j.at("customSpectatorPolicy").get<LolMatchmakingQueueCustomGameSpectatorPolicy>(); 
  v.isCustom = j.at("isCustom").get<bool>(); 
  v.isSpectator = j.at("isSpectator").get<bool>(); 
  v.allowedPlayAgain = j.at("allowedPlayAgain").get<bool>(); 
  v.lobbyId = j.at("lobbyId").get<std::optional<std::string>>(); 
  v.isLeader = j.at("isLeader").get<bool>(); 
  v.queueId = j.at("queueId").get<int32_t>(); 
  v.memberSummonerIds = j.at("memberSummonerIds").get<std::vector<uint64_t>>(); 
  }
}