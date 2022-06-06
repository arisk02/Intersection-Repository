#ifndef __VEHICLE_BASE_H__
#define __VEHICLE_BASE_H__
#include <string>
#include <vector>

// author: Aris Karamustafic
// author: Hyewon Hong

using namespace std;

enum class Direction   {north, south, east, west};
enum class VehicleType {car, suv, truck};
enum class LightColor  {green, yellow, red};

class VehicleBase
{
   public:
      static int vehicleCount;

   private:
      int         vehicleID;
      VehicleType vehicleType;
      Direction   vehicleDirection;        //currentDirection -- need to switch this for right turns.
      bool        turnRightAtIntersection; // true if it should turn right
      bool        canMove;                 // true if it can move (i.e., nothing in front)
      int         currentPosition;         // measure of current position.

   public:
      VehicleBase(VehicleType type, Direction originalDirection, bool turningRight); // base constructor
      VehicleBase(const VehicleBase& other);                      // copy constructor
      VehicleBase& operator=(const VehicleBase& other);           // copy operator
      VehicleBase(VehicleBase&& other) noexcept;                  // move constructor
      VehicleBase& operator=(VehicleBase&& other) noexcept;       // move assigner
      ~VehicleBase();                                             // destructor

      void changeMovePermission(int halfSize, vector<VehicleBase*>* one, vector<VehicleBase*>* two, LightColor NorthSouth, LightColor EastWest, int modulus, string filePath);
      inline void        changeCurrPosition(int newPosition){this->currentPosition = newPosition;}
      inline void        moveOne(){this->currentPosition++;}
      inline bool        doesItTurnRight(){return this->turnRightAtIntersection;}
      inline bool        canItMove(){return this->canMove;}
      inline int         getCurrPosition(){return this->currentPosition;}
      inline int         getVehicleID() const { return this->vehicleID; }
      inline VehicleType getVehicleType() const { return this->vehicleType; }
      inline Direction   getVehicleOriginalDirection() const { return this->vehicleDirection; }
};

#endif
