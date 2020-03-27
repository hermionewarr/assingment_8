//assignment 8 - polymorphism
//Hermione Warr 
//20/03/2020

#include<iostream>
double pi = 3.14159;
//abstract base class
class shape {
protected:
	double dimensions{};
public:
	shape(double shape_dimensions) { dimensions = shape_dimensions;}
	virtual ~shape() { std::cout << "destroying shape" << std::endl; }
	virtual double area() {return 0;}
	virtual double volume() {return 0;}
	virtual void info()
	{
		std::cout << "shape, with dimensions: " << dimensions << std::endl;
	}
};
//abstract derived classes
//2D
class two_D_shape: public shape
{
protected:
	double vertices{};
public:
	two_D_shape(double corners) : shape{ 2 } { vertices = corners; }
	virtual ~two_D_shape() {std::cout << "destroying 2D shape" << std::endl;}
	virtual two_D_shape* duplicate() { return 0; };
	virtual double perimeter() { return 0; }
	virtual void info() 
	{ 
		std::cout << "2D shape with " << vertices << " corners." << std::endl; 
	}
};
//3D
class three_D_shape : public shape
{
protected:
	double vertices{};
public:
	three_D_shape(double corners) :shape{ 3 } {vertices = corners;}
	virtual ~three_D_shape() { std::cout << "destroying 3D shape" << std::endl; }
	virtual double suface_area() { return 0; };
	virtual void info() 
	{
		std::cout << "3D shape with " << vertices << " corners." << std::endl;
	}
};
//derived 2D shape classes
class rectangle : public two_D_shape
{
private:
	double length{};
	double width{};
public:
	rectangle(double width_input, double length_input): two_D_shape{4}
	{
		width = width_input;
		length = length_input;
	};
	~rectangle() { std::cout << "destroying rectangle" << std::endl; }
	double area() 
	{
		double rec_area = width * length;
		return rec_area;
	}
	double perimeter() 
	{
		double rec_perimeter = 2 * (length + width);
		return rec_perimeter;
	}
	two_D_shape* duplicate() 
	{
		return new rectangle(width, length);
	}
	void info()
	{
		std::cout << "rectangle, area: " << area() << std::endl;
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
	void info()
	{
		std::cout << "square, area: " << area() << std::endl;
	}
};
class ellipse : public two_D_shape
{
private:
	double major_radius{};
	double minor_radius{};
public:
	ellipse(double long_radius, double short_radius) :two_D_shape{0} 
	{
		major_radius = long_radius;
		minor_radius = short_radius;
	}
	~ellipse() { std::cout << "destroying ellipse" << std::endl; }
	double area() 
	{
		double pi = 3.14159;
		double ellipse_area = pi * major_radius * minor_radius;
		return ellipse_area;
	}
	double perimeter() 
	{
		//Ramanujan's approximation
		double h = pow(major_radius - minor_radius, 2) / pow(major_radius + minor_radius, 2);
		double ellipse_perimeter = pi * (major_radius + minor_radius) * (1 + (3 * h) / (10 + sqrt(4 - 3 * h)));
		return ellipse_perimeter;
	}
	two_D_shape* duplicate() 
	{
		return new ellipse(major_radius, minor_radius);
	}
	void info()
	{
		std::cout << "ellipse, area: " << area() << std::endl;
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
	double perimeter() 
	{
		double circle_perimeter = 2 * pi * (circle_radius);
		return circle_perimeter;
	}
	~circle() { std::cout << "destroying circle" << std::endl; }
	void info()
	{
		std::cout << "circle, area: " << area() << std::endl;
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
	cuboid(double cuboid_length, double cuboid_width, double cuboid_height) :three_D_shape(8) 
	{
		length = cuboid_length;
		width = cuboid_width;
		height = cuboid_height;
	}
	~cuboid(){ std::cout << "destroying cuboid" << std::endl; }
	double volume() 
	{
		double cuboid_volume = length * width * height;
		return cuboid_volume;
	}
	double surface_area() 
	{
		double cuboid_SA = 2*(length * width + length * height + height * width);
		return cuboid_SA;
	}
	void info() 
	{
		std::cout << "cuboid, volume: " << volume() << std::endl;
		std::cout << "cuboid, surface area: " << surface_area() << std::endl;
	}
};
class cube : public cuboid
{
protected:
	double cube_length{};
public:
	cube(double length) : cuboid(length, length, length) 
	{
		cube_length = length;
	}
	~cube() { std::cout << "destroying cube" << std::endl; }
	void info() 
	{
		std::cout << "cube, volume: " << volume() << std::endl;
		std::cout << "cube, surface area: " << surface_area() << std::endl;
	}
};
class ellipsoid : public three_D_shape
{
protected:
	double radius_1{};
	double radius_2{};
	double radius_3{};
	double p{ 1.6075 };
public:
	ellipsoid(double r1, double r2, double r3) : three_D_shape{0} 
	{
		radius_1 = r1;
		radius_2 = r2;
		radius_3 = r3;
	}
	~ellipsoid(){ std::cout << "destroying ellipsoid" << std::endl; }
	double volume() 
	{
		double pi = 3.14159;
		double ellipsoid_volume = (4 / 3) * pi * radius_1 * radius_2 * radius_3;
		return ellipsoid_volume;
	}
	double surface_area() 
	{
		//Knud Thomsen's formula
		double knud_ellipsoid_sa = 4 * pi * pow((pow(radius_1,p) * pow(radius_2, p) + pow(radius_1, p)* pow(radius_3, p) + pow(radius_2, p)* pow(radius_3, p)) / 3, 1/p);
		return knud_ellipsoid_sa;
	}
	void info() 
	{
		std::cout << "ellipsoid, volume: " << volume() << std::endl;
		std::cout << "ellipsoid, surface area: " << surface_area() << std::endl;
	}
};
class sphere: public ellipsoid
{
protected:
	double radius{};
public:
	sphere(double r) : ellipsoid(r,r,r) 
	{
		radius = r;
	}
	~sphere() { std::cout << "destroying sphere" << std::endl; }
	double surface_area() 
	{
		double sphere_sa = (4 / 3) * pi * pow(radius, 3);
		return sphere_sa;
	}
	void info() 
	{
		std::cout << "sphere, volume: " << volume() << std::endl;
		std::cout << "sphere, surface area: " << surface_area() << std::endl;
	}
};
class prism : public three_D_shape
{
protected:
	two_D_shape* prism_base{};
	double prism_depth{};
	double corners{};
public:
	prism(two_D_shape& base, double depth) : three_D_shape(corners)
	{
		prism_base = base.duplicate();
		prism_depth = depth;
	}
	~prism() { std::cout << "destroying prism" << std::endl; }
	double volume() 
	{
		double prism_volume = prism_base->area() * prism_depth;
		return prism_volume;
	}
	double surface_area() 
	{
		double prism_sa = 2 * (prism_base->area()) + prism_depth * (prism_base->perimeter());
		return prism_sa;
	}
	void info() 
	{
		std::cout << "prism, base area: "<< prism_base->area() << "\nprism, volume: " << volume() << std::endl;
		std::cout << "prism, surface area: " << surface_area() << std::endl;
	}
};

int main()
{
	shape **shape_array = new shape*[11];
	shape_array[0] = new rectangle{ 2,3 };
	shape_array[1] = new square{3};
	shape_array[2] = new ellipse{ 4,5 };
	shape_array[3] = new circle{ 3 };
	shape_array[4] = new cuboid{ 1,2,3 };
	shape_array[5] = new cube{ 9 };
	shape_array[6] = new ellipsoid{ 2,3,4 };
	shape_array[7] = new sphere{ 5 };
	square prism_base1(4);
	shape_array[8] = new prism{ prism_base1,2 };
	circle prism_base2(2);
	shape_array[9] = new prism{ prism_base2,4 };
	ellipse prism_base3(1, 2);
	shape_array[10] = new prism{ prism_base3,3 };
	shape_array[0]->info();
	shape_array[1]->info();
	shape_array[2]->info();
	shape_array[3]->info();
	shape_array[4]->info();
	shape_array[5]->info();
	shape_array[6]->info();
	shape_array[7]->info();
	shape_array[8]->info();
	shape_array[9]->info();
	shape_array[10]->info();
	delete shape_array[0]; shape_array[0] = 0;
	delete shape_array[1]; shape_array[1] = 0;
	delete shape_array[2]; shape_array[2] = 0;
	delete shape_array[3]; shape_array[3] = 0;
	delete shape_array[4]; shape_array[4] = 0;
	delete shape_array[5]; shape_array[5] = 0;
	delete shape_array[6]; shape_array[6] = 0;
	delete shape_array[7]; shape_array[7] = 0;
	delete shape_array[8]; shape_array[8] = 0;
	delete shape_array[9]; shape_array[9] = 0;
	delete shape_array[9]; shape_array[9] = 0;
	return 0;
}