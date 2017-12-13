#pragma once
#include<lol/base_def.hpp> 
namespace lol {
  struct ClientDynamicConfig { 
    std::string configs;
    bool compressed;
    bool delta; 
  };
  void to_json(json& j, const ClientDynamicConfig& v) {
  j["configs"] = v.configs; 
  j["compressed"] = v.compressed; 
  j["delta"] = v.delta; 
  }
  void from_json(const json& j, ClientDynamicConfig& v) {
  v.configs = j.at("configs").get<std::string>(); 
  v.compressed = j.at("compressed").get<bool>(); 
  v.delta = j.at("delta").get<bool>(); 
  }
}