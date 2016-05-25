#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>

using namespace std;


//4.1
//int sum(int a, int b){
//	return a + b;
//}
//double sum(double a, double b){
//	return a + b;
//}

//4.3
//int sum(int num1, int num2, int num3){
//	return num1 + num2 + num3;
//
//int sum(int num1, int num2, int num3, int num4){
//	return num1 + num2 + num3 + num4;
//}

//4.4
//int sum(int num1 = 0, int num2 = 0, int num3 = 0, int num4 = 0){
//	return num1 + num2 + num3 + num4;
//}

//4.5
/*
int sum(int arr[], int length){
	int total = 0;
	for(int i = 0; i < length; i++){
		total += arr[i];
	}
	return total;
}*/

//4.6
/*int sum(int arr[], int length){
	if(length <= 1)
		return arr[length - 1];
	else{
		return arr[0] + sum(arr + 1, length - 1);
	}
}*/

//5
/*double calculatePi(double throws){
	srand(time(0));
	double dartsIn = 0;
	double pi;
	for(int n = 0; n < throws; n++){
		double dartX = (double)rand() / RAND_MAX;
		double dartY = (double)rand() / RAND_MAX;
		if(sqrt((dartX * dartX) + (dartY * dartY))<= 1)
			dartsIn++;
	}
	pi = 4.0 * (dartsIn / throws);
	return pi;
	//cout<<"x: "<<std::setprecision(8)<<dartX<<endl;
	//cout<<"y: "<<std::setprecision(8)<<dartY<<endl;
}*/

int main (){
	
	//4.1
	//cout << sum(1, 3) << ' ' << sum(3.5, 4.3) << endl;
	
	//4.4
	//cout<< sum(1, 2, 3) << endl;

	//4.5
	//int nums[] = {1, 2, 3};
	//cout << sum(nums, 3) << endl;

	//5
	//I did some additional calcualtions, ran the Monte Carlo estimation 300 times
	//and found the average
	/*double averagePi = 0;
	double tempPi;
	for(int i = 0; i < 300; i++){
		tempPi = calculatePi(5000000);
		averagePi += tempPi;
		if(i % 6 == 0)//because we are using system time for our average number, every 6 are the same.
			cout << tempPi << "\n";
	}
		

	averagePi /= 300;
	cout << "Average Pi: "<< averagePi << "\n";*/


	return 0;
}