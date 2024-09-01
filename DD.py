import math
import time
import os

def main():
    a = 0
    b = 0
    z = [0] * 1760
    b_char = [' '] * 1760

    print("\x1b[2J", end='')
    while True:
        b_char = [' '] * 1760
        z = [0] * 1760

        for j in range(0, 628, 7):
            j = j * 0.01
            for i in range(0, 628, 2):
                i = i * 0.01
                sin_i, cos_i = math.sin(i), math.cos(i)
                sin_j, cos_j = math.sin(j), math.cos(j)
                sin_a, cos_a = math.sin(a), math.cos(a)
                sin_b, cos_b = math.sin(b), math.cos(b)

                h = cos_j + 2
                d = 1 / (sin_i * h * sin_a + sin_j * cos_a + 5)
                t = sin_i * h * cos_a - sin_j * sin_a

                x = int(40 + 30 * d * (cos_i * h * cos_b - t * sin_b))
                y = int(12 + 15 * d * (cos_i * h * sin_b + t * cos_b))
                o = x + 80 * y
                n = int(8 * ((sin_j * sin_a - sin_i * cos_j * cos_a) * cos_b
                             - sin_i * cos_j * sin_a
                             - sin_j * cos_a
                             - cos_i * cos_j * sin_b))

                if 22 > y > 0 and 0 < x < 80 and d > z[o]:
                    z[o] = d
                    b_char[o] = ".,-~:;=!*#$@"[max(n, 0)]

        print("\x1b[H", end='')
        for k in range(1761):
            print(b_char[k] if k % 80 else '\n', end='')

        a += 0.00004
        b += 0.00002

        time.sleep(0.03)

if __name__ == "__main__":
    main()