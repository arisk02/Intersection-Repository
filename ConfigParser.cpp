#ifndef __CONFIG_PARSER_CPP__
#define __CONFIG_PARSER_CPP__
#include "ConfigParser.h"

// author: Aris Karamustafic
// author: Hyewon Hong

    ConfigParser::ConfigParser(string filePath)
    {
        configParser(filePath);
    }

    ConfigParser::ConfigParser(const ConfigParser& other)
    {
        maximum_simulated_time = other.maximum_simulated_time;
        number_of_sections_before_intersection = other.number_of_sections_before_intersection;
        green_north_south = other.green_north_south;
        yellow_north_south = other.yellow_north_south;
        green_east_west = other.green_east_west;
        yellow_east_west = other.yellow_east_west;
        prob_new_vehicle_northbound = other.prob_new_vehicle_northbound;
        prob_new_vehicle_southbound = other.prob_new_vehicle_southbound;
        prob_new_vehicle_eastbound = other.prob_new_vehicle_eastbound;
        prob_new_vehicle_westbound = other.prob_new_vehicle_westbound;
        proportion_of_cars = other.proportion_of_cars;
        proportion_of_SUVs = other.proportion_of_SUVs;
        proportion_right_turn_cars = other.proportion_right_turn_cars;
        proportion_left_turn_cars = other.proportion_left_turn_cars;
        proportion_right_turn_SUVs = other.proportion_right_turn_SUVs;
        proportion_left_turn_SUVs = other.proportion_left_turn_SUVs;
        proportion_right_turn_trucks = other.proportion_right_turn_trucks;
        proportion_left_turn_trucks = other.proportion_left_turn_trucks;
        red_east_west = other.red_east_west;
        red_north_south = other.red_north_south;
        proportion_of_trucks = other.proportion_of_trucks;
    }

    ConfigParser& ConfigParser::operator=(const ConfigParser& other)
    {
        if (this == &other)
        {
            return *this;
        }

        maximum_simulated_time = other.maximum_simulated_time;
        number_of_sections_before_intersection = other.number_of_sections_before_intersection;
        green_north_south = other.green_north_south;
        yellow_north_south = other.yellow_north_south;
        green_east_west = other.green_east_west;
        yellow_east_west = other.yellow_east_west;
        prob_new_vehicle_northbound = other.prob_new_vehicle_northbound;
        prob_new_vehicle_southbound = other.prob_new_vehicle_southbound;
        prob_new_vehicle_eastbound = other.prob_new_vehicle_eastbound;
        prob_new_vehicle_westbound = other.prob_new_vehicle_westbound;
        proportion_of_cars = other.proportion_of_cars;
        proportion_of_SUVs = other.proportion_of_SUVs;
        proportion_right_turn_cars = other.proportion_right_turn_cars;
        proportion_left_turn_cars = other.proportion_left_turn_cars;
        proportion_right_turn_SUVs = other.proportion_right_turn_SUVs;
        proportion_left_turn_SUVs = other.proportion_left_turn_SUVs;
        proportion_right_turn_trucks = other.proportion_right_turn_trucks;
        proportion_left_turn_trucks = other.proportion_left_turn_trucks;
        red_east_west = other.red_east_west;
        red_north_south = other.red_north_south;
        proportion_of_trucks = other.proportion_of_trucks;

        return *this;
    }

    ConfigParser::ConfigParser(ConfigParser&& other) noexcept
    {
        maximum_simulated_time = other.maximum_simulated_time;
        number_of_sections_before_intersection = other.number_of_sections_before_intersection;
        green_north_south = other.green_north_south;
        yellow_north_south = other.yellow_north_south;
        green_east_west = other.green_east_west;
        yellow_east_west = other.yellow_east_west;
        prob_new_vehicle_northbound = other.prob_new_vehicle_northbound;
        prob_new_vehicle_southbound = other.prob_new_vehicle_southbound;
        prob_new_vehicle_eastbound = other.prob_new_vehicle_eastbound;
        prob_new_vehicle_westbound = other.prob_new_vehicle_westbound;
        proportion_of_cars = other.proportion_of_cars;
        proportion_of_SUVs = other.proportion_of_SUVs;
        proportion_right_turn_cars = other.proportion_right_turn_cars;
        proportion_left_turn_cars = other.proportion_left_turn_cars;
        proportion_right_turn_SUVs = other.proportion_right_turn_SUVs;
        proportion_left_turn_SUVs = other.proportion_left_turn_SUVs;
        proportion_right_turn_trucks = other.proportion_right_turn_trucks;
        proportion_left_turn_trucks = other.proportion_left_turn_trucks;
        red_east_west = other.red_east_west;
        red_north_south = other.red_north_south;
        proportion_of_trucks = other.proportion_of_trucks;

        other.maximum_simulated_time = 0;
        other.number_of_sections_before_intersection = 0;
        other.green_north_south = 0;
        other.yellow_north_south = 0;
        other.green_east_west = 0;
        other.yellow_east_west = 0;
        other.prob_new_vehicle_northbound = 0;
        other.prob_new_vehicle_southbound = 0;
        other.prob_new_vehicle_eastbound = 0;
        other.prob_new_vehicle_westbound = 0;
        other.proportion_of_cars = 0;
        other.proportion_of_SUVs = 0;
        other.proportion_right_turn_cars = 0;
        other.proportion_left_turn_cars = 0;
        other.proportion_right_turn_SUVs = 0;
        other.proportion_left_turn_SUVs = 0;
        other.proportion_right_turn_trucks = 0;
        other.proportion_left_turn_trucks = 0;
        other.red_east_west = 0;
        other.red_north_south = 0;
        other.proportion_of_trucks = 0;
    }

    ConfigParser& ConfigParser::operator=(ConfigParser&& other) noexcept
    {
        if (this == &other)
        {
            return *this;
        }

        maximum_simulated_time = other.maximum_simulated_time;
        number_of_sections_before_intersection = other.number_of_sections_before_intersection;
        green_north_south = other.green_north_south;
        yellow_north_south = other.yellow_north_south;
        green_east_west = other.green_east_west;
        yellow_east_west = other.yellow_east_west;
        prob_new_vehicle_northbound = other.prob_new_vehicle_northbound;
        prob_new_vehicle_southbound = other.prob_new_vehicle_southbound;
        prob_new_vehicle_eastbound = other.prob_new_vehicle_eastbound;
        prob_new_vehicle_westbound = other.prob_new_vehicle_westbound;
        proportion_of_cars = other.proportion_of_cars;
        proportion_of_SUVs = other.proportion_of_SUVs;
        proportion_right_turn_cars = other.proportion_right_turn_cars;
        proportion_left_turn_cars = other.proportion_left_turn_cars;
        proportion_right_turn_SUVs = other.proportion_right_turn_SUVs;
        proportion_left_turn_SUVs = other.proportion_left_turn_SUVs;
        proportion_right_turn_trucks = other.proportion_right_turn_trucks;
        proportion_left_turn_trucks = other.proportion_left_turn_trucks;
        red_east_west = other.red_east_west;
        red_north_south = other.red_north_south;
        proportion_of_trucks = other.proportion_of_trucks;

        other.maximum_simulated_time = 0;
        other.number_of_sections_before_intersection = 0;
        other.green_north_south = 0;
        other.yellow_north_south = 0;
        other.green_east_west = 0;
        other.yellow_east_west = 0;
        other.prob_new_vehicle_northbound = 0;
        other.prob_new_vehicle_southbound = 0;
        other.prob_new_vehicle_eastbound = 0;
        other.prob_new_vehicle_westbound = 0;
        other.proportion_of_cars = 0;
        other.proportion_of_SUVs = 0;
        other.proportion_right_turn_cars = 0;
        other.proportion_left_turn_cars = 0;
        other.proportion_right_turn_SUVs = 0;
        other.proportion_left_turn_SUVs = 0;
        other.proportion_right_turn_trucks = 0;
        other.proportion_left_turn_trucks = 0;
        other.red_east_west = 0;
        other.red_north_south = 0;
        other.proportion_of_trucks = 0;

        return *this;
    }

    ConfigParser::~ConfigParser() {}

    //goes through the file line by line and matches correct values to correct variables
    void ConfigParser::configParser(string filePath)
    {
        // std::ifstream is RAII, i.e. no need to call close
        ifstream cFile (filePath);

        if (cFile.is_open())
        {
            string line;
            while(getline(cFile, line)){
                line.erase(remove_if(line.begin(), line.end(), ::isspace),
                                    line.end());
                if(line[0] == '#' || line.empty())
                    continue;
                int delimiterPos = line.find(":");
                string name = line.substr(0, delimiterPos);
                float value = stof(line.substr(delimiterPos + 1));

                if(name == "maximum_simulated_time"){
                    maximum_simulated_time = value;
                }
                else if(name == "number_of_sections_before_intersection"){
                    number_of_sections_before_intersection = value;
                }
                else if (name == "green_north_south"){
                    green_north_south = value;
                }
                else if(name == "yellow_north_south"){
                    yellow_north_south = value;
                }
                else if(name == "green_east_west"){
                    green_east_west = value;
                }
                else if(name == "yellow_east_west"){
                    yellow_east_west = value;
                }
                else if(name == "prob_new_vehicle_northbound"){
                prob_new_vehicle_northbound = value;
                }
                else if(name == "prob_new_vehicle_southbound"){
                    prob_new_vehicle_southbound = value;
                }
                else if(name == "prob_new_vehicle_eastbound"){
                    prob_new_vehicle_eastbound = value;
                }
                else if(name == "prob_new_vehicle_westbound"){
                    prob_new_vehicle_westbound = value;
                }
                else if(name == "proportion_of_cars"){
                    proportion_of_cars = value;
                }
                else if(name == "proportion_of_SUVs"){
                    proportion_of_SUVs = value;
                }
                else if(name == "proportion_right_turn_cars"){
                    proportion_right_turn_cars = value;
                }
                else if(name == "proportion_right_turn_SUVs"){
                    proportion_right_turn_SUVs = value;
                }
                else if(name == "proportion_right_turn_trucks"){
                    proportion_right_turn_trucks = value;
                }
                else if(name == "proportion_left_turn_cars"){
                    proportion_left_turn_cars = value;
                }
                else if(name == "proportion_left_turn_SUVs"){
                    proportion_left_turn_SUVs = value;
                }
                else if(name == "proportion_left_turn_trucks"){
                    proportion_left_turn_trucks = value;
                }
                else{
                    cout << "Incorrect name, please check your config file" << endl;
                    cout << name << "is the name that was not found" << endl;
                } // end big if chain
            } // end of while loop to read file
            proportion_of_trucks = (1 - proportion_of_cars - proportion_of_SUVs);
            red_east_west = (green_north_south + yellow_north_south);
            red_north_south = (green_east_west + yellow_east_west);
        } // end of open file (remember to add close file. )
        else {
            std::cerr << "Couldn't open config file for reading.\n";
        }
    } // end of method

    int ConfigParser::get_maximum_simulated_time(){
        return maximum_simulated_time;
    }
    int ConfigParser::get_number_of_sections_before_intersection(){
        return number_of_sections_before_intersection;
    }
    int ConfigParser::get_green_north_south(){
        return green_north_south;
    }
    int ConfigParser::get_yellow_north_south(){
        return yellow_north_south;
    }
    int ConfigParser::get_green_east_west(){
        return green_east_west;
    }
    int ConfigParser::get_yellow_east_west(){
        return yellow_east_west;
    }
    float ConfigParser::get_prob_new_vehicle_northbound(){
        return prob_new_vehicle_northbound;
    }
    float ConfigParser::get_prob_new_vehicle_southbound(){
        return prob_new_vehicle_southbound;
    }
    float ConfigParser::get_prob_new_vehicle_eastbound(){
        return prob_new_vehicle_eastbound;
    }
    float ConfigParser::get_prob_new_vehicle_westbound(){
        return prob_new_vehicle_westbound;
    }
    float ConfigParser::get_proportion_of_cars(){
        return proportion_of_cars;
    }
    float ConfigParser::get_proportion_of_SUVs(){
        return proportion_of_SUVs;
    }
    float ConfigParser::get_proportion_right_turn_cars(){
        return proportion_right_turn_cars;
    }
    float ConfigParser::get_proportion_left_turn_cars(){
        return proportion_left_turn_cars;
    }
    float ConfigParser::get_proportion_right_turn_SUVs(){
        return proportion_right_turn_SUVs;
    }
    float ConfigParser::get_proportion_left_turn_SUVs(){
        return proportion_left_turn_SUVs;
    }
    float ConfigParser::get_proportion_right_turn_trucks(){
        return proportion_right_turn_trucks;
    }
    float ConfigParser::get_proportion_left_turn_trucks(){
        return proportion_left_turn_trucks;
    }
    int ConfigParser::get_red_east_west(){
        return red_east_west;
    }
    int ConfigParser::get_red_north_south(){
        return red_north_south;
    }
    float ConfigParser::get_proportion_of_trucks(){
        return proportion_of_trucks;
    }


#endif