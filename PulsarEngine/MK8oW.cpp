#include <kamek.hpp>

namespace MK8oW {

kmWrite32(0x807BB8EC, 0x60000000); // Accurate Item Roulette v2 [Ro]

kmWrite32(0x808A5380, 0x00000003); // Item Behavior Modifier - Rotating Triple Bananas [Luis]

kmWrite32(0x80568778, 0x60000000); // Getting starred doesn't drop your item
kmWrite32(0x80569084, 0x60000000); // Getting billed doesn't drop your item

//Item Damage Type Modifier [CLF78, Skullface, Supastarrio] https://mariokartwii.com/showthread.php?tid=1638
kmWrite32(0x805731CC, 0x38600002); // Bob-Omb Explosion knockback [Skullface]
kmWrite32(0x805731D8, 0x38600009); // Bob-omb Firey spinout [Skullface]
kmWrite32(0x805731B4, 0x38600002); // Blue Shell Explosion knockback [Skullface]

//Itembox From Common [Gabriela_]
asmFunc ItemBoxCommon() {
    ASM(
   nofralloc;
   li        r4, 0x1;
   lis       r12, 0x6974;
   ori       r12, r12, 0x656D;
   lwz       r11, 0x0(r5);
   cmplw     r11, r12;
   bne-      loc_0x1C;
   li        r4, 0;

   loc_0x1C:
   blr;)
}
kmCall(0x8081FDAC, ItemBoxCommon);

// Anti Mii Crash
asmFunc AntiWiper() {
    ASM(
        nofralloc;
        loc_0x0 : cmpwi r4, 0x6;
        ble validMii;
        lhz r12, 0xE(r30);
        cmpwi r12, 0x0;
        bne validMii;
        li r31, 0x0;
        li r4, 0x6;
        validMii : mr r29, r4;
        blr;)
}
kmCall(0x800CB6C0, AntiWiper);
kmWrite32(0x80526660, 0x38000001);  // Credits to Ro for the last line.

//Allow All Vehicles in Battle Mode [Nameless, Scruffy]
kmWrite32(0x80553F98, 0x3880000A);
kmWrite32(0x8084FEF0, 0x48000044);
kmWrite32(0x80860A90, 0x38600000);

}  // namespace MK8oW