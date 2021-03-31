#include <string>

#include "Defines.hpp"
#include "Packets.hpp"
#include "CNStructs.hpp"

#define PACKET(id) {id, {id, sizeof(s##id), #id}}
#define MANUAL(id) {id, {id, sizeof(s##id), #id}}
#define VAR_PACKET(id, memb, tr) {id, {id, sizeof(s##id), #id, offsetof(s##id, memb), sizeof(tr)}}

/*
 * This map defines descriptors for all packets, and is used by the new system
 * for validation. From now on, we have to convert new variadic packets from
 * PACKET to VAR_PACKET in this list to use them.
 *
 * MANUAL is just a form of documentation stating that the packet is variadic
 * and atypically encoded, so it won't be able to pass outbound validation and
 * will need to be manually validated and sent using the legacy sendPacket()
 * invocation pattern.
 */
std::map<uint32_t, PacketDesc> Packets::packets = {
    // CL2LS
    PACKET(P_CL2LS_REQ_LOGIN),
    PACKET(P_CL2LS_REQ_CHECK_CHAR_NAME),
    PACKET(P_CL2LS_REQ_SAVE_CHAR_NAME),
    PACKET(P_CL2LS_REQ_CHAR_CREATE),
    PACKET(P_CL2LS_REQ_CHAR_SELECT),
    PACKET(P_CL2LS_REQ_CHAR_DELETE),
    PACKET(P_CL2LS_REQ_SHARD_SELECT),
    PACKET(P_CL2LS_REQ_SHARD_LIST_INFO),
    PACKET(P_CL2LS_CHECK_NAME_LIST),
    PACKET(P_CL2LS_REQ_SAVE_CHAR_TUTOR),
    PACKET(P_CL2LS_REQ_PC_EXIT_DUPLICATE),
    PACKET(P_CL2LS_REP_LIVE_CHECK),
    PACKET(P_CL2LS_REQ_CHANGE_CHAR_NAME),
    PACKET(P_CL2LS_REQ_SERVER_SELECT),

    // CL2FE
    PACKET(P_CL2FE_REQ_PC_ENTER),
    PACKET(P_CL2FE_REQ_PC_EXIT),
    PACKET(P_CL2FE_REQ_PC_MOVE),
    PACKET(P_CL2FE_REQ_PC_STOP),
    PACKET(P_CL2FE_REQ_PC_JUMP),
    VAR_PACKET(P_CL2FE_REQ_PC_ATTACK_NPCs, iNPCCnt, int32_t),
    PACKET(P_CL2FE_REQ_SEND_FREECHAT_MESSAGE),
    PACKET(P_CL2FE_REQ_SEND_MENUCHAT_MESSAGE),
    PACKET(P_CL2FE_REQ_PC_REGEN),
    PACKET(P_CL2FE_REQ_ITEM_MOVE),
    PACKET(P_CL2FE_REQ_PC_TASK_START),
    PACKET(P_CL2FE_REQ_PC_TASK_END),
    PACKET(P_CL2FE_REQ_NANO_EQUIP),
    PACKET(P_CL2FE_REQ_NANO_UNEQUIP),
    PACKET(P_CL2FE_REQ_NANO_ACTIVE),
    PACKET(P_CL2FE_REQ_NANO_TUNE),
    VAR_PACKET(P_CL2FE_REQ_NANO_SKILL_USE, iTargetCnt, int32_t),
    PACKET(P_CL2FE_REQ_PC_TASK_STOP),
    PACKET(P_CL2FE_REQ_PC_TASK_CONTINUE),
    PACKET(P_CL2FE_REQ_PC_GOTO),
    PACKET(P_CL2FE_REQ_CHARGE_NANO_STAMINA),
    PACKET(P_CL2FE_REQ_PC_KILL_QUEST_NPCs),
    PACKET(P_CL2FE_REQ_PC_VENDOR_ITEM_BUY),
    PACKET(P_CL2FE_REQ_PC_VENDOR_ITEM_SELL),
    PACKET(P_CL2FE_REQ_PC_ITEM_DELETE),
    PACKET(P_CL2FE_REQ_PC_GIVE_ITEM),
    PACKET(P_CL2FE_REQ_PC_ROCKET_STYLE_READY),
    PACKET(P_CL2FE_REQ_PC_ROCKET_STYLE_FIRE),
    VAR_PACKET(P_CL2FE_REQ_PC_ROCKET_STYLE_HIT, iTargetCnt, int64_t),
    PACKET(P_CL2FE_REQ_PC_GRENADE_STYLE_READY),
    PACKET(P_CL2FE_REQ_PC_GRENADE_STYLE_FIRE),
    PACKET(P_CL2FE_REQ_PC_GRENADE_STYLE_HIT),
    PACKET(P_CL2FE_REQ_PC_NANO_CREATE),
    PACKET(P_CL2FE_REQ_PC_TRADE_OFFER),
    PACKET(P_CL2FE_REQ_PC_TRADE_OFFER_CANCEL),
    PACKET(P_CL2FE_REQ_PC_TRADE_OFFER_ACCEPT),
    PACKET(P_CL2FE_REQ_PC_TRADE_OFFER_REFUSAL),
    PACKET(P_CL2FE_REQ_PC_TRADE_OFFER_ABORT),
    PACKET(P_CL2FE_REQ_PC_TRADE_CONFIRM),
    PACKET(P_CL2FE_REQ_PC_TRADE_CONFIRM_CANCEL),
    PACKET(P_CL2FE_REQ_PC_TRADE_CONFIRM_ABORT),
    PACKET(P_CL2FE_REQ_PC_TRADE_ITEM_REGISTER),
    PACKET(P_CL2FE_REQ_PC_TRADE_ITEM_UNREGISTER),
    PACKET(P_CL2FE_REQ_PC_TRADE_CASH_REGISTER),
    PACKET(P_CL2FE_REQ_PC_TRADE_EMOTES_CHAT),
    PACKET(P_CL2FE_REQ_PC_BANK_OPEN),
    PACKET(P_CL2FE_REQ_PC_BANK_CLOSE),
    PACKET(P_CL2FE_REQ_PC_VENDOR_START),
    PACKET(P_CL2FE_REQ_PC_VENDOR_TABLE_UPDATE),
    PACKET(P_CL2FE_REQ_PC_VENDOR_ITEM_RESTORE_BUY),
    PACKET(P_CL2FE_REQ_PC_COMBAT_BEGIN),
    PACKET(P_CL2FE_REQ_PC_COMBAT_END),
    PACKET(P_CL2FE_REQ_REQUEST_MAKE_BUDDY),
    PACKET(P_CL2FE_REQ_ACCEPT_MAKE_BUDDY),
    PACKET(P_CL2FE_REQ_SEND_BUDDY_FREECHAT_MESSAGE),
    PACKET(P_CL2FE_REQ_SEND_BUDDY_MENUCHAT_MESSAGE),
    PACKET(P_CL2FE_REQ_GET_BUDDY_STYLE),
    PACKET(P_CL2FE_REQ_SET_BUDDY_BLOCK),
    PACKET(P_CL2FE_REQ_REMOVE_BUDDY),
    PACKET(P_CL2FE_REQ_GET_BUDDY_STATE),
    PACKET(P_CL2FE_REQ_PC_JUMPPAD),
    PACKET(P_CL2FE_REQ_PC_LAUNCHER),
    PACKET(P_CL2FE_REQ_PC_ZIPLINE),
    PACKET(P_CL2FE_REQ_PC_MOVEPLATFORM),
    PACKET(P_CL2FE_REQ_PC_SLOPE),
    PACKET(P_CL2FE_REQ_PC_STATE_CHANGE),
    PACKET(P_CL2FE_REQ_PC_MAP_WARP),
    PACKET(P_CL2FE_REQ_PC_GIVE_NANO),
    PACKET(P_CL2FE_REQ_NPC_SUMMON),
    PACKET(P_CL2FE_REQ_NPC_UNSUMMON),
    PACKET(P_CL2FE_REQ_ITEM_CHEST_OPEN),
    PACKET(P_CL2FE_REQ_PC_GIVE_NANO_SKILL),
    PACKET(P_CL2FE_DOT_DAMAGE_ONOFF),
    PACKET(P_CL2FE_REQ_PC_VENDOR_BATTERY_BUY),
    PACKET(P_CL2FE_REQ_PC_WARP_USE_NPC),
    PACKET(P_CL2FE_REQ_PC_GROUP_INVITE),
    PACKET(P_CL2FE_REQ_PC_GROUP_INVITE_REFUSE),
    PACKET(P_CL2FE_REQ_PC_GROUP_JOIN),
    PACKET(P_CL2FE_REQ_PC_GROUP_LEAVE),
    PACKET(P_CL2FE_REQ_PC_AVATAR_EMOTES_CHAT),
    PACKET(P_CL2FE_REQ_PC_BUDDY_WARP),
    PACKET(P_CL2FE_REQ_GET_MEMBER_STYLE),
    PACKET(P_CL2FE_REQ_GET_GROUP_STYLE),
    PACKET(P_CL2FE_REQ_PC_CHANGE_MENTOR),
    PACKET(P_CL2FE_REQ_GET_BUDDY_LOCATION),
    PACKET(P_CL2FE_REQ_NPC_GROUP_SUMMON),
    PACKET(P_CL2FE_REQ_PC_WARP_TO_PC),
    PACKET(P_CL2FE_REQ_EP_RANK_GET_LIST),
    PACKET(P_CL2FE_REQ_EP_RANK_GET_DETAIL),
    PACKET(P_CL2FE_REQ_EP_RANK_GET_PC_INFO),
    PACKET(P_CL2FE_REQ_EP_RACE_START),
    PACKET(P_CL2FE_REQ_EP_RACE_END),
    PACKET(P_CL2FE_REQ_EP_RACE_CANCEL),
    PACKET(P_CL2FE_REQ_EP_GET_RING),
    PACKET(P_CL2FE_REQ_IM_CHANGE_SWITCH_STATUS),
    PACKET(P_CL2FE_REQ_SHINY_PICKUP),
    PACKET(P_CL2FE_REQ_SHINY_SUMMON),
    PACKET(P_CL2FE_REQ_PC_MOVETRANSPORTATION),
    PACKET(P_CL2FE_REQ_SEND_ALL_GROUP_FREECHAT_MESSAGE),
    PACKET(P_CL2FE_REQ_SEND_ANY_GROUP_FREECHAT_MESSAGE),
    PACKET(P_CL2FE_REQ_BARKER),
    PACKET(P_CL2FE_REQ_SEND_ALL_GROUP_MENUCHAT_MESSAGE),
    PACKET(P_CL2FE_REQ_SEND_ANY_GROUP_MENUCHAT_MESSAGE),
    PACKET(P_CL2FE_REQ_REGIST_TRANSPORTATION_LOCATION),
    PACKET(P_CL2FE_REQ_PC_WARP_USE_TRANSPORTATION),
    PACKET(P_CL2FE_GM_REQ_PC_SPECIAL_STATE_SWITCH),
    PACKET(P_CL2FE_GM_REQ_PC_SET_VALUE),
    PACKET(P_CL2FE_GM_REQ_KICK_PLAYER),
    PACKET(P_CL2FE_GM_REQ_TARGET_PC_TELEPORT),
    PACKET(P_CL2FE_GM_REQ_PC_LOCATION),
    PACKET(P_CL2FE_GM_REQ_PC_ANNOUNCE),
    PACKET(P_CL2FE_REQ_SET_PC_BLOCK),
    PACKET(P_CL2FE_REQ_REGIST_RXCOM),
    PACKET(P_CL2FE_GM_REQ_PC_MOTD_REGISTER),
    PACKET(P_CL2FE_REQ_ITEM_USE),
    PACKET(P_CL2FE_REQ_WARP_USE_RECALL),
    PACKET(P_CL2FE_REP_LIVE_CHECK),
    PACKET(P_CL2FE_REQ_PC_MISSION_COMPLETE),
    PACKET(P_CL2FE_REQ_PC_TASK_COMPLETE),
    PACKET(P_CL2FE_REQ_NPC_INTERACTION),
    PACKET(P_CL2FE_DOT_HEAL_ONOFF),
    PACKET(P_CL2FE_REQ_PC_SPECIAL_STATE_SWITCH),
    PACKET(P_CL2FE_REQ_PC_EMAIL_UPDATE_CHECK),
    PACKET(P_CL2FE_REQ_PC_READ_EMAIL),
    PACKET(P_CL2FE_REQ_PC_RECV_EMAIL_PAGE_LIST),
    PACKET(P_CL2FE_REQ_PC_DELETE_EMAIL),
    PACKET(P_CL2FE_REQ_PC_SEND_EMAIL),
    PACKET(P_CL2FE_REQ_PC_RECV_EMAIL_ITEM),
    PACKET(P_CL2FE_REQ_PC_RECV_EMAIL_CANDY),
    PACKET(P_CL2FE_GM_REQ_TARGET_PC_SPECIAL_STATE_ONOFF),
    PACKET(P_CL2FE_REQ_PC_SET_CURRENT_MISSION_ID),
    PACKET(P_CL2FE_REQ_NPC_GROUP_INVITE),
    PACKET(P_CL2FE_REQ_NPC_GROUP_KICK),
    PACKET(P_CL2FE_REQ_PC_FIRST_USE_FLAG_SET),
    PACKET(P_CL2FE_REQ_PC_TRANSPORT_WARP),
    PACKET(P_CL2FE_REQ_PC_TIME_TO_GO_WARP),
    PACKET(P_CL2FE_REQ_PC_RECV_EMAIL_ITEM_ALL),
    PACKET(P_CL2FE_REQ_CHANNEL_INFO),
    PACKET(P_CL2FE_REQ_PC_CHANNEL_NUM),
    PACKET(P_CL2FE_REQ_PC_WARP_CHANNEL),
    PACKET(P_CL2FE_REQ_PC_LOADING_COMPLETE),
    PACKET(P_CL2FE_REQ_PC_FIND_NAME_MAKE_BUDDY),
    PACKET(P_CL2FE_REQ_PC_FIND_NAME_ACCEPT_BUDDY),
    VAR_PACKET(P_CL2FE_REQ_PC_ATTACK_CHARs, iTargetCnt, sGM_PVPTarget),
    PACKET(P_CL2FE_PC_STREETSTALL_REQ_READY),
    PACKET(P_CL2FE_PC_STREETSTALL_REQ_CANCEL),
    PACKET(P_CL2FE_PC_STREETSTALL_REQ_REGIST_ITEM),
    PACKET(P_CL2FE_PC_STREETSTALL_REQ_UNREGIST_ITEM),
    PACKET(P_CL2FE_PC_STREETSTALL_REQ_SALE_START),
    PACKET(P_CL2FE_PC_STREETSTALL_REQ_ITEM_LIST),
    PACKET(P_CL2FE_PC_STREETSTALL_REQ_ITEM_BUY),
    PACKET(P_CL2FE_REQ_PC_ITEM_COMBINATION),
    PACKET(P_CL2FE_GM_REQ_SET_PC_SKILL),
    PACKET(P_CL2FE_REQ_PC_SKILL_ADD),
    PACKET(P_CL2FE_REQ_PC_SKILL_DEL),
    PACKET(P_CL2FE_REQ_PC_SKILL_USE),
    PACKET(P_CL2FE_REQ_PC_ROPE),
    PACKET(P_CL2FE_REQ_PC_BELT),
    PACKET(P_CL2FE_REQ_PC_VEHICLE_ON),
    PACKET(P_CL2FE_REQ_PC_VEHICLE_OFF),
    PACKET(P_CL2FE_REQ_PC_REGIST_QUICK_SLOT),
    PACKET(P_CL2FE_REQ_PC_DISASSEMBLE_ITEM),
    PACKET(P_CL2FE_GM_REQ_REWARD_RATE),
    PACKET(P_CL2FE_REQ_PC_ITEM_ENCHANT),

    // LS2CL
    PACKET(P_LS2CL_REP_LOGIN_SUCC),
    PACKET(P_LS2CL_REP_LOGIN_FAIL),
    PACKET(P_LS2CL_REP_CHAR_INFO),
    PACKET(P_LS2CL_REP_CHECK_CHAR_NAME_SUCC),
    PACKET(P_LS2CL_REP_CHECK_CHAR_NAME_FAIL),
    PACKET(P_LS2CL_REP_SAVE_CHAR_NAME_SUCC),
    PACKET(P_LS2CL_REP_SAVE_CHAR_NAME_FAIL),
    PACKET(P_LS2CL_REP_CHAR_CREATE_SUCC),
    PACKET(P_LS2CL_REP_CHAR_CREATE_FAIL),
    PACKET(P_LS2CL_REP_CHAR_SELECT_SUCC),
    PACKET(P_LS2CL_REP_CHAR_SELECT_FAIL),
    PACKET(P_LS2CL_REP_CHAR_DELETE_SUCC),
    PACKET(P_LS2CL_REP_CHAR_DELETE_FAIL),
    PACKET(P_LS2CL_REP_SHARD_SELECT_SUCC),
    PACKET(P_LS2CL_REP_SHARD_SELECT_FAIL),
    PACKET(P_LS2CL_REP_VERSION_CHECK_SUCC),
    PACKET(P_LS2CL_REP_VERSION_CHECK_FAIL),
    PACKET(P_LS2CL_REP_CHECK_NAME_LIST_SUCC),
    PACKET(P_LS2CL_REP_CHECK_NAME_LIST_FAIL),
    PACKET(P_LS2CL_REP_PC_EXIT_DUPLICATE),
    PACKET(P_LS2CL_REQ_LIVE_CHECK),
    PACKET(P_LS2CL_REP_CHANGE_CHAR_NAME_SUCC),
    PACKET(P_LS2CL_REP_CHANGE_CHAR_NAME_FAIL),
    PACKET(P_LS2CL_REP_SHARD_LIST_INFO_SUCC),

    // FE2CL
    PACKET(P_FE2CL_ERROR),
    PACKET(P_FE2CL_REP_PC_ENTER_FAIL),
    PACKET(P_FE2CL_REP_PC_ENTER_SUCC),
    PACKET(P_FE2CL_PC_NEW),
    PACKET(P_FE2CL_REP_PC_EXIT_FAIL),
    PACKET(P_FE2CL_REP_PC_EXIT_SUCC),
    PACKET(P_FE2CL_PC_EXIT),
    PACKET(P_FE2CL_PC_AROUND),
    PACKET(P_FE2CL_PC_MOVE),
    PACKET(P_FE2CL_PC_STOP),
    PACKET(P_FE2CL_PC_JUMP),
    PACKET(P_FE2CL_NPC_ENTER),
    PACKET(P_FE2CL_NPC_EXIT),
    PACKET(P_FE2CL_NPC_MOVE),
    PACKET(P_FE2CL_NPC_NEW),
    PACKET(P_FE2CL_NPC_AROUND),
    PACKET(P_FE2CL_AROUND_DEL_PC),
    PACKET(P_FE2CL_AROUND_DEL_NPC),
    PACKET(P_FE2CL_REP_SEND_FREECHAT_MESSAGE_SUCC),
    PACKET(P_FE2CL_REP_SEND_FREECHAT_MESSAGE_FAIL),
    VAR_PACKET(P_FE2CL_PC_ATTACK_NPCs_SUCC, iNPCCnt, sAttackResult),
    VAR_PACKET(P_FE2CL_PC_ATTACK_NPCs, iNPCCnt, sAttackResult),
    VAR_PACKET(P_FE2CL_NPC_ATTACK_PCs, iPCCnt, sAttackResult),
    PACKET(P_FE2CL_REP_PC_REGEN_SUCC),
    PACKET(P_FE2CL_REP_SEND_MENUCHAT_MESSAGE_SUCC),
    PACKET(P_FE2CL_REP_SEND_MENUCHAT_MESSAGE_FAIL),
    PACKET(P_FE2CL_PC_ITEM_MOVE_SUCC),
    PACKET(P_FE2CL_PC_EQUIP_CHANGE),
    PACKET(P_FE2CL_REP_PC_TASK_START_SUCC),
    PACKET(P_FE2CL_REP_PC_TASK_START_FAIL),
    PACKET(P_FE2CL_REP_PC_TASK_END_SUCC),
    PACKET(P_FE2CL_REP_PC_TASK_END_FAIL),
    PACKET(P_FE2CL_NPC_SKILL_READY),
    PACKET(P_FE2CL_NPC_SKILL_FIRE),
    MANUAL(P_FE2CL_NPC_SKILL_HIT), // variadic, trailer type depends on power
    PACKET(P_FE2CL_NPC_SKILL_CORRUPTION_READY),
    VAR_PACKET(P_FE2CL_NPC_SKILL_CORRUPTION_HIT, iTargetCnt, sCAttackResult),
    PACKET(P_FE2CL_NPC_SKILL_CANCEL),
    PACKET(P_FE2CL_REP_NANO_EQUIP_SUCC),
    PACKET(P_FE2CL_REP_NANO_UNEQUIP_SUCC),
    PACKET(P_FE2CL_REP_NANO_ACTIVE_SUCC),
    PACKET(P_FE2CL_REP_NANO_TUNE_SUCC),
    PACKET(P_FE2CL_NANO_ACTIVE),
    MANUAL(P_FE2CL_NANO_SKILL_USE_SUCC), // variadic, trailer type depends on power
    PACKET(P_FE2CL_NANO_SKILL_USE),
    PACKET(P_FE2CL_REP_PC_TASK_STOP_SUCC),
    PACKET(P_FE2CL_REP_PC_TASK_STOP_FAIL),
    PACKET(P_FE2CL_REP_PC_TASK_CONTINUE_SUCC),
    PACKET(P_FE2CL_REP_PC_TASK_CONTINUE_FAIL),
    PACKET(P_FE2CL_REP_PC_GOTO_SUCC),
    PACKET(P_FE2CL_REP_CHARGE_NANO_STAMINA),
    PACKET(P_FE2CL_REP_PC_TICK),
    PACKET(P_FE2CL_REP_PC_KILL_QUEST_NPCs_SUCC),
    PACKET(P_FE2CL_REP_PC_VENDOR_ITEM_BUY_SUCC),
    PACKET(P_FE2CL_REP_PC_VENDOR_ITEM_BUY_FAIL),
    PACKET(P_FE2CL_REP_PC_VENDOR_ITEM_SELL_SUCC),
    PACKET(P_FE2CL_REP_PC_VENDOR_ITEM_SELL_FAIL),
    PACKET(P_FE2CL_REP_PC_ITEM_DELETE_SUCC),
    PACKET(P_FE2CL_PC_ROCKET_STYLE_READY),
    PACKET(P_FE2CL_REP_PC_ROCKET_STYLE_FIRE_SUCC),
    PACKET(P_FE2CL_PC_ROCKET_STYLE_FIRE),
    PACKET(P_FE2CL_PC_ROCKET_STYLE_HIT),
    PACKET(P_FE2CL_PC_GRENADE_STYLE_READY),
    PACKET(P_FE2CL_REP_PC_GRENADE_STYLE_FIRE_SUCC),
    PACKET(P_FE2CL_PC_GRENADE_STYLE_FIRE),
    VAR_PACKET(P_FE2CL_PC_GRENADE_STYLE_HIT, iTargetCnt, sAttackResult),
    PACKET(P_FE2CL_REP_PC_TRADE_OFFER),
    PACKET(P_FE2CL_REP_PC_TRADE_OFFER_CANCEL),
    PACKET(P_FE2CL_REP_PC_TRADE_OFFER_SUCC),
    PACKET(P_FE2CL_REP_PC_TRADE_OFFER_REFUSAL),
    PACKET(P_FE2CL_REP_PC_TRADE_OFFER_ABORT),
    PACKET(P_FE2CL_REP_PC_TRADE_CONFIRM),
    PACKET(P_FE2CL_REP_PC_TRADE_CONFIRM_CANCEL),
    PACKET(P_FE2CL_REP_PC_TRADE_CONFIRM_ABORT),
    PACKET(P_FE2CL_REP_PC_TRADE_CONFIRM_SUCC),
    PACKET(P_FE2CL_REP_PC_TRADE_CONFIRM_FAIL),
    PACKET(P_FE2CL_REP_PC_TRADE_ITEM_REGISTER_SUCC),
    PACKET(P_FE2CL_REP_PC_TRADE_ITEM_REGISTER_FAIL),
    PACKET(P_FE2CL_REP_PC_TRADE_ITEM_UNREGISTER_SUCC),
    PACKET(P_FE2CL_REP_PC_TRADE_ITEM_UNREGISTER_FAIL),
    PACKET(P_FE2CL_REP_PC_TRADE_CASH_REGISTER_SUCC),
    PACKET(P_FE2CL_REP_PC_TRADE_CASH_REGISTER_FAIL),
    PACKET(P_FE2CL_REP_PC_TRADE_EMOTES_CHAT),
    PACKET(P_FE2CL_REP_PC_NANO_CREATE_SUCC),
    PACKET(P_FE2CL_REP_PC_NANO_CREATE_FAIL),
    PACKET(P_FE2CL_REP_NANO_TUNE_FAIL),
    PACKET(P_FE2CL_REP_PC_BANK_OPEN_SUCC),
    PACKET(P_FE2CL_REP_PC_BANK_OPEN_FAIL),
    PACKET(P_FE2CL_REP_PC_BANK_CLOSE_SUCC),
    PACKET(P_FE2CL_REP_PC_BANK_CLOSE_FAIL),
    PACKET(P_FE2CL_REP_PC_VENDOR_START_SUCC),
    PACKET(P_FE2CL_REP_PC_VENDOR_START_FAIL),
    PACKET(P_FE2CL_REP_PC_VENDOR_TABLE_UPDATE_SUCC),
    PACKET(P_FE2CL_REP_PC_VENDOR_TABLE_UPDATE_FAIL),
    PACKET(P_FE2CL_REP_PC_VENDOR_ITEM_RESTORE_BUY_SUCC),
    PACKET(P_FE2CL_REP_PC_VENDOR_ITEM_RESTORE_BUY_FAIL),
    PACKET(P_FE2CL_CHAR_TIME_BUFF_TIME_OUT),
    PACKET(P_FE2CL_REP_PC_GIVE_ITEM_SUCC),
    PACKET(P_FE2CL_REP_PC_GIVE_ITEM_FAIL),
    VAR_PACKET(P_FE2CL_REP_PC_BUDDYLIST_INFO_SUCC, iBuddyCnt, sBuddyBaseInfo),
    PACKET(P_FE2CL_REP_PC_BUDDYLIST_INFO_FAIL),
    PACKET(P_FE2CL_REP_REQUEST_MAKE_BUDDY_SUCC),
    PACKET(P_FE2CL_REP_REQUEST_MAKE_BUDDY_FAIL),
    PACKET(P_FE2CL_REP_ACCEPT_MAKE_BUDDY_SUCC),
    PACKET(P_FE2CL_REP_ACCEPT_MAKE_BUDDY_FAIL),
    PACKET(P_FE2CL_REP_SEND_BUDDY_FREECHAT_MESSAGE_SUCC),
    PACKET(P_FE2CL_REP_SEND_BUDDY_FREECHAT_MESSAGE_FAIL),
    PACKET(P_FE2CL_REP_SEND_BUDDY_MENUCHAT_MESSAGE_SUCC),
    PACKET(P_FE2CL_REP_SEND_BUDDY_MENUCHAT_MESSAGE_FAIL),
    PACKET(P_FE2CL_REP_GET_BUDDY_STYLE_SUCC),
    PACKET(P_FE2CL_REP_GET_BUDDY_STYLE_FAIL),
    PACKET(P_FE2CL_REP_GET_BUDDY_STATE_SUCC),
    PACKET(P_FE2CL_REP_GET_BUDDY_STATE_FAIL),
    PACKET(P_FE2CL_REP_SET_BUDDY_BLOCK_SUCC),
    PACKET(P_FE2CL_REP_SET_BUDDY_BLOCK_FAIL),
    PACKET(P_FE2CL_REP_REMOVE_BUDDY_SUCC),
    PACKET(P_FE2CL_REP_REMOVE_BUDDY_FAIL),
    PACKET(P_FE2CL_PC_JUMPPAD),
    PACKET(P_FE2CL_PC_LAUNCHER),
    PACKET(P_FE2CL_PC_ZIPLINE),
    PACKET(P_FE2CL_PC_MOVEPLATFORM),
    PACKET(P_FE2CL_PC_SLOPE),
    PACKET(P_FE2CL_PC_STATE_CHANGE),
    PACKET(P_FE2CL_REP_REQUEST_MAKE_BUDDY_SUCC_TO_ACCEPTER),
    VAR_PACKET(P_FE2CL_REP_REWARD_ITEM, iItemCnt, sItemReward),
    PACKET(P_FE2CL_REP_ITEM_CHEST_OPEN_SUCC),
    PACKET(P_FE2CL_REP_ITEM_CHEST_OPEN_FAIL),
    MANUAL(P_FE2CL_CHAR_TIME_BUFF_TIME_TICK), // variadic, depends on skill type
    PACKET(P_FE2CL_REP_PC_VENDOR_BATTERY_BUY_SUCC),
    PACKET(P_FE2CL_REP_PC_VENDOR_BATTERY_BUY_FAIL),
    PACKET(P_FE2CL_NPC_ROCKET_STYLE_FIRE),
    PACKET(P_FE2CL_NPC_GRENADE_STYLE_FIRE),
    PACKET(P_FE2CL_NPC_BULLET_STYLE_HIT),
    PACKET(P_FE2CL_CHARACTER_ATTACK_CHARACTERs),
    PACKET(P_FE2CL_PC_GROUP_INVITE),
    PACKET(P_FE2CL_PC_GROUP_INVITE_FAIL),
    PACKET(P_FE2CL_PC_GROUP_INVITE_REFUSE),
    MANUAL(P_FE2CL_PC_GROUP_JOIN), // double-variadic, incompatible with this system
    PACKET(P_FE2CL_PC_GROUP_JOIN_FAIL),
    PACKET(P_FE2CL_PC_GROUP_JOIN_SUCC), // probably these ones too, but we don't use them anyway
    MANUAL(P_FE2CL_PC_GROUP_LEAVE), // double-variadic, incompatible with this system
    PACKET(P_FE2CL_PC_GROUP_LEAVE_FAIL),
    PACKET(P_FE2CL_PC_GROUP_LEAVE_SUCC), // see GROUP_JOIN_SUCC
    MANUAL(P_FE2CL_PC_GROUP_MEMBER_INFO), // double-variadic, incompatible with this system
    PACKET(P_FE2CL_REP_PC_WARP_USE_NPC_SUCC),
    PACKET(P_FE2CL_REP_PC_WARP_USE_NPC_FAIL),
    PACKET(P_FE2CL_REP_PC_AVATAR_EMOTES_CHAT),
    PACKET(P_FE2CL_REP_PC_CHANGE_MENTOR_SUCC),
    PACKET(P_FE2CL_REP_PC_CHANGE_MENTOR_FAIL),
    PACKET(P_FE2CL_REP_GET_MEMBER_STYLE_FAIL),
    PACKET(P_FE2CL_REP_GET_MEMBER_STYLE_SUCC),
    PACKET(P_FE2CL_REP_GET_GROUP_STYLE_FAIL),
    PACKET(P_FE2CL_REP_GET_GROUP_STYLE_SUCC),
    PACKET(P_FE2CL_PC_REGEN),
    PACKET(P_FE2CL_INSTANCE_MAP_INFO),
    PACKET(P_FE2CL_TRANSPORTATION_ENTER),
    PACKET(P_FE2CL_TRANSPORTATION_EXIT),
    PACKET(P_FE2CL_TRANSPORTATION_MOVE),
    PACKET(P_FE2CL_TRANSPORTATION_NEW),
    PACKET(P_FE2CL_TRANSPORTATION_AROUND),
    PACKET(P_FE2CL_AROUND_DEL_TRANSPORTATION),
    PACKET(P_FE2CL_REP_EP_RANK_LIST),
    PACKET(P_FE2CL_REP_EP_RANK_DETAIL),
    PACKET(P_FE2CL_REP_EP_RANK_PC_INFO),
    PACKET(P_FE2CL_REP_EP_RACE_START_SUCC),
    PACKET(P_FE2CL_REP_EP_RACE_START_FAIL),
    PACKET(P_FE2CL_REP_EP_RACE_END_SUCC),
    PACKET(P_FE2CL_REP_EP_RACE_END_FAIL),
    PACKET(P_FE2CL_REP_EP_RACE_CANCEL_SUCC),
    PACKET(P_FE2CL_REP_EP_RACE_CANCEL_FAIL),
    PACKET(P_FE2CL_REP_EP_GET_RING_SUCC),
    PACKET(P_FE2CL_REP_EP_GET_RING_FAIL),
    PACKET(P_FE2CL_REP_IM_CHANGE_SWITCH_STATUS),
    PACKET(P_FE2CL_SHINY_ENTER),
    PACKET(P_FE2CL_SHINY_EXIT),
    PACKET(P_FE2CL_SHINY_NEW),
    PACKET(P_FE2CL_SHINY_AROUND),
    PACKET(P_FE2CL_AROUND_DEL_SHINY),
    PACKET(P_FE2CL_REP_SHINY_PICKUP_FAIL),
    PACKET(P_FE2CL_REP_SHINY_PICKUP_SUCC),
    PACKET(P_FE2CL_PC_MOVETRANSPORTATION),
    PACKET(P_FE2CL_REP_SEND_ALL_GROUP_FREECHAT_MESSAGE_SUCC),
    PACKET(P_FE2CL_REP_SEND_ALL_GROUP_FREECHAT_MESSAGE_FAIL),
    PACKET(P_FE2CL_REP_SEND_ANY_GROUP_FREECHAT_MESSAGE_SUCC),
    PACKET(P_FE2CL_REP_SEND_ANY_GROUP_FREECHAT_MESSAGE_FAIL),
    PACKET(P_FE2CL_REP_BARKER),
    PACKET(P_FE2CL_REP_SEND_ALL_GROUP_MENUCHAT_MESSAGE_SUCC),
    PACKET(P_FE2CL_REP_SEND_ALL_GROUP_MENUCHAT_MESSAGE_FAIL),
    PACKET(P_FE2CL_REP_SEND_ANY_GROUP_MENUCHAT_MESSAGE_SUCC),
    PACKET(P_FE2CL_REP_SEND_ANY_GROUP_MENUCHAT_MESSAGE_FAIL),
    PACKET(P_FE2CL_REP_PC_REGIST_TRANSPORTATION_LOCATION_FAIL),
    PACKET(P_FE2CL_REP_PC_REGIST_TRANSPORTATION_LOCATION_SUCC),
    PACKET(P_FE2CL_REP_PC_WARP_USE_TRANSPORTATION_FAIL),
    PACKET(P_FE2CL_REP_PC_WARP_USE_TRANSPORTATION_SUCC),
    PACKET(P_FE2CL_ANNOUNCE_MSG),
    PACKET(P_FE2CL_REP_PC_SPECIAL_STATE_SWITCH_SUCC),
    PACKET(P_FE2CL_PC_SPECIAL_STATE_CHANGE),
    PACKET(P_FE2CL_GM_REP_PC_SET_VALUE),
    PACKET(P_FE2CL_GM_PC_CHANGE_VALUE),
    PACKET(P_FE2CL_GM_REP_PC_LOCATION),
    PACKET(P_FE2CL_GM_REP_PC_ANNOUNCE),
    PACKET(P_FE2CL_REP_PC_BUDDY_WARP_FAIL),
    PACKET(P_FE2CL_REP_PC_CHANGE_LEVEL),
    PACKET(P_FE2CL_REP_SET_PC_BLOCK_SUCC),
    PACKET(P_FE2CL_REP_SET_PC_BLOCK_FAIL),
    PACKET(P_FE2CL_REP_REGIST_RXCOM),
    PACKET(P_FE2CL_REP_REGIST_RXCOM_FAIL),
    PACKET(P_FE2CL_PC_INVEN_FULL_MSG),
    PACKET(P_FE2CL_REQ_LIVE_CHECK),
    PACKET(P_FE2CL_PC_MOTD_LOGIN),
    PACKET(P_FE2CL_REP_PC_ITEM_USE_FAIL),
    VAR_PACKET(P_FE2CL_REP_PC_ITEM_USE_SUCC, iTargetCnt, sSkillResult_Buff),
    PACKET(P_FE2CL_PC_ITEM_USE),
    PACKET(P_FE2CL_REP_GET_BUDDY_LOCATION_SUCC),
    PACKET(P_FE2CL_REP_GET_BUDDY_LOCATION_FAIL),
    PACKET(P_FE2CL_REP_PC_RIDING_FAIL),
    PACKET(P_FE2CL_REP_PC_RIDING_SUCC),
    PACKET(P_FE2CL_PC_RIDING),
    PACKET(P_FE2CL_PC_BROOMSTICK_MOVE),
    PACKET(P_FE2CL_REP_PC_BUDDY_WARP_OTHER_SHARD_SUCC),
    PACKET(P_FE2CL_REP_WARP_USE_RECALL_FAIL),
    PACKET(P_FE2CL_REP_PC_EXIT_DUPLICATE),
    PACKET(P_FE2CL_REP_PC_MISSION_COMPLETE_SUCC),
    PACKET(P_FE2CL_PC_BUFF_UPDATE),
    PACKET(P_FE2CL_REP_PC_NEW_EMAIL),
    PACKET(P_FE2CL_REP_PC_READ_EMAIL_SUCC),
    PACKET(P_FE2CL_REP_PC_READ_EMAIL_FAIL),
    PACKET(P_FE2CL_REP_PC_RECV_EMAIL_PAGE_LIST_SUCC),
    PACKET(P_FE2CL_REP_PC_RECV_EMAIL_PAGE_LIST_FAIL),
    PACKET(P_FE2CL_REP_PC_DELETE_EMAIL_SUCC),
    PACKET(P_FE2CL_REP_PC_DELETE_EMAIL_FAIL),
    PACKET(P_FE2CL_REP_PC_SEND_EMAIL_SUCC),
    PACKET(P_FE2CL_REP_PC_SEND_EMAIL_FAIL),
    PACKET(P_FE2CL_REP_PC_RECV_EMAIL_ITEM_SUCC),
    PACKET(P_FE2CL_REP_PC_RECV_EMAIL_ITEM_FAIL),
    PACKET(P_FE2CL_REP_PC_RECV_EMAIL_CANDY_SUCC),
    PACKET(P_FE2CL_REP_PC_RECV_EMAIL_CANDY_FAIL),
    PACKET(P_FE2CL_PC_SUDDEN_DEAD),
    PACKET(P_FE2CL_REP_GM_REQ_TARGET_PC_SPECIAL_STATE_ONOFF_SUCC),
    PACKET(P_FE2CL_REP_PC_SET_CURRENT_MISSION_ID),
    PACKET(P_FE2CL_REP_NPC_GROUP_INVITE_FAIL),
    PACKET(P_FE2CL_REP_NPC_GROUP_INVITE_SUCC),
    PACKET(P_FE2CL_REP_NPC_GROUP_KICK_FAIL),
    PACKET(P_FE2CL_REP_NPC_GROUP_KICK_SUCC),
    PACKET(P_FE2CL_PC_EVENT),
    PACKET(P_FE2CL_REP_PC_TRANSPORT_WARP_SUCC),
    PACKET(P_FE2CL_REP_PC_TRADE_EMOTES_CHAT_FAIL),
    PACKET(P_FE2CL_REP_PC_RECV_EMAIL_ITEM_ALL_SUCC),
    PACKET(P_FE2CL_REP_PC_RECV_EMAIL_ITEM_ALL_FAIL),
    PACKET(P_FE2CL_REP_PC_LOADING_COMPLETE_SUCC),
    PACKET(P_FE2CL_REP_CHANNEL_INFO),
    PACKET(P_FE2CL_REP_PC_CHANNEL_NUM),
    PACKET(P_FE2CL_REP_PC_WARP_CHANNEL_FAIL),
    PACKET(P_FE2CL_REP_PC_WARP_CHANNEL_SUCC),
    PACKET(P_FE2CL_REP_PC_FIND_NAME_MAKE_BUDDY_SUCC),
    PACKET(P_FE2CL_REP_PC_FIND_NAME_MAKE_BUDDY_FAIL),
    PACKET(P_FE2CL_REP_PC_FIND_NAME_ACCEPT_BUDDY_FAIL),
    PACKET(P_FE2CL_REP_PC_BUDDY_WARP_SAME_SHARD_SUCC),
    VAR_PACKET(P_FE2CL_PC_ATTACK_CHARs_SUCC, iTargetCnt, sAttackResult),
    VAR_PACKET(P_FE2CL_PC_ATTACK_CHARs, iTargetCnt, sAttackResult),
    PACKET(P_FE2CL_NPC_ATTACK_CHARs),
    PACKET(P_FE2CL_REP_PC_CHANGE_LEVEL_SUCC),
    PACKET(P_FE2CL_REP_PC_NANO_CREATE),
    PACKET(P_FE2CL_PC_STREETSTALL_REP_READY_SUCC),
    PACKET(P_FE2CL_PC_STREETSTALL_REP_READY_FAIL),
    PACKET(P_FE2CL_PC_STREETSTALL_REP_CANCEL_SUCC),
    PACKET(P_FE2CL_PC_STREETSTALL_REP_CANCEL_FAIL),
    PACKET(P_FE2CL_PC_STREETSTALL_REP_REGIST_ITEM_SUCC),
    PACKET(P_FE2CL_PC_STREETSTALL_REP_REGIST_ITEM_FAIL),
    PACKET(P_FE2CL_PC_STREETSTALL_REP_UNREGIST_ITEM_SUCC),
    PACKET(P_FE2CL_PC_STREETSTALL_REP_UNREGIST_ITEM_FAIL),
    PACKET(P_FE2CL_PC_STREETSTALL_REP_SALE_START_SUCC),
    PACKET(P_FE2CL_PC_STREETSTALL_REP_SALE_START_FAIL),
    PACKET(P_FE2CL_PC_STREETSTALL_REP_ITEM_LIST),
    PACKET(P_FE2CL_PC_STREETSTALL_REP_ITEM_LIST_FAIL),
    PACKET(P_FE2CL_PC_STREETSTALL_REP_ITEM_BUY_SUCC_BUYER),
    PACKET(P_FE2CL_PC_STREETSTALL_REP_ITEM_BUY_SUCC_SELLER),
    PACKET(P_FE2CL_PC_STREETSTALL_REP_ITEM_BUY_FAIL),
    PACKET(P_FE2CL_REP_PC_ITEM_COMBINATION_SUCC),
    PACKET(P_FE2CL_REP_PC_ITEM_COMBINATION_FAIL),
    PACKET(P_FE2CL_PC_CASH_BUFF_UPDATE),
    PACKET(P_FE2CL_REP_PC_SKILL_ADD_SUCC),
    PACKET(P_FE2CL_REP_PC_SKILL_ADD_FAIL),
    PACKET(P_FE2CL_REP_PC_SKILL_DEL_SUCC),
    PACKET(P_FE2CL_REP_PC_SKILL_DEL_FAIL),
    PACKET(P_FE2CL_REP_PC_SKILL_USE_SUCC),
    PACKET(P_FE2CL_REP_PC_SKILL_USE_FAIL),
    PACKET(P_FE2CL_PC_SKILL_USE),
    PACKET(P_FE2CL_PC_ROPE),
    PACKET(P_FE2CL_PC_BELT),
    PACKET(P_FE2CL_PC_VEHICLE_ON_SUCC),
    PACKET(P_FE2CL_PC_VEHICLE_ON_FAIL),
    PACKET(P_FE2CL_PC_VEHICLE_OFF_SUCC),
    PACKET(P_FE2CL_PC_VEHICLE_OFF_FAIL),
    PACKET(P_FE2CL_PC_QUICK_SLOT_INFO),
    PACKET(P_FE2CL_REP_PC_REGIST_QUICK_SLOT_FAIL),
    PACKET(P_FE2CL_REP_PC_REGIST_QUICK_SLOT_SUCC),
    VAR_PACKET(P_FE2CL_PC_DELETE_TIME_LIMIT_ITEM, iItemListCount, sTimeLimitItemDeleteInfo2CL),
    PACKET(P_FE2CL_REP_PC_DISASSEMBLE_ITEM_SUCC),
    PACKET(P_FE2CL_REP_PC_DISASSEMBLE_ITEM_FAIL),
    PACKET(P_FE2CL_GM_REP_REWARD_RATE_SUCC),
    PACKET(P_FE2CL_REP_PC_ITEM_ENCHANT_SUCC),
    PACKET(P_FE2CL_REP_PC_ITEM_ENCHANT_FAIL),

#ifdef ACADEMY
    // Academy-specific
    PACKET(P_FE2CL_REP_NANO_BOOK_SUBSET),
#endif
};

std::string Packets::p2str(int val) {
    if (packets.find(val) == packets.end())
        return "UNKNOWN";

    return packets[val].name;
}
