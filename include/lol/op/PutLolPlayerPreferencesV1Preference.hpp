#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/PlayerPreferences.hpp"
namespace lol {
  template<typename T>
  inline Result<json> PutLolPlayerPreferencesV1Preference(T& _client, const PlayerPreferences& preferences)
  {
    try {
      return ToResult<json>(_client.https.request("put", "/lol-player-preferences/v1/preference?" +
        SimpleWeb::QueryString::create(Args2Headers({  })), 
        json(preferences).dump(),
        Args2Headers({
          {"content-type", "application/json"},
        {"Authorization", _client.auth},  })));
    } catch(const SimpleWeb::system_error &e) {
      return ToResult<json>(e.code());
    }
  }
  template<typename T>
  inline void PutLolPlayerPreferencesV1Preference(T& _client, const PlayerPreferences& preferences, std::function<void(T&, const Result<json>&)> cb)
  {
    _client.httpsa.request("put", "/lol-player-preferences/v1/preference?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
        json(preferences).dump(),
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