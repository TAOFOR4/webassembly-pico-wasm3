#![no_std]
#![no_main]

use core::panic::PanicInfo;

#[panic_handler]
fn panic(_info: &PanicInfo) -> ! {
    loop {}
}

#[no_mangle]
pub extern "C" fn main() {
    let mut arr: [i32; 100] = [
        64, 34, 25, 12, 22, 11, 90, 88, 76, 45, 33, 99, 82, 44, 18, 56, 67, 43, 29, 37, 71, 50, 21,
        30, 83, 92, 66, 55, 23, 10, 6, 85, 57, 41, 27, 79, 70, 28, 7, 35, 63, 48, 86, 95, 58, 54,
        17, 89, 26, 19, 97, 68, 84, 32, 20, 87, 42, 60, 15, 3, 14, 24, 77, 98, 31, 36, 4, 73, 61,
        80, 62, 74, 39, 13, 78, 93, 75, 38, 59, 91, 47, 40, 53, 16, 8, 52, 2, 49, 94, 72, 69, 81,
        46, 9, 1, 65, 51, 5, 100, 96,
    ];

    bubble_sort(&mut arr);
}

fn bubble_sort(arr: &mut [i32]) {
    let n = arr.len();
    for i in 0..n {
        for j in 0..n - i - 1 {
            if arr[j] > arr[j + 1] {
                arr.swap(j, j + 1);
            }
        }
    }
}
