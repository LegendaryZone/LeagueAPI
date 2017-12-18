#pragma once
#include "../base_def.hpp" 
#include "BannedChampion.hpp"
#include "PlayerParticipant.hpp"
namespace lol {
  struct EogLcdsGameDTO { 
    std::vector<PlayerParticipant> teamOne;
    std::vector<PlayerParticipant> teamTwo;
    std::string gameState;
    std::vector<BannedChampion> bannedChampions;
    uint64_t id; 
  };
  inline void to_json(json& j, const EogLcdsGameDTO& v) {
    j["teamOne"] = v.teamOne; 
    j["teamTwo"] = v.teamTwo; 
    j["gameState"] = v.gameState; 
    j["bannedChampions"] = v.bannedChampions; 
    j["id"] = v.id; 
  }
  inline void from_json(const json& j, EogLcdsGameDTO& v) {
    v.teamOne = j.at("teamOne").get<std::vector<PlayerParticipant>>(); 
    v.teamTwo = j.at("teamTwo").get<std::vector<PlayerParticipant>>(); 
    v.gameState = j.at("gameState").get<std::string>(); 
    v.bannedChampions = j.at("bannedChampions").get<std::vector<BannedChampion>>(); 
    v.id = j.at("id").get<uint64_t>(); 
  }
}