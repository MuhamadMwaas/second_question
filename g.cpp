#include <iostream>
#include <vector>
#include <algorithm>
#include <mpi.h>

using namespace std;

struct Edge {
  int u, v;
  int weight;
};

int main(int argc, char** argv) {
  int num_processors, rank;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &num_processors);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  // Read the graph from stdin.
  int n;
  cin >> n;
  vector<vector<Edge>> edges(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int weight;
      cin >> weight;
      if (i != j) {
        edges[i].push_back({i, j, weight});
      }
    }
  }

  // Initialize the set S to contain the starting vertex.
  int start = rank;
  vector<bool> in_S(n, false);
  in_S[start] = true;

  // Initialize the set T to be empty.
  vector<int> T;

  // While T does not contain all of the vertices in the graph:
  while (T.size() < n) {
    // Find the minimum weight edge e connecting a vertex in S to a vertex not in T.
    int min_weight = INT_MAX;
    int min_u = -1;
    int min_v = -1;
    for (int u = 0; u < n; u++) {
      if (in_S[u]) {
        for (Edge e : edges[u]) {
          if (!in_S[e.v]) {
            if (e.weight < min_weight) {
              min_weight = e.weight;
              min_u = u;
              min_v = e.v;
            }
          }
        }
      }
    }

    // Add e to T.
    T.push_back(min_v);
    in_S[min_v] = true;

    // Update S to include all of the vertices in T.
    for (int u : T) {
      for (Edge e : edges[u]) {
        if (!in_S[e.v]) {
          in_S[e.v] = true;
        }
      }
    }
  }

  // The minimum spanning tree is the set T.
  for (int u : T) {
    for (Edge e : edges[u]) {
      if (!in_S[e.v]) {
        cout << u << " " << e.v << " " << e.weight << endl;
      }
    }
  }

  MPI_Finalize();
  return 0;
}
