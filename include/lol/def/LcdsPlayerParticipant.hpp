#pragma once
#include "../base_def.hpp" 
namespace lol {
  struct LcdsPlayerParticipant { 
    uint64_t summonerId;
    std::string summonerName;
    std::string summonerInternalName;
    int32_t botSkillLevel; 
  };
  inline void to_json(json& j, const LcdsPlayerParticipant& v) {
    j["summonerId"] = v.summonerId; 
    j["summonerName"] = v.summonerName; 
    j["summonerInternalName"] = v.summonerInternalName; 
    j["botSkillLevel"] = v.botSkillLevel; 
  }
  inline void from_json(const json& j, LcdsPlayerParticipant& v) {
    v.summonerId = j.at("summonerId").get<uint64_t>(); 
    v.summonerName = j.at("summonerName").get<std::string>(); 
    v.summonerInternalName = j.at("summonerInternalName").get<std::string>(); 
    v.botSkillLevel = j.at("botSkillLevel").get<int32_t>(); 
  }
}