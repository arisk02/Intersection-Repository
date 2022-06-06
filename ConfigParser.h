#ifndef __CONFIG_PARSER_H__
#define __CONFIG_PARSER_H__

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

// author: Aris Karamustafic
// author: Hyewon Hong

using namespace std;

class ConfigParser
{
    private:
    //read from file datafields.
        int maximum_simulated_time;
        int number_of_sections_before_intersection;
        int green_north_south;
        int yellow_north_south;
        int green_east_west;
        int yellow_east_west;
        float prob_new_vehicle_northbound;
        float prob_new_vehicle_southbound;
        float prob_new_vehicle_eastbound;
        float prob_new_vehicle_westbound;
        float proportion_of_cars;
        float proportion_of_SUVs;
        float proportion_right_turn_cars;
        float proportion_left_turn_cars;
        float proportion_right_turn_SUVs;
        float proportion_left_turn_SUVs;
        float proportion_right_turn_trucks;
        float proportion_left_turn_trucks;

    //calculated datafields
        int red_east_west;
        int red_north_south;
        float proportion_of_trucks;

    public:

        ConfigParser(string filePath);
        ConfigParser(const ConfigParser& other);
        ConfigParser& operator=(const ConfigParser& other);
        ConfigParser(ConfigParser&& other) noexcept;
        ConfigParser& operator=(ConfigParser&& other) noexcept;
        ~ConfigParser();


        void configParser(string filePath);

        int get_maximum_simulated_time();
        int get_number_of_sections_before_intersection();
        int get_green_north_south();
        int get_yellow_north_south();
        int get_green_east_west();
        int get_yellow_east_west();
        float get_prob_new_vehicle_northbound();
        float get_prob_new_vehicle_southbound();
        float get_prob_new_vehicle_eastbound();
        float get_prob_new_vehicle_westbound();
        float get_proportion_of_cars();
        float get_proportion_of_SUVs();
        float get_proportion_right_turn_cars();
        float get_proportion_left_turn_cars();
        float get_proportion_right_turn_SUVs();
        float get_proportion_left_turn_SUVs();
        float get_proportion_right_turn_trucks();
        float get_proportion_left_turn_trucks();
        int get_red_east_west();
        int get_red_north_south();
        float get_proportion_of_trucks();

};

#endif