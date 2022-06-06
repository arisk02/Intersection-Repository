#ifndef __VEHICLE_BASE_CPP__
#define __VEHICLE_BASE_CPP__

#include <iostream>
#include "VehicleBase.h"
#include "ConfigParser.h"

// author: Aris Karamustafic
// author: Hyewon Hong

int VehicleBase::vehicleCount = 0;

//normal constructor with vehicleType and Direction
VehicleBase::VehicleBase(VehicleType type, Direction direction, bool turnRight){
  vehicleID = vehicleCount;
  vehicleCount++; // increment vehicleCount for each new vehicle made
  vehicleType = type;
  vehicleDirection = direction;
  currentPosition = -1;
  canMove = false;

  if(turnRight == true){
    turnRightAtIntersection = true;
  }
  else{
    turnRightAtIntersection = false;
  }

} // end of base constructor

VehicleBase::VehicleBase(const VehicleBase& other){ // copy constructor
  vehicleID = other.vehicleID;
  vehicleType = other.vehicleType;
  vehicleDirection = other.vehicleDirection;
  turnRightAtIntersection = other.turnRightAtIntersection;
  canMove = other.canMove;
  currentPosition = other.currentPosition;
}

VehicleBase& VehicleBase::operator=(const VehicleBase& other) // copy operator
{
  if (this == &other)
  {
    return *this;
  }

  vehicleID = other.vehicleID;
  vehicleType = other.vehicleType;
  vehicleDirection = other.vehicleDirection;
  turnRightAtIntersection = other.turnRightAtIntersection;
  canMove = other.canMove;
  currentPosition = other.currentPosition;

  return *this;
}

VehicleBase::VehicleBase(VehicleBase&& other) noexcept // move constructor
{
  vehicleID = other.vehicleID;
  vehicleType = other.vehicleType;
  vehicleDirection = other.vehicleDirection;
  turnRightAtIntersection = other.turnRightAtIntersection;
  canMove = other.canMove;
  currentPosition = other.currentPosition;

  other.vehicleID = 0;
  other.vehicleType = VehicleType::car;
  other.vehicleDirection = Direction::north;
  other.turnRightAtIntersection = 0;
  other.canMove = 0;
  other.currentPosition = 0;
}

VehicleBase& VehicleBase::operator=(VehicleBase&& other) noexcept // move operator
{
  if (this == &other)
  {
    return *this;
  }

  vehicleID = other.vehicleID;
  vehicleType = other.vehicleType;
  vehicleDirection = other.vehicleDirection;
  turnRightAtIntersection = other.turnRightAtIntersection;
  canMove = other.canMove;
  currentPosition = other.currentPosition;

  other.vehicleID = 0;
  other.vehicleType = VehicleType::car;
  other.vehicleDirection = Direction::north;
  other.turnRightAtIntersection = 0;
  other.canMove = 0;
  other.currentPosition = 0;

  return *this;  
}

VehicleBase::~VehicleBase() {}

