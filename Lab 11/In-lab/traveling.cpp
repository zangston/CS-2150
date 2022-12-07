// Winston Zhang, wyz5rge
// traveling.cpp
// adapted from skeleton code found in traveling-skeletin.cpp, written by Aaron Bloomfield
// 30 November 2021

/**
 * @author Winston Zhang
 */

#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

#include "middleearth.h"

/**
 * @brief method prototypes
 */
float computeDistance(MiddleEarth& me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);

/**
 * @brief main method - finds shortests path between MiddleEarth cities
 * @param argc number of command line parameters
 * @param argv vector of command line parameter names
 * @return int 0
 */
int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);

    // TODO: YOUR CODE HERE
    sort(dests.begin() + 1, dests.end());
    
    float min = computeDistance(me, dests[0], dests);
    
    float temp = 0.0;
    vector<string> path = dests;
    while(next_permutation(dests.begin() + 1, dests.end()))
      {
	temp = computeDistance(me, dests[0], dests);
	if(temp < min)
	  {
	    min = temp;
	    path = dests;
	  }
      }
    cout << "Minimum path has distance " << min << ": ";
    printRoute(path[0], path);
    cout << endl;
    
    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.

/**
 * @brief computes distance for a cycle
 * @param me MiddleEarth object
 * @param start starting city
 * @param dests vector of destination cities
 */
float computeDistance(MiddleEarth& me, const string& start, vector<string> dests) {
    // TODO: YOUR CODE HERE
  float distance = 0.0;
  string s = start;

  for(int i = 0; i < dests.size(); i++)
    {
      distance += me.getDistance(s, dests[i]);
      s = dests.at(i);
    }
  distance += me.getDistance(start, dests[dests.size() - 1]);
  return distance;
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.
// The output should be similar to:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor

/**
 * @brief prints route of city cycle
 * @param start starting city
 * @param dests vector of destination cities
 */
void printRoute(const string& start, const vector<string>& dests) {
    // TODO: YOUR CODE HERE
  for(int i = 0; i < dests.size(); i++)
    {
      cout << dests[i] << " -> ";
    }
  cout << dests[0];
  // cout << start << endl;
}
