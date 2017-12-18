#pragma once
#include "../base_op.hpp"
#include <functional> 
namespace lol {
  inline Result<json> PostLolLobbyV1LobbyMembersByIdGrantInvite(LeagueClient& _client, const uint64_t& id)
  {
    try {
      return Result<json> {
        _client.https.request("post", "/lol-lobby/v1/lobby/members/"+to_string(id)+"/grant-invite?" +
          SimpleWeb::QueryString::create(Args2Headers({  })), 
          "",
          Args2Headers({  
            {"Authorization", _client.auth},  }))
      };
    } catch(const SimpleWeb::system_error &e) {
      return Result<json> { Error { to_string(e.code().value()), -1, e.code().message() } };
    }
  }
  inline void PostLolLobbyV1LobbyMembersByIdGrantInvite(LeagueClient& _client, const uint64_t& id, std::function<void(LeagueClient&,const Result<json>&)> cb)
  {
    _client.httpsa.request("post", "/lol-lobby/v1/lobby/members/"+to_string(id)+"/grant-invite?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
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