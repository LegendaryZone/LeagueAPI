#pragma once
#include "../base_op.hpp"
#include <functional> 
#include "../def/SeriesDTO.hpp"
namespace lol {
  template<typename T>
  inline Result<std::vector<SeriesDTO>> GetLolMissionsV1Series(T& _client)
  {
    try {
      return ToResult<std::vector<SeriesDTO>>(_client.https.request("get", "/lol-missions/v1/series?" +
        SimpleWeb::QueryString::create(Args2Headers({  })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  })));
    } catch(const SimpleWeb::system_error &e) {
      return ToResult<std::vector<SeriesDTO>>(e.code());
    }
  }
  template<typename T>
  inline void GetLolMissionsV1Series(T& _client, std::function<void(T&, const Result<std::vector<SeriesDTO>>&)> cb)
  {
    _client.httpsa.request("get", "/lol-missions/v1/series?" +
      SimpleWeb::QueryString::create(Args2Headers({  })), 
        "",
        Args2Headers({  
        {"Authorization", _client.auth},  }),[cb,&_client](std::shared_ptr<HttpsClient::Response> response, const SimpleWeb::error_code &e) {
            if(e)
              cb(_client, ToResult<std::vector<SeriesDTO>>(e));
            else
              cb(_client, ToResult<std::vector<SeriesDTO>>(response));
        });
  }
}