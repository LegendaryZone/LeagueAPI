#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/LolLobbyLobbyBotParams.hpp"
namespace lol {
  template<typename T>
  inline Result<json> PostLolLobbyV1LobbyCustomBots(T& _client, const LolLobbyLobbyBotParams& parameters)
  {
    try {
      return ToResult<json>(_client.https.request("post", "/lol-lobby/v1/lobby/custom/bots?" +
        SimpleWeb::QueryString::create(Args2Headers({  })), 
        json(parameters).dump(),
        Args2Headers({
          {"content-type", "application/json"},
        {"Authorization", _client.auth},  })));
    } catch(const SimpleWeb::system_error &e) {
      return ToResult<json>(e.code());
    }
  }
  template<typename T>
  inline void PostLolLobbyV1LobbyCustomBots(T& _client, const LolLobbyLobbyBotParams& parameters, std::function<void(T&, const Result<json>&)> cb)
  {
    _client.httpsa.request("post", "/lol-lobby/v1/lobby/custom/bots?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
        json(parameters).dump(),
        Args2Headers({
          {"content-type", "application/json"},
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
            if(e)
              cb(_client, ToResult<json>(e));
            else
              cb(_client, ToResult<json>(response));
        });
  }
}