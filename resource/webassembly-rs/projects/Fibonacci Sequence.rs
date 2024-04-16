#![no_std]
#![no_main]

use core::panic::PanicInfo;

#[panic_handler]
fn panic(_info: &PanicInfo) -> ! {
    loop {}
}

fn fibonacci(n: u32) -> u32 {
    let mut a = 0;
    let mut b = 1;
    if n == 0 {
        return a;
    }
    for _ in 2..=n {
        let c = a + b;
        a = b;
        b = c;
    }
    b
}

#[no_mangle]
fn main() -> u32 {
    let num = 10; // You can change this value to test with different numbers
    fibonacci(num)
}
