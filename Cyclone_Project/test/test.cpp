#include "pch.h"
#include "../Cyclone_Library/core.h"
#include "../Cyclone_Library/particle.h"

TEST(core, TestMagni) {
	cyclone::Vector3 vector{ 3, 4, 12 };

	EXPECT_EQ(vector.magnitude(), 13);
}

TEST(core, TestNormalise) {
	cyclone::Vector3 vector{ 0, 3, 4 };
	vector.normalise();

	EXPECT_EQ(vector.x, 0);
	EXPECT_EQ(vector.y, 0.6);
	EXPECT_EQ(vector.z, 0.8);
}

TEST(core, TestScalar) {
	cyclone::Vector3 vector{ 1, 2, 3 };
	cyclone::Vector3 vec{ -2, 5, 4 };

	EXPECT_EQ(vector.scalarProduct(vec), 20);
}

TEST(core, TestScale) {
	cyclone::Vector3 vector{ 1, 2, 3 };
	cyclone::Vector3 vec{ 2, -1, 4 };
	vector.addScaledVector(vec, 0.5);

	EXPECT_EQ(vector.x, 2);
	EXPECT_EQ(vector.y, 1.5);
	EXPECT_EQ(vector.z, 5);
}

TEST(particle, TestIntegrate) {
	cyclone::Particle particle;
	particle.setPosition(cyclone::Vector3{ 0, 0, 0 });
	particle.setVelocity(cyclone::Vector3{ 2, 0, 0 });
	particle.setAcceleration(cyclone::Vector3{ 0, 0, 0 });
	particle.setDamping(1);
	particle.setMass(1);
	particle.integrate(0.5);

	cyclone::Vector3 vecPos;
	vecPos.x = particle.getPosition().x;
	vecPos.y = particle.getPosition().y;
	vecPos.z = particle.getPosition().z;

	cyclone::Vector3 vecVelo;
	vecVelo.x = particle.getVelocity().x;
	vecVelo.y = particle.getVelocity().y;
	vecVelo.z = particle.getVelocity().z;

	EXPECT_EQ(vecPos.x, 1);
	EXPECT_EQ(vecVelo.x, 2);

}