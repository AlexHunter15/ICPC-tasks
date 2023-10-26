#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double point_to_segment_distance(double x, double y, double x1, double y1, double x2, double y2) {
    double segment_length_squared = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
    if (segment_length_squared == 0) {
        return sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
    }
    double t = max(0.0, min(1.0, ((x - x1) * (x2 - x1) + (y - y1) * (y2 - y1)) / segment_length_squared));
    double closest_x = x1 + t * (x2 - x1);
    double closest_y = y1 + t * (y2 - y1);
    return sqrt((x - closest_x) * (x - closest_x) + (y - closest_y) * (y - closest_y));
}

double expected_distance(double x1, double y1, double x2, double y2, double x3, double y3) {
    double d1 = distance(x1, y1, x2, y2);
    double d2 = distance(x2, y2, x3, y3);
    double d3 = distance(x3, y3, x1, y1);
    double s = (d1 + d2 + d3) / 2.0;
    double triangle_area = sqrt(s * (s - d1) * (s - d2) * (s - d3));

    double expected_dist = (d1 + d2 + d3 + triangle_area * 2.0) / (4.0 * triangle_area);
    return expected_dist;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        double x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        double result = expected_distance(x1, y1, x2, y2, x3, y3);
        cout << fixed << setprecision(12) << result << endl;
    }

    return 0;
}
