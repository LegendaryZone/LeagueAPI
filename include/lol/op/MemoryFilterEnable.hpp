#pragma once
#include "../base_op.hpp"
#include <functional> 
namespace lol {
  inline Result<std::nullptr_t> MemoryFilterEnable(LeagueClient& _client, const std::optional<int32_t>& enable = std::nullopt)
  {
    try {
      return ToResult<std::nullptr_t>(_client.https.request("post", "/MemoryFilterEnable?" +
        SimpleWeb::QueryString::create(Args2Headers({ 
          { "enable", to_string(enable) }, })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  })));
    } catch(const SimpleWeb::system_error &e) {
      return ToResult<std::nullptr_t>(e.code());
    }
  }
  inline void MemoryFilterEnable(LeagueClient& _client, const std::optional<int32_t>& enable = std::nullopt, std::function<void(LeagueClient&, const Result<std::nullptr_t>&)> cb)
  {
    _client.httpsa.request("post", "/MemoryFilterEnable?" +
      SimpleWeb::QueryString::create(Args2Headers({ 
          { "enable", to_string(enable) }, })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
            if(e)
              cb(_client, ToResult<std::nullptr_t>(e));
            else
              cb(_client, ToResult<std::nullptr_t>(response));
        });
  }
}