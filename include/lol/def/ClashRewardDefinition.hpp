#pragma once
#include "../base_def.hpp" 
#include "ClashRewardSpec.hpp"
#include "ClashRewardType.hpp"
namespace lol {
  struct ClashRewardDefinition { 
    ClashRewardSpec rewardSpec;
    ClashRewardType rewardType; 
  };
  inline void to_json(json& j, const ClashRewardDefinition& v) {
    j["rewardSpec"] = v.rewardSpec; 
    j["rewardType"] = v.rewardType; 
  }
  inline void from_json(const json& j, ClashRewardDefinition& v) {
    v.rewardSpec = j.at("rewardSpec").get<ClashRewardSpec>(); 
    v.rewardType = j.at("rewardType").get<ClashRewardType>(); 
  }
}