#![no_std]
#![no_main]

use core::panic::PanicInfo;

#[panic_handler]
fn panic(_info: &PanicInfo) -> ! {
    loop {}
}

#[no_mangle]
pub extern "C" fn gcd(mut a: i8, mut b: i8) -> i8 {
    while b != 0 {
        let t = a % b;
        a = b;
        b = t;
    }
    a
}
