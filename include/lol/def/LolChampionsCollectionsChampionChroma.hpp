#pragma once
#include "../base_def.hpp" 
#include "LolChampionsCollectionsOwnership.hpp"
namespace lol {
  struct LolChampionsCollectionsChampionChroma { 
    bool lastSelected;
    std::optional<std::string> chromaPath;
    std::vector<std::string> colors;
    bool disabled;
    LolChampionsCollectionsOwnership ownership;
    bool stillObtainable;
    std::string name;
    int32_t championId;
    int32_t id; 
  };
  inline void to_json(json& j, const LolChampionsCollectionsChampionChroma& v) {
    j["lastSelected"] = v.lastSelected; 
    if(v.chromaPath)
      j["chromaPath"] = *v.chromaPath;
    j["colors"] = v.colors; 
    j["disabled"] = v.disabled; 
    j["ownership"] = v.ownership; 
    j["stillObtainable"] = v.stillObtainable; 
    j["name"] = v.name; 
    j["championId"] = v.championId; 
    j["id"] = v.id; 
  }
  inline void from_json(const json& j, LolChampionsCollectionsChampionChroma& v) {
    v.lastSelected = j.at("lastSelected").get<bool>(); 
    if(auto it = j.find("chromaPath"); it != j.end() && !it->is_null())
      v.chromaPath = it->get<std::optional<std::string>>(); 
    v.colors = j.at("colors").get<std::vector<std::string>>(); 
    v.disabled = j.at("disabled").get<bool>(); 
    v.ownership = j.at("ownership").get<LolChampionsCollectionsOwnership>(); 
    v.stillObtainable = j.at("stillObtainable").get<bool>(); 
    v.name = j.at("name").get<std::string>(); 
    v.championId = j.at("championId").get<int32_t>(); 
    v.id = j.at("id").get<int32_t>(); 
  }
}