#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/LolLoginLcdsResponse.hpp"
namespace lol {
  inline Result<LolLoginLcdsResponse> PostLolLoginV1SessionInvoke(LeagueClient& _client, const std::string& destination, const std::string& method, const std::vector<json>& args)
  {
    try {
      return Result<LolLoginLcdsResponse> {
        _client.https.request("post", "/lol-login/v1/session/invoke?" +
          SimpleWeb::QueryString::create(Args2Headers({ 
           { "destination", to_string(destination) },
           { "method", to_string(method) }, })), 
          Args2String({ 
           { "args", to_string(args) }, }),
          Args2Headers({
            {"content-type", "application/x-www-form-urlencoded"},
            {"Authorization", _client.auth},  }))
      };
    } catch(const SimpleWeb::system_error &e) {
      return Result<LolLoginLcdsResponse> { Error { to_string(e.code().value()), -1, e.code().message() } };
    }
  }
  inline void PostLolLoginV1SessionInvoke(LeagueClient& _client, const std::string& destination, const std::string& method, const std::vector<json>& args, std::function<void(LeagueClient&,const Result<LolLoginLcdsResponse>&)> cb)
  {
    _client.httpsa.request("post", "/lol-login/v1/session/invoke?" +
      SimpleWeb::QueryString::create(Args2Headers({ 
           { "destination", to_string(destination) },
           { "method", to_string(method) }, })), 
          Args2String({ 
           { "args", to_string(args) }, }),
          Args2Headers({
            {"content-type", "application/x-www-form-urlencoded"},
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
          if(!e)
            cb(_client, Result<LolLoginLcdsResponse> { response });
          else
            cb(_client,Result<LolLoginLcdsResponse> { Error { to_string(e.value()), -1, e.message() } });
        });
  }
}