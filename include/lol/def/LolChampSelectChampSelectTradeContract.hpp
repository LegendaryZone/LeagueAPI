#pragma once
#include "../base_def.hpp" 
#include "LolChampSelectChampSelectTradeState.hpp"
namespace lol {
  struct LolChampSelectChampSelectTradeContract { 
    LolChampSelectChampSelectTradeState state;
    int64_t cellId;
    int64_t id; 
  };
  inline void to_json(json& j, const LolChampSelectChampSelectTradeContract& v) {
    j["state"] = v.state; 
    j["cellId"] = v.cellId; 
    j["id"] = v.id; 
  }
  inline void from_json(const json& j, LolChampSelectChampSelectTradeContract& v) {
    v.state = j.at("state").get<LolChampSelectChampSelectTradeState>(); 
    v.cellId = j.at("cellId").get<int64_t>(); 
    v.id = j.at("id").get<int64_t>(); 
  }
}