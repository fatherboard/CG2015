class Vector3
{
protected:
	double _x;
	double _y;
	double _z;

public:
	Vector3(void);
	Vector3(double x, double y, double z);
	~Vector3(void);
	double getX();
	double getY();
	double getZ();
	void set(double x, double y, double z);
	Vector3 operator=(Vector3 const vec);
	Vector3 operator*(double num);
	Vector3 operator+(Vector3 const vec);
	Vector3 operator-(Vector3 const vec);
};

