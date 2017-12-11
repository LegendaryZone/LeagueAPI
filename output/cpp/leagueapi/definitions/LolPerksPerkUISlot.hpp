#pragma once
#include <leagueapi/base.hpp>

namespace leagueapi {
  struct LolPerksPerkUISlot { /**/ 
    std::string type;/**/
    std::vector<int32_t> perks;/**/
    std::string slotLabel;/**/
  };
  static void to_json(json& j, const LolPerksPerkUISlot& v) { 
    j["type"] = v.type;
    j["perks"] = v.perks;
    j["slotLabel"] = v.slotLabel;
  }
  static void from_json(const json& j, LolPerksPerkUISlot& v) { 
    v.type = j.at("type").get<std::string>(); 
    v.perks = j.at("perks").get<std::vector<int32_t>>(); 
    v.slotLabel = j.at("slotLabel").get<std::string>(); 
  }
} 