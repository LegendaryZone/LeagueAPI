#pragma once
#include <leagueapi/base.hpp>

namespace leagueapi {
  struct LolClubsPublicUserResource { /**/ 
    std::optional<std::string> lastSeenOnlineTimestamp;/**/
    uint64_t id;/**/
    std::string name;/**/
    std::map<std::string, std::string> lol;/**/
    int32_t icon;/**/
    std::string availability;/**/
  };
  static void to_json(json& j, const LolClubsPublicUserResource& v) { 
    j["lastSeenOnlineTimestamp"] = v.lastSeenOnlineTimestamp;
    j["id"] = v.id;
    j["name"] = v.name;
    j["lol"] = v.lol;
    j["icon"] = v.icon;
    j["availability"] = v.availability;
  }
  static void from_json(const json& j, LolClubsPublicUserResource& v) { 
    v.lastSeenOnlineTimestamp = j.at("lastSeenOnlineTimestamp").get<std::optional<std::string>>(); 
    v.id = j.at("id").get<uint64_t>(); 
    v.name = j.at("name").get<std::string>(); 
    v.lol = j.at("lol").get<std::map<std::string, std::string>>(); 
    v.icon = j.at("icon").get<int32_t>(); 
    v.availability = j.at("availability").get<std::string>(); 
  }
} 