//This program is made for a competition run by Queen Guinevere Bakeries and will allow the contestants to put their recipe measurements for bread recipes.

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    const int MIN_PER_HR = 60; // minutes in 1 hour
    const float KG_PER_CUP_FLOUR = 0.125; // 1 cup of flour  =  0.125 kilograms of flour
    const float GM_PER_CUP_WATER = 240;   // 1 cup of water = 240 grams of water
    const float LOAF_DISCOUNT = 0.25; // discount for an entire loaf is 25%
    float discount;
    string recipe_name;
    int slice_amount;
    float flour_cups;
    float flour_kg;
    float sugar_tsp;
    float salt_tsp;
    float yeast_tsp;
    float water_cups;
    float water_gr;
    float oil_tbs;
    int baking_time_min;
    int hours;
    int minutes;
    int temperature_f;
    int temperature_c;
    float price_per_slice;
    float price_per_loaf; //price of the whole loaf after discount
    string summarize;
    
    cout << "Please input the information about your bread recipe." << endl;
    cout << "Name of your recipe: ";
    getline(cin, recipe_name);
    cout << "Number of servings: ";
    cin >> slice_amount;
    
    cout << "Cups flour: ";
    cin >> flour_cups;
    flour_kg = flour_cups * KG_PER_CUP_FLOUR; // changing cups to kilograms
    
    cout << "Teaspoons of sugar: ";
    cin >> sugar_tsp;
    cout << "Teaspoons of salt: ";
    cin >> salt_tsp;
    cout << "Teaspoons of yeast: ";
    cin >> yeast_tsp;
    cout << "Cups water: ";
    cin >> water_cups;
    water_gr = water_cups * GM_PER_CUP_WATER; // changing cups to grams
    
    cout << "Tablespoons of oil: ";
    cin >> oil_tbs;
 
    cout << "Baking time in minutes: ";
    cin >> baking_time_min;
    hours = baking_time_min / MIN_PER_HR; // changing minutes to full hours
    minutes = baking_time_min % MIN_PER_HR; // counting the remaining minutes
 
    cout << "Baking Temperature (F): ";
    cin >> temperature_f;
    temperature_c = (temperature_f - 32)/ 1.8; // Fahrenheit to Celsius Conversion Formula
    cin.ignore();
    
    cout << "Summarize Instructions: ";
    getline(cin, summarize);
    
    cout << "Enter a suggested price per serving: ";
    cin >> price_per_slice;
    discount = (price_per_slice * slice_amount) * LOAF_DISCOUNT; // counting the amount of discount
    price_per_loaf = (price_per_slice * slice_amount) - discount; // counting the price of the loaf after discount
    cout << endl;
    cout << endl;
    
    cout << "--- " << recipe_name << " Recipe" " ---" << endl;
    cout << "Yields " << slice_amount << " servings" << endl;
    cout << "--- Ingredients ---" << endl;
    cout << flour_cups << " cups flour (" << flour_kg << "kg flour)" << endl;
    cout << sugar_tsp << " tsp sugar" << endl;
    cout << salt_tsp << " tsp salt" << endl;
    cout << yeast_tsp << " tsp yeast" << endl;
    cout << water_cups << " cups water (" << water_gr << "g water)" << endl;
    cout << oil_tbs << " tbsp oil" << endl;
    cout << "--- Instructions ---" << endl;
    cout << summarize << endl;
    cout << "Bake at " << temperature_f << " F (" << temperature_c << " C) for " << baking_time_min << " minutes (" << hours << " hr " << minutes << " min)" << endl;
    cout << "If selected, slices will sell in the bakery for $" << setprecision(2) << fixed << showpoint << price_per_slice << endl; // setting up the decimal point to 2 for price
    cout << "Each loaf will sell for $" << setprecision(2) << fixed << showpoint << price_per_loaf << endl; //setting up the decimal point to 2 for price
    
    return 0;
}
