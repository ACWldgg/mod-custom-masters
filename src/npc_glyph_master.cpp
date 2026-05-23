#include "ScriptMgr.h"
#include "ScriptedGossip.h"
#include "Player.h"
#include "WorldSession.h"

class npc_glyph_master : public CreatureScript
{
public:
    npc_glyph_master() : CreatureScript("npc_glyph_master") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Glyphs: Warrior", GOSSIP_SENDER_MAIN, 910001);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Glyphs: Paladin", GOSSIP_SENDER_MAIN, 910002);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Glyphs: Hunter", GOSSIP_SENDER_MAIN, 910003);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Glyphs: Rogue", GOSSIP_SENDER_MAIN, 910004);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Glyphs: Priest", GOSSIP_SENDER_MAIN, 910005);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Glyphs: Death Knight", GOSSIP_SENDER_MAIN, 910006);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Glyphs: Shaman", GOSSIP_SENDER_MAIN, 910007);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Glyphs: Mage", GOSSIP_SENDER_MAIN, 910008);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Glyphs: Warlock", GOSSIP_SENDER_MAIN, 910009);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Glyphs: Druid", GOSSIP_SENDER_MAIN, 910010);

        SendGossipMenuFor(player, 907, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        CloseGossipMenuFor(player);
        // ЗДЕСЬ ИСПРАВЛЕНИЕ: Мы передаем action, а не жесткое 910001
        // Теперь сервер будет открывать тот ID, который привязан к кнопке
        player->GetSession()->SendListInventory(creature->GetGUID(), action);
        return true;
    }
};

void AddSC_npc_glyph_master()
{
    new npc_glyph_master();
}