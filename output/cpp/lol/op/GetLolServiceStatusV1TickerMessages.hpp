#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/TickerMessage.hpp"
namespace lol {
  inline Result<std::vector<TickerMessage>> GetLolServiceStatusV1TickerMessages(LeagueClient& _client)
  {
    try {
      return Result<std::vector<TickerMessage>> {
        _client.https.request("get", "/lol-service-status/v1/ticker-messages?" +
          SimpleWeb::QueryString::create(Args2Headers({  })), 
          "",
          Args2Headers({  
            {"Authorization", _client.auth},  }))
      };
    } catch(const SimpleWeb::system_error &e) {
      return Result<std::vector<TickerMessage>> { Error { to_string(e.code().value()), -1, e.code().message() } };
    }
  }
  inline void GetLolServiceStatusV1TickerMessages(LeagueClient& _client, std::function<void(LeagueClient&,const Result<std::vector<TickerMessage>>&)> cb)
  {
    _client.httpsa.request("get", "/lol-service-status/v1/ticker-messages?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
          "",
          Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
          if(!e)
            cb(_client, Result<std::vector<TickerMessage>> { response });
          else
            cb(_client,Result<std::vector<TickerMessage>> { Error { to_string(e.value()), -1, e.message() } });
        });
  }
}