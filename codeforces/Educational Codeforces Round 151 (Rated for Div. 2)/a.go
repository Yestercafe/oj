package main

import (
	. "fmt"
	"os"
	"io"
	"bufio"
)

func sol(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var T int
	for Fscan(in, &T); T > 0; T-- {
		var n, k, x int
		Fscan(in, &n, &k, &x)
		if x != 1 {
			Fprintln(out, "YES")
			Fprintln(out, n)
			for i := 0; i < n; i++ {
				Fprint(out, "1 ")
			}
			Fprintln(out)
			continue
		}

		// x == 1
		if k == 1 {
			Fprintln(out, "NO")
			continue
		} else if k == 2 {
			if n % 2 == 1 {
				Fprintln(out, "NO")
			} else {
				Fprintln(out, "YES")
				Fprintln(out, n / 2)
				for i := 0; i < n / 2; i++ {
					Fprint(out, "2 ")
				}
				Fprintln(out)
			}
			continue
		}

		// x == 1, k >= 3
		if n == 1 {
			Fprintln(out, "NO")
			continue
		} else if n == 2 {
			Fprintln(out, "YES\n1\n2")
		} else {
			if n % 2 == 0 {
				Fprintln(out, "YES")
				Fprintln(out, n / 2)
				for i := 0; i < n / 2; i++ {
					Fprint(out, "2 ")
				}
				Fprintln(out)
			} else {
				n -= 3
				Fprintln(out, "YES")
				Fprintln(out, n / 2 + 1)
				for i := 0; i < n / 2; i++ {
					Fprint(out, "2 ")
				}
				Fprint(out, "3")
				Fprintln(out)
			}
		}
	}
}

func main() {
	sol(os.Stdin, os.Stdout)
}

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}
