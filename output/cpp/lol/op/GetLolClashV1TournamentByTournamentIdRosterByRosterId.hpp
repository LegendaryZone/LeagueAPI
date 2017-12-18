#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/LolClashRoster.hpp"
namespace lol {
  inline Result<LolClashRoster> GetLolClashV1TournamentByTournamentIdRosterByRosterId(LeagueClient& _client, const int64_t& tournamentId, const std::string& rosterId)
  {
    try {
      return Result<LolClashRoster> {
        _client.https.request("get", "/lol-clash/v1/tournament/"+to_string(tournamentId)+"/roster/"+to_string(rosterId)+"?" +
          SimpleWeb::QueryString::create(Args2Headers({  })), 
          "",
          Args2Headers({  
            {"Authorization", _client.auth},  }))
      };
    } catch(const SimpleWeb::system_error &e) {
      return Result<LolClashRoster> { Error { to_string(e.code().value()), -1, e.code().message() } };
    }
  }
  inline void GetLolClashV1TournamentByTournamentIdRosterByRosterId(LeagueClient& _client, const int64_t& tournamentId, const std::string& rosterId, std::function<void(LeagueClient&,const Result<LolClashRoster>&)> cb)
  {
    _client.httpsa.request("get", "/lol-clash/v1/tournament/"+to_string(tournamentId)+"/roster/"+to_string(rosterId)+"?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
          "",
          Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
          if(!e)
            cb(_client, Result<LolClashRoster> { response });
          else
            cb(_client,Result<LolClashRoster> { Error { to_string(e.value()), -1, e.message() } });
        });
  }
}