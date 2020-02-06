const double PI = 3.14;

class Shape {
	string id;

protected:
	double *size;

public:
	static int count;
	Shape(double *size) : size(size) {
		id = " " + to_string(count);
		count ++;
	}
	virtual double get_area() = 0;
	virtual string type() = 0;
	friend ostream &operator <<(ostream &out, Shape *w) {
		return out << w->type() + w->id << ": " << w->get_area();
	}
	virtual ~Shape() {}
};

class Rectangle : public Shape {
public:
	Rectangle(double *size)
		: Shape(size) {}
	virtual double get_area() { return size[0]*size[1]; }
	virtual string type() {
		return "Rectangle";
	}
	int angles() {
		return 4;
	}

	~Rectangle() {
		if (size) {
			delete[] size;
			size = nullptr;
		}
	}
};

class Square : public Rectangle {
public:
	Square(double *size)
		: Rectangle(size) {}
	virtual double get_area() { return size[0]*size[0]; }
	virtual string type() {
		return "Square";
	}

	~Square() {
		if (size) {
			delete size;
			size = nullptr;
		}
	}
};

class Circle : public Shape {
public:
	Circle(double *size)
		: Shape(size) {}
	virtual double get_area() { return PI*size[0]*size[0]; }
	virtual string type() {
		return "Circle";
	}

	~Circle() {
		if (size) {
			delete size;
			size = nullptr;
		}
	}	
};
