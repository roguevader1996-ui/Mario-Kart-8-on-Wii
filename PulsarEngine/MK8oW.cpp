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

//Shock Squishing [CLF78, Ro]
asmFunc ShockSquick1() {
    ASM(
        nofralloc;
  rlwinm.   r26,r6,16,31,31;
  bne-      loc_0x20;
  rlwinm.   r26,r6,25,31,31;
  beq-      loc_0x20;
  rlwinm.   r26,r7,25,31,31;
  bne-      loc_0x3C;
  li        r23, 0x1;
  b         loc_0x3C;

loc_0x20:
  rlwinm.   r26,r7,16,31,31;
  bne-      loc_0x3C;
  rlwinm.   r26,r7,25,31,31;
  beq-      loc_0x3C;
  rlwinm.   r26,r6,25,31,31;
  bne-      loc_0x3C;
  li        r24, 0x1;

loc_0x3C:
  cmpwi     r27, 0;
  rlwinm    r26,r3,1,31,31;
  blr;
    )
}
kmCall(0x8056fd4c, ShockSquick1);

asmFunc ShockSquish2() {
    ASM(
        nofralloc;
  lwz       r5, 0x0(r31);
  li        r4, 0xD;
  lwz       r5, 0x4(r5);
  lwz       r5, 0xC(r5);
  rlwinm.   r5,r5,17,31,31;
  bne-      loc_0x1C;
  li        r4, 0x10;

loc_0x1C:
  blr;

    )
}
kmCall(0x8057042c, ShockSquish2);

asmFunc ShockSquish3() {
    ASM(
        nofralloc;
  lwz       r5, 0x4(r30);
  li        r4, 0xD;
  lwz       r5, 0x4(r5);
  lwz       r5, 0xC(r5);
  rlwinm.   r5,r5,17,31,31;
  bne-      loc_0x1C;
  li        r4, 0x10;

loc_0x1C:
  blr;

    )
}
kmCall(0x805705bc, ShockSquish3);
kmWrite8(0x805698cb, 0x00);
kmWrite32(0x8056990c, 0x48000024);
kmWrite32(0x80569948, 0x48000018);

}  // namespace MK8oW