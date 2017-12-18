#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/RsoAuthAuthorization.hpp"
namespace lol {
  inline Result<RsoAuthAuthorization> GetRsoAuthV1Authorization(LeagueClient& _client)
  {
    try {
      return Result<RsoAuthAuthorization> {
        _client.https.request("get", "/rso-auth/v1/authorization?" +
          SimpleWeb::QueryString::create(Args2Headers({  })), 
          "",
          Args2Headers({  
            {"Authorization", _client.auth},  }))
      };
    } catch(const SimpleWeb::system_error &e) {
      return Result<RsoAuthAuthorization> { Error { to_string(e.code().value()), -1, e.code().message() } };
    }
  }
  inline void GetRsoAuthV1Authorization(LeagueClient& _client, std::function<void(LeagueClient&,const Result<RsoAuthAuthorization>&)> cb)
  {
    _client.httpsa.request("get", "/rso-auth/v1/authorization?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
          "",
          Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
          if(!e)
            cb(_client, Result<RsoAuthAuthorization> { response });
          else
            cb(_client,Result<RsoAuthAuthorization> { Error { to_string(e.value()), -1, e.message() } });
        });
  }
}