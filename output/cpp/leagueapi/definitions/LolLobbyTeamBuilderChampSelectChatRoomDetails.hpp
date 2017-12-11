#pragma once
#include <leagueapi/base.hpp>

namespace leagueapi {
  struct LolLobbyTeamBuilderChampSelectChatRoomDetails { /**/ 
    std::optional<std::string> chatRoomPassword;/**/
    std::string chatRoomName;/**/
  };
  static void to_json(json& j, const LolLobbyTeamBuilderChampSelectChatRoomDetails& v) { 
    j["chatRoomPassword"] = v.chatRoomPassword;
    j["chatRoomName"] = v.chatRoomName;
  }
  static void from_json(const json& j, LolLobbyTeamBuilderChampSelectChatRoomDetails& v) { 
    v.chatRoomPassword = j.at("chatRoomPassword").get<std::optional<std::string>>(); 
    v.chatRoomName = j.at("chatRoomName").get<std::string>(); 
  }
} 