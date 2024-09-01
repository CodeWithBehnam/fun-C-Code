use std::{thread, time};

fn main() {
    let mut a: f32 = 0.0;
    let mut b: f32 = 0.0;
    let mut z = [0.0; 1760];
    let mut b_char = [' '; 1760];

    print!("\x1b[2J");
    loop {
        b_char = [' '; 1760];
        z = [0.0; 1760];

        for j in (0..628).map(|j| j as f32 * 0.01) {
            for i in (0..628).map(|i| i as f32 * 0.01) {
                let (sin_i, cos_i) = i.sin_cos();
                let (sin_j, cos_j) = j.sin_cos();
                let (sin_a, cos_a) = a.sin_cos();
                let (sin_b, cos_b) = b.sin_cos();

                let h = cos_j + 2.0;
                let d = 1.0 / (sin_i * h * sin_a + sin_j * cos_a + 5.0);
                let t = sin_i * h * cos_a - sin_j * sin_a;

                let x = (40.0 + 30.0 * d * (cos_i * h * cos_b - t * sin_b)) as usize;
                let y = (12.0 + 15.0 * d * (cos_i * h * sin_b + t * cos_b)) as usize;
                let o = x + 80 * y;
                let n = (8.0 * ((sin_j * sin_a - sin_i * cos_j * cos_a) * cos_b
                    - sin_i * cos_j * sin_a
                    - sin_j * cos_a
                    - cos_i * cos_j * sin_b)) as usize;

                if y < 22 && y > 0 && x > 0 && x < 80 && d > z[o] {
                    z[o] = d;
                    b_char[o] = ".,-~:;=!*#$@".chars().nth(if n > 0 { n as usize } else { 0 }).unwrap();
                }
            }
        }

        print!("\x1b[H");
        for k in 0..1761 {
            if k % 80 != 0 {
                print!("{}", b_char[k]);
            } else {
                println!();
            }
        }

        a += 0.00004;
        b += 0.00002;

        thread::sleep(time::Duration::from_micros(30000));
    }
}