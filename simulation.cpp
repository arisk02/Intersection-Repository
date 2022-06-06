#include <iostream>
#include "Animator.h"
#include "VehicleBase.h"
#include "ConfigParser.h"
#include <vector>
#include <random>

// author: Aris Karamustafic
// author: Hyewon Hong

void moveVehicle(int halfSize, VehicleBase* vehicle, vector<VehicleBase*>* one, vector<VehicleBase*>* two, LightColor NorthSouth, LightColor EastWest, int modulus, string filePath){
  int currPos = vehicle->getCurrPosition();
  vehicle->changeMovePermission(halfSize, one, two, NorthSouth, EastWest, modulus, filePath);
  int roadLength = halfSize*2 + 2;
  if(vehicle->canItMove()){
    vehicle->moveOne();
    currPos++; //move forward their current position w/n function.
    if(currPos == 0){
      (*one)[0] = vehicle;
    } else if (currPos == 1 && vehicle->getVehicleType() != VehicleType::car)
    {
      (*one)[currPos -1] = (*one)[currPos] = vehicle;
    } else if (currPos == 2 && vehicle->getVehicleType() == VehicleType::truck)
    {
      (*one)[currPos -2] = (*one)[currPos -1] = (*one)[currPos] = vehicle;
    }
    else if (currPos == 1 && vehicle->getVehicleType() == VehicleType::car)
    {
      (*one)[currPos -1] = (*one)[currPos] = vehicle;
    } else if (currPos == 2 && vehicle->getVehicleType() == VehicleType::suv)
    {
      (*one)[currPos -2] = (*one)[currPos -1] = (*one)[currPos] = vehicle;
    } else if (currPos == 3 && vehicle->getVehicleType() == VehicleType::truck)
    {
      (*one)[currPos -3] = (*one)[currPos -2] = (*one)[currPos -1] = (*one)[currPos] = vehicle;
    }
    else if(vehicle->doesItTurnRight() == true){
      if(currPos < halfSize){
        if (vehicle->getVehicleType() == VehicleType::car)
        {
          (*one)[currPos -2] = nullptr;
          (*one)[currPos -1] = (*one)[currPos] = vehicle;
        } else if (vehicle->getVehicleType() == VehicleType::suv)
        {
          (*one)[currPos -3] = nullptr;
          (*one)[currPos -2] = (*one)[currPos -1] = (*one)[currPos] = vehicle;
        } else if (vehicle->getVehicleType() == VehicleType::truck)
        {
          (*one)[currPos -4] = nullptr;
          (*one)[currPos -3] = (*one)[currPos -2] = (*one)[currPos -1] = (*one)[currPos] = vehicle;
        }
      }
      else if(currPos == halfSize){//just entered intersection
        if (vehicle->getVehicleType() == VehicleType::car)
        {
          (*one)[currPos-2] = nullptr;
          (*one)[currPos-1] = (*one)[currPos] = vehicle;
          (*two)[currPos+1] = vehicle;
        } else if (vehicle->getVehicleType() == VehicleType::suv)
        {
          (*one)[currPos-3] = nullptr;
          (*one)[currPos-2] = (*one)[currPos-1] = (*one)[currPos] = vehicle;
          (*two)[currPos+1] = vehicle;
        } else if (vehicle->getVehicleType() == VehicleType::truck)
        {
          (*one)[currPos-4] = nullptr;
          (*one)[currPos-3] = (*one)[currPos-2] = (*one)[currPos-1] = (*one)[currPos] = vehicle;
          (*two)[currPos + 1] = vehicle;
        }
      } // end if
      else if (currPos == halfSize + 1 && vehicle->getVehicleType() != VehicleType::car)
      {
        if(vehicle->getVehicleType() == VehicleType::suv)
        {
          (*one)[currPos-3] = nullptr;
          (*one)[currPos-2] = (*one)[currPos-1] = vehicle;
          (*two)[currPos] = (*two)[currPos+1] = vehicle;
        } else if (vehicle->getVehicleType() == VehicleType::truck)
        {
          (*one)[currPos-4] = nullptr;
          (*one)[currPos-3] = (*one)[currPos-2] = (*one)[currPos-1] = vehicle;
          (*two)[currPos] = (*two)[currPos + 1] = vehicle;
        }
      }
      else if (currPos == halfSize + 2 && vehicle->getVehicleType() == VehicleType::truck)
      {
        (*one)[currPos-4] = nullptr;
        (*one)[currPos-3] = (*one)[currPos-2] = vehicle;
        (*two)[currPos - 1] = (*two)[currPos] = (*two)[currPos + 1] = vehicle;
      }
      //probably code something for right after intersection
      else if (currPos < roadLength -1){
        if (vehicle->getVehicleType() == VehicleType::car)
        {
          (*two)[currPos-1] = nullptr;
          (*two)[currPos] = (*two)[currPos+1] = vehicle;
        } else if (vehicle->getVehicleType() == VehicleType::suv)
        {
          (*two)[currPos-2] = nullptr;
          (*two)[currPos - 1] = (*two)[currPos] = (*two)[currPos + 1] = vehicle;
        } else if (vehicle->getVehicleType() == VehicleType::truck)
        {
          (*two)[currPos-3] = nullptr;
          (*two)[currPos - 2] = (*two)[currPos - 1] = (*two)[currPos] = (*two)[currPos+1] = vehicle;
        }
      }
      else if(currPos == roadLength-1){ // front part of vehicle is out of lane.
        if (vehicle->getVehicleType() == VehicleType::car)
        {
          (*two)[currPos-1] = nullptr;
          (*two)[currPos] = vehicle;
        } else if (vehicle->getVehicleType() == VehicleType::suv)
        {
          (*two)[currPos-2] = nullptr;
          (*two)[currPos - 1] = (*two)[currPos] = vehicle;
        } else if (vehicle->getVehicleType() == VehicleType::truck)
        {
          (*two)[currPos-3] = nullptr;
          (*two)[currPos - 2] = (*two)[currPos - 1] = (*two)[currPos] = vehicle;
        }
      } // end  if
      else if (currPos == roadLength && vehicle->getVehicleType() != VehicleType::car)
      {
        if (vehicle->getVehicleType() == VehicleType::suv)
        {
          (*two)[currPos-2] = nullptr;
          (*two)[currPos - 1] = vehicle;
        } else if (vehicle->getVehicleType() == VehicleType::truck)
        {
          (*two)[currPos-3] = nullptr;
          (*two)[currPos - 2] = (*two)[currPos - 1] = vehicle;
        }
      }
      else if (currPos == roadLength + 1 && vehicle->getVehicleType() == VehicleType::truck)
      {
        (*two)[currPos-3] = nullptr;
        (*two)[currPos - 2] =vehicle;
      }
      //the else is vehicle goes out of lane.
    } // end if turn right.
    else if (vehicle->doesItTurnRight() == false) { // does not turn right -- just goes straight.
      if(currPos < roadLength){//not at the end of the road yet
        if (vehicle->getVehicleType() == VehicleType::car)
        {
          (*one)[currPos-2] = nullptr;
          (*one)[currPos-1] = (*one)[currPos] = vehicle;
        } else if (vehicle->getVehicleType() == VehicleType::suv)
        {
          (*one)[currPos-3] = nullptr;
          (*one)[currPos-2] = (*one)[currPos - 1] = (*one)[currPos] = vehicle;
        } else if (vehicle->getVehicleType() == VehicleType::truck)
        {
          (*one)[currPos-4] = nullptr;
          (*one)[currPos - 3] = (*one)[currPos - 2] = (*one)[currPos - 1] = (*one)[currPos] = vehicle;
        }
      }
      else if(currPos == roadLength){//section one is out of view
        if (vehicle->getVehicleType() == VehicleType::car)
        {
          (*one)[currPos-2] = nullptr;
          (*one)[currPos-1] = vehicle;
        } else if (vehicle->getVehicleType() == VehicleType::suv)
        {
          (*one)[currPos-3] = nullptr;
          (*one)[currPos-2] = (*one)[currPos-1] = vehicle;
        } else if (vehicle->getVehicleType() == VehicleType::truck)
        {
          (*one)[currPos-4] = nullptr;
          (*one)[currPos-3] = (*one)[currPos-2] = (*one)[currPos-1] = vehicle;
        }
      }
      else if (currPos == roadLength + 1 && vehicle->getVehicleType() != VehicleType::car)
      {
        if (vehicle->getVehicleType() == VehicleType::suv)
        {
          (*one)[currPos-3] = nullptr;
          (*one)[currPos-2] = vehicle;
        } else if (vehicle->getVehicleType() == VehicleType::truck)
        {
          (*one)[currPos-4] = nullptr;
          (*one)[currPos-3] = (*one)[currPos-2] = vehicle;
        }
      } 
      else if (currPos == roadLength + 2 && vehicle->getVehicleType() == VehicleType::truck)
      {
        (*one)[currPos-4] = nullptr;
        (*one)[currPos-3] = vehicle;
      }
    } // end else
  } //end if vehicle can Move check.
  else{ //vehicle can't move, stays where it is
    if (currPos == 0)
    {
      (*one)[currPos] = vehicle;
    }
    else if (currPos == 1)
    {
      (*one)[currPos-1] = (*one)[currPos] = vehicle;
    } 
    else if (currPos == 2 && vehicle->getVehicleType() != VehicleType::car)
    {
      (*one)[currPos-2] = (*one)[currPos-1] = (*one)[currPos] = vehicle; 
    } 
    else if (vehicle->getVehicleType() == VehicleType::truck)
    {
      (*one)[currPos-3] = (*one)[currPos-2] = (*one)[currPos-1] = (*one)[currPos] = vehicle;
    }
    else if (vehicle->getVehicleType() == VehicleType::car)
    {
      (*one)[currPos-1] = (*one)[currPos] = vehicle;
    }
    else if (vehicle->getVehicleType() == VehicleType::suv)
    {
      (*one)[currPos-2] = (*one)[currPos-1] = (*one)[currPos] = vehicle;
    }
  }
} // end moveVehicle


