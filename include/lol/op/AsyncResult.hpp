#pragma once
#include "../base_op.hpp"
#include <functional> 
namespace lol {
  template<typename T>
  inline Result<json> AsyncResult(T& _client, const uint32_t& asyncToken)
  {
    try {
      return ToResult<json>(_client.https.request("post", "/AsyncResult?" +
        SimpleWeb::QueryString::create(Args2Headers({ 
          { "asyncToken", to_string(asyncToken) }, })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  })));
    } catch(const SimpleWeb::system_error &e) {
      return ToResult<json>(e.code());
    }
  }
  template<typename T>
  inline void AsyncResult(T& _client, const uint32_t& asyncToken, std::function<void(T&, const Result<json>&)> cb)
  {
    _client.httpsa.request("post", "/AsyncResult?" +
      SimpleWeb::QueryString::create(Args2Headers({ 
          { "asyncToken", to_string(asyncToken) }, })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
            if(e)
              cb(_client, ToResult<json>(e));
            else
              cb(_client, ToResult<json>(response));
        });
  }
}