#pragma once
#include <leagueapi/base.hpp>

namespace leagueapi {
  struct LolChampSelectChampSelectPickableChampions { /**/ 
    std::vector<int32_t> championIds;/**/
  };
  static void to_json(json& j, const LolChampSelectChampSelectPickableChampions& v) { 
    j["championIds"] = v.championIds;
  }
  static void from_json(const json& j, LolChampSelectChampSelectPickableChampions& v) { 
    v.championIds = j.at("championIds").get<std::vector<int32_t>>(); 
  }
} 