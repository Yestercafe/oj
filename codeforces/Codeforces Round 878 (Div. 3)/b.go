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
		var n, k int
		Fscan(in, &n, &k)
		if k > 32 {
			k = 32
		}

		ans := min(n + 1, 1 << k)
		Fprintln(out, ans)
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
