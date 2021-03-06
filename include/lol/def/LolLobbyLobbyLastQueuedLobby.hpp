#pragma once
#include "../base_def.hpp" 
#include "LolLobbyLobbyLastQueuedMember.hpp"
namespace lol {
  struct LolLobbyLobbyLastQueuedLobby { 
    int32_t queueId;
    bool wasOwner;
    bool canPlayAgain;
    std::vector<LolLobbyLobbyLastQueuedMember> members; 
  };
  inline void to_json(json& j, const LolLobbyLobbyLastQueuedLobby& v) {
    j["queueId"] = v.queueId; 
    j["wasOwner"] = v.wasOwner; 
    j["canPlayAgain"] = v.canPlayAgain; 
    j["members"] = v.members; 
  }
  inline void from_json(const json& j, LolLobbyLobbyLastQueuedLobby& v) {
    v.queueId = j.at("queueId").get<int32_t>(); 
    v.wasOwner = j.at("wasOwner").get<bool>(); 
    v.canPlayAgain = j.at("canPlayAgain").get<bool>(); 
    v.members = j.at("members").get<std::vector<LolLobbyLobbyLastQueuedMember>>(); 
  }
}