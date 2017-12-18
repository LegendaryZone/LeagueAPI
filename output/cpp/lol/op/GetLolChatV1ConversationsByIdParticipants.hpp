#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/LolChatUserResource.hpp"
namespace lol {
  inline Result<std::vector<LolChatUserResource>> GetLolChatV1ConversationsByIdParticipants(LeagueClient& _client, const std::string& id)
  {
    try {
      return Result<std::vector<LolChatUserResource>> {
        _client.https.request("get", "/lol-chat/v1/conversations/"+to_string(id)+"/participants?" +
          SimpleWeb::QueryString::create(Args2Headers({  })), 
          "",
          Args2Headers({  
            {"Authorization", _client.auth},  }))
      };
    } catch(const SimpleWeb::system_error &e) {
      return Result<std::vector<LolChatUserResource>> { Error { to_string(e.code().value()), -1, e.code().message() } };
    }
  }
  inline void GetLolChatV1ConversationsByIdParticipants(LeagueClient& _client, const std::string& id, std::function<void(LeagueClient&,const Result<std::vector<LolChatUserResource>>&)> cb)
  {
    _client.httpsa.request("get", "/lol-chat/v1/conversations/"+to_string(id)+"/participants?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
          "",
          Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
          if(!e)
            cb(_client, Result<std::vector<LolChatUserResource>> { response });
          else
            cb(_client,Result<std::vector<LolChatUserResource>> { Error { to_string(e.value()), -1, e.message() } });
        });
  }
}