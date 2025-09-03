#pragma once

#include <cstdint>

#include "AdConstants.h"

namespace Ad {
    namespace Types {
        enum class LaneAssocationType {
            UnknownLane,
            LeftLane,
            CenterLane,
            RightLane
        };

        struct VehicleType {
            std::int32_t id;
            LaneAssocationType lane;
            float speed_mps; // units: meter/s
            float relative_distance_m; // units: meter
        };
    }
}
