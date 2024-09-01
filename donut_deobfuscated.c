#define _XOPEN_SOURCE   600
#define _POSIX_C_SOURCE 200112L
#define _BSD_SOURCE
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <unistd.h>


int main() {
    // Rotation angles
    float A = 0, B = 0;
    float i, j;
    int k;
    // Arrays to store z-buffer and output buffer
    float z[1760];
    char b[1760];
    
    // Clear the screen
    printf("\x1b[2J");
    
    // Infinite loop for animation
    for(;;) {
        // Clear the buffers
        memset(b,32,1760);  // Fill with spaces
        memset(z,0,7040);   // Clear z-buffer
        
        // Outer loop for torus rotation
        for(j=0; j < 6.28; j += 0.07) {
            // Inner loop for torus rotation
            for(i=0; i < 6.28; i += 0.02) {
                // Calculate 3D coordinates and project to 2D
                float c = sin(i);
                float d = cos(j);
                float e = sin(A);
                float f = sin(j);
                float g = cos(A);
                float h = d + 2;  // R1 + R2*cos(theta)
                float D = 1 / (c * h * e + f * g + 5);  // 1/(z + K2)
                float l = cos(i);
                float m = cos(B);
                float n = sin(B);
                float t = c * h * g - f * e;
                
                // Calculate 2D projection
                int x = 40 + 30 * D * (l * h * m - t * n);
                int y= 12 + 15 * D * (l * h * n + t * m);
                int o = x + 80 * y;  // 1D index from 2D coordinates
                
                // Calculate luminance
                int N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);
                
                // Update output if point is visible and closer than previous point at this position
                if(22 > y && y > 0 && x > 0 && 80 > x && D > z[o]) {
                    z[o] = D;
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];  // Choose character based on luminance
                }
            }
        }
        
        // Move cursor to home position
        printf("\x1b[H");
        
        // Output the frame
        for(k = 0; k < 1761; k++) {
            putchar(k % 80 ? b[k] : 10);  // New line every 80 characters
            // Increment rotation angles
            A += 0.00004;
            B += 0.00002;
        }
        
        // Delay between frames
        usleep(30000);
    }
    return 0;
}