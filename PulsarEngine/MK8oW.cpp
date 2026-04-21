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

// 1st Place Crown on Minimap based on Crown() from Insane Kart Wii by the Insane Kart Wii contributors: https://github.com/insanekartwii/Insane-Kart-Wii/blob/2ecbdd3f0603118280ba10fca9cb5fe8fbc9cabc/PulsarEngine/UI/SettingsFeatures.cpp#L558
// Licensed under GPL v3, modified by RogueVader1996.
asmFunc Crown() {
    ASM(
  lwzx      r4, r4, r0;
  li        r11, 0;
  lbz       r12, 0x20(r4);
  cmpwi     r12, 0x1;
  bne-      storeCrownVisibility;
  lwz       r12, 0xD728(r3);
  lwz       r12, 0xB70(r12);
  cmpwi     r12, 0x2;
  blt-      setCrownVisible;
  cmpwi     r12, 0x3;
  beq-      hasEnoughBattlePoints;
  cmpwi     r12, 0x7;
  blt-      end;
  cmpwi     r12, 0x9;
  blt-      setCrownVisible;
hasEnoughBattlePoints:
  lhz       r12, 0x22(r4);
  cmpwi     r12, 0x3;
  blt-      storeCrownVisibility;
setCrownVisible:
  li        r11, 0x1;
storeCrownVisibility:
  lwz       r12, 0x1B8(r28);
  stb       r11, 0x887(r12);
  lha       r11, 0xB8(r12);
  stb       r11, 0x884(r12);
end:
  blr;
    )
}
kmCall(0x807EB490, Crown);

}  // namespace MK8oW