#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // 1. Get Center Point
    string centerName;
    double centerX, centerY;

    cout << "Enter Center Point Name: ";
    cin >> centerName;
    cout << "Enter Center X: ";
    cin >> centerX;
    cout << "Enter Center Y: ";
    cin >> centerY;

    // 2. Get Buffers
    int numBuffers;
    cout << "\nHow many buffer sizes? ";
    cin >> numBuffers;

    double buffers[100]; // Array to hold up to 100 buffer radii
    for (int i = 0; i < numBuffers; i++) {
        cout << "Enter radius for Buffer " << (i + 1) << ": ";
        cin >> buffers[i];
    }

    // 3. Get Points to Test
    int numPoints;
    cout << "\nHow many points to test? ";
    cin >> numPoints;

    string pointNames[100];
    double pointX[100];
    double pointY[100];

    for (int i = 0; i < numPoints; i++) {
        cout << "\nEnter Point " << (i + 1) << " Name: ";
        cin >> pointNames[i];
        cout << "Enter X: ";
        cin >> pointX[i];
        cout << "Enter Y: ";
        cin >> pointY[i];
    }

    // 4. Perform Analysis
    
    cout << "        \n RESULTS  \n                 " << endl;
    

    for (int b = 0; b < numBuffers; b++) {
        double currentRadius = buffers[b];
        int count = 0;

        cout << "\n--- Checking Buffer Radius: " << currentRadius << " ---" << endl;

        for (int p = 0; p < numPoints; p++) {
            // Calculate distance using distance formula: sqrt((x2-x1)^2 + (y2-y1)^2)
            double distance = sqrt(pow(pointX[p] - centerX, 2) + pow(pointY[p] - centerY, 2));

            // Check if point falls within radius
            if (distance <= currentRadius) {
                cout << "Point " << pointNames[p] << " is INSIDE (Distance = " << distance << ")" << endl;
                count++;
            }
        }

        cout << "Total points in this buffer: " << count << endl;
    }

    return 0;
}