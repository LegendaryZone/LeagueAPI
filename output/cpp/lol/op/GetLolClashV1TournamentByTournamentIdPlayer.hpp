#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/LolClashPlayerTournamentData.hpp"
namespace lol {
  inline Result<LolClashPlayerTournamentData> GetLolClashV1TournamentByTournamentIdPlayer(LeagueClient& _client, const int64_t& tournamentId)
  {
    try {
      return Result<LolClashPlayerTournamentData> {
        _client.https.request("get", "/lol-clash/v1/tournament/"+to_string(tournamentId)+"/player?" +
          SimpleWeb::QueryString::create(Args2Headers({  })), 
          "",
          Args2Headers({  
            {"Authorization", _client.auth},  }))
      };
    } catch(const SimpleWeb::system_error &e) {
      return Result<LolClashPlayerTournamentData> { Error { to_string(e.code().value()), -1, e.code().message() } };
    }
  }
  inline void GetLolClashV1TournamentByTournamentIdPlayer(LeagueClient& _client, const int64_t& tournamentId, std::function<void(LeagueClient&,const Result<LolClashPlayerTournamentData>&)> cb)
  {
    _client.httpsa.request("get", "/lol-clash/v1/tournament/"+to_string(tournamentId)+"/player?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
          "",
          Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
          if(!e)
            cb(_client, Result<LolClashPlayerTournamentData> { response });
          else
            cb(_client,Result<LolClashPlayerTournamentData> { Error { to_string(e.value()), -1, e.message() } });
        });
  }
}