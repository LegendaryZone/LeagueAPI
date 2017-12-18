#pragma once
#include "../base_op.hpp"
#include <functional> 
namespace lol {
  inline Result<std::vector<uint64_t>> GetLolEndOfGameV1ReportedPlayers(LeagueClient& _client)
  {
    try {
      return Result<std::vector<uint64_t>> {
        _client.https.request("get", "/lol-end-of-game/v1/reported-players?" +
          SimpleWeb::QueryString::create(Args2Headers({  })), 
          "",
          Args2Headers({  
            {"Authorization", _client.auth},  }))
      };
    } catch(const SimpleWeb::system_error &e) {
      return Result<std::vector<uint64_t>> { Error { to_string(e.code().value()), -1, e.code().message() } };
    }
  }
  inline void GetLolEndOfGameV1ReportedPlayers(LeagueClient& _client, std::function<void(LeagueClient&,const Result<std::vector<uint64_t>>&)> cb)
  {
    _client.httpsa.request("get", "/lol-end-of-game/v1/reported-players?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
          "",
          Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
          if(!e)
            cb(_client, Result<std::vector<uint64_t>> { response });
          else
            cb(_client,Result<std::vector<uint64_t>> { Error { to_string(e.value()), -1, e.message() } });
        });
  }
}