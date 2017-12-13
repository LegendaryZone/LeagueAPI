#pragma once
#include<lol/base_op.hpp> 
#include <lol/def/LolStoreCatalogItem.hpp>
namespace lol {
  Result<LolStoreCatalogItem> GetLolStoreV1SkinsBySkinId(const LeagueClient& _client, const int32_t& skinId)
  {
    HttpsClient _client_(_client.host, false);
    return _client_.request("get", "/lol-store/v1/skins/"+to_string(skinId)+"?" + SimpleWeb::QueryString::create(Args2Headers({  })), "",
      Args2Headers({ {"Authorization", _client.auth},  }) );
  }
}