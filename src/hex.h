#include <iostream>
#include <vector>
#include <rand>

#include "unit.h"

#ifndef __HEX_H__
#define __HEX_H__

const unsigned LEVEL_TO_METRES_NUM = 6;

struct terrainType
{
  std::string cName;
  int cMovementCost;
  std::vector<UNIT::unitTypeID> RestrictedUnitTypes;
  terrainType(std::string iName, int movementCost);
};

struct terrainFeature
{
  std::string cName;
  std::vector<int> effectID;
};

class hex
{
 private:
  int q;
  int r;
  int level;
  terrainType* cType;
 public:
  hex();
  hex(int iQ, int iR, int level, terrainType* iType);
  int getQ() const;
  int getR() const;
  int getEnterCost(hex beginningHex) const;
};

class HexMap
{
 private:
  std::vector< std::vector<hex> > data;
 public:
  HexMap();
  bool addRow(hex firstHex);
  bool addRow(std::vector<hex> newRow);
  bool addHex(hex newHex);
  hex* findHex(int iQ, int iR);
  int getNumRow();
  int getColumnNumAtRow(int targetRow);
  int getNumHex();
 private:
  std::vector<hex>* findRow(int iR);
};

bool operator==(const hex& lhs, const hex& rhs);
bool operator!=(const hex& lhs, const hex& rhs);

#endif
