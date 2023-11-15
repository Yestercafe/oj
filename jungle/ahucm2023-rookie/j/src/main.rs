use std::io;

fn main() {
    let mut s = String::new();
    let _ = io::stdin().read_line(&mut s);
    let t = s.trim().parse::<i32>().unwrap();
    for _ in 0..t {
        let mut s = String::new();
        let _ = io::stdin().read_line(&mut s);
        let size = s.trim().split_whitespace().map(|s| s.parse::<usize>().unwrap()).collect::<Vec<_>>();
        let mut maze = vec![];
        for _ in 0..size[0] {
            let mut s = String::new();
            let _ = io::stdin().read_line(&mut s);
            maze.push(s.trim().split_whitespace().map(|s| s.parse::<i32>().unwrap()).collect::<Vec<_>>());
        }
        
        let mut f = vec![vec![-1; size[1] + 1]; size[0] + 1];
        f[1][1] = maze[0][0];
        for i in 1..=size[0] {
            for j in 1..=size[1] {
                if maze[i - 1][j - 1] == 0 {
                    f[i][j] = -1;
                    continue
                }
                if i - 1 > 0 && f[i - 1][j] >= 0 && j - 1 > 0 && f[i][j - 1] >= 0 {
                    f[i][j] = f[i][j].max(maze[i - 1][j - 1] + f[i - 1][j].max(f[i][j - 1]));
                } else if j - 1 > 0 && f[i][j - 1] >= 0  {
                    f[i][j] = f[i][j].max(maze[i - 1][j - 1] + f[i][j - 1]);
                } else if i - 1 > 0 && f[i - 1][j] >= 0 {
                    f[i][j] = f[i][j].max(maze[i - 1][j - 1] + f[i - 1][j]);
                } else if i != 1 && j != 1 {
                    f[i][j] = -1;
                }
            }
        }

        println!("{}", f.last().unwrap().last().unwrap())
    }
}

