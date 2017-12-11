#pragma once
#include <leagueapi/base.hpp>

namespace leagueapi {
  struct ClubsServerConfigDto { /**/ 
    int32_t minClubNameLength;/**/
    bool clubNominationsEnabled;/**/
    int32_t clubMotdMaxLength;/**/
    int32_t clubNominationsMaxPending;/**/
    int32_t maxClubNameLength;/**/
    int32_t maxClubTagLength;/**/
    int32_t clubDescriptionMaxLength;/**/
    int32_t clubTagRequirementsMinMemberLevel;/**/
    int32_t minClubTagLength;/**/
    int32_t maxActiveClubs;/**/
    int32_t clubTagRequirementMinMembers;/**/
    int32_t clubTagRequirementMinGames;/**/
  };
  static void to_json(json& j, const ClubsServerConfigDto& v) { 
    j["minClubNameLength"] = v.minClubNameLength;
    j["clubNominationsEnabled"] = v.clubNominationsEnabled;
    j["clubMotdMaxLength"] = v.clubMotdMaxLength;
    j["clubNominationsMaxPending"] = v.clubNominationsMaxPending;
    j["maxClubNameLength"] = v.maxClubNameLength;
    j["maxClubTagLength"] = v.maxClubTagLength;
    j["clubDescriptionMaxLength"] = v.clubDescriptionMaxLength;
    j["clubTagRequirementsMinMemberLevel"] = v.clubTagRequirementsMinMemberLevel;
    j["minClubTagLength"] = v.minClubTagLength;
    j["maxActiveClubs"] = v.maxActiveClubs;
    j["clubTagRequirementMinMembers"] = v.clubTagRequirementMinMembers;
    j["clubTagRequirementMinGames"] = v.clubTagRequirementMinGames;
  }
  static void from_json(const json& j, ClubsServerConfigDto& v) { 
    v.minClubNameLength = j.at("minClubNameLength").get<int32_t>(); 
    v.clubNominationsEnabled = j.at("clubNominationsEnabled").get<bool>(); 
    v.clubMotdMaxLength = j.at("clubMotdMaxLength").get<int32_t>(); 
    v.clubNominationsMaxPending = j.at("clubNominationsMaxPending").get<int32_t>(); 
    v.maxClubNameLength = j.at("maxClubNameLength").get<int32_t>(); 
    v.maxClubTagLength = j.at("maxClubTagLength").get<int32_t>(); 
    v.clubDescriptionMaxLength = j.at("clubDescriptionMaxLength").get<int32_t>(); 
    v.clubTagRequirementsMinMemberLevel = j.at("clubTagRequirementsMinMemberLevel").get<int32_t>(); 
    v.minClubTagLength = j.at("minClubTagLength").get<int32_t>(); 
    v.maxActiveClubs = j.at("maxActiveClubs").get<int32_t>(); 
    v.clubTagRequirementMinMembers = j.at("clubTagRequirementMinMembers").get<int32_t>(); 
    v.clubTagRequirementMinGames = j.at("clubTagRequirementMinGames").get<int32_t>(); 
  }
} 