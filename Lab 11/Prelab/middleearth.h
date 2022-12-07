// Winston Zhang, wyz5rge
// middleearth.h
// 30 November 2021

#ifndef MIDDLEEARTH_H
#define MIDDLEEARTH_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <random>

using namespace std;

// see the comments in the lab11 write-up, or in middleearth.cpp

class MiddleEarth {
public:

  /**
   * @brief Creates MiddleEarth object
   * @return void
   * @param xsize size along horizontal axis
   * @param ysize size along vertical axis
   * @param num_cities number of cities in MiddleEarth
   * @param seed randomly generated value
   */
  MiddleEarth(int xsize, int ysize, int num_cities, int seed);

  /**
   * @brief prints MiddleEarth's city information
   * @return void
   */
  void print();

  /**
   * @brief prints tab-separated table of distances between cities
   * @return void
   */
  void printTable();

  /**
   * @brief returns distance between two cities passed in
   * @return float
   * @param city1 name of first city parameter
   * @param city2 name of second city parameter
   */
  float getDistance(const string& city1, const string& city2);

  /**
   * @brief returns list of cities in travel path
   * @return string vector
   * @param length number of cities in path
   */
  vector<string> getItinerary(unsigned int length);

private:
  int num_city_names, xsize, ysize;
  unordered_map<string, float> xpos, ypos;
  vector<string> cities;
  unordered_map<string, unordered_map<string, float>> distances;
  
  mt19937 gen; // Mersenne-Twister random number engine
};

#endif
