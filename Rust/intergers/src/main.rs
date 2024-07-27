fn main() {
    let number1: i32 = 24;
    let number2: i32 = 42;
    let minimum: i32 =
        if number1 < number2 {
            number1
        } else {
            number2

        };
    println!("{}", minimum);
    if number1 > number2 {
        println!("{} > {}", number1, number2);
    }
    else {
        println!("{} <= {}", number1, number2);
    }

    let mut a: i32 = 15;
    let mut b: i32 = 40;
    while b != 0 {
        let temp: i32 = b;
        b = a % b;
        a = temp;
    }
    println!("Greatest common divisor of 15 and 40 is: {}", a);
}