#include <stdio.h>

class Object
{
public:
	Object() 
	{ 
			x = 0, 
			y = 0, 
			z = 0; 
	}

	float getX() { return x; }
	float getY() { return y; }
	float getZ() { return z; }

	virtual void Update() {};

private:
	float x, y, z;
};

class Rides : public Object
{
public:
	Rides() 
	{
		speed = 0;
		accel = 0;

	}

	void setSpeed(float speed, float accel);
	float getSpeed() { return speed; }
	float getAccel() { return accel; }

	virtual void Update() {}

private:
	float speed, accel;
};

class Car : public Rides
{
public:

	Rides rides;
	void setSpeed(float speed, float accel) { rides.setSpeed(speed, accel); }
	void Update();
};

void Rides::setSpeed(float speed, float accel)
{
	this->speed = speed;
	this->accel = accel;
}
void Car::Update()
{
	float speed;
	speed = rides.getSpeed();
	printf("%f\n", speed);
}

int main()
{
	Car car;
	car.setSpeed(5, 1);

	for (int i = 0; i < 100; i++)
	{
		car.Update();
	}
	return 0;
}