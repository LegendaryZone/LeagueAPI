#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/LolReplaysReplayMetadata.hpp"
namespace lol {
  inline Result<LolReplaysReplayMetadata> GetLolReplaysV1MetadataByGameId(LeagueClient& _client, const uint64_t& gameId)
  {
    try {
      return Result<LolReplaysReplayMetadata> {
        _client.https.request("get", "/lol-replays/v1/metadata/"+to_string(gameId)+"?" +
          SimpleWeb::QueryString::create(Args2Headers({  })), 
          "",
          Args2Headers({  
            {"Authorization", _client.auth},  }))
      };
    } catch(const SimpleWeb::system_error &e) {
      return Result<LolReplaysReplayMetadata> { Error { to_string(e.code().value()), -1, e.code().message() } };
    }
  }
  inline void GetLolReplaysV1MetadataByGameId(LeagueClient& _client, const uint64_t& gameId, std::function<void(LeagueClient&,const Result<LolReplaysReplayMetadata>&)> cb)
  {
    _client.httpsa.request("get", "/lol-replays/v1/metadata/"+to_string(gameId)+"?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
          "",
          Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
          if(!e)
            cb(_client, Result<LolReplaysReplayMetadata> { response });
          else
            cb(_client,Result<LolReplaysReplayMetadata> { Error { to_string(e.value()), -1, e.message() } });
        });
  }
}