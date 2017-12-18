#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/LolStoreCatalogItem.hpp"
namespace lol {
  inline Result<LolStoreCatalogItem> GetLolStoreV1SkinsBySkinId(LeagueClient& _client, const int32_t& skinId)
  {
    try {
      return Result<LolStoreCatalogItem> {
        _client.https.request("get", "/lol-store/v1/skins/"+to_string(skinId)+"?" +
          SimpleWeb::QueryString::create(Args2Headers({  })), 
          "",
          Args2Headers({  
            {"Authorization", _client.auth},  }))
      };
    } catch(const SimpleWeb::system_error &e) {
      return Result<LolStoreCatalogItem> { Error { to_string(e.code().value()), -1, e.code().message() } };
    }
  }
  inline void GetLolStoreV1SkinsBySkinId(LeagueClient& _client, const int32_t& skinId, std::function<void(LeagueClient&,const Result<LolStoreCatalogItem>&)> cb)
  {
    _client.httpsa.request("get", "/lol-store/v1/skins/"+to_string(skinId)+"?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
          "",
          Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
          if(!e)
            cb(_client, Result<LolStoreCatalogItem> { response });
          else
            cb(_client,Result<LolStoreCatalogItem> { Error { to_string(e.value()), -1, e.message() } });
        });
  }
}