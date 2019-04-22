#include <iostream>


class GameObject
{
private:	
	std::string type_;
	int size_;
	int x_, y_;
	int velocity_x_, velocity_y_;
public:
	GameObject();
	GameObject(std::string type, int size, int x, int y, int velocity_x, int velocity_y);
	virtual void info() = 0;
};

class Planet : public GameObject
{
private:
	bool beautiness_;
public:
	Planet(bool beautiness, std::string type, int size, int x, int y, int velocity_x, int velocity_y);
	virtual void info() override;
};

GameObject :: GameObject() :
	type_			(nullptr),
	size_			(0),
	x_			(0),
	y_			(0),
	velocity_x_		(0),
	velocity_y_		(0)
{
	std::cout << "Default constructor made some noise!" << std::endl;
}	

GameObject :: GameObject(std::string type, int size, int x, int y, int velocity_x, int velocity_y) :
        type_			(type),
        size_               	(size),
        x_                  	(x),
        y_                 	(y),
        velocity_x_         	(velocity_x),
        velocity_y_         	(velocity_y)
{
        std::cout << "Constructor created new GameObject!" << std::endl;
	std::cout << "Params: " << type << " " << size << " " << x << " " << y << std::endl; 
}

void GameObject :: info()
{
	std::cout << "If you called this function, you are a lucky guy!" << std::endl;
}

void Planet :: info()
{
	GameObject::info();
	std::cout << "And do not forget about the beautiness of this planet!" << std::endl;

}


Planet :: Planet(bool beautiness, std::string type, int size, int x, int y, int velocity_x, int velocity_y) :
	beautiness_		(beautiness),
	GameObject		(type, size, x, y, velocity_x, velocity_y)
{
	std::cout << "Constructor creates new Earth! Look at its beautiness : ";
	std::cout << beautiness_ << " beautiness!" << std::endl;
}

int main()
{
	/*GameObject base("small", 6000, 0, 0, 0, 0);
	base.info();*/
	Planet Earth(true, "small", 6000, 0, 0, 0, 0);
	Earth.info();
	return 0;
}





