#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/LolStoreOrderNotificationResource.hpp"
namespace lol {
  inline Result<std::vector<LolStoreOrderNotificationResource>> GetLolStoreV1OrderNotifications(LeagueClient& _client)
  {
    try {
      return Result<std::vector<LolStoreOrderNotificationResource>> {
        _client.https.request("get", "/lol-store/v1/order-notifications?" +
          SimpleWeb::QueryString::create(Args2Headers({  })), 
          "",
          Args2Headers({  
            {"Authorization", _client.auth},  }))
      };
    } catch(const SimpleWeb::system_error &e) {
      return Result<std::vector<LolStoreOrderNotificationResource>> { Error { to_string(e.code().value()), -1, e.code().message() } };
    }
  }
  inline void GetLolStoreV1OrderNotifications(LeagueClient& _client, std::function<void(LeagueClient&,const Result<std::vector<LolStoreOrderNotificationResource>>&)> cb)
  {
    _client.httpsa.request("get", "/lol-store/v1/order-notifications?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
          "",
          Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
          if(!e)
            cb(_client, Result<std::vector<LolStoreOrderNotificationResource>> { response });
          else
            cb(_client,Result<std::vector<LolStoreOrderNotificationResource>> { Error { to_string(e.value()), -1, e.message() } });
        });
  }
}