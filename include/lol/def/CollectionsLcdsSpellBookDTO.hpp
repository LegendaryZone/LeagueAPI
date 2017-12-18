#pragma once
#include "../base_def.hpp" 
#include "CollectionsLcdsSpellBookPageDTO.hpp"
namespace lol {
  struct CollectionsLcdsSpellBookDTO { 
    std::vector<CollectionsLcdsSpellBookPageDTO> bookPages;
    std::string dateString;
    uint64_t summonerId; 
  };
  inline void to_json(json& j, const CollectionsLcdsSpellBookDTO& v) {
    j["bookPages"] = v.bookPages; 
    j["dateString"] = v.dateString; 
    j["summonerId"] = v.summonerId; 
  }
  inline void from_json(const json& j, CollectionsLcdsSpellBookDTO& v) {
    v.bookPages = j.at("bookPages").get<std::vector<CollectionsLcdsSpellBookPageDTO>>(); 
    v.dateString = j.at("dateString").get<std::string>(); 
    v.summonerId = j.at("summonerId").get<uint64_t>(); 
  }
}