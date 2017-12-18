#pragma once
#include "../base_op.hpp"
#include <functional> 
namespace lol {
  inline Result<bool> GetLolLobbyV1AutofillDisplayed(LeagueClient& _client)
  {
    try {
      return Result<bool> {
        _client.https.request("get", "/lol-lobby/v1/autofill-displayed?" +
          SimpleWeb::QueryString::create(Args2Headers({  })), 
          "",
          Args2Headers({  
            {"Authorization", _client.auth},  }))
      };
    } catch(const SimpleWeb::system_error &e) {
      return Result<bool> { Error { to_string(e.code().value()), -1, e.code().message() } };
    }
  }
  inline void GetLolLobbyV1AutofillDisplayed(LeagueClient& _client, std::function<void(LeagueClient&,const Result<bool>&)> cb)
  {
    _client.httpsa.request("get", "/lol-lobby/v1/autofill-displayed?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
          "",
          Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
          if(!e)
            cb(_client, Result<bool> { response });
          else
            cb(_client,Result<bool> { Error { to_string(e.value()), -1, e.message() } });
        });
  }
}