#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/PlayerClubMembership.hpp"
#include "../def/ClubInvite.hpp"
namespace lol {
  inline Result<PlayerClubMembership> PatchLolClubsV1ClubsInvitations(LeagueClient& _client, const ClubInvite& invitation)
  {
    try {
      return Result<PlayerClubMembership> {
        _client.https.request("patch", "/lol-clubs/v1/clubs/invitations?" +
          SimpleWeb::QueryString::create(Args2Headers({  })), 
          json(invitation).dump(),
          Args2Headers({
            {"content-type", "application/json"},
            {"Authorization", _client.auth},  }))
      };
    } catch(const SimpleWeb::system_error &e) {
      return Result<PlayerClubMembership> { Error { to_string(e.code().value()), -1, e.code().message() } };
    }
  }
  inline void PatchLolClubsV1ClubsInvitations(LeagueClient& _client, const ClubInvite& invitation, std::function<void(LeagueClient&,const Result<PlayerClubMembership>&)> cb)
  {
    _client.httpsa.request("patch", "/lol-clubs/v1/clubs/invitations?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
          json(invitation).dump(),
          Args2Headers({
            {"content-type", "application/json"},
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
          if(!e)
            cb(_client, Result<PlayerClubMembership> { response });
          else
            cb(_client,Result<PlayerClubMembership> { Error { to_string(e.value()), -1, e.message() } });
        });
  }
}