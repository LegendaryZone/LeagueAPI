#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/RemotingSerializedFormat.hpp"
namespace lol {
  inline Result<json> WebSocketFormat(LeagueClient& _client, const std::optional<RemotingSerializedFormat>& format = std::nullopt)
  {
    try {
      return Result<json> {
        _client.https.request("post", "/WebSocketFormat?" +
          SimpleWeb::QueryString::create(Args2Headers({ 
           { "format", to_string(format) }, })), 
          "",
          Args2Headers({  
            {"Authorization", _client.auth},  }))
      };
    } catch(const SimpleWeb::system_error &e) {
      return Result<json> { Error { to_string(e.code().value()), -1, e.code().message() } };
    }
  }
  inline void WebSocketFormat(LeagueClient& _client, const std::optional<RemotingSerializedFormat>& format = std::nullopt, std::function<void(LeagueClient&,const Result<json>&)> cb)
  {
    _client.httpsa.request("post", "/WebSocketFormat?" +
      SimpleWeb::QueryString::create(Args2Headers({ 
           { "format", to_string(format) }, })), 
          "",
          Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
          if(!e)
            cb(_client, Result<json> { response });
          else
            cb(_client,Result<json> { Error { to_string(e.value()), -1, e.message() } });
        });
  }
}