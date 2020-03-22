//assignment 8 - polymorphism
//Hermione Warr 
//20/03/2020

#include<iostream>

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

class two_D_shape: public shape
{
protected:
	double vertices{};
	std::string name{};
public:
	two_D_shape(std::string shape_name) : shape{ 2 } {
		name = shape_name;
	};
	virtual ~two_D_shape() {}
};
template <class T> class dericed_two_d_shape: two_D_shape {

};

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
	~rectangle() {}
	double rec_area() {
		double area = width * length;
		return area;
	}
};

class square : public rectangle
{
private:
	double length{};
public:
	square(double length) :rectangle{ length, length } {};
	~square() { std::cout << "destroying square" << std::endl; }
	double square_area() {
		double area = pow(length, 2);
		return area;
	}
};

class ellipse : public two_D_shape
{
private:
	double long_radius{};
	double short_radius{};
public:
	ellipse(double l_radius, double s_radius) :two_D_shape{ "ellipse" } {
		long_radius = l_radius;
		short_radius = s_radius;
	}
	~ellipse() { std::cout << "destroying ellipse" << std::endl; }
};

class circle : public ellipse
{
private:
	double radius{};
public:
	circle():ellipse{ radius,radius }{}
	~circle() { std::cout << "destroying circle" << std::endl; }
	double circle_area() {
		double pi = 3.14159;
		double area = pi*pow(radius, 2);
		return area;
	}
};

class three_D_shape : public shape 
{
protected:
	double vertices{};
public:
	three_D_shape():shape{ 3 } {};
	virtual ~three_D_shape() {}
};

int main()
{
	shape* shape_array[3];
	shape_array[0] = new shape{ 2 };
	shape_array[1] = new two_D_shape{ "rectangle" };
	shape_array[2] = new square{3};
	shape_array[0]->info();
	delete shape_array[0]; shape_array[0] = 0;
	return 0;
}