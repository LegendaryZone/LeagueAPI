#pragma once
#include<lol/base_def.hpp> 
namespace lol {
  struct LolChatBlockedPlayerResource { 
    std::string name;
    uint64_t id; 
  };
  void to_json(json& j, const LolChatBlockedPlayerResource& v) {
  j["name"] = v.name; 
  j["id"] = v.id; 
  }
  void from_json(const json& j, LolChatBlockedPlayerResource& v) {
  v.name = j.at("name").get<std::string>(); 
  v.id = j.at("id").get<uint64_t>(); 
  }
}