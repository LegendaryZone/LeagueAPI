#pragma once
#include "../base_def.hpp" 
namespace lol {
  struct LolChampSelectLegacyChampSelectBannableChampions { 
    std::vector<int32_t> championIds; 
  };
  inline void to_json(json& j, const LolChampSelectLegacyChampSelectBannableChampions& v) {
    j["championIds"] = v.championIds; 
  }
  inline void from_json(const json& j, LolChampSelectLegacyChampSelectBannableChampions& v) {
    v.championIds = j.at("championIds").get<std::vector<int32_t>>(); 
  }
}