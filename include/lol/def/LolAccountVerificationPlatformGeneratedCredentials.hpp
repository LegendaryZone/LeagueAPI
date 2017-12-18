#pragma once
#include "../base_def.hpp" 
namespace lol {
  struct LolAccountVerificationPlatformGeneratedCredentials { 
    std::string password;
    std::string username;
    json gasToken; 
  };
  inline void to_json(json& j, const LolAccountVerificationPlatformGeneratedCredentials& v) {
    j["password"] = v.password; 
    j["username"] = v.username; 
    j["gasToken"] = v.gasToken; 
  }
  inline void from_json(const json& j, LolAccountVerificationPlatformGeneratedCredentials& v) {
    v.password = j.at("password").get<std::string>(); 
    v.username = j.at("username").get<std::string>(); 
    v.gasToken = j.at("gasToken").get<json>(); 
  }
}