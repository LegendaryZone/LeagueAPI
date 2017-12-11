#pragma once
#include <leagueapi/base.hpp>
#include <leagueapi/definitions/LolChampSelectLegacyCollectionsRental.hpp>

namespace leagueapi {
  struct LolChampSelectLegacyCollectionsOwnership { /**/ 
    LolChampSelectLegacyCollectionsRental rental;/**/
    bool freeToPlayReward;/**/
    bool owned;/**/
  };
  static void to_json(json& j, const LolChampSelectLegacyCollectionsOwnership& v) { 
    j["rental"] = v.rental;
    j["freeToPlayReward"] = v.freeToPlayReward;
    j["owned"] = v.owned;
  }
  static void from_json(const json& j, LolChampSelectLegacyCollectionsOwnership& v) { 
    v.rental = j.at("rental").get<LolChampSelectLegacyCollectionsRental>(); 
    v.freeToPlayReward = j.at("freeToPlayReward").get<bool>(); 
    v.owned = j.at("owned").get<bool>(); 
  }
} 