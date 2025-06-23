#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
  int n = 8;            // Number of nodes
  int costMatrix[9][9]; // 2D cost matrix, indexing nodes from 1 to 8

  // Initialize the cost matrix with INT_MAX to represent no edge
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      costMatrix[i][j] = INT_MAX;
    }
  }

  // Fill the cost matrix with the given edges and their weights
  costMatrix[1][2] = 1;
  costMatrix[1][3] = 2;
  costMatrix[1][4] = 5;
  costMatrix[2][5] = 4;
  costMatrix[3][5] = 1;
  costMatrix[3][6] = 2;
  costMatrix[4][6] = 1;
  costMatrix[5][7] = 2;
  costMatrix[6][7] = 3;
  costMatrix[7][8] = 1;

  // Array to store the minimum cost from each node to the destination
  int minCost[9];
  minCost[8] = 0; // No cost to reach the destination from node 8

  // Start filling the minCost array from node 7 to node 1
  for (int i = 7; i >= 1; i--)
  {
    minCost[i] = INT_MAX; // Initialize minCost of node i to a large number

    // Check all nodes j that are after i (i+1 to n) and are reachable from i
    for (int j = i + 1; j <= n; j++)
    {
      if (costMatrix[i][j] != INT_MAX)
      { // There is an edge from i to j
        // Update the minCost for node i by considering the cost to reach node j
        minCost[i] = min(minCost[i], costMatrix[i][j] + minCost[j]);
      }
    }
  }

  // Output the minimum cost to reach the destination from node 1
  cout << "Minimum cost from node 1 to node 8: " << minCost[1] << endl;

  return 0;
}
