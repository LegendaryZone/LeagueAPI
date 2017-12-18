#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/ClubMember.hpp"
namespace lol {
  inline Result<std::vector<ClubMember>> GetLolClubsV1ClubsByClubKeyMembers(LeagueClient& _client, const std::string& clubKey)
  {
    try {
      return Result<std::vector<ClubMember>> {
        _client.https.request("get", "/lol-clubs/v1/clubs/"+to_string(clubKey)+"/members?" +
          SimpleWeb::QueryString::create(Args2Headers({  })), 
          "",
          Args2Headers({  
            {"Authorization", _client.auth},  }))
      };
    } catch(const SimpleWeb::system_error &e) {
      return Result<std::vector<ClubMember>> { Error { to_string(e.code().value()), -1, e.code().message() } };
    }
  }
  inline void GetLolClubsV1ClubsByClubKeyMembers(LeagueClient& _client, const std::string& clubKey, std::function<void(LeagueClient&,const Result<std::vector<ClubMember>>&)> cb)
  {
    _client.httpsa.request("get", "/lol-clubs/v1/clubs/"+to_string(clubKey)+"/members?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
          "",
          Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
          if(!e)
            cb(_client, Result<std::vector<ClubMember>> { response });
          else
            cb(_client,Result<std::vector<ClubMember>> { Error { to_string(e.value()), -1, e.message() } });
        });
  }
}