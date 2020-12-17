#pragma once
#include "SupplyShip.h"
#include "DefendShip.h"
namespace MC {
	class MilShip : public DefShip, public SupShip
	{
	public:
		std::ostream& print(std::ostream& c) override;
		MilShip(DefShip sh, int weight, int coeff) :DefShip(sh), SupShip(weight,coeff) {}
		~MilShip() override {};
	};
}