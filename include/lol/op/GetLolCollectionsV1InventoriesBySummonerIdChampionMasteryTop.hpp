#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/LolCollectionsCollectionsTopChampionMasteries.hpp"
namespace lol {
  template<typename T>
  inline Result<LolCollectionsCollectionsTopChampionMasteries> GetLolCollectionsV1InventoriesBySummonerIdChampionMasteryTop(T& _client, const uint64_t& summonerId, const uint64_t& limit, const std::optional<std::string>& sortRule = std::nullopt)
  {
    try {
      return ToResult<LolCollectionsCollectionsTopChampionMasteries>(_client.https.request("get", "/lol-collections/v1/inventories/"+to_string(summonerId)+"/champion-mastery/top?" +
        SimpleWeb::QueryString::create(Args2Headers({ 
          { "limit", to_string(limit) },
          { "sortRule", to_string(sortRule) }, })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  })));
    } catch(const SimpleWeb::system_error &e) {
      return ToResult<LolCollectionsCollectionsTopChampionMasteries>(e.code());
    }
  }
  template<typename T>
  inline void GetLolCollectionsV1InventoriesBySummonerIdChampionMasteryTop(T& _client, const uint64_t& summonerId, const uint64_t& limit, const std::optional<std::string>& sortRule = std::nullopt, std::function<void(T&, const Result<LolCollectionsCollectionsTopChampionMasteries>&)> cb)
  {
    _client.httpsa.request("get", "/lol-collections/v1/inventories/"+to_string(summonerId)+"/champion-mastery/top?" +
      SimpleWeb::QueryString::create(Args2Headers({ 
          { "limit", to_string(limit) },
          { "sortRule", to_string(sortRule) }, })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
            if(e)
              cb(_client, ToResult<LolCollectionsCollectionsTopChampionMasteries>(e));
            else
              cb(_client, ToResult<LolCollectionsCollectionsTopChampionMasteries>(response));
        });
  }
}