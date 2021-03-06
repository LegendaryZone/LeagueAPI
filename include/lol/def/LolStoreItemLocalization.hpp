#pragma once
#include "../base_def.hpp" 
namespace lol {
  struct LolStoreItemLocalization { 
    std::string language;
    std::string name;
    std::string description; 
  };
  inline void to_json(json& j, const LolStoreItemLocalization& v) {
    j["language"] = v.language; 
    j["name"] = v.name; 
    j["description"] = v.description; 
  }
  inline void from_json(const json& j, LolStoreItemLocalization& v) {
    v.language = j.at("language").get<std::string>(); 
    v.name = j.at("name").get<std::string>(); 
    v.description = j.at("description").get<std::string>(); 
  }
}