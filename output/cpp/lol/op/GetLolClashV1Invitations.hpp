#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/LolClashRoster.hpp"
namespace lol {
  inline Result<std::vector<LolClashRoster>> GetLolClashV1Invitations(LeagueClient& _client)
  {
    try {
      return Result<std::vector<LolClashRoster>> {
        _client.https.request("get", "/lol-clash/v1/invitations?" +
          SimpleWeb::QueryString::create(Args2Headers({  })), 
          "",
          Args2Headers({  
            {"Authorization", _client.auth},  }))
      };
    } catch(const SimpleWeb::system_error &e) {
      return Result<std::vector<LolClashRoster>> { Error { to_string(e.code().value()), -1, e.code().message() } };
    }
  }
  inline void GetLolClashV1Invitations(LeagueClient& _client, std::function<void(LeagueClient&,const Result<std::vector<LolClashRoster>>&)> cb)
  {
    _client.httpsa.request("get", "/lol-clash/v1/invitations?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
          "",
          Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
          if(!e)
            cb(_client, Result<std::vector<LolClashRoster>> { response });
          else
            cb(_client,Result<std::vector<LolClashRoster>> { Error { to_string(e.value()), -1, e.message() } });
        });
  }
}