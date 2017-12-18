#pragma once
#include "../base_op.hpp"
#include <functional> 
namespace lol {
  inline Result<void> PostLolLoginV1ServiceProxyAsyncRequestsByServiceNameByMethodName(LeagueClient& _client, const std::string& serviceName, const std::string& methodName, const uint32_t& pluginId)
  {
    try {
      return Result<void> {
        _client.https.request("post", "/lol-login/v1/service-proxy-async-requests/"+to_string(serviceName)+"/"+to_string(methodName)+"?" +
          SimpleWeb::QueryString::create(Args2Headers({ 
           { "pluginId", to_string(pluginId) }, })), 
          "",
          Args2Headers({  
            {"Authorization", _client.auth},  }))
      };
    } catch(const SimpleWeb::system_error &e) {
      return Result<void> { Error { to_string(e.code().value()), -1, e.code().message() } };
    }
  }
  inline void PostLolLoginV1ServiceProxyAsyncRequestsByServiceNameByMethodName(LeagueClient& _client, const std::string& serviceName, const std::string& methodName, const uint32_t& pluginId, std::function<void(LeagueClient&,const Result<void>&)> cb)
  {
    _client.httpsa.request("post", "/lol-login/v1/service-proxy-async-requests/"+to_string(serviceName)+"/"+to_string(methodName)+"?" +
      SimpleWeb::QueryString::create(Args2Headers({ 
           { "pluginId", to_string(pluginId) }, })), 
          "",
          Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
          if(!e)
            cb(_client, Result<void> { response });
          else
            cb(_client,Result<void> { Error { to_string(e.value()), -1, e.message() } });
        });
  }
}