#pragma once
#include<lol/base_op.hpp> 
#include <lol/def/LolStoreCatalogItem.hpp>
namespace lol {
  Result<std::vector<LolStoreCatalogItem>> GetLolStoreV1Catalog(const LeagueClient& _client, const std::optional<std::vector<std::string>>& inventoryType = std::nullopt, const std::optional<std::vector<int32_t>>& itemId = std::nullopt)
  {
    HttpsClient _client_(_client.host, false);
    return _client_.request("get", "/lol-store/v1/catalog?" + SimpleWeb::QueryString::create(Args2Headers({ { "inventoryType", to_string(inventoryType) },
    { "itemId", to_string(itemId) } })), "",
      Args2Headers({ {"Authorization", _client.auth},  }) );
  }
}