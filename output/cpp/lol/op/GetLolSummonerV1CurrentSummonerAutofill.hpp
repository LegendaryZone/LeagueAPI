#pragma once
#include<lol/base_op.hpp> 
#include <lol/def/LolSummonerAutoFillDto.hpp>
namespace lol {
  Result<LolSummonerAutoFillDto> GetLolSummonerV1CurrentSummonerAutofill(const LeagueClient& _client)
  {
    HttpsClient _client_(_client.host, false);
    return _client_.request("get", "/lol-summoner/v1/current-summoner/autofill?" + SimpleWeb::QueryString::create(Args2Headers({  })), "",
      Args2Headers({ {"Authorization", _client.auth},  }) );
  }
}