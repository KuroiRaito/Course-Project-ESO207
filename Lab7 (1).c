#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct Point
{
	int x, y;
}Point;

int compX(const void* a, const void* b)
{
	Point *p1 = (Point *)a, *p2 = (Point *)b;
	return (p1->x - p2->x);
}

int compY(const void* a, const void* b)
{
	Point *p1 = (Point *)a, *p2 = (Point *)b;
	return (p1->y - p2->y);
}

float dist(Point p1, Point p2)
{
	return sqrt( (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y) );
}

float direct(Point P[], int n)
{
	float min = FLT_MAX;
	for (int i = 0; i < n; ++i)
		for (int j = i+1; j < n; ++j)
			if (dist(P[i], P[j]) < min)
				min = dist(P[i], P[j]);
	return min;
}

float min(float x, float y)
{
	return (x < y)? x : y;
}

float strpclo(Point strip[], int size, float d)
{
	float min = d; 
	qsort(strip, size, sizeof(Point), compY);
	for (int i = 0; i < size; ++i)
		for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
			if (dist(strip[i],strip[j]) < min)
				min = dist(strip[i], strip[j]);

	return min;
}

float partition(Point P[], int n)
{
	if (n <= 3)
		return direct(P, n);
	int mid = n/2;
	Point midPoint = P[mid];
	float dl = partition(P, mid);
	float dr = partition(P + mid, n-mid);
	float d = min(dl, dr);
	Point strip[n];
	int j = 0;
	for (int i = 0; i < n; i++)
		if (abs(P[i].x - midPoint.x) < d)  strip[j] = P[i], j++;
	return min(d, strpclo(strip, j, d) );
}

float closest(Point P[], int n)
{
	qsort(P, n, sizeof(Point), compX);
	return partition(P, n);
}

int main()
{
	{int i,j,n;
    scanf("%d",&n);
    Point p[n];
    srand(time(0));
    for(i=0;i<n;i++){
        p[i].x = rand()%1000000 + 1;
        p[i].y = rand()%1000000 + 1;     
    }
    double time_spent = 0.0;
    clock_t begin = clock();
	printf("%f\n", closest(p, n));
    clock_t end= clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f seconds", time_spent);
	return 0;}

    {int i,j,n;
    scanf("%d",&n);
    double p[n][2];
    double min = INFINITY;
    srand(time(0));
    for(i=0;i<n;i++){
        p[i][0] = rand()%1000000 + 1;
        p[i][1] = rand()%1000000 + 1;     
    }
    double time_spent = 0.0;
    clock_t begin = clock();
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if (min > sqrt(pow(p[i][0] - p[j][0],2) + pow(p[i][1] - p[j][1],2))){
            min = sqrt(pow(p[i][0] - p[j][0],2) + pow(p[i][1] - p[j][1],2));
            }
        }
    }
    printf("%f\n",min);
    clock_t end= clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f seconds", time_spent);
    return 0;}

}
