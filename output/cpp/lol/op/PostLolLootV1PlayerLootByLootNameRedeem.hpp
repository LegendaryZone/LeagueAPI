#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/LolLootPlayerLootUpdate.hpp"
namespace lol {
  inline Result<LolLootPlayerLootUpdate> PostLolLootV1PlayerLootByLootNameRedeem(LeagueClient& _client, const std::string& lootName)
  {
    try {
      return Result<LolLootPlayerLootUpdate> {
        _client.https.request("post", "/lol-loot/v1/player-loot/"+to_string(lootName)+"/redeem?" +
          SimpleWeb::QueryString::create(Args2Headers({  })), 
          "",
          Args2Headers({  
            {"Authorization", _client.auth},  }))
      };
    } catch(const SimpleWeb::system_error &e) {
      return Result<LolLootPlayerLootUpdate> { Error { to_string(e.code().value()), -1, e.code().message() } };
    }
  }
  inline void PostLolLootV1PlayerLootByLootNameRedeem(LeagueClient& _client, const std::string& lootName, std::function<void(LeagueClient&,const Result<LolLootPlayerLootUpdate>&)> cb)
  {
    _client.httpsa.request("post", "/lol-loot/v1/player-loot/"+to_string(lootName)+"/redeem?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
          "",
          Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
          if(!e)
            cb(_client, Result<LolLootPlayerLootUpdate> { response });
          else
            cb(_client,Result<LolLootPlayerLootUpdate> { Error { to_string(e.value()), -1, e.message() } });
        });
  }
}