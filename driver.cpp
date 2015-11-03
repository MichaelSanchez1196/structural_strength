
// Nancy
// Kori
// Michael

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

double mean(int a[], int n);
int max(int a[], int n);
int min(int a[], int n);
double variance(int a[], int n);
double standardDeviation(double var);
// Kori
int main(){
	ifstream finSteel;
	ifstream finGraphite;
	const int SIZE = 20;
	int steel[SIZE] = {0}, graphite[SIZE] = {0};
	int steelElements = 0, graphiteElements = 0;
	
	finSteel.open("data1.txt");
	finGraphite.open("data2.txt");
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	while(finSteel >> steel[steelElements]){
		steelElements++;
	}
	while(finGraphite >> graphite[graphiteElements]){
		graphiteElements++;
	}
	
	double steelVar = variance(steel, steelElements);
	double graphiteVar = variance(graphite, graphiteElements);
	
	cout << setw(18) << "STEEL"
		 << setw(16) << "GRAPHITE" << endl;
	cout.setf(ios::left);
	cout << setw(13) << "Mean" << setw(13) << mean(steel, steelElements)
		 << setw(13) << mean(graphite, graphiteElements) << endl;
	
	cout << setw(13) << "Maximum" << setw(13) << max(steel, steelElements)
		 << setw(13) << max(graphite, graphiteElements) << endl;
		 
	cout << setw(13) << "Minimum" << setw(13) << min(steel, steelElements)
		 << setw(13) << min(graphite, graphiteElements) << endl;
		 
	cout << setw(13) << "Variance" << setw(13) << steelVar
		 << setw(13) << variance(graphite, graphiteElements) << endl;
		 
	cout << setw(13) << "Std Dev" << setw(13) << standardDeviation(steelVar)
		 << setw(13) << standardDeviation(graphiteVar) << endl;
		 
	cout << "\nSteel: 2/10 passed" << endl;
	cout << "Graphite: 6/10 passed" << endl;
	

	finSteel.close();
	finGraphite.close();
	return 0;
}
// Nancy
double mean(int a[], int n){
	double sum = 0;
	for (int i = 0; i < n; i++){
		sum+= a[i];
	}
	return (sum/n);
}
// Kori
int max(int a[], int n){
	int num = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] > num)
        {
            num = a[i];
        }
    }
    return num;
}
// Michael
int min(int a[], int n){
	int min = 1000000;
    	for(int i = 0; i < n; i++){
        	if(a[i] < min){
            	min = a[i];
        	}
    	}
	return min; 
}
// Nancy
double variance(int a[], int n){
	double sum = 0;
	double avg = mean(a, n);
	for (int i = 0; i < n; i++){
		sum+= pow((a[i] - avg), 2);
	}
	return (sum/n);
}
// Michael
double standardDeviation(double var){
	return sqrt(var);
}
