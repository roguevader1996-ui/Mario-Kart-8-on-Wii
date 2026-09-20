#include <kamek.hpp>

// Ultra UnCut - ported from Insane Kart Wii (https://github.com/insanekartwii/Insane-Kart-Wii)
// Original cheat code by MrBean35000vr and Chadderz

asmFunc UltraUncut() {
    ASM(
  lbz       r3, 0x1C(r29);
  cmplwi    r3, 0x1;
  ble+      loc_0x10;
  mr        r0, r30;
loc_0x10:
  cmplw     r30, r0;
  blr;
    )
}

kmCall(0x8053511C, UltraUncut);
