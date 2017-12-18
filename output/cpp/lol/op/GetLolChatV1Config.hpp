#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/LolChatChatServiceDynamicClientConfig.hpp"
namespace lol {
  inline Result<LolChatChatServiceDynamicClientConfig> GetLolChatV1Config(LeagueClient& _client)
  {
    try {
      return Result<LolChatChatServiceDynamicClientConfig> {
        _client.https.request("get", "/lol-chat/v1/config?" +
          SimpleWeb::QueryString::create(Args2Headers({  })), 
          "",
          Args2Headers({  
            {"Authorization", _client.auth},  }))
      };
    } catch(const SimpleWeb::system_error &e) {
      return Result<LolChatChatServiceDynamicClientConfig> { Error { to_string(e.code().value()), -1, e.code().message() } };
    }
  }
  inline void GetLolChatV1Config(LeagueClient& _client, std::function<void(LeagueClient&,const Result<LolChatChatServiceDynamicClientConfig>&)> cb)
  {
    _client.httpsa.request("get", "/lol-chat/v1/config?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
          "",
          Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
          if(!e)
            cb(_client, Result<LolChatChatServiceDynamicClientConfig> { response });
          else
            cb(_client,Result<LolChatChatServiceDynamicClientConfig> { Error { to_string(e.value()), -1, e.message() } });
        });
  }
}