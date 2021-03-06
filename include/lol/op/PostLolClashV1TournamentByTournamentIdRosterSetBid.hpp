#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/LolClashSetTicketRequest.hpp"
namespace lol {
  template<typename T>
  inline Result<json> PostLolClashV1TournamentByTournamentIdRosterSetBid(T& _client, const int64_t& tournamentId, const LolClashSetTicketRequest& setTicketRequest)
  {
    try {
      return ToResult<json>(_client.https.request("post", "/lol-clash/v1/tournament/"+to_string(tournamentId)+"/roster/set-bid?" +
        SimpleWeb::QueryString::create(Args2Headers({  })), 
        json(setTicketRequest).dump(),
        Args2Headers({
          {"content-type", "application/json"},
        {"Authorization", _client.auth},  })));
    } catch(const SimpleWeb::system_error &e) {
      return ToResult<json>(e.code());
    }
  }
  template<typename T>
  inline void PostLolClashV1TournamentByTournamentIdRosterSetBid(T& _client, const int64_t& tournamentId, const LolClashSetTicketRequest& setTicketRequest, std::function<void(T&, const Result<json>&)> cb)
  {
    _client.httpsa.request("post", "/lol-clash/v1/tournament/"+to_string(tournamentId)+"/roster/set-bid?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
        json(setTicketRequest).dump(),
        Args2Headers({
          {"content-type", "application/json"},
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
            if(e)
              cb(_client, ToResult<json>(e));
            else
              cb(_client, ToResult<json>(response));
        });
  }
}