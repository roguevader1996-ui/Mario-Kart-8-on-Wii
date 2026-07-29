#include <kamek.hpp>

namespace MK8oW {

kmWrite32(0x807BB8EC, 0x60000000); // Accurate Item Roulette v2 [Ro]

kmWrite32(0x808A5380, 0x00000003); // Item Behavior Modifier - Rotating Triple Bananas [Luis]

//Item Damage Type Modifier [CLF78, Skullface, Supastarrio] https://mariokartwii.com/showthread.php?tid=1638
kmWrite32(0x805731CC, 0x38600002); // Bob-Omb Explosion knockback [Skullface]
kmWrite32(0x805731B4, 0x38600002); // Blue Shell Explosion knockback [Skullface]

kmWrite32(0x80568778, 0x60000000); // Getting starred doesn't drop your item
kmWrite32(0x80569084, 0x60000000); // Getting billed doesn't drop your item

}  // namespace MK8oW