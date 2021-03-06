#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/LolGameflowPlayerStatus.hpp"
namespace lol {
  template<typename T>
  inline Result<LolGameflowPlayerStatus> GetLolGameflowV1GameflowMetadataPlayerStatus(T& _client)
  {
    try {
      return ToResult<LolGameflowPlayerStatus>(_client.https.request("get", "/lol-gameflow/v1/gameflow-metadata/player-status?" +
        SimpleWeb::QueryString::create(Args2Headers({  })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  })));
    } catch(const SimpleWeb::system_error &e) {
      return ToResult<LolGameflowPlayerStatus>(e.code());
    }
  }
  template<typename T>
  inline void GetLolGameflowV1GameflowMetadataPlayerStatus(T& _client, std::function<void(T&, const Result<LolGameflowPlayerStatus>&)> cb)
  {
    _client.httpsa.request("get", "/lol-gameflow/v1/gameflow-metadata/player-status?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
            if(e)
              cb(_client, ToResult<LolGameflowPlayerStatus>(e));
            else
              cb(_client, ToResult<LolGameflowPlayerStatus>(response));
        });
  }
}