// sort vehicles based on their current position (largest position first)
void sortVehicles(vector<VehicleBase*> &currentVehicles) {
  VehicleBase* temp;
  for (int i = 0; i < currentVehicles.size(); i++)
  {
    int max = currentVehicles[i]->getCurrPosition();
    for (int j = i + 1; j < currentVehicles.size(); j++)
    {
      if (currentVehicles[j]->getCurrPosition() > max)
      {
        max = currentVehicles[j]->getCurrPosition();
        temp = currentVehicles[j];
        currentVehicles[j] = currentVehicles[i];
        currentVehicles[i] = temp;
      }
    }
  }
}

int main(int argc, char *argv[]){
  // get all the values from the config file
  ConfigParser c1 = ConfigParser(argv[1]);

  int maximum_simulated_time = c1.get_maximum_simulated_time();
  int halfSize = c1.get_number_of_sections_before_intersection();
  int green_north_south = c1.get_green_north_south();
  int yellow_north_south = c1.get_yellow_north_south();
  int green_east_west = c1.get_green_east_west();
  int yellow_east_west = c1.get_yellow_east_west();
  float prob_new_vehicle_northbound = c1.get_prob_new_vehicle_northbound();
  float prob_new_vehicle_southbound = c1.get_prob_new_vehicle_southbound();
  float prob_new_vehicle_eastbound = c1.get_prob_new_vehicle_eastbound();
  float prob_new_vehicle_westbound = c1.get_prob_new_vehicle_westbound();
  float proportion_of_cars = c1.get_proportion_of_cars();
  float proportion_of_SUVs = c1.get_proportion_of_SUVs();
  float proportion_right_turn_cars = c1.get_proportion_right_turn_cars();
  float proportion_left_turn_cars = c1.get_proportion_left_turn_cars();
  float proportion_right_turn_SUVs = c1.get_proportion_right_turn_SUVs();
  float proportion_left_turn_SUVs = c1.get_proportion_left_turn_SUVs();
  float proportion_right_turn_trucks = c1.get_proportion_right_turn_trucks();
  float proportion_left_turn_trucks = c1.get_proportion_left_turn_trucks();
  int red_east_west = c1.get_red_east_west();
  int red_north_south = c1.get_red_north_south();
  float proportion_of_trucks = c1.get_proportion_of_trucks();

  int seed = stoi(argv[2]);

  // set the values for the random number generator to work
  mt19937 randomNumberGenerator;
  uniform_real_distribution<double> rand_double(0,1);
  randomNumberGenerator.seed(seed);
  Animator::MAX_VEHICLE_COUNT = 999;

  //will need to set this to what the config file says.
  int streetLength = halfSize * 2 + 2;

  Animator anim(halfSize);

  // construct vectors of VehicleBase* of appropriate size, init to nullptr
  vector<VehicleBase*> westbound(streetLength + 2, nullptr);
  vector<VehicleBase*> eastbound(streetLength + 2, nullptr);
  vector<VehicleBase*> southbound(streetLength + 2, nullptr);
  vector<VehicleBase*> northbound(streetLength + 2, nullptr);

  char dummy = ' ';
  vector<VehicleBase*> currentVehicles;
  
  int i = 0;
  LightColor EastWest = LightColor::green;
  LightColor NorthSouth =  LightColor::red;

  while(i <= maximum_simulated_time){

    southbound.assign(halfSize * 2 + 2, nullptr); // reset vector at end of every loop
    northbound.assign(halfSize * 2 + 2, nullptr); // reset
    eastbound.assign(halfSize * 2 + 2, nullptr); // reset
    westbound.assign(halfSize * 2 + 2, nullptr); // reset

    //set the lights based on the values from the config file
    int modulus = i % (red_east_west + green_east_west + yellow_east_west);

    if (modulus <= red_east_west && modulus > 0)
    {
      anim.setLightEastWest(LightColor::red);
      EastWest = LightColor::red;
      if (modulus <= green_north_south)
      {
        anim.setLightNorthSouth(LightColor::green);
        NorthSouth = LightColor::green;
      } else
      {
        anim.setLightNorthSouth(LightColor::yellow);
        NorthSouth = LightColor::yellow;
      }
    } else if (modulus > red_east_west && modulus <= (red_east_west + green_east_west))
    {
      anim.setLightEastWest(LightColor::green);
      EastWest = LightColor::green;
      anim.setLightNorthSouth(LightColor::red);
      NorthSouth = LightColor::red;
    } else
    {
      anim.setLightEastWest(LightColor::yellow);
      EastWest = LightColor::yellow;
      anim.setLightNorthSouth(LightColor::red);
      NorthSouth = LightColor::red;
    }


    //before moving vehicles, sort them based on their current position. This is done because there is cases where a car
    //that was created first is behind a car that was created second (when the second car goes through an intersection, and the
    //first turns right) with no spaces inbetween. To prevent colisions, the car in front, that has a larger current position
    //is move first.
    sortVehicles(currentVehicles);

    //move all the cars
    for (int j = 0; j < currentVehicles.size(); j++)
    {
      if (!currentVehicles[j]->doesItTurnRight())
      {
        if (currentVehicles[j]->getVehicleOriginalDirection() == Direction::north)
        {
          moveVehicle(halfSize, currentVehicles[j], &northbound, &northbound, NorthSouth, EastWest, modulus, argv[1]);
        } else if (currentVehicles[j]->getVehicleOriginalDirection() == Direction::south)
        {
          moveVehicle(halfSize, currentVehicles[j], &southbound, &southbound, NorthSouth, EastWest, modulus, argv[1]);
        } else if (currentVehicles[j]->getVehicleOriginalDirection() == Direction::west)
        {
          moveVehicle(halfSize, currentVehicles[j], &westbound, &westbound, NorthSouth, EastWest, modulus, argv[1]);
        } else
        {
          moveVehicle(halfSize, currentVehicles[j], &eastbound, &eastbound, NorthSouth, EastWest, modulus, argv[1]);
        }
      } else
      {
        if (currentVehicles[j]->getVehicleOriginalDirection() == Direction::north)
        {
          moveVehicle(halfSize, currentVehicles[j], &northbound, &eastbound, NorthSouth, EastWest, modulus, argv[1]);
        } else if (currentVehicles[j]->getVehicleOriginalDirection() == Direction::south)
        {
          moveVehicle(halfSize, currentVehicles[j], &southbound, &westbound, NorthSouth, EastWest, modulus, argv[1]);
        } else if (currentVehicles[j]->getVehicleOriginalDirection() == Direction::west)
        {
          moveVehicle(halfSize, currentVehicles[j], &westbound, &northbound, NorthSouth, EastWest, modulus, argv[1]);
        } else
        {
          moveVehicle(halfSize, currentVehicles[j], &eastbound, &southbound, NorthSouth, EastWest, modulus, argv[1]);
        }
      }
    }


    //the block of code below is used to generate new vehicles based on probabilities from the config file. The reason why
    //they are created after the vehicles in the currentVehicles were moved is because we need to check if there is
    //going to be space for these cars to be created or not. After we move them we can check if the last spot
    //in the lane is free or not. After the car is created, move is called on it so it enters the lane.
    bool createNewVehicle = false;
    VehicleType vehicleType;
    bool turnsRight;

    //creation northbound ////////////////////////////////////////////////////////////////////////////////////
    double randNum = rand_double(randomNumberGenerator);
    if (randNum <= prob_new_vehicle_northbound && prob_new_vehicle_northbound != 0)
    {
      createNewVehicle = true;
    }

    randNum = rand_double(randomNumberGenerator);
    if (randNum <= proportion_of_cars)
    {
      vehicleType = VehicleType::car;
    } else if (randNum > proportion_of_cars && randNum <= (proportion_of_cars + proportion_of_SUVs))
    {
      vehicleType = VehicleType::suv;
    } else
    {
      vehicleType = VehicleType::truck;
    }

    randNum = rand_double(randomNumberGenerator);
    if (vehicleType == VehicleType::car && randNum <= proportion_right_turn_cars)
    {
      turnsRight = true;
    } else if (vehicleType == VehicleType::suv && randNum <= proportion_right_turn_SUVs)
    {
      turnsRight = true;
    } else if (vehicleType == VehicleType::truck && randNum <= proportion_right_turn_trucks)
    {
      turnsRight = true;
    } else
    {
      turnsRight = false;
    }

    if (createNewVehicle == true && (northbound)[0] == nullptr && i > 0)
    {
      currentVehicles.push_back(new VehicleBase(vehicleType, Direction::north, turnsRight));
      if (turnsRight)
      {
        moveVehicle(halfSize, currentVehicles[currentVehicles.size() - 1], &northbound, &eastbound, NorthSouth, EastWest, modulus, argv[1]);
      } else
      {
        moveVehicle(halfSize, currentVehicles[currentVehicles.size() - 1], &northbound, &northbound, NorthSouth, EastWest, modulus, argv[1]);
      }
    }

    createNewVehicle = false;

    //creation westbound ///////////////////////////////////////////////////////////////////////////////
    randNum = rand_double(randomNumberGenerator);
    if (randNum <= prob_new_vehicle_westbound && prob_new_vehicle_westbound != 0)
    {
      createNewVehicle = true;
    }

    randNum = rand_double(randomNumberGenerator);
    if (randNum <= proportion_of_cars)
    {
      vehicleType = VehicleType::car;
    } else if (randNum > proportion_of_cars && randNum <= (proportion_of_cars + proportion_of_SUVs))
    {
      vehicleType = VehicleType::suv;
    } else
    {
      vehicleType = VehicleType::truck;
    }

    randNum = rand_double(randomNumberGenerator);
    if (vehicleType == VehicleType::car && randNum <= proportion_right_turn_cars)
    {
      turnsRight = true;
    } else if (vehicleType == VehicleType::suv && randNum <= proportion_right_turn_SUVs)
    {
      turnsRight = true;
    } else if (vehicleType == VehicleType::truck && randNum <= proportion_right_turn_trucks)
    {
      turnsRight = true;
    } else
    {
      turnsRight = false;
    }

    if (createNewVehicle == true && (westbound)[0] == nullptr && i > 0)
    {
      currentVehicles.push_back(new VehicleBase(vehicleType, Direction::west, turnsRight));
      if (turnsRight)
      {
        moveVehicle(halfSize, currentVehicles[currentVehicles.size() - 1], &westbound, &northbound, NorthSouth, EastWest, modulus, argv[1]);
      } else
      {
        moveVehicle(halfSize, currentVehicles[currentVehicles.size() - 1], &westbound, &westbound, NorthSouth, EastWest, modulus, argv[1]);
      }
    }

    createNewVehicle = false;

    //creation southbound //////////////////////////////////////////////////////////////////////
    randNum = rand_double(randomNumberGenerator);
    if (randNum <= prob_new_vehicle_southbound && prob_new_vehicle_southbound != 0)
    {
      createNewVehicle = true;
    }

    randNum = rand_double(randomNumberGenerator);
    if (randNum <= proportion_of_cars)
    {
      vehicleType = VehicleType::car;
    } else if (randNum > proportion_of_cars && randNum <= (proportion_of_cars + proportion_of_SUVs))
    {
      vehicleType = VehicleType::suv;
    } else
    {
      vehicleType = VehicleType::truck;
    }

    randNum = rand_double(randomNumberGenerator);
    if (vehicleType == VehicleType::car && randNum <= proportion_right_turn_cars)
    {
      turnsRight = true;
    } else if (vehicleType == VehicleType::suv && randNum <= proportion_right_turn_SUVs)
    {
      turnsRight = true;
    } else if (vehicleType == VehicleType::truck && randNum <= proportion_right_turn_trucks)
    {
      turnsRight = true;
    } else
    {
      turnsRight = false;
    }

    if (createNewVehicle == true && (southbound)[0] == nullptr && i > 0)
    {
      currentVehicles.push_back(new VehicleBase(vehicleType, Direction::south, turnsRight));
      if (turnsRight)
      {
        moveVehicle(halfSize, currentVehicles[currentVehicles.size() - 1], &southbound, &westbound, NorthSouth, EastWest, modulus, argv[1]);
      } else
      {
        moveVehicle(halfSize, currentVehicles[currentVehicles.size() - 1], &southbound, &southbound, NorthSouth, EastWest, modulus, argv[1]);
      }
    }

    createNewVehicle = false;

    //creation eastbound ///////////////////////////////////////////////////////////////////////////
    randNum = rand_double(randomNumberGenerator);
    if (randNum <= prob_new_vehicle_eastbound && prob_new_vehicle_eastbound != 0)
    {
      createNewVehicle = true;
    }

    randNum = rand_double(randomNumberGenerator);
    if (randNum <= proportion_of_cars)
    {
      vehicleType = VehicleType::car;
    } else if (randNum > proportion_of_cars && randNum <= (proportion_of_cars + proportion_of_SUVs))
    {
      vehicleType = VehicleType::suv;
    } else
    {
      vehicleType = VehicleType::truck;
    }

    randNum = rand_double(randomNumberGenerator);
    if (vehicleType == VehicleType::car && randNum <= proportion_right_turn_cars)
    {
      turnsRight = true;
    } else if (vehicleType == VehicleType::suv && randNum <= proportion_right_turn_SUVs)
    {
      turnsRight = true;
    } else if (vehicleType == VehicleType::truck && randNum <= proportion_right_turn_trucks)
    {
      turnsRight = true;
    } else
    {
      turnsRight = false;
    }

    if (createNewVehicle == true && (eastbound)[0] == nullptr && i > 0)
    {
      currentVehicles.push_back(new VehicleBase(vehicleType, Direction::east, turnsRight));
      if (turnsRight)
      {
        moveVehicle(halfSize, currentVehicles[currentVehicles.size() - 1], &eastbound, &southbound, NorthSouth, EastWest, modulus, argv[1]);
      } else
      {
        moveVehicle(halfSize, currentVehicles[currentVehicles.size() - 1], &eastbound, &eastbound, NorthSouth, EastWest, modulus, argv[1]);
      }
    }

    //this block of code deletes any vehicles that are no longer in the intersection, thus giving
    //the simulation the ability to run endlessly without losing memory.
    vector<int> indexes;
    int j = 0;

    for (VehicleBase* vehicle : currentVehicles)
    {
      if (vehicle->getCurrPosition() == (halfSize * 2 + 3) && vehicle->getVehicleType() == VehicleType::car)
      {
        delete vehicle;
        indexes.push_back(j);
      }
      else if (vehicle->getCurrPosition() == (halfSize * 2 + 4) && vehicle->getVehicleType() == VehicleType::suv)
      {
        delete vehicle;
        indexes.push_back(j);
      }
      else if (vehicle->getCurrPosition() == (halfSize * 2 + 5) && vehicle->getVehicleType() == VehicleType::truck)
      {
        delete vehicle;
        indexes.push_back(j);
      }
      j++;
    }

    int count = 0;

    for (int index : indexes)
    {
      currentVehicles.erase(currentVehicles.begin()+(index-count));
      count++;
    }


    anim.setVehiclesNorthbound(northbound);
    anim.setVehiclesWestbound(westbound);
    anim.setVehiclesSouthbound(southbound);
    anim.setVehiclesEastbound(eastbound);


    anim.draw(i);

    //after the simulation, all the remaining vehicles need to be deleted, and that is wht the for loop down below does.

    if (i == maximum_simulated_time)
    {
      for (int t = 0; t < currentVehicles.size(); t++)
      {
        delete currentVehicles[t];
      }
      currentVehicles.clear();
    }

    cin.get(dummy);
    i++;

  } // end while


} // end main