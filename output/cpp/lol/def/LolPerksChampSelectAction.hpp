#pragma once
#include<lol/base_def.hpp> 
namespace lol {
  struct LolPerksChampSelectAction { 
    bool completed;
    int64_t actorCellId;
    std::string type;
    int32_t championId;
    int64_t id; 
  };
  void to_json(json& j, const LolPerksChampSelectAction& v) {
  j["completed"] = v.completed; 
  j["actorCellId"] = v.actorCellId; 
  j["type"] = v.type; 
  j["championId"] = v.championId; 
  j["id"] = v.id; 
  }
  void from_json(const json& j, LolPerksChampSelectAction& v) {
  v.completed = j.at("completed").get<bool>(); 
  v.actorCellId = j.at("actorCellId").get<int64_t>(); 
  v.type = j.at("type").get<std::string>(); 
  v.championId = j.at("championId").get<int32_t>(); 
  v.id = j.at("id").get<int64_t>(); 
  }
}