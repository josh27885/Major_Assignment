#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// struct to hold all variables related to the speech signal
struct speech_stats {
	double speech_arr[1000] = { 0.0 };
	double mean = 0.0;
	double variance = 0.0;
	double standard_deviation = 0.0;
	double average_power = 0.0;
	double average_magnitude = 0.0;

}TWO; // There is one object named two as only one speech signal is being processed

void read_speech_signal(double speech_array[1000]); // function which takes in an array of type double size 1000 and passes all values of a file containing a speech signal to it 
void find_mean_magnitude(double speech_array[1000], double* mean_mag); // function to calulate the mean value for magnitude across all samples
void find_variance(double speech_array[1000], double mean_mag, double* the_variance); // function tocalculate variance using mean and speech signal 
void find_standard_deviation(double the_variance, double* the_standard_deviation);  // This function will find the standard deviation of the data held in TWO_A.dat
void find_average_magnitude(double speech_array[1000], double* the_average_magnitude); // This function will find the average power and replace the valuie held in memory for average poower withthe calculated value
void find_average_power(double speech_array[1000], double* the_average_power); // This function will tyake all 1000 data points and get the average power oopf them
void disp_the_speech_statistics(const speech_stats& TWO); // function to display all values held for each speech statistic in the console window
int main()
{
	
	read_speech_signal(TWO.speech_arr); 
	find_mean_magnitude(TWO.speech_arr,&TWO.mean);
	find_variance(TWO.speech_arr, TWO.mean, &TWO.variance);
	find_standard_deviation(TWO.variance, &TWO.standard_deviation);
	find_average_magnitude(TWO.speech_arr, &TWO.average_magnitude);
	find_average_power(TWO.speech_arr, &TWO.average_power);
	disp_the_speech_statistics(TWO);
	



	return 0;

}

void read_speech_signal(double speech_array[1000]) 
{
	ifstream speech("TWO_A.dat"); // opens file TWO_A.dat which contains 1000 double values representing a speech signal of the word two
	if (speech.is_open()){ // if the file has been succesfully opened this code will run
		cout << "\nSpeech file has been sucesfully opened!!" << endl; 
		for (int i = 0; i < 1000; i++)
		{
			speech >> speech_array[i]; // passes each vaue held in TWO_A.dat to the speech_array

		}
		speech.close();      // closes the file named speech 
	}
	else
	{
		cout << "\nThe speech file hasn't been opened!!" << endl; // if the file isnt opened this line notifies the user
	}
}
void  find_mean_magnitude(double speech_array[1000],double* mean_mag) 
{
	double total_magnitude = 0.0; // creates a variable of type double to store the value of all speech samples combined
	for (int i = 0; i < 1000; i++)
	{
		total_magnitude += speech_array[i]; // sums all speech values together

	}
	*mean_mag = total_magnitude / 1000; // divides the sum of all speech signals by the number of specch signals to give the mean value across all sampled values

	cout << "\The mean magnitude calulated for the speech signal is: " << *mean_mag << endl; // outputs the mean value calulated in this function
}
void find_variance(double speech_array[1000], double mean_mag, double* the_variance)
{
	double speech_minus_mean = 0; // variable to hold the vvalue for each speech signal - mean
	double sum_of_variance = 0; // holds the sum of all variance before being divided by the number of samples
	for (int i = 0; i < 1000; i++)
	{
		speech_minus_mean = (speech_array[i] - mean_mag);
		sum_of_variance += speech_minus_mean * speech_minus_mean; // squares each speech -  mean value and adds them all together to get the sum of variance before being divided
	}
	*the_variance = sum_of_variance / 999; 

	cout << "The variance has been calculated to be: " << *the_variance << endl;
}
void find_standard_deviation(double the_variance, double* the_standard_deviation)
{
	*the_standard_deviation = sqrt(the_variance); // standard deviation is simply equal to the square root of the variance

	cout << "\nThe standard deviation is: " << *the_standard_deviation << endl;

}
void find_average_magnitude(double speech_array[1000], double* the_average_magnitude) // takes in the value held in speech array and a pointer to the average magnitude
{
	
	double total_magnitude = 0.0; // creates a variable to hold the sum of all magnitudes
	for (int i = 0; i < 1000; i++)
	{
		total_magnitude += sqrt(speech_array[i]*speech_array[i]); // to calculate all magnitudes the value is squared and then sqrt to get the absolute value 
	}
	*the_average_magnitude = total_magnitude / 1000; // the sum is divided by n otr number of values to achieve the overall average 
	cout << "\nThe average magnitude of the file provided is: " << *the_average_magnitude << endl; // this line outputs the average magnitude to the user 
}
void find_average_power(double speech_array[1000], double* the_average_power)
{
	double total_power = 0.0; // variable to hold the sum of all power values
	for (int i = 0; i < 1000; i++)
	{
		total_power += speech_array[i] * speech_array[i]; // power is calculated by squaring each value and adding them all together
	}
	*the_average_power = total_power / 1000; // the sum is the divided by the number of values to get average power
	cout << "\nThe average power of the file provided is: " << *the_average_power << endl; // outputs the average power to the user
}
void disp_the_speech_statistics(const speech_stats& TWO)
{
	cout << "\nThe following figures are the statistics calculated based off the data points stored in the file TWO_A.dat" << endl;
	cout << "Mean magnitude: " << TWO.mean << endl;
	cout << "Variance: " << TWO.variance << endl;
	cout << "Standard deviation: " << TWO.standard_deviation << endl;
	cout << "Average magnitude: " << TWO.average_magnitude << endl;
	cout << "Average power: " << TWO.average_power << endl;
}