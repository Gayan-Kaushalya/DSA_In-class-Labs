#include <iostream>
#include <cstring>
#include <limits.h>

using namespace std;

# define num_of_cities 6

// Finding the average time taken from a source city to the other cities
void averageTime(int time_arr[], int city_num){
    float sum = 0;

    for (int x = 0; x < num_of_cities; x++){
        sum += time_arr[x];
    }

    float average = sum / (num_of_cities - 1) ;
    cout << "Average time taken from city " << city_num << " to reach other cities is " << average << "." << endl;
}

// Dijkrstra's algorithm
void dijkstra(int adj[num_of_cities][num_of_cities],int source){
    int times[num_of_cities]; // Shortest times taken to reach each city

    // shortest_time_found[i] will be true if shortest time from source city to city i is found.
    bool shortest_time_found[num_of_cities]; 

    // Setting all times to infinity
	for (int i = 0; i < num_of_cities; i++){
		times[i] = INT_MAX;
    }

    // Time taken to reach source city is 0.
    times[source] = 0;
  
    // Initially no shortest time is found.  
    memset(shortest_time_found, false, sizeof(shortest_time_found));

    // Finding shortest time for other cities except the source city.
    for (int num = 0; num < num_of_cities; num++){
        // Finding the city with shortest time from the set of cities of which shortest time was not found.
        int min_time = INT_MAX;
        int city_with_min_time;
        for (int city = 0; city < num_of_cities; city++){
            if (shortest_time_found[city] == false && times[city] <= min_time){
                min_time = times[city];
                city_with_min_time = city;
            }
        }

        // Marking the picked city as shortest time found.
        shortest_time_found[city_with_min_time] = true;

        // Updating the time of the neighbouring cities of the picked city
        for (int neighbour = 0; neighbour < num_of_cities; neighbour++){

            // Here we first check whether shortest time for the neigbouring city has been found or not.
            // Then we check whether there is a road between the picked city and the neighbouring city.
            // Then we check whether the time taken to reach the picked city is not infinity.
            // Finally we check whether the time taken to reach the neighbouring city through the picked city is less than the time taken to reach the neighbouring city directly.
          
            if (!shortest_time_found[neighbour] && adj[city_with_min_time][neighbour] && times[city_with_min_time] != INT_MAX && times[city_with_min_time] + adj[city_with_min_time][neighbour] < times[neighbour]){
                    times[neighbour] = times[city_with_min_time] + adj[city_with_min_time][neighbour];
            }
        }
    }

    
    // Printing the shortest times taken to reach each city from the source city
    for (int i = 0; i < num_of_cities; i++){
        if (i != source){
            cout << "Shortest time taken to reach city " << i << " from city " << source << " is " << times[i] << "." << endl;
        }
    }

    cout << endl;

    // Printing the average time taken to reach each city from the source city
    averageTime(times, source);   
}

int main (){
    //Initializing adjacency matrix
    int graph [6][6] = {
        { 0, 10,  0,  0, 15,  5},
        {10,  0, 10, 30,  0,  0},
        { 0, 10,  0, 12,  5,  0},
        { 0, 30, 12,  0,  0, 20},
        {15,  0,  5,  0,  0,  0},
        { 5,  0,  0, 20,  0,  0}
    };

    dijkstra(graph, 5);

    return 0;
}