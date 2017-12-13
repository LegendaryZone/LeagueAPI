#pragma once
#include<lol/base_def.hpp> 
namespace lol {
  struct LolLoginLoginSessionWallet { 
    int64_t ip;
    int64_t rp; 
  };
  void to_json(json& j, const LolLoginLoginSessionWallet& v) {
  j["ip"] = v.ip; 
  j["rp"] = v.rp; 
  }
  void from_json(const json& j, LolLoginLoginSessionWallet& v) {
  v.ip = j.at("ip").get<int64_t>(); 
  v.rp = j.at("rp").get<int64_t>(); 
  }
}