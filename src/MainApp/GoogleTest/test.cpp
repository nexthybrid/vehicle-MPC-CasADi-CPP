#include "pch.h"
#include "../VehicleDynamics/vdyn.h"

using mpc::Vehicle;

TEST(VehicleDynamicsTest, ZeroStateZeroInput) {
	Vehicle vehObj = Vehicle();
	array<float, 2> next_state = vehObj.vehdyn({ 0,0 }, 0, 10);
	EXPECT_EQ(next_state[0], 0);
	EXPECT_EQ(next_state[1], 0);
}

TEST(VehicleDynamicsTest, ZeroStatePositiveInput) {
	Vehicle vehObj = Vehicle();
	array<float, 2> next_state = vehObj.vehdyn({ 0,0 }, 1, 10);
	EXPECT_TRUE(next_state[0] > 0);
	EXPECT_TRUE(next_state[1] > 0);
}

TEST(VehicleDynamicsTest, ZeroStateNegativeInput) {
	Vehicle vehObj = Vehicle();
	array<float, 2> next_state = vehObj.vehdyn({ 0,0 }, -1, 10);
	EXPECT_TRUE(next_state[0] < 0);
	EXPECT_TRUE(next_state[1] < 0);
}