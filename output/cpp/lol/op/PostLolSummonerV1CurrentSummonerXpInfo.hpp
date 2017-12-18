#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/LolSummonerSummoner.hpp"
namespace lol {
  inline Result<LolSummonerSummoner> PostLolSummonerV1CurrentSummonerXpInfo(LeagueClient& _client)
  {
    try {
      return Result<LolSummonerSummoner> {
        _client.https.request("post", "/lol-summoner/v1/current-summoner/xpInfo?" +
          SimpleWeb::QueryString::create(Args2Headers({  })), 
          "",
          Args2Headers({  
            {"Authorization", _client.auth},  }))
      };
    } catch(const SimpleWeb::system_error &e) {
      return Result<LolSummonerSummoner> { Error { to_string(e.code().value()), -1, e.code().message() } };
    }
  }
  inline void PostLolSummonerV1CurrentSummonerXpInfo(LeagueClient& _client, std::function<void(LeagueClient&,const Result<LolSummonerSummoner>&)> cb)
  {
    _client.httpsa.request("post", "/lol-summoner/v1/current-summoner/xpInfo?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
          "",
          Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
          if(!e)
            cb(_client, Result<LolSummonerSummoner> { response });
          else
            cb(_client,Result<LolSummonerSummoner> { Error { to_string(e.value()), -1, e.message() } });
        });
  }
}