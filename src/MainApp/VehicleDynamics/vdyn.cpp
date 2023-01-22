#include "pch.h"
#include "framework.h"
#include "vdyn.h"

namespace mpc
{
	array<float, 2> Vehicle::vehdyn(const array<float, 2>& states, const float& input, const float& vx)
	{
		
		array<float, 2> next_state;

		array<array<float,2>, 2> Amatrix =
		{	
			{
			{-(C_AF + C_AR) / MASS / vx,
			(-L_F * C_AF + L_R * C_AR) / MASS / vx - vx},
			{(-(L_F * C_AF + L_R * C_AR) / I_Z / vx ), 
			-(L_F * L_F * C_AF + L_R * L_R * C_AR) / I_Z / vx }
			}
		};

		array<float, 2> Bmatrix = { C_AF / MASS, L_F * C_AF / I_Z };

		for (int i = 0; i < 2; i++) {
			next_state[i] = 0;
			for (int j = 0; j < 2; j++) {
				next_state[i] += Amatrix[i][j] * states[j];
			}
			next_state[i] += Bmatrix[i] * input;
		}

		return next_state;
	}
}