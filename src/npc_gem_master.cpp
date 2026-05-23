#include "ScriptMgr.h"
#include "ScriptedGossip.h"
#include "Player.h"
#include "WorldSession.h"

class npc_gem_master : public CreatureScript
{
public:
    npc_gem_master() : CreatureScript("npc_gem_master") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Gems: Red (Красные)", GOSSIP_SENDER_MAIN, 910021);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Gems: Blue (Синие)", GOSSIP_SENDER_MAIN, 910022);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Gems: Yellow (Желтые)", GOSSIP_SENDER_MAIN, 910023);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Gems: Green (Зеленые)", GOSSIP_SENDER_MAIN, 910024);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Gems: Orange (Оранжевые)", GOSSIP_SENDER_MAIN, 910025);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Gems: Purple (Фиолетовые)", GOSSIP_SENDER_MAIN, 910026);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Gems: Meta (Особые)", GOSSIP_SENDER_MAIN, 910027);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Gems: Prismatic (Многоцветные)", GOSSIP_SENDER_MAIN, 910028);

        SendGossipMenuFor(player, 907, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        CloseGossipMenuFor(player);
        player->GetSession()->SendListInventory(creature->GetGUID(), action);
        return true;
    }
};

void AddSC_npc_gem_master()
{
    new npc_gem_master();
}
