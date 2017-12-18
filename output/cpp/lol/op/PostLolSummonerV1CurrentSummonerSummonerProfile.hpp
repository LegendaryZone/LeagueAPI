#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/LolSummonerSummonerProfileUpdate.hpp"
namespace lol {
  inline Result<json> PostLolSummonerV1CurrentSummonerSummonerProfile(LeagueClient& _client, const LolSummonerSummonerProfileUpdate& body)
  {
    try {
      return Result<json> {
        _client.https.request("post", "/lol-summoner/v1/current-summoner/summoner-profile?" +
          SimpleWeb::QueryString::create(Args2Headers({  })), 
          json(body).dump(),
          Args2Headers({
            {"content-type", "application/json"},
            {"Authorization", _client.auth},  }))
      };
    } catch(const SimpleWeb::system_error &e) {
      return Result<json> { Error { to_string(e.code().value()), -1, e.code().message() } };
    }
  }
  inline void PostLolSummonerV1CurrentSummonerSummonerProfile(LeagueClient& _client, const LolSummonerSummonerProfileUpdate& body, std::function<void(LeagueClient&,const Result<json>&)> cb)
  {
    _client.httpsa.request("post", "/lol-summoner/v1/current-summoner/summoner-profile?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
          json(body).dump(),
          Args2Headers({
            {"content-type", "application/json"},
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
          if(!e)
            cb(_client, Result<json> { response });
          else
            cb(_client,Result<json> { Error { to_string(e.value()), -1, e.message() } });
        });
  }
}