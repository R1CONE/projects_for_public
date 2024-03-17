class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        double Kelvin, Fahrenheit;
        Kelvin = celsius + 273.15;
        Fahrenheit = celsius * 1.80 + 32.00;
        std::vector<double> ans(2);
        ans[0] = Kelvin;
        ans[1] = Fahrenheit;
        return ans;
    }
};
