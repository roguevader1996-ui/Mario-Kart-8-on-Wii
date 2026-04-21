#include <kamek.hpp>
#include <MarioKartWii/UI/Ctrl/CtrlRace/CtrlRaceBalloon.hpp>

namespace Pulsar {
namespace Race {

static void DisableNametags() {
    RaceBalloons::maxDistanceNames = 0.0f;
}
RaceFrameHook NoNametags(DisableNametags);

}//namespace Race
}//namespace Pulsar