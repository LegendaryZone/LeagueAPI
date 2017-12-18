#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/TencentQTNotification.hpp"
namespace lol {
  inline Result<TencentQTNotification> GetLolTencentQtV1UiStatesByFeature(LeagueClient& _client, const std::string& feature)
  {
    try {
      return Result<TencentQTNotification> {
        _client.https.request("get", "/lol-tencent-qt/v1/ui-states/"+to_string(feature)+"?" +
          SimpleWeb::QueryString::create(Args2Headers({  })), 
          "",
          Args2Headers({  
            {"Authorization", _client.auth},  }))
      };
    } catch(const SimpleWeb::system_error &e) {
      return Result<TencentQTNotification> { Error { to_string(e.code().value()), -1, e.code().message() } };
    }
  }
  inline void GetLolTencentQtV1UiStatesByFeature(LeagueClient& _client, const std::string& feature, std::function<void(LeagueClient&,const Result<TencentQTNotification>&)> cb)
  {
    _client.httpsa.request("get", "/lol-tencent-qt/v1/ui-states/"+to_string(feature)+"?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
          "",
          Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
          if(!e)
            cb(_client, Result<TencentQTNotification> { response });
          else
            cb(_client,Result<TencentQTNotification> { Error { to_string(e.value()), -1, e.message() } });
        });
  }
}