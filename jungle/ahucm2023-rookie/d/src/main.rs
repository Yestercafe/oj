use std::io;

const MOD: i64 = 1e9 as i64 + 7;

fn main() {
    let mut s = String::new();
    let _ = io::stdin().read_line(&mut s);

    let mut s = String::new();
    let _ = io::stdin().read_line(&mut s);
    let pos = s.trim().split_whitespace().map(|s| s.parse::<i64>().unwrap()).collect::<Vec<_>>();

    let mut dir = String::new();
    let _ = io::stdin().read_line(&mut dir);
    let dir = dir.trim().chars();
    
    let mut s = String::new();
    let _ = io::stdin().read_line(&mut s);
    let time = s.trim().parse::<i64>().unwrap();
    
    let mut target = vec![];
    for (i, d) in dir.enumerate() {
        if d == 'L' {
            target.push(pos[i] - time);
        } else {   // d == 'R'
            target.push(pos[i] + time);
        }
    }

    target.sort();
    let mut ans: i64 = 0;
    for i in 0..target.len() {
        ans -= (target.len() - i - 1) as i64 * target[i];
        ans += i as i64 * target[i];
        while ans < 0 {
            ans += MOD;
        }
        ans %= MOD;
    }

    println!("{ans}");
}

