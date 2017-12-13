#pragma once
#include<lol/base_op.hpp> 
namespace lol {
  Result<json> PostLolHighlightsV1FileBrowserByHighlightId(const LeagueClient& _client, const uint64_t& highlightId)
  {
    HttpsClient _client_(_client.host, false);
    return _client_.request("post", "/lol-highlights/v1/file-browser/"+to_string(highlightId)+"?" + SimpleWeb::QueryString::create(Args2Headers({  })), "",
      Args2Headers({ {"Authorization", _client.auth},  }) );
  }
}