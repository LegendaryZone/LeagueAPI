#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/LolPftPFTSurvey.hpp"
namespace lol {
  inline Result<void> PostLolPftV2Survey(LeagueClient& _client, const LolPftPFTSurvey& survey)
  {
    try {
      return Result<void> {
        _client.https.request("post", "/lol-pft/v2/survey?" +
          SimpleWeb::QueryString::create(Args2Headers({  })), 
          json(survey).dump(),
          Args2Headers({
            {"content-type", "application/json"},
            {"Authorization", _client.auth},  }))
      };
    } catch(const SimpleWeb::system_error &e) {
      return Result<void> { Error { to_string(e.code().value()), -1, e.code().message() } };
    }
  }
  inline void PostLolPftV2Survey(LeagueClient& _client, const LolPftPFTSurvey& survey, std::function<void(LeagueClient&,const Result<void>&)> cb)
  {
    _client.httpsa.request("post", "/lol-pft/v2/survey?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
          json(survey).dump(),
          Args2Headers({
            {"content-type", "application/json"},
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
          if(!e)
            cb(_client, Result<void> { response });
          else
            cb(_client,Result<void> { Error { to_string(e.value()), -1, e.message() } });
        });
  }
}