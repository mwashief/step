/*
    14 November 2026
   ~ step others jam
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
    let m = scan.token::<usize>();

    let mut adj = vec![Vec::<usize>::new(); n];

    for _ in 0..m {
        let mut u = scan.token::<usize>();
        let mut v = scan.token::<usize>();
        u -= 1;
        v -= 1;
        adj[u].push(v);
        adj[v].push(u);
    }

    for children in adj.iter() {
        if children.len() == 0 {
            writeln!(w, "Brain Melt");
            return;
        }
    }

    let mut visited = vec![false; n];

    fn visit(node: usize, visited: &mut [bool], adj: &[Vec<usize>]) {
        for &neighbour in &adj[node] {
            if !visited[neighbour] {
                visited[neighbour] = true;
                visit(neighbour, visited, adj);
            }
        }
    }

    let mut components = 0;

    for i in 0..n {
        if !visited[i] {
            components += 1;
            visited[i] = true;
            visit(i, &mut visited, &adj);
        }
    }

    // more than 1 connected components or there is a cycle
    if components > 1 || m > n - 1 {
        writeln!(w, "Many");
        return;
    }

    // it's a tree
    let mut leaves = 0;
    for nei in adj.iter() {
        if nei.len() == 1 {
            leaves += 1;
        }
    }

    if leaves < n - 1 {
        writeln!(w, "Many");
        return;
    }

    // star graph
    writeln!(w, "2");
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
