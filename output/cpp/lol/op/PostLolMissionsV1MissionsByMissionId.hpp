#pragma once
#include<lol/base_op.hpp> 
namespace lol {
  Result<void> PostLolMissionsV1MissionsByMissionId(const LeagueClient& _client, const std::string& missionId)
  {
    HttpsClient _client_(_client.host, false);
    return _client_.request("post", "/lol-missions/v1/missions/"+to_string(missionId)+"?" + SimpleWeb::QueryString::create(Args2Headers({  })), "",
      Args2Headers({ {"Authorization", _client.auth},  }) );
  }
}