#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/LolPurchaseWidgetPurchaseWidgetConfig.hpp"
namespace lol {
  inline Result<LolPurchaseWidgetPurchaseWidgetConfig> GetLolPurchaseWidgetV1Configuration(LeagueClient& _client)
  {
    try {
      return ToResult<LolPurchaseWidgetPurchaseWidgetConfig>(_client.https.request("get", "/lol-purchase-widget/v1/configuration?" +
        SimpleWeb::QueryString::create(Args2Headers({  })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  })));
    } catch(const SimpleWeb::system_error &e) {
      return ToResult<LolPurchaseWidgetPurchaseWidgetConfig>(e.code());
    }
  }
  inline void GetLolPurchaseWidgetV1Configuration(LeagueClient& _client, std::function<void(LeagueClient&, const Result<LolPurchaseWidgetPurchaseWidgetConfig>&)> cb)
  {
    _client.httpsa.request("get", "/lol-purchase-widget/v1/configuration?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
            if(e)
              cb(_client, ToResult<LolPurchaseWidgetPurchaseWidgetConfig>(e));
            else
              cb(_client, ToResult<LolPurchaseWidgetPurchaseWidgetConfig>(response));
        });
  }
}