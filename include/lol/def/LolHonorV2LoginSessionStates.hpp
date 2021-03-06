#pragma once
#include "../base_def.hpp" 
namespace lol {
  enum struct LolHonorV2LoginSessionStates {  
    ERROR_e = 3,
    IN_PROGRESS_e = 0,
    LOGGING_OUT_e = 2,
    SUCCEEDED_e = 1,
  };
  inline void to_json(json& j, const LolHonorV2LoginSessionStates& v) {
    if(v == LolHonorV2LoginSessionStates::ERROR_e) {
      j = "ERROR";
      return;
    }
    if(v == LolHonorV2LoginSessionStates::IN_PROGRESS_e) {
      j = "IN_PROGRESS";
      return;
    }
    if(v == LolHonorV2LoginSessionStates::LOGGING_OUT_e) {
      j = "LOGGING_OUT";
      return;
    }
    if(v == LolHonorV2LoginSessionStates::SUCCEEDED_e) {
      j = "SUCCEEDED";
      return;
    }
  }
  inline void from_json(const json& j, LolHonorV2LoginSessionStates& v) {
    if(j.get<std::string>() == "ERROR") {
      v = LolHonorV2LoginSessionStates::ERROR_e;
      return;
    } 
    if(j.get<std::string>() == "IN_PROGRESS") {
      v = LolHonorV2LoginSessionStates::IN_PROGRESS_e;
      return;
    } 
    if(j.get<std::string>() == "LOGGING_OUT") {
      v = LolHonorV2LoginSessionStates::LOGGING_OUT_e;
      return;
    } 
    if(j.get<std::string>() == "SUCCEEDED") {
      v = LolHonorV2LoginSessionStates::SUCCEEDED_e;
      return;
    } 
  }
}