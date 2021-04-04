#include<stdio.h>
#include<stdlib.h>
#include<math.h> // link with -lm, located at the end of line
#include<omp.h> // link with -fopenmp
//Compile: gcc -fopenmp pi.c -o pi -lm

int main()
{
	double len = 1e5;

	double pi_1_way = 0;
	double time_start_1 = omp_get_wtime(); // linux time
	for(double i = 0; i < len; ++i)
		pi_1_way += 4 / len * sqrt(1 - i*i/len/len);
	double time_end_1 = omp_get_wtime();
	printf("First way: PI =  %.10lf\n", pi_1_way);
	printf("First way: time is %lf\n", time_end_1 - time_start_1);


	int len_int = (int)len;
	double pi[4] = {};
	double pi_2_way = 0;
	omp_set_num_threads(4); // set number of threads for the futher parallel section
	double time_start_2 = omp_get_wtime();
	#pragma omp parallel for
		for(int i = 0; i < len_int; ++i)
			pi[omp_get_thread_num() % 4] += 4 / len * sqrt(1 - ((double)i * i / len / len));
	double time_end_2 = omp_get_wtime();
	for(int i = 0; i < 4; ++i)
		pi_2_way += pi[i];
	printf("Second way: PI =  %lf\n", pi_2_way);
	printf("Second way: time is %.10lf\n", time_end_2 - time_start_2);


	omp_set_num_threads(4);
	for(int i = 0; i < 4; ++i)
		pi[i] = 0;
	double pi_3_way = 0;
	double time_start_3 = omp_get_wtime();
	#pragma omp parallel
	{
		double len_1_4 = len / 4;
		double len_2_4 = len / 2;
		double len_3_4 = 3 * len / 4;
		switch(omp_get_thread_num())
		{
			case 0:
				for(int i = 0; i < len_1_4; ++i)
					pi[0] += 4 / len * sqrt(1 - ((double)i * i / len / len));
				break;

			case 1:
				for(int i = len_1_4; i < len_2_4; ++i)
					pi[1] += 4 / len * sqrt(1 - ((double)i * i / len / len));
				break;

			case 2:
				for(int i = len_2_4; i < len_3_4; ++i)
					pi[2] += 4 / len * sqrt(1 - ((double)i * i / len / len));
				break;

			case 3:
				for(int i = len_3_4; i < len; ++i)
					pi[3] += 4 / len * sqrt(1 - ((double)i * i / len / len));
				break;
		}
	}
	double time_end_3 = omp_get_wtime();
	for(int i = 0; i < 4; ++i)
		pi_3_way += pi[i];
	printf("Third way: PI =  %lf\n", pi_3_way);
	printf("Third way: time is %lf\n", time_end_3 - time_start_3);

	return 0;
}
