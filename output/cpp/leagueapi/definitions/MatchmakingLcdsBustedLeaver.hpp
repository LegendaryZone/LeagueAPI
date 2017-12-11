#pragma once
#include <leagueapi/base.hpp>
#include <leagueapi/definitions/MatchmakingLcdsSummoner.hpp>

namespace leagueapi {
  struct MatchmakingLcdsBustedLeaver { /**/ 
    std::string accessToken;/**/
    uint64_t leaverPenaltyMillisRemaining;/**/
    std::string reasonFailed;/**/
    MatchmakingLcdsSummoner summoner;/**/
  };
  static void to_json(json& j, const MatchmakingLcdsBustedLeaver& v) { 
    j["accessToken"] = v.accessToken;
    j["leaverPenaltyMillisRemaining"] = v.leaverPenaltyMillisRemaining;
    j["reasonFailed"] = v.reasonFailed;
    j["summoner"] = v.summoner;
  }
  static void from_json(const json& j, MatchmakingLcdsBustedLeaver& v) { 
    v.accessToken = j.at("accessToken").get<std::string>(); 
    v.leaverPenaltyMillisRemaining = j.at("leaverPenaltyMillisRemaining").get<uint64_t>(); 
    v.reasonFailed = j.at("reasonFailed").get<std::string>(); 
    v.summoner = j.at("summoner").get<MatchmakingLcdsSummoner>(); 
  }
} 