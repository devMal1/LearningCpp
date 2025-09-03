#include <cmath>
#include <cstdint>
#include <iostream>

#include "AdConstants.h"
#include "AdFunctions.h"

namespace Ad {
    namespace Utils {
        float kph_to_mps(const float kph) {
            const auto mph = kph * 1000.0f /* m/km */ / 3600.0f /*h/s*/;
            return mph;
        }
    }

    namespace Data {
        Ad::Types::VehicleType init_ego_vehicle() {
            const auto ego_vehicle = Ad::Types::VehicleType{
                .id=Ad::Constants::EGO_VEHICLE_ID,
                .lane=Ad::Types::LaneAssocationType::CenterLane,
                .speed_mps=Ad::Utils::kph_to_mps(135.0f),
                .relative_distance_m=float{}
            };
            return ego_vehicle;
        }
    }

    namespace Visualize {
        void print_vehicle(const Ad::Types::VehicleType vehicle) {
            std::cout << vehicle.id << std::endl;
            std::cout << vehicle.speed_mps << std::endl;
            std::cout << vehicle.relative_distance_m << std::endl;
        }
    }
}
