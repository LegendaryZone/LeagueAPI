#pragma once
#include "../base_def.hpp" 
namespace lol {
  struct LolEsportStreamNotificationsESportsAPI_streamgroups { 
    int64_t id;
    std::string slug;
    std::string title;
    bool live;
    std::string content; 
  };
  inline void to_json(json& j, const LolEsportStreamNotificationsESportsAPI_streamgroups& v) {
    j["id"] = v.id; 
    j["slug"] = v.slug; 
    j["title"] = v.title; 
    j["live"] = v.live; 
    j["content"] = v.content; 
  }
  inline void from_json(const json& j, LolEsportStreamNotificationsESportsAPI_streamgroups& v) {
    v.id = j.at("id").get<int64_t>(); 
    v.slug = j.at("slug").get<std::string>(); 
    v.title = j.at("title").get<std::string>(); 
    v.live = j.at("live").get<bool>(); 
    v.content = j.at("content").get<std::string>(); 
  }
}