#include <kamek.hpp>
#include <MarioKartWii/System/Random.hpp>
#include <MarioKartWii/RKNet/RKNetController.hpp>
#include <MarioKartWii/Objects/Collidable/Itembox/Itembox.hpp>

namespace ItemBoxRespawnTime {

// Item Box Respawn Time Modifier based on ItemBoxRespawn() by Retro Rewind Team: https://github.com/Retro-Rewind-Team/rr-pulsar/blob/4895fbefdfff5a973b8353cf60cb6f9c852effc2/PulsarEngine/RetroRewind.cpp#L77
// Licensed under GPL v3, reimplemented by RogueVader1996 with a fixed 60-frame respawn for non-WW rooms instead of the original's configurable fast/default/200cc logic.
void ItemBoxRespawn(Objects::Itembox* itembox) {
    itembox->isActive = 0;
    itembox->respawnTime = (RKNet::Controller::sInstance->roomType == RKNet::ROOMTYPE_VS_WW) ? 150 : 60;
}
kmCall(0x80828EDC, ItemBoxRespawn);

}  // namespace ItemBoxRespawnTime
