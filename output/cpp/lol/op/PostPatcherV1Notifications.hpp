#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/PatcherNotificationId.hpp"
namespace lol {
  inline Result<void> PostPatcherV1Notifications(LeagueClient& _client, const PatcherNotificationId& notificationId)
  {
    try {
      return Result<void> {
        _client.https.request("post", "/patcher/v1/notifications?" +
          SimpleWeb::QueryString::create(Args2Headers({ 
           { "notificationId", to_string(notificationId) }, })), 
          "",
          Args2Headers({  
            {"Authorization", _client.auth},  }))
      };
    } catch(const SimpleWeb::system_error &e) {
      return Result<void> { Error { to_string(e.code().value()), -1, e.code().message() } };
    }
  }
  inline void PostPatcherV1Notifications(LeagueClient& _client, const PatcherNotificationId& notificationId, std::function<void(LeagueClient&,const Result<void>&)> cb)
  {
    _client.httpsa.request("post", "/patcher/v1/notifications?" +
      SimpleWeb::QueryString::create(Args2Headers({ 
           { "notificationId", to_string(notificationId) }, })), 
          "",
          Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
          if(!e)
            cb(_client, Result<void> { response });
          else
            cb(_client,Result<void> { Error { to_string(e.value()), -1, e.message() } });
        });
  }
}