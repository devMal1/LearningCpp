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

        Ad::Types::NeighborVehiclesType init_vehicle() {
            const auto vehicles = Ad::Types::NeighborVehiclesType{
                .left_lane_vehicles={
                    Ad::Types::VehicleType{
                        .id=0,
                        .lane=Ad::Types::LaneAssocationType::LeftLane,
                        .speed_mps=Ad::Utils::kph_to_mps(135.0f),
                        .relative_distance_m=40.0f
                    },
                    Ad::Types::VehicleType{
                        .id=1,
                        .lane=Ad::Types::LaneAssocationType::LeftLane,
                        .speed_mps=Ad::Utils::kph_to_mps(135.0f),
                        .relative_distance_m=-20.0f
                    }
                },
                .center_lane_vehicles={
                    Ad::Types::VehicleType{
                        .id=2,
                        .lane=Ad::Types::LaneAssocationType::CenterLane,
                        .speed_mps=Ad::Utils::kph_to_mps(135.0f),
                        .relative_distance_m=100.0f
                    },
                    Ad::Types::VehicleType{
                        .id=3,
                        .lane=Ad::Types::LaneAssocationType::CenterLane,
                        .speed_mps=Ad::Utils::kph_to_mps(135.0f),
                        .relative_distance_m=60.0f
                    }
                },
                .right_lane_vehicles={
                    Ad::Types::VehicleType{
                        .id=4,
                        .lane=Ad::Types::LaneAssocationType::RightLane,
                        .speed_mps=Ad::Utils::kph_to_mps(135.0f),
                        .relative_distance_m=70.0f
                    },
                    Ad::Types::VehicleType{
                        .id=5,
                        .lane=Ad::Types::LaneAssocationType::RightLane,
                        .speed_mps=Ad::Utils::kph_to_mps(135.0f),
                        .relative_distance_m=-50.0f
                    }
                }
            };

            return vehicles;
        }
    }

    namespace Visualize {
        void print_vehicle(const Ad::Types::VehicleType &vehicle) {
            std::cout << vehicle.id << std::endl;
            std::cout << vehicle.speed_mps << std::endl;
            std::cout << vehicle.relative_distance_m << std::endl;
        }

        void print_neighbor_vehicles(const Ad::Types::NeighborVehiclesType &vehicles) {
            print_vehicle(vehicles.left_lane_vehicles[0]);
            print_vehicle(vehicles.left_lane_vehicles[1]);

            print_vehicle(vehicles.center_lane_vehicles[0]);
            print_vehicle(vehicles.center_lane_vehicles[1]);

            print_vehicle(vehicles.right_lane_vehicles[0]);
            print_vehicle(vehicles.right_lane_vehicles[1]);

        }

        // TODO: finish!
        void print_scene(const Ad::Types::VehicleType &ego_vehicle, const Ad::Types::NeighborVehiclesType &vehicles) {
            std::cout << "           L   C   R  " << std::endl;

            for (std::int16_t distance = 100; distance >= -100; distance -= 20) {
                std::cout << distance;

                if (vehicles.left_lane_vehicles[0].relative_distance_m == distance || vehicles.left_lane_vehicles[1].relative_distance_m == distance) {
                    std::cout << "| V |";
                } else {
                    std::cout << "|   |";
                }

                if (vehicles.center_lane_vehicles[0].relative_distance_m == distance || vehicles.center_lane_vehicles[1].relative_distance_m == distance) {
                    std::cout << " V ";
                } else {
                    std::cout << "   ";
                }

                if (vehicles.right_lane_vehicles[0].relative_distance_m == distance || vehicles.right_lane_vehicles[1].relative_distance_m == distance) {
                    std::cout << "| V |";
                } else {
                    std::cout << "|   |";
                }

                std::cout << std::endl;
            }
        }
    }
}
