#pragma once
#include<lol/base_def.hpp> 
#include <lol/def/ClubDto.hpp>
#include <lol/def/PlayerInfoDto.hpp>
#include <lol/def/ClubReferenceDto.hpp>
#include <lol/def/ClubsServerConfigDto.hpp>
#include <lol/def/PlayerMembershipPreferencesDto.hpp>
#include <lol/def/MembershipInviteDto.hpp>
namespace lol {
  struct PlayerMembershipDto { 
    ClubsServerConfigDto clubsServerConfig;
    PlayerMembershipPreferencesDto playerClubPreferences;
    PlayerInfoDto player;
    std::vector<ClubDto> activeClubs;
    std::string secureClubPresenceInfoString;
    std::string resourceUri;
    std::vector<ClubReferenceDto> removedClubs;
    std::vector<MembershipInviteDto> pendingInvites;
    std::vector<ClubReferenceDto> revokedInviteClubs; 
  };
  void to_json(json& j, const PlayerMembershipDto& v) {
  j["clubsServerConfig"] = v.clubsServerConfig; 
  j["playerClubPreferences"] = v.playerClubPreferences; 
  j["player"] = v.player; 
  j["activeClubs"] = v.activeClubs; 
  j["secureClubPresenceInfoString"] = v.secureClubPresenceInfoString; 
  j["resourceUri"] = v.resourceUri; 
  j["removedClubs"] = v.removedClubs; 
  j["pendingInvites"] = v.pendingInvites; 
  j["revokedInviteClubs"] = v.revokedInviteClubs; 
  }
  void from_json(const json& j, PlayerMembershipDto& v) {
  v.clubsServerConfig = j.at("clubsServerConfig").get<ClubsServerConfigDto>(); 
  v.playerClubPreferences = j.at("playerClubPreferences").get<PlayerMembershipPreferencesDto>(); 
  v.player = j.at("player").get<PlayerInfoDto>(); 
  v.activeClubs = j.at("activeClubs").get<std::vector<ClubDto>>(); 
  v.secureClubPresenceInfoString = j.at("secureClubPresenceInfoString").get<std::string>(); 
  v.resourceUri = j.at("resourceUri").get<std::string>(); 
  v.removedClubs = j.at("removedClubs").get<std::vector<ClubReferenceDto>>(); 
  v.pendingInvites = j.at("pendingInvites").get<std::vector<MembershipInviteDto>>(); 
  v.revokedInviteClubs = j.at("revokedInviteClubs").get<std::vector<ClubReferenceDto>>(); 
  }
}