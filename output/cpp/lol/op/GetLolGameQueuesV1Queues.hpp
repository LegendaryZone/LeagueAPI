#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/LolGameQueuesQueue.hpp"
namespace lol {
  inline Result<std::vector<LolGameQueuesQueue>> GetLolGameQueuesV1Queues(LeagueClient& _client)
  {
    try {
      return Result<std::vector<LolGameQueuesQueue>> {
        _client.https.request("get", "/lol-game-queues/v1/queues?" +
          SimpleWeb::QueryString::create(Args2Headers({  })), 
          "",
          Args2Headers({  
            {"Authorization", _client.auth},  }))
      };
    } catch(const SimpleWeb::system_error &e) {
      return Result<std::vector<LolGameQueuesQueue>> { Error { to_string(e.code().value()), -1, e.code().message() } };
    }
  }
  inline void GetLolGameQueuesV1Queues(LeagueClient& _client, std::function<void(LeagueClient&,const Result<std::vector<LolGameQueuesQueue>>&)> cb)
  {
    _client.httpsa.request("get", "/lol-game-queues/v1/queues?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
          "",
          Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
          if(!e)
            cb(_client, Result<std::vector<LolGameQueuesQueue>> { response });
          else
            cb(_client,Result<std::vector<LolGameQueuesQueue>> { Error { to_string(e.value()), -1, e.message() } });
        });
  }
}