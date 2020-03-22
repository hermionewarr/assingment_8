//assignment 8 - polymorphism
//Hermione Warr 
//20/03/2020

#include<iostream>

//abstract base class
class shape {
protected:
	double dimensions{};
public:
	shape(double shape_dimensions) { dimensions = shape_dimensions; }
	virtual void info() 
	{ 
		std::cout << "shape, with dimensions: " << dimensions << std::endl; 
	}
	virtual ~shape() {}
};
//abstract derived classes
//2D
class two_D_shape: public shape
{
protected:
	double vertices{};
	std::string name{};
public:
	two_D_shape(std::string shape_name) : shape{ 2 } {
		name = shape_name;
	};
	virtual ~two_D_shape() {std::cout << "destroying 2D shape" << std::endl;}
};
//3D
class three_D_shape : public shape
{
protected:
	double vertices{};
	std::string name;
public:
	three_D_shape(std::string shape_name) :shape{ 3 } {
		name = shape_name;
	};
	virtual ~three_D_shape() { std::cout << "destroying 3D shape" << std::endl; }
};
//derived 2D shape classes
class rectangle : public two_D_shape
{
private:
	double length{};
	double width{};
public:
	rectangle(double width_input, double length_input): two_D_shape{"rectangle"}
	{
		width = width_input;
		length = length_input;
	};
	~rectangle() { std::cout << "destroying rectangle" << std::endl; }
	double rec_area() {
		double area = width * length;
		return area;
	}
	void info()
	{
		std::cout << "rectangle, area: " << (*this).rec_area() << std::endl;
	}
};

class square : public rectangle
{
private:
	double square_length{};
public:
	square(double length) : rectangle{ length, length } 
	{
		square_length = length;
	}
	~square() { std::cout << "destroying square" << std::endl; }
	double square_area() {
		double area = rec_area();
		return area;
	}
	void info()
	{
		std::cout << "square, area: " << (*this).square_area() << std::endl;
	}
};

class ellipse : public two_D_shape
{
private:
	double major_radius{};
	double minor_radius{};
public:
	ellipse(double long_radius, double short_radius) :two_D_shape{ "ellipse" } {
		major_radius = long_radius;
		minor_radius = short_radius;
	}
	~ellipse() { std::cout << "destroying ellipse" << std::endl; }
	double ellipse_area() {
		double pi = 3.14159;
		double area = pi * major_radius * minor_radius;
		return area;
	}
	void info()
	{
		std::cout << "ellipse, area: " << (*this).ellipse_area() << std::endl;
	}
};

class circle : public ellipse
{
private:
	double circle_radius{};
public:
	circle(double radius) :ellipse{ radius,radius } 
	{ 
		circle_radius = radius; 
	}
	~circle() { std::cout << "destroying circle" << std::endl; }
	double circle_area() {
		double area = ellipse_area();
		return area;
	}
	void info()
	{
		std::cout << "circle, area: " << (*this).circle_area() << std::endl;
	}
};
//3D derived classes
class cuboid : public three_D_shape
{
protected:
	double length{};
	double width{};
	double height{};
public:
	cuboid(double cuboid_length, double cuboid_width, double cuboid_height) :three_D_shape("cuboid") {
		length = cuboid_length;
		width = cuboid_width;
		height = cuboid_height;
	}
	~cuboid(){ std::cout << "destroying cuboid" << std::endl; }
	double cuboid_volume() {
		double volume = length * width * height;
		return volume;
	}
	void info() {
		std::cout << "cuboid volume: " << (*this).cuboid_volume() << std::endl;
	}
};
class cube : public cuboid
{
protected:
	double cube_length{};
public:
	cube(double length) : cuboid(length, length, length) {
		cube_length = length;
	}
	~cube() { std::cout << "destroying cube" << std::endl; }
	double cube_volume() {
		double volume = cuboid_volume();
		return volume;
	}
	void info() {
		std::cout << "cube volume: " << (*this).cube_volume() << std::endl;
	}
};
class ellipsoid : public three_D_shape
{
protected:
	double radius_1{};
	double radius_2{};
	double radius_3{};
public:
	ellipsoid(double r1, double r2, double r3) : three_D_shape{"ellipsoid"} {
		radius_1 = r1;
		radius_2 = r2;
		radius_3 = r3;
	}
	~ellipsoid(){ std::cout << "destroying ellipsoid" << std::endl; }
	double ellipsoid_volume() {
		double pi = 3.14159;
		double volume = (4 / 3) * pi * radius_1 * radius_2 * radius_3;
		return volume;
	}
	void info() {
		std::cout << "ellipsoid volume: " << (*this).ellipsoid_volume() << std::endl;
	}
};
class sphere: public ellipsoid
{
protected:
	double radius{};
public:
	sphere(double r) : ellipsoid(r,r,r) {
		radius = r;
	}
	~sphere() { std::cout << "destroying sphere" << std::endl; }
	double sphere_volume() {
		double volume = ellipsoid_volume();
		return volume;
	}
	void info() {
		std::cout << "sphere volume: " << (*this).sphere_volume() << std::endl;
	}
};

int main()
{
	shape* shape_array[8];
	shape_array[0] = new square{3};
	shape_array[1] = new rectangle{ 2,3 };
	shape_array[2] = new ellipse{ 4,5 };
	shape_array[3] = new circle{ 3 };
	shape_array[4] = new cuboid{ 1,2,3 };
	shape_array[5] = new cube{ 9 };
	shape_array[6] = new ellipsoid{ 2,3,4 };
	shape_array[7] = new sphere{ 5 };
	shape_array[0]->info();
	shape_array[1]->info();
	shape_array[2]->info();
	shape_array[3]->info();
	shape_array[4]->info();
	shape_array[5]->info();
	shape_array[6]->info();
	shape_array[7]->info();
	delete shape_array[0]; shape_array[0] = 0;
	delete shape_array[1]; shape_array[1] = 0;
	delete shape_array[2]; shape_array[2] = 0;
	delete shape_array[3]; shape_array[3] = 0;
	delete shape_array[4]; shape_array[4] = 0;
	delete shape_array[5]; shape_array[5] = 0;
	delete shape_array[6]; shape_array[6] = 0;
	delete shape_array[7]; shape_array[7] = 0;
	return 0;
}