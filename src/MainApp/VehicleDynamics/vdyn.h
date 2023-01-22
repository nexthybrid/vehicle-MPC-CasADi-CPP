#pragma once
#include <array>

#define MASS 1500		// [kg] vehicle mass
#define I_Z 2000		// [kg*m^2]	vehicle yaw moment of inertia
#define C_AF 10000		// [] vehicle front tire cornering stiffness
#define C_AR 10000		// [] vehicle rear tire cornering stiffness
#define L_F 1.5			// [m] distance from CG to front axle
#define L_R 1.5			// [m] distance from CG to rear axle

using std::array;

namespace mpc
{
	class Vehicle
	{
	public:
		// state-space dynamics of the vehicle model, returns dx/dt
		array<float, 2> vehdyn(const array<float, 2>& states, const float& input, const float& vx);
	};




}