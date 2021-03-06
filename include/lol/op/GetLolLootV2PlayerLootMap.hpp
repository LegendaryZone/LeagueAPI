#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/LolLootPlayerLootMap.hpp"
namespace lol {
  template<typename T>
  inline Result<LolLootPlayerLootMap> GetLolLootV2PlayerLootMap(T& _client)
  {
    try {
      return ToResult<LolLootPlayerLootMap>(_client.https.request("get", "/lol-loot/v2/player-loot-map?" +
        SimpleWeb::QueryString::create(Args2Headers({  })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  })));
    } catch(const SimpleWeb::system_error &e) {
      return ToResult<LolLootPlayerLootMap>(e.code());
    }
  }
  template<typename T>
  inline void GetLolLootV2PlayerLootMap(T& _client, std::function<void(T&, const Result<LolLootPlayerLootMap>&)> cb)
  {
    _client.httpsa.request("get", "/lol-loot/v2/player-loot-map?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
            if(e)
              cb(_client, ToResult<LolLootPlayerLootMap>(e));
            else
              cb(_client, ToResult<LolLootPlayerLootMap>(response));
        });
  }
}