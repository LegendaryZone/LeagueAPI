#pragma once
#include "../base_def.hpp" 
#include "LolChampionsCollectionsChampionSkinEmblemPosition.hpp"
#include "LolChampionsCollectionsChampionSkinEmblemPath.hpp"
namespace lol {
  struct LolChampionsCollectionsChampionSkinEmblem { 
    LolChampionsCollectionsChampionSkinEmblemPath emblemPath;
    LolChampionsCollectionsChampionSkinEmblemPosition positions;
    std::string name; 
  };
  inline void to_json(json& j, const LolChampionsCollectionsChampionSkinEmblem& v) {
    j["emblemPath"] = v.emblemPath; 
    j["positions"] = v.positions; 
    j["name"] = v.name; 
  }
  inline void from_json(const json& j, LolChampionsCollectionsChampionSkinEmblem& v) {
    v.emblemPath = j.at("emblemPath").get<LolChampionsCollectionsChampionSkinEmblemPath>(); 
    v.positions = j.at("positions").get<LolChampionsCollectionsChampionSkinEmblemPosition>(); 
    v.name = j.at("name").get<std::string>(); 
  }
}