#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/FailedInvite.hpp"
namespace lol {
  inline Result<std::vector<FailedInvite>> PostLolClashV1TournamentByTournamentIdRosterInvite(LeagueClient& _client, const int64_t& tournamentId, const std::vector<uint64_t>& summonerIds)
  {
    try {
      return Result<std::vector<FailedInvite>> {
        _client.https.request("post", "/lol-clash/v1/tournament/"+to_string(tournamentId)+"/roster/invite?" +
          SimpleWeb::QueryString::create(Args2Headers({  })), 
          json(summonerIds).dump(),
          Args2Headers({
            {"content-type", "application/json"},
            {"Authorization", _client.auth},  }))
      };
    } catch(const SimpleWeb::system_error &e) {
      return Result<std::vector<FailedInvite>> { Error { to_string(e.code().value()), -1, e.code().message() } };
    }
  }
  inline void PostLolClashV1TournamentByTournamentIdRosterInvite(LeagueClient& _client, const int64_t& tournamentId, const std::vector<uint64_t>& summonerIds, std::function<void(LeagueClient&,const Result<std::vector<FailedInvite>>&)> cb)
  {
    _client.httpsa.request("post", "/lol-clash/v1/tournament/"+to_string(tournamentId)+"/roster/invite?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
          json(summonerIds).dump(),
          Args2Headers({
            {"content-type", "application/json"},
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
          if(!e)
            cb(_client, Result<std::vector<FailedInvite>> { response });
          else
            cb(_client,Result<std::vector<FailedInvite>> { Error { to_string(e.value()), -1, e.message() } });
        });
  }
}