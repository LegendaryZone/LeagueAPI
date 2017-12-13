#pragma once
#include<lol/base_def.hpp> 
#include <lol/def/LolLobbyGatekeeperRestrictionDto.hpp>
#include <lol/def/LolLobbyGameModeDto.hpp>
#include <lol/def/LolLobbyPartyMemberDto.hpp>
#include <lol/def/LolLobbyQueueRestrictionDto.hpp>
#include <lol/def/LolLobbyPartyChatDto.hpp>
namespace lol {
  struct LolLobbyPartyDto { 
    uint64_t version;
    uint64_t activityStartedUtcMillis;
    std::string platformId;
    LolLobbyQueueRestrictionDto activeRestrictions;
    std::string partyId;
    LolLobbyGameModeDto gameMode;
    int64_t eligibilityHash;
    int32_t maxPartySize;
    std::optional<std::vector<LolLobbyGatekeeperRestrictionDto>> eligibilityRestrictions;
    std::string partyType;
    bool activityLocked;
    uint64_t activityResumeUtcMillis;
    std::vector<LolLobbyPartyMemberDto> players;
    LolLobbyPartyChatDto chat; 
  };
  void to_json(json& j, const LolLobbyPartyDto& v) {
  j["version"] = v.version; 
  j["activityStartedUtcMillis"] = v.activityStartedUtcMillis; 
  j["platformId"] = v.platformId; 
  j["activeRestrictions"] = v.activeRestrictions; 
  j["partyId"] = v.partyId; 
  j["gameMode"] = v.gameMode; 
  j["eligibilityHash"] = v.eligibilityHash; 
  j["maxPartySize"] = v.maxPartySize; 
  j["eligibilityRestrictions"] = v.eligibilityRestrictions; 
  j["partyType"] = v.partyType; 
  j["activityLocked"] = v.activityLocked; 
  j["activityResumeUtcMillis"] = v.activityResumeUtcMillis; 
  j["players"] = v.players; 
  j["chat"] = v.chat; 
  }
  void from_json(const json& j, LolLobbyPartyDto& v) {
  v.version = j.at("version").get<uint64_t>(); 
  v.activityStartedUtcMillis = j.at("activityStartedUtcMillis").get<uint64_t>(); 
  v.platformId = j.at("platformId").get<std::string>(); 
  v.activeRestrictions = j.at("activeRestrictions").get<LolLobbyQueueRestrictionDto>(); 
  v.partyId = j.at("partyId").get<std::string>(); 
  v.gameMode = j.at("gameMode").get<LolLobbyGameModeDto>(); 
  v.eligibilityHash = j.at("eligibilityHash").get<int64_t>(); 
  v.maxPartySize = j.at("maxPartySize").get<int32_t>(); 
  v.eligibilityRestrictions = j.at("eligibilityRestrictions").get<std::optional<std::vector<LolLobbyGatekeeperRestrictionDto>>>(); 
  v.partyType = j.at("partyType").get<std::string>(); 
  v.activityLocked = j.at("activityLocked").get<bool>(); 
  v.activityResumeUtcMillis = j.at("activityResumeUtcMillis").get<uint64_t>(); 
  v.players = j.at("players").get<std::vector<LolLobbyPartyMemberDto>>(); 
  v.chat = j.at("chat").get<LolLobbyPartyChatDto>(); 
  }
}