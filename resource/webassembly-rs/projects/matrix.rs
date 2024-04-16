#![no_std]
#![no_main]

use core::panic::PanicInfo;

#[panic_handler]
fn panic(_info: &PanicInfo) -> ! {
    loop {}
}

const N: usize = 3; // Define the size of the matrix (N x N)

fn matrix_multiply() {
    let a = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]; // Matrix A
    let b = [[9, 8, 7], [6, 5, 4], [3, 2, 1]]; // Matrix B
    let mut c = [[0; N]; N]; // Matrix C initialized to zeros

    for i in 0..N {
        for j in 0..N {
            for k in 0..N {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

#[no_mangle]
fn main() {
    matrix_multiply(); // Call the function to perform multiplication
}
