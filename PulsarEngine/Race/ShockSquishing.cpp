#include <kamek.hpp>

namespace ShockSquishing {

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

} //namespace ShockSquishing
