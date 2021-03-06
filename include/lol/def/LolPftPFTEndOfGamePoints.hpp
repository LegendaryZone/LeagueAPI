#pragma once
#include "../base_def.hpp" 
namespace lol {
  struct LolPftPFTEndOfGamePoints { 
    int32_t pointChangeFromChampionsOwned;
    int32_t pointChangeFromGameplay;
    int32_t pointsUsed;
    int32_t previousPoints;
    int32_t pointsUntilNextReroll;
    int32_t rerollCount;
    int32_t totalPoints; 
  };
  inline void to_json(json& j, const LolPftPFTEndOfGamePoints& v) {
    j["pointChangeFromChampionsOwned"] = v.pointChangeFromChampionsOwned; 
    j["pointChangeFromGameplay"] = v.pointChangeFromGameplay; 
    j["pointsUsed"] = v.pointsUsed; 
    j["previousPoints"] = v.previousPoints; 
    j["pointsUntilNextReroll"] = v.pointsUntilNextReroll; 
    j["rerollCount"] = v.rerollCount; 
    j["totalPoints"] = v.totalPoints; 
  }
  inline void from_json(const json& j, LolPftPFTEndOfGamePoints& v) {
    v.pointChangeFromChampionsOwned = j.at("pointChangeFromChampionsOwned").get<int32_t>(); 
    v.pointChangeFromGameplay = j.at("pointChangeFromGameplay").get<int32_t>(); 
    v.pointsUsed = j.at("pointsUsed").get<int32_t>(); 
    v.previousPoints = j.at("previousPoints").get<int32_t>(); 
    v.pointsUntilNextReroll = j.at("pointsUntilNextReroll").get<int32_t>(); 
    v.rerollCount = j.at("rerollCount").get<int32_t>(); 
    v.totalPoints = j.at("totalPoints").get<int32_t>(); 
  }
}