void VehicleBase::changeMovePermission(int halfSize, vector<VehicleBase*>* one, vector<VehicleBase*>* two, LightColor NorthSouth, LightColor EastWest, int modulus, string filePath){
  ConfigParser c1 = ConfigParser(filePath);
  int currPos = this->getCurrPosition();
  int roadLength = halfSize*2 + 2;
  Direction currDirection = this->getVehicleOriginalDirection();
  this->canMove = true; // assume they can move.
  if(this->turnRightAtIntersection == false){//they stay straight
    if(currPos < halfSize-1){ // before intersection
      if((*one)[currPos+1] != nullptr){ // position in front is occupied by another vehicles
        this->canMove = false;
      } // end if
    }
    else if(currPos == halfSize-1){ //right before the intersection
      if(NorthSouth == LightColor::red){
        if(this->getVehicleOriginalDirection() == Direction::north){
          this->canMove = false;
        }
        else if(this->getVehicleOriginalDirection() == Direction::south){
          this->canMove = false;
        } // next else if checks if there is enough ticks for a car to enter and leave the intersection by the time light turns red
        else if(this->getVehicleOriginalDirection() == Direction::east ||this->getVehicleOriginalDirection() == Direction::west)
        {
          if ((c1.get_green_east_west() + c1.get_red_east_west() + c1.get_yellow_east_west() - modulus) < 2 && this->getVehicleType() == VehicleType::car)
          {
            this->canMove = false;
          }
          if ((c1.get_green_east_west() + c1.get_red_east_west() + c1.get_yellow_east_west() - modulus) < 3 && this->getVehicleType() == VehicleType::suv)
          {
            this->canMove = false;
          }
          if ((c1.get_green_east_west() + c1.get_red_east_west() + c1.get_yellow_east_west() - modulus) < 4 && this->getVehicleType() == VehicleType::truck)
          {
            this->canMove = false;
          }
          if (modulus == 0)
          {
            this->canMove = false;
          }
        }
      }//end NorthSouth lights
      else if(EastWest == LightColor::red){
        if(this->getVehicleOriginalDirection() == Direction::east){
          this->canMove = false;
        }
        else if(this->getVehicleOriginalDirection() == Direction::west){
          this->canMove = false;
        } // next else if checks if there is enough ticks for a car to enter and leave the intersection by the time light turns red
        else if(this->getVehicleOriginalDirection() == Direction::north || (this->getVehicleOriginalDirection() == Direction::south)) 
        {
          if (((c1.get_green_north_south() + c1.get_yellow_north_south() - modulus) < 2) && this->getVehicleType() == VehicleType::car)
          {
            this->canMove = false;
          }
          if (((c1.get_green_north_south() + c1.get_yellow_north_south() - modulus) < 3) && this->getVehicleType() == VehicleType::suv)
          {
            this->canMove = false;
          }
          if (((c1.get_green_north_south() + c1.get_yellow_north_south() - modulus) < 4) && this->getVehicleType() == VehicleType::truck)
          {
            this->canMove = false;
          }
        }
      } // end EastWest ligts
    } // end car is right before intersection.
    else if(currPos < roadLength){
      if((*one)[currPos+1] != nullptr){ // position in front is occupied by another vehicle
        this->canMove = false;
      }
    }
  } // end if they turned straight.
  else{ // they turn right
    if(currPos < halfSize-1){ // before intersection
      if((*one)[currPos+1] != nullptr){ // position in front is occupied by another vehicle
        this->canMove = false;
      } // end if
    }
    else if(currPos == halfSize-1){ //right before the intersection
      if(NorthSouth == LightColor::red){
        if(this->getVehicleOriginalDirection() == Direction::north){
          this->canMove = false;
        }
        else if(this->getVehicleOriginalDirection() == Direction::south){
          this->canMove = false;
        }
        else if(this->getVehicleOriginalDirection() == Direction::east || (this->getVehicleOriginalDirection() == Direction::west))
        {
         if (modulus > (c1.get_green_east_west() + c1.get_red_east_west()))
         {
            if ((c1.get_green_east_west() + c1.get_red_east_west() + c1.get_yellow_east_west()) - modulus < 2 && this->getVehicleType() == VehicleType::car)
            {
              this->canMove = false;
            }
            if ((c1.get_green_east_west() + c1.get_red_east_west() + c1.get_yellow_east_west()) - modulus < 3 && this->getVehicleType() == VehicleType::suv)
            {
              this->canMove = false;
            }
            if ((c1.get_green_east_west() + c1.get_red_east_west() + c1.get_yellow_east_west()) - modulus < 4 && this->getVehicleType() == VehicleType::truck)
            {
              this->canMove = false;
            }
          }
        }
      }//end NorthSouth lights
      else if(EastWest == LightColor::red){
        if(this->getVehicleOriginalDirection() == Direction::east){
          this->canMove = false;
        }
        else if(this->getVehicleOriginalDirection() == Direction::west){
          this->canMove = false;
        }
        else if(this->getVehicleOriginalDirection() == Direction::north || (this->getVehicleOriginalDirection() == Direction::south))
        {
          if ((c1.get_green_north_south() + c1.get_yellow_north_south() - modulus) < 2 && this->getVehicleType() == VehicleType::car)
          {
            this->canMove = false;
          }
          if ((c1.get_green_north_south() + c1.get_yellow_north_south() - modulus) < 3 && this->getVehicleType() == VehicleType::suv)
          {
            this->canMove = false;
          }
          if ((c1.get_green_north_south() + c1.get_yellow_north_south() - modulus) < 4 && this->getVehicleType() == VehicleType::truck)
          {
            this->canMove = false;
          }
        }
      } // end EastWest ligts
    } // end car is right before intersection.
    else if(currPos < roadLength){
      if((*one)[currPos+1] != nullptr){ // position in front is occupied by another vehicle
        this->canMove = false;
      }
    }
  } // end turn right
}//end function

#endif
