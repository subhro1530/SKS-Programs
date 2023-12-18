#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

typedef struct
{
    double x;
    double y;
} Point;

double calculatePolarAngle(Point referencePoint, Point currentPoint)
{
    return atan2(currentPoint.y - referencePoint.y, currentPoint.x - referencePoint.x);
}

int compareAngles(const void *a, const void *b)
{
    double angleA = *((double *)a);
    double angleB = *((double *)b);

    if (angleA < angleB)
        return -1;
    if (angleA > angleB)
        return 1;
    return 0;
}

void orderPoints(Point *points, int numPoints, Point referencePoint, int clockwise)
{
    double *angles = malloc(numPoints * sizeof(double));

    // Calculate polar angles
    for (int i = 0; i < numPoints; ++i)
    {
        angles[i] = calculatePolarAngle(referencePoint, points[i]);
        printf("Angle %d: %lf\n", i + 1, angles[i]);
    }

    // Sort indices based on angles
    qsort(angles, numPoints, sizeof(double), compareAngles);

    // Reverse the order if clockwise is true
    if (clockwise)
    {
        for (int i = 0; i < numPoints / 2; ++i)
        {
            double temp = angles[i];
            angles[i] = angles[numPoints - i - 1];
            angles[numPoints - i - 1] = temp;
        }
    }

    // Print the ordered points
    printf("Ordered Points:\n");
    for (int i = 0; i < numPoints; ++i)
    {
        printf("(%lf, %lf)\n", points[(int)angles[i]].x, points[(int)angles[i]].y);
    }

    free(angles);
}

int main()
{
    int numPoints;
    printf("Enter the number of points: ");
    scanf("%d", &numPoints);

    Point *points = malloc(numPoints * sizeof(Point));

    // Input points
    printf("Enter the coordinates of each point:\n");
    for (int i = 0; i < numPoints; ++i)
    {
        printf("Point %d (x y): ", i + 1);
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    Point referencePoint;
    printf("Enter the coordinates of the reference point (x y): ");
    scanf("%lf %lf", &referencePoint.x, &referencePoint.y);

    int clockwise;
    printf("Enter 1 for clockwise order or 0 for anticlockwise order: ");
    scanf("%d", &clockwise);

    orderPoints(points, numPoints, referencePoint, clockwise);

    free(points);

    return 0;
}
