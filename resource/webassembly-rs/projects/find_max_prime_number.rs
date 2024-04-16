#![no_std]
#![no_main]

use core::panic::PanicInfo;

#[panic_handler]
fn panic(_info: &PanicInfo) -> ! {
    loop {}
}

fn is_prime(n: u32) -> bool {
    if n <= 1 {
        return false;
    }
    if n <= 3 {
        return true;
    }
    if n % 2 == 0 || n % 3 == 0 {
        return false;
    }
    let mut i = 5;
    while i * i <= n {
        if n % i == 0 || n % (i + 2) == 0 {
            return false;
        }
        i += 6;
    }
    true
}

#[no_mangle]
fn main() -> i32 {
    let mut largest_prime = 2;
    let max_check = 1000; // Define the upper limit to check for primes

    for num in 2..=max_check {
        if is_prime(num) {
            largest_prime = num;
        }
    }

    largest_prime as i32
}
