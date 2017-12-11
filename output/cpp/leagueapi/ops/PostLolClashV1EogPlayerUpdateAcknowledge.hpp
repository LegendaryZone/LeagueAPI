#pragma once
#include <leagueapi/https.hpp>

namespace leagueapi::op {
  /**/
  static https::Result<json> PostLolClashV1EogPlayerUpdateAcknowledge (const https::Info& _info_ )
  { 
    return { https::Do(_info_, "post", "/lol-clash/v1/eogPlayerUpdate/acknowledge?", { 
    }, { 
    }) };
  }
} 