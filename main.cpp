#include <iostream>
#include <chrono>

import sqrtmath;

double run_with_timer(const Math::Types& type, double x, int maxIterations) {
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < maxIterations; ++i) {
        Math::sqrt(type, x);
    }
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << "Type " << Math::EnumToString(type) << ": " << elapsed.count() << " ms\n";
    return elapsed.count();
}

bool check_input(const std::string& input) {
    try {
        std::stod(input);
        return true;
    } catch (const std::invalid_argument& e) {
        std::cout << "Invalid input\n";
        return false;
    }
}

int main() {
    int maxIterations{ 1000000 };
//    double x{ 12837.3284290217631 }; For makalah purposes only

    // I need a more robust input validation for real
    double x;
    do {
        std::string input;
        std::cout << "Enter a valid number: ";
        std::getline(std::cin >> std::ws, input);
        std::istringstream iss(input);
        iss >> x;

        if (!iss.fail()) {
            break;
        }

        std::cout << "Invalid input\n";
    } while (true);

    double control = Math::sqrt(Math::Types::NATIVE, x);

    run_with_timer(Math::Types::NATIVE, x, maxIterations);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    double bruteforce = run_with_timer(Math::Types::BRUTEFORCE, x, maxIterations);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    double babylonian = run_with_timer(Math::Types::BABYLONIAN, x, maxIterations);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    double bisection = run_with_timer(Math::Types::BISECTION, x, maxIterations);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    double assembly = run_with_timer(Math::Types::ASM, x, maxIterations);

    std::cout << std::endl;

    std::cout << "Control: " << std::setprecision(18) << control << "\n";

    double result = Math::sqrt(Math::Types::BRUTEFORCE, x);
    double diff = control - result;
    std::cout << "Brute force: " << std::setprecision(18) << result << "\n";
    std::cout << "Difference: " << std::setprecision(18) << diff << "\n";
    std::cout << "Time per iteration: " << std::setprecision(18) << bruteforce / maxIterations * 1000 << " microseconds\n\n";

    result = Math::sqrt(Math::Types::BABYLONIAN, x);
    diff = control - result;
    std::cout << "Babylonian: " << std::setprecision(18) << result << "\n";
    std::cout << "Difference: " << std::setprecision(18) << diff << "\n";
    std::cout << "Time per iteration: " << std::setprecision(18) << babylonian / maxIterations * 1000 << " microseconds\n\n";

    result = Math::sqrt(Math::Types::BISECTION, x);
    diff = control - result;
    std::cout << "Bisection: " << std::setprecision(18) << result << "\n";
    std::cout << "Difference: " << std::setprecision(18) << diff << "\n";
    std::cout << "Time per iteration: " << std::setprecision(18) << bisection / maxIterations * 1000 << " microseconds\n\n";

    result = Math::sqrt(Math::Types::ASM, x);
    diff = control - result;
    std::cout << "Assembly: " << std::setprecision(18) << result << "\n";
    std::cout << "Difference: " << std::setprecision(18) << diff << "\n";
    std::cout << "Time per iteration: " << std::setprecision(18) << assembly / maxIterations * 1000 << " microseconds\n\n";

    return 0;
}
