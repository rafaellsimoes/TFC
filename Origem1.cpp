#include<cstdlib>
#include<ctime>
#include <iostream>


void bubble(int* v, int n) {
	int i, j, aux;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n - 1;j++) {
			if (v[j] > v[j + 1]) {
				aux = v[j];
				v[j] = v[j + 1];
				v[j + 1] = aux;
			}
		}
	}
}

int main()
{
	int first_clock = clock();
	int first_time = time(NULL);
	srand(time(NULL));

	int n = 0;
	std::cin >> n;

	printf("%d \n", n);
	int* v = new int[n];

	for (int i = 0; i < n; i++) {
		v[i] = 0 + rand() % n;
	}


	bubble(v, n);



	delete[] v;

	int second_clock = clock();
	int second_time = time(NULL);

	std::cout << "Tempo decorrido (clock): " << (second_clock - first_clock) / (double)CLOCKS_PER_SEC << " segundos" << std::endl;
	std::cout << "Tempo decorrido (time): " << (second_time - first_time) << " segundos" << std::endl;

	return 0;

}

