#include <libgeom/figures.h>
#include <libgeom/intersections.h>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
void findIntersections(vector<circle>& arr)
{
    int N = arr.size();
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (sqrt(pow(arr[j].center.x - arr[i].center.x, 2)
                     + pow(arr[j].center.y - arr[i].center.y, 2))
                <= arr[i].rad + arr[j].rad) {
                string tmp = arr[i].position + ". circle";
                arr[j].intersections.push_back(tmp);
                tmp = arr[j].position + ". circle";
                arr[i].intersections.push_back(tmp);
            }
        }
    }
}
