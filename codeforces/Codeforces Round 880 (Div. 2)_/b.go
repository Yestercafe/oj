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
		var n, k, g int
		Fscan(in, &n, &k, &g)
		if k == 0 {
			Fprintln(out, 0)
			continue
		}
		half := (g - 1) / 2
		if n * half <= k * g {
			ans := n * half
			// remain := (k * g - n * half + half) % g
			// remain := ((k - n + 1) * half + k * (g - half)) % g
			remain := (k * g - ans) % g;
			if remain != 0 {
				ans -= g - remain
			}
			Fprintln(out, ans)
		} else {
			Fprintln(out, k * g)
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
