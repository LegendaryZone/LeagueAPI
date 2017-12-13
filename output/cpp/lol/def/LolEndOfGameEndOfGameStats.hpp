#pragma once
#include<lol/base_def.hpp> 
#include <lol/def/LolEndOfGameEndOfGameTeamBoost.hpp>
#include <lol/def/LolEndOfGameEndOfGameTeam.hpp>
#include <lol/def/LolEndOfGameEndOfGamePoints.hpp>
namespace lol {
  struct LolEndOfGameEndOfGameStats { 
    std::string roomName;
    int32_t missionsXpEarned;
    int32_t skinId;
    int32_t elo;
    bool ranked;
    int32_t loyaltyBoostIpEarned;
    bool imbalancedTeamsNoPoints;
    std::string gameMode;
    int32_t experienceEarned;
    int32_t timeUntilNextFirstWinBonus;
    int32_t battleBoostIpEarned;
    std::string summonerName;
    int32_t rpEarned;
    bool teamEarlySurrendered;
    int32_t ipEarned;
    std::vector<int32_t> newSpells;
    uint64_t accountId;
    int32_t coOpVsAiMinutesLeftToday;
    int32_t loyaltyBoostXpEarned;
    int32_t globalBoostXpEarned;
    bool earlySurrenderAccomplice;
    int32_t customMinutesLeftToday;
    int32_t talentPointsGained;
    std::string roomPassword;
    int32_t basePoints;
    uint64_t gameId;
    LolEndOfGameEndOfGamePoints rerollData;
    uint64_t previousLevel;
    uint64_t currentLevel;
    bool invalid;
    std::string queueType;
    json pointsPenalties;
    std::string gameType;
    uint64_t summonerId;
    std::optional<LolEndOfGameEndOfGameTeamBoost> teamBoost;
    uint64_t previousXpTotal;
    int32_t queueBonusEarned;
    std::string myTeamStatus;
    uint64_t reportGameId;
    uint64_t userId;
    std::vector<std::string> gameMutators;
    bool sendStatsToTournamentProvider;
    bool gameEndedInEarlySurrender;
    int32_t boostIpEarned;
    int32_t experienceTotal;
    int32_t ipTotal;
    int32_t championId;
    bool leveledUp;
    std::string difficulty;
    int32_t eloChange;
    int32_t completionBonusPoints;
    std::vector<LolEndOfGameEndOfGameTeam> teams;
    int32_t coOpVsAiMsecsUntilReset;
    int32_t skinIndex;
    int32_t odinBonusIp;
    int32_t boostXpEarned;
    uint64_t nextLevelXp;
    bool causedEarlySurrender;
    int32_t partyRewardsBonusIpEarned;
    int32_t firstWinBonus;
    int32_t customMsecsUntilReset;
    int32_t gameLength; 
  };
  void to_json(json& j, const LolEndOfGameEndOfGameStats& v) {
  j["roomName"] = v.roomName; 
  j["missionsXpEarned"] = v.missionsXpEarned; 
  j["skinId"] = v.skinId; 
  j["elo"] = v.elo; 
  j["ranked"] = v.ranked; 
  j["loyaltyBoostIpEarned"] = v.loyaltyBoostIpEarned; 
  j["imbalancedTeamsNoPoints"] = v.imbalancedTeamsNoPoints; 
  j["gameMode"] = v.gameMode; 
  j["experienceEarned"] = v.experienceEarned; 
  j["timeUntilNextFirstWinBonus"] = v.timeUntilNextFirstWinBonus; 
  j["battleBoostIpEarned"] = v.battleBoostIpEarned; 
  j["summonerName"] = v.summonerName; 
  j["rpEarned"] = v.rpEarned; 
  j["teamEarlySurrendered"] = v.teamEarlySurrendered; 
  j["ipEarned"] = v.ipEarned; 
  j["newSpells"] = v.newSpells; 
  j["accountId"] = v.accountId; 
  j["coOpVsAiMinutesLeftToday"] = v.coOpVsAiMinutesLeftToday; 
  j["loyaltyBoostXpEarned"] = v.loyaltyBoostXpEarned; 
  j["globalBoostXpEarned"] = v.globalBoostXpEarned; 
  j["earlySurrenderAccomplice"] = v.earlySurrenderAccomplice; 
  j["customMinutesLeftToday"] = v.customMinutesLeftToday; 
  j["talentPointsGained"] = v.talentPointsGained; 
  j["roomPassword"] = v.roomPassword; 
  j["basePoints"] = v.basePoints; 
  j["gameId"] = v.gameId; 
  j["rerollData"] = v.rerollData; 
  j["previousLevel"] = v.previousLevel; 
  j["currentLevel"] = v.currentLevel; 
  j["invalid"] = v.invalid; 
  j["queueType"] = v.queueType; 
  j["pointsPenalties"] = v.pointsPenalties; 
  j["gameType"] = v.gameType; 
  j["summonerId"] = v.summonerId; 
  j["teamBoost"] = v.teamBoost; 
  j["previousXpTotal"] = v.previousXpTotal; 
  j["queueBonusEarned"] = v.queueBonusEarned; 
  j["myTeamStatus"] = v.myTeamStatus; 
  j["reportGameId"] = v.reportGameId; 
  j["userId"] = v.userId; 
  j["gameMutators"] = v.gameMutators; 
  j["sendStatsToTournamentProvider"] = v.sendStatsToTournamentProvider; 
  j["gameEndedInEarlySurrender"] = v.gameEndedInEarlySurrender; 
  j["boostIpEarned"] = v.boostIpEarned; 
  j["experienceTotal"] = v.experienceTotal; 
  j["ipTotal"] = v.ipTotal; 
  j["championId"] = v.championId; 
  j["leveledUp"] = v.leveledUp; 
  j["difficulty"] = v.difficulty; 
  j["eloChange"] = v.eloChange; 
  j["completionBonusPoints"] = v.completionBonusPoints; 
  j["teams"] = v.teams; 
  j["coOpVsAiMsecsUntilReset"] = v.coOpVsAiMsecsUntilReset; 
  j["skinIndex"] = v.skinIndex; 
  j["odinBonusIp"] = v.odinBonusIp; 
  j["boostXpEarned"] = v.boostXpEarned; 
  j["nextLevelXp"] = v.nextLevelXp; 
  j["causedEarlySurrender"] = v.causedEarlySurrender; 
  j["partyRewardsBonusIpEarned"] = v.partyRewardsBonusIpEarned; 
  j["firstWinBonus"] = v.firstWinBonus; 
  j["customMsecsUntilReset"] = v.customMsecsUntilReset; 
  j["gameLength"] = v.gameLength; 
  }
  void from_json(const json& j, LolEndOfGameEndOfGameStats& v) {
  v.roomName = j.at("roomName").get<std::string>(); 
  v.missionsXpEarned = j.at("missionsXpEarned").get<int32_t>(); 
  v.skinId = j.at("skinId").get<int32_t>(); 
  v.elo = j.at("elo").get<int32_t>(); 
  v.ranked = j.at("ranked").get<bool>(); 
  v.loyaltyBoostIpEarned = j.at("loyaltyBoostIpEarned").get<int32_t>(); 
  v.imbalancedTeamsNoPoints = j.at("imbalancedTeamsNoPoints").get<bool>(); 
  v.gameMode = j.at("gameMode").get<std::string>(); 
  v.experienceEarned = j.at("experienceEarned").get<int32_t>(); 
  v.timeUntilNextFirstWinBonus = j.at("timeUntilNextFirstWinBonus").get<int32_t>(); 
  v.battleBoostIpEarned = j.at("battleBoostIpEarned").get<int32_t>(); 
  v.summonerName = j.at("summonerName").get<std::string>(); 
  v.rpEarned = j.at("rpEarned").get<int32_t>(); 
  v.teamEarlySurrendered = j.at("teamEarlySurrendered").get<bool>(); 
  v.ipEarned = j.at("ipEarned").get<int32_t>(); 
  v.newSpells = j.at("newSpells").get<std::vector<int32_t>>(); 
  v.accountId = j.at("accountId").get<uint64_t>(); 
  v.coOpVsAiMinutesLeftToday = j.at("coOpVsAiMinutesLeftToday").get<int32_t>(); 
  v.loyaltyBoostXpEarned = j.at("loyaltyBoostXpEarned").get<int32_t>(); 
  v.globalBoostXpEarned = j.at("globalBoostXpEarned").get<int32_t>(); 
  v.earlySurrenderAccomplice = j.at("earlySurrenderAccomplice").get<bool>(); 
  v.customMinutesLeftToday = j.at("customMinutesLeftToday").get<int32_t>(); 
  v.talentPointsGained = j.at("talentPointsGained").get<int32_t>(); 
  v.roomPassword = j.at("roomPassword").get<std::string>(); 
  v.basePoints = j.at("basePoints").get<int32_t>(); 
  v.gameId = j.at("gameId").get<uint64_t>(); 
  v.rerollData = j.at("rerollData").get<LolEndOfGameEndOfGamePoints>(); 
  v.previousLevel = j.at("previousLevel").get<uint64_t>(); 
  v.currentLevel = j.at("currentLevel").get<uint64_t>(); 
  v.invalid = j.at("invalid").get<bool>(); 
  v.queueType = j.at("queueType").get<std::string>(); 
  v.pointsPenalties = j.at("pointsPenalties").get<json>(); 
  v.gameType = j.at("gameType").get<std::string>(); 
  v.summonerId = j.at("summonerId").get<uint64_t>(); 
  v.teamBoost = j.at("teamBoost").get<std::optional<LolEndOfGameEndOfGameTeamBoost>>(); 
  v.previousXpTotal = j.at("previousXpTotal").get<uint64_t>(); 
  v.queueBonusEarned = j.at("queueBonusEarned").get<int32_t>(); 
  v.myTeamStatus = j.at("myTeamStatus").get<std::string>(); 
  v.reportGameId = j.at("reportGameId").get<uint64_t>(); 
  v.userId = j.at("userId").get<uint64_t>(); 
  v.gameMutators = j.at("gameMutators").get<std::vector<std::string>>(); 
  v.sendStatsToTournamentProvider = j.at("sendStatsToTournamentProvider").get<bool>(); 
  v.gameEndedInEarlySurrender = j.at("gameEndedInEarlySurrender").get<bool>(); 
  v.boostIpEarned = j.at("boostIpEarned").get<int32_t>(); 
  v.experienceTotal = j.at("experienceTotal").get<int32_t>(); 
  v.ipTotal = j.at("ipTotal").get<int32_t>(); 
  v.championId = j.at("championId").get<int32_t>(); 
  v.leveledUp = j.at("leveledUp").get<bool>(); 
  v.difficulty = j.at("difficulty").get<std::string>(); 
  v.eloChange = j.at("eloChange").get<int32_t>(); 
  v.completionBonusPoints = j.at("completionBonusPoints").get<int32_t>(); 
  v.teams = j.at("teams").get<std::vector<LolEndOfGameEndOfGameTeam>>(); 
  v.coOpVsAiMsecsUntilReset = j.at("coOpVsAiMsecsUntilReset").get<int32_t>(); 
  v.skinIndex = j.at("skinIndex").get<int32_t>(); 
  v.odinBonusIp = j.at("odinBonusIp").get<int32_t>(); 
  v.boostXpEarned = j.at("boostXpEarned").get<int32_t>(); 
  v.nextLevelXp = j.at("nextLevelXp").get<uint64_t>(); 
  v.causedEarlySurrender = j.at("causedEarlySurrender").get<bool>(); 
  v.partyRewardsBonusIpEarned = j.at("partyRewardsBonusIpEarned").get<int32_t>(); 
  v.firstWinBonus = j.at("firstWinBonus").get<int32_t>(); 
  v.customMsecsUntilReset = j.at("customMsecsUntilReset").get<int32_t>(); 
  v.gameLength = j.at("gameLength").get<int32_t>(); 
  }
}