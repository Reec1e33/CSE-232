// WRITE YOUR CODE HERE

class Temperature {
  private:
    double temp;
    char ch;
  public:
    Temperature(double temperature, char scale) : temp(temperature) , ch(scale) {}
    
  
    double AsCelsius() {
        switch (ch) {
        case 'C':
            return temp;
        case 'F':
            return (temp -32) * 5/9;
        case 'R':
            return (temp - 491.67) * 5/9;
        case 'K':
            return temp - 273.15;
        default:
            return 0;

        }
    }
    double AsFahrenheit() {
        switch (ch) {
        case 'C':
            return (temp * 9 /5) + 32;
        case 'F':
            return temp;
        case 'R':
            return temp - 459.67;
        case 'K':
            return (temp-273.15) * (9/5) + 32;
        default:
            return 0;
        }
    }
    double AsKelvin() {
        switch (ch) {
        case 'C':
            return temp +273.15;
        case 'F':
            return (temp - 32) * 5 /9;
        case 'R':
            return temp * 5/9;
        case 'K':
            return temp;
        default:
            return 0;

        }    
    }
    double AsRankine() {
        switch (ch) {
        case 'C':
            return (temp +273.15) * 9/5;
        case 'F':
            return temp + 459.67;
        case 'R':
            return temp;
        case 'K':
            return temp * 9/5;
        default:
            return 0;
        }
    }
};