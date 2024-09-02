#![no_std]
#![no_main]

use core::panic::PanicInfo;

#[panic_handler]
fn panic(_info: &PanicInfo) -> ! {
    loop {}
}

#[no_mangle]
pub extern "C" fn main() {
    // Initialize the array with some values
    let mut arr: [i32; 100] = [0; 100]; // Create an array of size 1000 initialized to 0

    for i in 0..100 {
        arr[i] = (100 - i) as i32; // Fill the array in descending order, cast to i32
    }

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
