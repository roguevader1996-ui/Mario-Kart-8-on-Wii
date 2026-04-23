#include <kamek.hpp>
#include <MarioKartWii/System/Random.hpp>
#include <MarioKartWii/RKNet/RKNetController.hpp>
#include <MarioKartWii/Objects/Collidable/Itembox/Itembox.hpp>

namespace MK8oW {

kmWrite32(0x807BB8EC, 0x60000000); // Accurate Item Roulette v2 [Ro]

kmWrite32(0x808A5380, 0x00000003); // Item Behavior Modifier - Rotating Triple Bananas [Luis]

kmWrite32(0x805731CC, 0x38600002); // Item Damage Type Modifier - Bob-Omb Explosion knockback [Skullface]
kmWrite32(0x805731B4, 0x38600002); // Item Damage Type Modifier - Blue Shell Explosion knockback [Skullface]

// Item Box Respawn Time Modifier based on ItemBoxRespawn() by Retro Rewind Team: https://github.com/Retro-Rewind-Team/rr-pulsar/blob/4895fbefdfff5a973b8353cf60cb6f9c852effc2/PulsarEngine/RetroRewind.cpp#L77
// Licensed under GPL v3, reimplemented by RogueVader1996 with a fixed 60-frame respawn for non-WW rooms instead of the original's configurable fast/default/200cc logic.
void ItemBoxRespawn(Objects::Itembox* itembox) {
    itembox->isActive = 0;
    itembox->respawnTime = (RKNet::Controller::sInstance->roomType == RKNet::ROOMTYPE_VS_WW) ? 150 : 60;
}
kmCall(0x80828EDC, ItemBoxRespawn);

}  // namespace MK8oW