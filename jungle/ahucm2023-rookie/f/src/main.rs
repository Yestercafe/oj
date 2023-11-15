use std::{collections::BinaryHeap, io};

fn main() {
    let mut s = String::new();
    let _ = io::stdin().read_line(&mut s);
    let t = s.trim().parse::<i32>().unwrap();
    for _ in 0..t {
        let mut upper: BinaryHeap<i32> = BinaryHeap::new();
        let mut lower: BinaryHeap<i32> = BinaryHeap::new();
        // make lower.len() + 1 == upper.len() || lower.len() == upper.len()
    
        loop {
            let mut s = String::new();
            let _ = io::stdin().read_line(&mut s);
            let q = s.trim().parse::<i32>().unwrap();
            if q == 0 {
                break
            } else if q < 0 {
                println!("{}", lower.peek().unwrap());
                continue
            }
            
            if lower.is_empty() {
                lower.push(q);
                continue
            }
            if upper.is_empty() {
                upper.push(-q);
                continue
            }
            // now upper and lower should be not empty

            if lower.len() == upper.len() {
                // insert q into lower
                if q > -*upper.peek().unwrap() {
                    lower.push(-upper.pop().unwrap());
                    upper.push(-q);
                } else {
                    lower.push(q);
                }
                println!("a");
            } else {    // lower.len() + 1 == upper.len()
                if q < *lower.peek().unwrap() {
                    upper.push(-lower.pop().unwrap());
                    lower.push(q);
                } else {
                    upper.push(-q);
                }
                println!("b");
            }
        }
    }
}
