#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/LolLoginLoginSessionWallet.hpp"
namespace lol {
  inline Result<LolLoginLoginSessionWallet> GetLolLoginV1Wallet(LeagueClient& _client)
  {
    try {
      return Result<LolLoginLoginSessionWallet> {
        _client.https.request("get", "/lol-login/v1/wallet?" +
          SimpleWeb::QueryString::create(Args2Headers({  })), 
          "",
          Args2Headers({  
            {"Authorization", _client.auth},  }))
      };
    } catch(const SimpleWeb::system_error &e) {
      return Result<LolLoginLoginSessionWallet> { Error { to_string(e.code().value()), -1, e.code().message() } };
    }
  }
  inline void GetLolLoginV1Wallet(LeagueClient& _client, std::function<void(LeagueClient&,const Result<LolLoginLoginSessionWallet>&)> cb)
  {
    _client.httpsa.request("get", "/lol-login/v1/wallet?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
          "",
          Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
          if(!e)
            cb(_client, Result<LolLoginLoginSessionWallet> { response });
          else
            cb(_client,Result<LolLoginLoginSessionWallet> { Error { to_string(e.value()), -1, e.message() } });
        });
  }
}