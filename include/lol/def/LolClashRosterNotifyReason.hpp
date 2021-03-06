#pragma once
#include "../base_def.hpp" 
namespace lol {
  enum struct LolClashRosterNotifyReason {  
    BYE_AUTO_WIN_e = 5,
    CHANGE_POSITION_e = 6,
    GAME_COMPLETED_e = 12,
    GAME_STARTED_e = 13,
    GAME_STARTED_ERROR_e = 14,
    LOSER_ROUND_COMPLETE_e = 16,
    PHASE_CHECKIN_e = 11,
    PHASE_READY_e = 10,
    PHASE_UNREADY_e = 9,
    QUEUE_DODGE_e = 15,
    REGISTERED_e = 7,
    RESTRICTION_AUTO_WIN_e = 8,
    ROSTER_ACCEPT_TICKET_e = 2,
    ROSTER_DECLINE_TICKET_e = 3,
    ROSTER_OFFER_TICKET_e = 1,
    ROSTER_REVOKED_TICKET_e = 4,
    ROSTER_SET_TICKET_e = 0,
    SUB_ACCEPT_e = 18,
    SUB_ACCEPTSUGGEST_e = 22,
    SUB_DECLINE_e = 19,
    SUB_DECLINESUGGEST_e = 23,
    SUB_INVITE_e = 17,
    SUB_RECLAIM_e = 24,
    SUB_REVOKE_e = 20,
    SUB_SUGGEST_e = 21,
    VOTE_WITHDRAW_DISMISS_e = 26,
    VOTE_WITHDRAW_UPDATE_e = 25,
    WINNER_ROUND_COMPLETE_e = 28,
    WITHDRAW_e = 27,
  };
  inline void to_json(json& j, const LolClashRosterNotifyReason& v) {
    if(v == LolClashRosterNotifyReason::BYE_AUTO_WIN_e) {
      j = "BYE_AUTO_WIN";
      return;
    }
    if(v == LolClashRosterNotifyReason::CHANGE_POSITION_e) {
      j = "CHANGE_POSITION";
      return;
    }
    if(v == LolClashRosterNotifyReason::GAME_COMPLETED_e) {
      j = "GAME_COMPLETED";
      return;
    }
    if(v == LolClashRosterNotifyReason::GAME_STARTED_e) {
      j = "GAME_STARTED";
      return;
    }
    if(v == LolClashRosterNotifyReason::GAME_STARTED_ERROR_e) {
      j = "GAME_STARTED_ERROR";
      return;
    }
    if(v == LolClashRosterNotifyReason::LOSER_ROUND_COMPLETE_e) {
      j = "LOSER_ROUND_COMPLETE";
      return;
    }
    if(v == LolClashRosterNotifyReason::PHASE_CHECKIN_e) {
      j = "PHASE_CHECKIN";
      return;
    }
    if(v == LolClashRosterNotifyReason::PHASE_READY_e) {
      j = "PHASE_READY";
      return;
    }
    if(v == LolClashRosterNotifyReason::PHASE_UNREADY_e) {
      j = "PHASE_UNREADY";
      return;
    }
    if(v == LolClashRosterNotifyReason::QUEUE_DODGE_e) {
      j = "QUEUE_DODGE";
      return;
    }
    if(v == LolClashRosterNotifyReason::REGISTERED_e) {
      j = "REGISTERED";
      return;
    }
    if(v == LolClashRosterNotifyReason::RESTRICTION_AUTO_WIN_e) {
      j = "RESTRICTION_AUTO_WIN";
      return;
    }
    if(v == LolClashRosterNotifyReason::ROSTER_ACCEPT_TICKET_e) {
      j = "ROSTER_ACCEPT_TICKET";
      return;
    }
    if(v == LolClashRosterNotifyReason::ROSTER_DECLINE_TICKET_e) {
      j = "ROSTER_DECLINE_TICKET";
      return;
    }
    if(v == LolClashRosterNotifyReason::ROSTER_OFFER_TICKET_e) {
      j = "ROSTER_OFFER_TICKET";
      return;
    }
    if(v == LolClashRosterNotifyReason::ROSTER_REVOKED_TICKET_e) {
      j = "ROSTER_REVOKED_TICKET";
      return;
    }
    if(v == LolClashRosterNotifyReason::ROSTER_SET_TICKET_e) {
      j = "ROSTER_SET_TICKET";
      return;
    }
    if(v == LolClashRosterNotifyReason::SUB_ACCEPT_e) {
      j = "SUB_ACCEPT";
      return;
    }
    if(v == LolClashRosterNotifyReason::SUB_ACCEPTSUGGEST_e) {
      j = "SUB_ACCEPTSUGGEST";
      return;
    }
    if(v == LolClashRosterNotifyReason::SUB_DECLINE_e) {
      j = "SUB_DECLINE";
      return;
    }
    if(v == LolClashRosterNotifyReason::SUB_DECLINESUGGEST_e) {
      j = "SUB_DECLINESUGGEST";
      return;
    }
    if(v == LolClashRosterNotifyReason::SUB_INVITE_e) {
      j = "SUB_INVITE";
      return;
    }
    if(v == LolClashRosterNotifyReason::SUB_RECLAIM_e) {
      j = "SUB_RECLAIM";
      return;
    }
    if(v == LolClashRosterNotifyReason::SUB_REVOKE_e) {
      j = "SUB_REVOKE";
      return;
    }
    if(v == LolClashRosterNotifyReason::SUB_SUGGEST_e) {
      j = "SUB_SUGGEST";
      return;
    }
    if(v == LolClashRosterNotifyReason::VOTE_WITHDRAW_DISMISS_e) {
      j = "VOTE_WITHDRAW_DISMISS";
      return;
    }
    if(v == LolClashRosterNotifyReason::VOTE_WITHDRAW_UPDATE_e) {
      j = "VOTE_WITHDRAW_UPDATE";
      return;
    }
    if(v == LolClashRosterNotifyReason::WINNER_ROUND_COMPLETE_e) {
      j = "WINNER_ROUND_COMPLETE";
      return;
    }
    if(v == LolClashRosterNotifyReason::WITHDRAW_e) {
      j = "WITHDRAW";
      return;
    }
  }
  inline void from_json(const json& j, LolClashRosterNotifyReason& v) {
    if(j.get<std::string>() == "BYE_AUTO_WIN") {
      v = LolClashRosterNotifyReason::BYE_AUTO_WIN_e;
      return;
    } 
    if(j.get<std::string>() == "CHANGE_POSITION") {
      v = LolClashRosterNotifyReason::CHANGE_POSITION_e;
      return;
    } 
    if(j.get<std::string>() == "GAME_COMPLETED") {
      v = LolClashRosterNotifyReason::GAME_COMPLETED_e;
      return;
    } 
    if(j.get<std::string>() == "GAME_STARTED") {
      v = LolClashRosterNotifyReason::GAME_STARTED_e;
      return;
    } 
    if(j.get<std::string>() == "GAME_STARTED_ERROR") {
      v = LolClashRosterNotifyReason::GAME_STARTED_ERROR_e;
      return;
    } 
    if(j.get<std::string>() == "LOSER_ROUND_COMPLETE") {
      v = LolClashRosterNotifyReason::LOSER_ROUND_COMPLETE_e;
      return;
    } 
    if(j.get<std::string>() == "PHASE_CHECKIN") {
      v = LolClashRosterNotifyReason::PHASE_CHECKIN_e;
      return;
    } 
    if(j.get<std::string>() == "PHASE_READY") {
      v = LolClashRosterNotifyReason::PHASE_READY_e;
      return;
    } 
    if(j.get<std::string>() == "PHASE_UNREADY") {
      v = LolClashRosterNotifyReason::PHASE_UNREADY_e;
      return;
    } 
    if(j.get<std::string>() == "QUEUE_DODGE") {
      v = LolClashRosterNotifyReason::QUEUE_DODGE_e;
      return;
    } 
    if(j.get<std::string>() == "REGISTERED") {
      v = LolClashRosterNotifyReason::REGISTERED_e;
      return;
    } 
    if(j.get<std::string>() == "RESTRICTION_AUTO_WIN") {
      v = LolClashRosterNotifyReason::RESTRICTION_AUTO_WIN_e;
      return;
    } 
    if(j.get<std::string>() == "ROSTER_ACCEPT_TICKET") {
      v = LolClashRosterNotifyReason::ROSTER_ACCEPT_TICKET_e;
      return;
    } 
    if(j.get<std::string>() == "ROSTER_DECLINE_TICKET") {
      v = LolClashRosterNotifyReason::ROSTER_DECLINE_TICKET_e;
      return;
    } 
    if(j.get<std::string>() == "ROSTER_OFFER_TICKET") {
      v = LolClashRosterNotifyReason::ROSTER_OFFER_TICKET_e;
      return;
    } 
    if(j.get<std::string>() == "ROSTER_REVOKED_TICKET") {
      v = LolClashRosterNotifyReason::ROSTER_REVOKED_TICKET_e;
      return;
    } 
    if(j.get<std::string>() == "ROSTER_SET_TICKET") {
      v = LolClashRosterNotifyReason::ROSTER_SET_TICKET_e;
      return;
    } 
    if(j.get<std::string>() == "SUB_ACCEPT") {
      v = LolClashRosterNotifyReason::SUB_ACCEPT_e;
      return;
    } 
    if(j.get<std::string>() == "SUB_ACCEPTSUGGEST") {
      v = LolClashRosterNotifyReason::SUB_ACCEPTSUGGEST_e;
      return;
    } 
    if(j.get<std::string>() == "SUB_DECLINE") {
      v = LolClashRosterNotifyReason::SUB_DECLINE_e;
      return;
    } 
    if(j.get<std::string>() == "SUB_DECLINESUGGEST") {
      v = LolClashRosterNotifyReason::SUB_DECLINESUGGEST_e;
      return;
    } 
    if(j.get<std::string>() == "SUB_INVITE") {
      v = LolClashRosterNotifyReason::SUB_INVITE_e;
      return;
    } 
    if(j.get<std::string>() == "SUB_RECLAIM") {
      v = LolClashRosterNotifyReason::SUB_RECLAIM_e;
      return;
    } 
    if(j.get<std::string>() == "SUB_REVOKE") {
      v = LolClashRosterNotifyReason::SUB_REVOKE_e;
      return;
    } 
    if(j.get<std::string>() == "SUB_SUGGEST") {
      v = LolClashRosterNotifyReason::SUB_SUGGEST_e;
      return;
    } 
    if(j.get<std::string>() == "VOTE_WITHDRAW_DISMISS") {
      v = LolClashRosterNotifyReason::VOTE_WITHDRAW_DISMISS_e;
      return;
    } 
    if(j.get<std::string>() == "VOTE_WITHDRAW_UPDATE") {
      v = LolClashRosterNotifyReason::VOTE_WITHDRAW_UPDATE_e;
      return;
    } 
    if(j.get<std::string>() == "WINNER_ROUND_COMPLETE") {
      v = LolClashRosterNotifyReason::WINNER_ROUND_COMPLETE_e;
      return;
    } 
    if(j.get<std::string>() == "WITHDRAW") {
      v = LolClashRosterNotifyReason::WITHDRAW_e;
      return;
    } 
  }
}