#include <iostream>
#include <iomanip>

int main () {
    int num;
    std::cout << "Input: ";
    std::cin >> num;
    double auMile = 92955800;
    double auKm = 149598000;
    double distancek = 37.33 * auKm;
    double distancem = 37.33 * auMile;
    double secondsHour = 3600;
    double speedKM = 14.33;
    double speedMI = 8.90;
    double radioSpeed = 299792458;
    double kmOutput = distancek + (num * secondsHour * 24 * speedKM);
    double miOutput = distancem + (num * secondsHour * 24 * speedMI);
    double radioOutput = (kmOutput * 2000) / (radioSpeed * 3600);

    std::cout << std::fixed << std::setprecision(2) << kmOutput << std::endl;
    std::cout << std::fixed << std::setprecision(2) << miOutput << std::endl;
    std::cout << std::fixed << std::setprecision(2) << radioOutput << std::endl;
}