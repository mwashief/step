/*
    15 November 2026
   ~ step codeforces 2251-2500 2271 2271C
*/

#![allow(dead_code)]
#![allow(unused)]
#![allow(unused_imports)]

use std::cmp::{max, min, Reverse};
use std::collections::{HashMap, HashSet};
use std::fs::File;
use std::io::{self, prelude::*};
use std::str;

struct Scanner<R> {
    reader: R,
    buf_str: Vec<u8>,
    buf_iter: str::SplitWhitespace<'static>,
}
impl<R: BufRead> Scanner<R> {
    fn new(reader: R) -> Self {
        Self {
            reader,
            buf_str: vec![],
            buf_iter: "".split_whitespace(),
        }
    }
    fn token<T: str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buf_iter.next() {
                return token.parse().ok().expect("Failed parse");
            }
            self.buf_str.clear();
            self.reader
                .read_until(b'\n', &mut self.buf_str)
                .expect("Failed read");
            self.buf_iter = unsafe {
                let slice = str::from_utf8_unchecked(&self.buf_str);
                std::mem::transmute(slice.split_whitespace())
            }
        }
    }
}

fn __run_test<R: BufRead, W: Write>(scan: &mut Scanner<R>, w: &mut W) {
    let n = scan.token::<usize>();
    let mut largest_bit: usize = 0;
    for bit in (0..31) {
        if (n & (1 << bit) > 0) {
            largest_bit = bit;
        }
    }

    let largest_number = (1 << (largest_bit + 1)) - 1;
    writeln!(w, "{}", 2 * largest_number + 1);

    let mut previous_prefix_sum = 0;
    for i in (1..(1 << (largest_bit + 1))) {
        let current_prefix_sum = i ^ (i >> 1);
        let current_number = current_prefix_sum ^ previous_prefix_sum;
        write!(w, "{} 0 ", current_number);
        previous_prefix_sum = current_prefix_sum;
    }
    writeln!(w, "{}", previous_prefix_sum);
}

fn solve<R: BufRead, W: Write>(scan: &mut Scanner<R>, w: &mut W) {
    let t: usize = scan.token();
    for _ in 0..t {
        __run_test(scan, w);
    }
}

fn main() {
    #[cfg(debug_assertions)]
    let (input, output): (Box<dyn Read>, Box<dyn Write>) = (
        Box::new(
            File::open(option_env!("LOCAL_INPUT").unwrap_or("IO/input.txt"))
                .expect("failed to open input"),
        ),
        Box::new(
            File::create(option_env!("LOCAL_OUTPUT").unwrap_or("IO/output.txt"))
                .expect("failed to create output"),
        ),
    );
    #[cfg(not(debug_assertions))]
    let (input, output): (Box<dyn Read>, Box<dyn Write>) =
        (Box::new(io::stdin()), Box::new(io::stdout()));

    let mut scan = Scanner::new(io::BufReader::new(input));
    let mut out = io::BufWriter::new(output);
    solve(&mut scan, &mut out);
}

/*
-> Check for data types
-> Fix macro
-> Run test case
-> Check the copied part
-> Set or multiset?
-> Check statement order
-> Check simple logic errors
-> Read problem statements carefully
*/
