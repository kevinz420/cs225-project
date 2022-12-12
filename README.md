# cs225-project

## Github Organization

* cs225-project
  * bin (contains all the executables after being made)
  * src 
    * algorithms.cpp (algorithms description file)
    * algorithms.h (algorithms header file)
    * graph.cpp (graph class description file)
    * graph.h (graph class header file)
  * tests
    * catch.hpp (auto-generated)
    * tests.cpp (contains our test cases) 
  * MakeFile
  * ReadME.md
  * main.cpp (entry)
  * presentation.mp4 (to view our video, please download the file and play it on your local computer)
  * results.md
  * team_contract.md
  * team_proposal.md 

## Usage

To compile and turn the program into an executuble run `make` in the same directory that contains the MakeFile.

To run just the test cases use `make tests` followed by `./bin/tests`. Our tests cover gathering and parsing the input into a custom graph data structure, tests for the shortest path algorithm, pageranks, and betweeness centrality algorithm.  

To run the main file use `make exec` followed by `./bin/exec`, you may modify the main file as you please to play around with the data and algorithms we have written. 

To clear the bin run `make clean`
