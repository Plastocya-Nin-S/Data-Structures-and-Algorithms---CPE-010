#include <iostream>
#include <vector> // for using std::vector (list of numbers)
#include <cmath> // for sqrt and pow
#include <string>
#include <algorithm> // for swap

// ===== No 1: Swap Elements =====
// Function to input a list of numbers
void inputList(std::vector<int> &nums, int size) {
    std::cout << "\nEnter " << size << " numbers:\n";
    for (int i = 0; i < size; i++) {
        std::cout << "Number " << i << ": ";
        std::cin >> nums[i];
    }
}

// Function to display a list of numbers
void displayList(const std::vector<int> &nums, std::string message) {
    std::cout << "\n" << message << ": ";
    for (int num : nums) std::cout << num << " ";
    std::cout << std::endl;
}

// Function to swap two elements in a list
void swapElements(std::vector<int> &nums, int index1, int index2) {
    if (index1 >= 0 && index1 < nums.size() && index2 >= 0 && index2 < nums.size()) {
        std::swap(nums[index1], nums[index2]);
    } else {
        std::cout << "Invalid indices for swapping!" << std::endl;
    }
}

// ===== No 2: Kelvin to Fahrenheit =====
// Function to convert Kelvin to Fahrenheit
double kelvinToFahrenheit(double kelvin) {
    return (kelvin - 273.15) * 9.0 / 5.0 + 32.0;
}

// ===== No 3: Distance Between Two Points =====
// Function to calculate distance between two points (x1, y1) and (x2, y2)
double calculateDistance(double x1, double y1, double x2, double y2) {
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

// ===== No 4: Extended Triangle Class =====
// Triangle class with perimeter, area, and classification methods
class Triangle {
private:
    double sideA, sideB, sideC;
public:
    Triangle(double a, double b, double c) {
        sideA = a; sideB = b; sideC = c;
    }

    // Function to validate if the sides can form a triangle
    bool validateTriangle() {
        return (sideA + sideB > sideC &&
                sideA + sideC > sideB &&
                sideB + sideC > sideA);
    }

    // Function to compute the perimeter of the triangle
    double computePerimeter() {
        return sideA + sideB + sideC;
    }

    // Function to compute the area of the triangle using Heron's formula
    double computeArea() {
        double s = computePerimeter() / 2.0;
        return std::sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
    }

    // Function to classify the triangle based on its angles
    std::string classifyTriangle() {
        double a = sideA, b = sideB, c = sideC;
        if (a > b) std::swap(a, b);
        if (b > c) std::swap(b, c);
        if (a > b) std::swap(a, b);

        double lhs = a*a + b*b;
        double rhs = c*c;

        if (fabs(lhs - rhs) < 1e-9) return "Right-angled";
        else if (lhs > rhs) return "Acute-angled";
        else return "Obtuse-angled";
    }
};

// ===== Main Menu =====
int main() {
    int choice;
    do {
        std::cout << "\n========= Supplementary Activity Menu =========\n";
        std::cout << "1. Swap Elements in a List\n";
        std::cout << "2. Convert Kelvin to Fahrenheit\n";
        std::cout << "3. Calculate Distance Between Two Points\n";
        std::cout << "4. Triangle Calculations (Perimeter, Area, Classification)\n";
        std::cout << "0. Exit\n";
        std::cout << "===============================================\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch(choice) {
            case 1: {
                int size;
                std::cout << "===============================================\n";
                std::cout << "Enter how many numbers you want in the list: ";
                std::cin >> size;
                std::vector<int> numbers(size);
                inputList(numbers, size);
                displayList(numbers, "Before swapping");

                int pos1, pos2;
                std::cout << "Enter first position to swap (0-based index): ";
                std::cin >> pos1;
                std::cout << "Enter second position to swap (0-based index): ";
                std::cin >> pos2;

                swapElements(numbers, pos1, pos2);
                displayList(numbers, "After swapping");
                break;
            }
            case 2: {
                double kelvin;
                std::cout << "===============================================\n";
                std::cout << "Enter temperature in Kelvin: ";
                std::cin >> kelvin;
                if (kelvin < 0) {
                    std::cout << "Invalid input! Kelvin cannot be negative.\n";
                } else {
                    double fahrenheit = kelvinToFahrenheit(kelvin);
                    std::cout << kelvin << " K = " << fahrenheit << " F\n";
                }
                break;
            }
            case 3: {
                double x1, y1, x2, y2;
                std::cout << "===============================================\n";
                std::cout << "Enter x1: "; std::cin >> x1;
                std::cout << "Enter y1: "; std::cin >> y1;
                std::cout << "Enter x2: "; std::cin >> x2;
                std::cout << "Enter y2: "; std::cin >> y2;

                double distance = calculateDistance(x1, y1, x2, y2);
                std::cout << "The distance between (" << x1 << ", " << y1 << ") and ("
                          << x2 << ", " << y2 << ") is: " << distance << std::endl;
                break;
            }
            case 4: {
                double a, b, c;
                std::cout << "===============================================\n";
                std::cout << "Enter side A: "; std::cin >> a;
                std::cout << "Enter side B: "; std::cin >> b;
                std::cout << "Enter side C: "; std::cin >> c;

                Triangle tri(a, b, c);
                if (tri.validateTriangle()) {
                    std::cout << "The shape is a valid triangle.\n";
                    std::cout << "Perimeter: " << tri.computePerimeter() << std::endl;
                    std::cout << "Area: " << tri.computeArea() << std::endl;
                    std::cout << "Classification: " << tri.classifyTriangle() << std::endl;
                } else {
                    std::cout << "The shape is NOT a valid triangle.\n";
                }
                break;
            }
            case 0:
                std::cout << "Program Ended. Thank You!\n";
                break;
            default:
                std::cout << "Invalid choice! Try again.\n";
        }
    } while(choice != 0);

    return 0;
}

