use std::io::{stdin, Read};
use std::fmt::Write;

fn main(){
    let mut input = String::new();
    stdin().read_to_string(&mut input).unwrap();
    let mut tokens = input.split_ascii_whitespace().map(str::parse).flatten();
    let mut empty = String::new();
    let a: i32 = tokens.next().unwrap();
    let b: i32 = tokens.next().unwrap();
    let ans: i32 = a + b;
    writeln!(empty, "{}", ans).unwrap();
    print!("{}", empty);
}