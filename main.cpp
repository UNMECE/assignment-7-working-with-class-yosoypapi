#include <iostream>
#include <cmath>

class Electric_Field {
private:
    double *E;

public:
    Electric_Field() {
        E = new double[3];
        E[0] = 0.0;
        E[1] = 0.0;
        E[2] = 0.0;
    }

    Electric_Field(double x, double y, double z) {
        E = new double[3];  
        E[0] = x;
        E[1] = y;
        E[2] = z;
    }

    ~Electric_Field() {
        delete[] E;
    }

    double calculateMagnitude() {
        return std::sqrt(E[0] * E[0] + E[1] * E[1] + E[2] * E[2]);
    }

    double getX() { return E[0]; }
    double getY() { return E[1]; }
    double getZ() { return E[2]; }

    void setX(double x) { E[0] = x; }
    void setY(double y) { E[1] = y; }
    void setZ(double z) { E[2] = z; }

    double innerProduct(Electric_Field &other) {
        return E[0] * other.getX() + E[1] * other.getY() + E[2] * other.getZ();
    }
};

class Magnetic_Field {
private:
    double *B;

public:
    Magnetic_Field() {
        B = new double[3];
        B[0] = 0.0;
        B[1] = 0.0;
        B[2] = 0.0;
    }

    Magnetic_Field(double x, double y, double z) {
        B = new double[3];
        B[0] = x;
        B[1] = y;
        B[2] = z;
    }

    ~Magnetic_Field() {
        delete[] B;
    }

    double calculateMagnitude() {
        return std::sqrt(B[0] * B[0] + B[1] * B[1] + B[2] * B[2]);
    }

    void calculateUnitVector() {
        double mag = calculateMagnitude();
        if (mag != 0) {
            std::cout << "Unit Vector: (" << B[0] / mag << ", " << B[1] / mag << ", " << B[2] / mag << ")\n";
        } else {
            std::cout << "Unit Vector: (0, 0, 0) (Zero magnitude)\n";
        }
    }
};

int main() {
    Electric_Field E1;
    Electric_Field E2(1e5, 10.9, 1.7e2); 

    Magnetic_Field B1; 
    Magnetic_Field B2(2.5, 1.2, 0.8);

    std::cout << "Electric Field Magnitude: " << E2.calculateMagnitude() << "\n";
    std::cout << "Magnetic Field Magnitude: " << B2.calculateMagnitude() << "\n";

    std::cout << "Inner Product of Electric Fields: " << E1.innerProduct(E2) << "\n";

    B2.calculateUnitVector();

    return 0;
}