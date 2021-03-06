#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/LolReplaysReplaysConfiguration.hpp"
namespace lol {
  template<typename T>
  inline Result<LolReplaysReplaysConfiguration> GetLolReplaysV1Configuration(T& _client)
  {
    try {
      return ToResult<LolReplaysReplaysConfiguration>(_client.https.request("get", "/lol-replays/v1/configuration?" +
        SimpleWeb::QueryString::create(Args2Headers({  })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  })));
    } catch(const SimpleWeb::system_error &e) {
      return ToResult<LolReplaysReplaysConfiguration>(e.code());
    }
  }
  template<typename T>
  inline void GetLolReplaysV1Configuration(T& _client, std::function<void(T&, const Result<LolReplaysReplaysConfiguration>&)> cb)
  {
    _client.httpsa.request("get", "/lol-replays/v1/configuration?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
            if(e)
              cb(_client, ToResult<LolReplaysReplaysConfiguration>(e));
            else
              cb(_client, ToResult<LolReplaysReplaysConfiguration>(response));
        });
  }
}