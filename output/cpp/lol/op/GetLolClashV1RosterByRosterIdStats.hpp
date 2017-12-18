#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/LolClashRosterStats.hpp"
namespace lol {
  inline Result<LolClashRosterStats> GetLolClashV1RosterByRosterIdStats(LeagueClient& _client, const int64_t& rosterId)
  {
    try {
      return Result<LolClashRosterStats> {
        _client.https.request("get", "/lol-clash/v1/roster/"+to_string(rosterId)+"/stats?" +
          SimpleWeb::QueryString::create(Args2Headers({  })), 
          "",
          Args2Headers({  
            {"Authorization", _client.auth},  }))
      };
    } catch(const SimpleWeb::system_error &e) {
      return Result<LolClashRosterStats> { Error { to_string(e.code().value()), -1, e.code().message() } };
    }
  }
  inline void GetLolClashV1RosterByRosterIdStats(LeagueClient& _client, const int64_t& rosterId, std::function<void(LeagueClient&,const Result<LolClashRosterStats>&)> cb)
  {
    _client.httpsa.request("get", "/lol-clash/v1/roster/"+to_string(rosterId)+"/stats?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
          "",
          Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
          if(!e)
            cb(_client, Result<LolClashRosterStats> { response });
          else
            cb(_client,Result<LolClashRosterStats> { Error { to_string(e.value()), -1, e.message() } });
        });
  }
}