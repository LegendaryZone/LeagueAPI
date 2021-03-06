#pragma once
#include "../base_def.hpp" 
namespace lol {
  struct LolChatAuthResourcePlain { 
    std::string username;
    std::string password;
    json gasToken; 
  };
  inline void to_json(json& j, const LolChatAuthResourcePlain& v) {
    j["username"] = v.username; 
    j["password"] = v.password; 
    j["gasToken"] = v.gasToken; 
  }
  inline void from_json(const json& j, LolChatAuthResourcePlain& v) {
    v.username = j.at("username").get<std::string>(); 
    v.password = j.at("password").get<std::string>(); 
    v.gasToken = j.at("gasToken").get<json>(); 
  }
}