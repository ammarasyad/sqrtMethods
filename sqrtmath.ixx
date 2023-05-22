export module sqrtmath;

export import <stdexcept>;
export import <cmath>;

// Complexity: O(n)
double bruteForceSqrt(double x) {
    int closest { 0 };

    const int maxIterations { 10 }; // 10 digits of precision

    for (int i = 1; i <= x; ++i) {
        if (i * i > x) {
            closest = i - 1;
            break;
        }
    }

    if (closest * closest == x) {
        return closest;
    }

    double result { static_cast<double>(closest) };
    double step { 0.1 };
    for (int i = 0; i < maxIterations; i++) {
        while (result * result <= x) {
            result += step;
        }

        result -= step;
        step /= 10;
    }

    return result;
}

// Complexity: O(log log n/m)
double babylonianSqrt(double x) {
    double result { x };
    const double accuracy { 0.0001 };
    while (std::abs(result * result - x) > accuracy) {
        result = (result + x / result) / 2;
    }

    return result;
}

// Complexity: O(log n)
double bisectionMethod(double x) {
    double left { 0 };
    double right { x };
    double mid { (left + right) / 2 };

    const double accuracy { 1e-9 };

    while (std::abs(mid * mid - x) > accuracy) {
        if (mid * mid > x) {
            right = mid;
        } else {
            left = mid;
        }
        mid = (left + right) / 2;
    }

    return mid;
}

// Complexity: O(1)
extern "C" double asmSqrt(double);

export namespace Math {
    enum class Types { NATIVE, BRUTEFORCE, BABYLONIAN, BISECTION, ASM };

    inline const char* EnumToString(const Types& type) {
        switch (type) {
            case Types::NATIVE:
                return "NATIVE";
            case Types::BRUTEFORCE:
                return "BRUTEFORCE";
            case Types::BABYLONIAN:
                return "BABYLONIAN";
            case Types::BISECTION:
                return "BISECTION";
            case Types::ASM:
                return "ASM";
        }
        return "Unknown";
    }

    double sqrt(const Types& type, double x) {
        if (x < 0) {
            throw std::domain_error{ "Negative argument for sqrt is unsupported" };
        }

        switch (type) {
            case Math::Types::NATIVE:
                return std::sqrt(x); // Complexity: O(1)
            case Math::Types::BRUTEFORCE:
                return bruteForceSqrt(x);
            case Math::Types::BABYLONIAN:
                return babylonianSqrt(x);
            case Math::Types::BISECTION:
                return bisectionMethod(x);
            case Math::Types::ASM:
                return asmSqrt(x);
        }
        throw std::runtime_error("Unknown type");
    }
}