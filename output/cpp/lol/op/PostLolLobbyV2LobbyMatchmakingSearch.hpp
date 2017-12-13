#pragma once
#include<lol/base_op.hpp> 
namespace lol {
  Result<json> PostLolLobbyV2LobbyMatchmakingSearch(const LeagueClient& _client)
  {
    HttpsClient _client_(_client.host, false);
    return _client_.request("post", "/lol-lobby/v2/lobby/matchmaking/search?" + SimpleWeb::QueryString::create(Args2Headers({  })), "",
      Args2Headers({ {"Authorization", _client.auth},  }) );
  }
}