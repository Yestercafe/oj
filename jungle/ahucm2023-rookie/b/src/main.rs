use std::io;

fn main() {
    let mut s = String::new();
    let _ = io::stdin().read_line(&mut s);
    let t = s.trim().split_whitespace().map(|s| s.parse::<i64>().unwrap()).collect::<Vec<_>>();
    
    let mut vac = vec![];

    for _ in 0..t[1] {
        let mut s = String::new();
        let _ = io::stdin().read_line(&mut s);
        let q = s.trim().split_whitespace().map(|s| s.parse::<i64>().unwrap()).collect::<Vec<_>>();
        if q[0] <= 0 || q[0] > t[0] || q[1] <= 0 || q[1] > t[0] { continue }
        vac.push((-q[1], -q[0]));
    }
    let mut diff = vec![0i64; t[0] as usize + 1];
    for _ in 0..t[2] {
        let mut s = String::new();
        let _ = io::stdin().read_line(&mut s);
        let q = s.trim().split_whitespace().map(|s| s.parse::<i64>().unwrap()).collect::<Vec<_>>();
        diff[q[0] as usize] += 1;
        diff[q[1] as usize + 1] -= 1;
    }

    let mut adm = vec![0i64; t[0] as usize + 1];
    for i in 1..=t[0] as usize {
        adm[i] = adm[i - 1] + diff[i];
    }
    
    vac.sort();
    
    let mut ans = 0i64;
    let mut head = t[0] + 1;
    for (_, v) in vac.iter().enumerate() {
        if adm[-v.0 as usize] > 0 {
            continue
        }
        if -v.1 >= head {
            continue
        }
        
        let mut flag = false;
        for i in (-v.1..=-v.0).rev() {
            let i = i as usize;
            if adm[i] > 0 {
                flag = true;
                break
            }
        }

        if !flag {
            head = -v.1;
            ans += 1;
        }
    }

    println!("{ans}");
}
