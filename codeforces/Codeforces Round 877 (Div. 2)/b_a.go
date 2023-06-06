package main

import (
	. "fmt"
	"os"
	"io"
	"bufio"
	"sort"
)

func sol(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var T int
	for Fscan(in, &T); T > 0; T-- {
		var n int
		Fscan(in, &n)

		var p1, p2, pn int
		for i := 0; i < n; i++ {
			var a int
			Fscan(in, &a)
			if a == 1 {
				p1 = i + 1
			} else if a == 2 {
				p2 = i + 1
			} else if a == n {
				pn = i + 1
			}
		}

		arr := []int{p1, p2, pn}
		sort.Ints(arr)
		Fprintln(out, pn, arr[1])
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
