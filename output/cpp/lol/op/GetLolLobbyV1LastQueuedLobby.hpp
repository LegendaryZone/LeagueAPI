#pragma once
#include<lol/base_op.hpp> 
#include <lol/def/LolLobbyLobbyLastQueuedLobby.hpp>
namespace lol {
  Result<LolLobbyLobbyLastQueuedLobby> GetLolLobbyV1LastQueuedLobby(const LeagueClient& _client)
  {
    HttpsClient _client_(_client.host, false);
    return _client_.request("get", "/lol-lobby/v1/last-queued-lobby?" + SimpleWeb::QueryString::create(Args2Headers({  })), "",
      Args2Headers({ {"Authorization", _client.auth},  }) );
  }
}