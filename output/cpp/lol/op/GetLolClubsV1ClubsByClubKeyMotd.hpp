#pragma once
#include<lol/base_op.hpp> 
namespace lol {
  Result<std::string> GetLolClubsV1ClubsByClubKeyMotd(const LeagueClient& _client, const std::string& clubKey)
  {
    HttpsClient _client_(_client.host, false);
    return _client_.request("get", "/lol-clubs/v1/clubs/"+to_string(clubKey)+"/motd?" + SimpleWeb::QueryString::create(Args2Headers({  })), "",
      Args2Headers({ {"Authorization", _client.auth},  }) );
  }
}