#include <kamek.hpp>

namespace MK8oW {

kmWrite32(0x807BB8EC, 0x60000000); // Accurate Item Roulette v2 [Ro]

kmWrite32(0x808A5380, 0x00000003); // Item Behavior Modifier - Rotating Triple Bananas [Luis]

kmWrite32(0x805731CC, 0x38600002); // Item Damage Type Modifier - Bob-Omb Explosion knockback [Skullface]
kmWrite32(0x805731B4, 0x38600002); // Item Damage Type Modifier - Blue Shell Explosion knockback [Skullface]

}  // namespace MK8oW