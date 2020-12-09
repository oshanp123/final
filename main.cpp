#include <iostream>

#include <vector>
#include <queue>
#include <stack> 
#include <string> 

#include <fstream> 

// This function opens a file and copies its contents to a vector
void init_temps(std::vector<int> &v, std::string filename) {
	std::ifstream infile(filename);
	if (infile.is_open()) {
		int temp;
		while (infile >> temp) {
			v.push_back(temp);
		}
		infile.close();
	}
}

// Print functions
template <typename T>
void print_vector(const std::vector<T> &v) {
	for (const auto &i : v) {
		std::cout << i << ' ';
	}
	std::cout << '\n';
}

template <typename Q>
void print_queue(std::queue<Q> q) {
	while(!q.empty()) {
		std::cout << q.front() << ' ';
		q.pop();
	}
	std::cout << '\n';
}

template <typename S>
void print_stack(std::stack<S> s) {
	while(!s.empty()) {
		std::cout << s.top() << ' ';
		s.pop();
	}
	std::cout << '\n';
}

int main() {
	std::string filename("temperature_data.txt");

	// A vector containing temperatures
	std::vector<int> temps;
	init_temps(temps, filename);

	// Start here
	std::queue<int> temps_queue;
	//This is a loop to put value in queue
	for(int i=0;i<temps.size();i++){
		temps_queue.push(temps[i]);
			    	}
		

	std::stack<int> group_A, group_B;
			
	for (int i=0; i<temps_queue.size(); i++){
		int temp = temps_queue.front();
		temps_queue.pop();
	if (temp > 99){
	        group_A.push(temp);
        }
	else if (temp <= 99){
         	    group_B.push(temp);
	    	    }
		}
	int sum = 0; 
	int max = 0, min = 0;
	int totalTemperature = group_A.size() + group_B.size();
	//maximum and minimum value
	for(int i=0; i<group_A.size();i++){
		    int top = group_A.top();
        if(max<top){
    	        max=top;
		   }
   	    group_A.pop();
    	    sum = sum +top;
   	}
         for(int i=0; i<group_B.size();i++){
	    	    int top = group_A.top();
         if(min>top){
    	        min=top;
	    }
    	    group_B.pop();
   	    sum = sum +top;
    	}
    	std::cout << "The minimum temperature is: " << min << std::endl;
	std::cout << "The maximum temperature is: " << max << std::endl;
	std::cout << "The average temperature is: " << sum/totalTemperature << std::endl;
	return 0;
}

