# Balintawak Wet market Route finder

## Statement of Real world problem:
Balintawak Market is a popular local Wet market in the Philippines which is swarmed by hundreds of people trying to purchase fresh produce from local farmers. However, for many small store owners, they will need to visit a number of stalls in order to purchase all of the produce they need. This is can prove difficult as there are many routes to take (from the one entrance and exit) to accomplish their daunting shopping run.

## Proposed Solution
The Balintawak Market can be modelled as a complete graph at which each stall is a vertex labelled by numbers. Using a Genetic Algorithm we can determine the best route on should take without having to 
## Objectives: 
The Goal of the project was to construct a program that would generate the most time-efficient shopping route based on data provided on products to be purchased and sold by vendors.
## Program Description:

Utilizes a genetic algorithm library which was modified and retrofited to dynamically generate a subgraph of a complete graph model (of the Balintawak wet market) which it will then “traverse” and find the best route.


## Resources
The Genetic algorithm library tsp.h and tsp.cpp was taken from marcoscastros's tsp_genetic 
Link: https://github.com/marcoscastro/tsp_genetic 

## Status:
Under development
Thins to do:
-[x] Read Sample data from .csv files
-[x] Modify fitness function to consider presence of essential nodes in fitness calculation
-[] Construct decision making code to determine which vertices are essential nodes

